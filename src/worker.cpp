#include "worker.hpp"
#include "common.hpp"

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace jklim
{

class worker::implement
{
  friend class worker;
  worker* _parent;
  bool _need_to_stop = false;
  std::thread _thread;
  std::mutex _mutex;
  std::condition_variable _cv;

public:
  implement(worker* parent)
    : _parent(parent)
  {
  }
  ~implement()
  {
    stop();
  }
  int start()
  {
    stop();
    _need_to_stop = false;

    _thread = std::thread(&implement::_loop_main, this);

    return ec::no_error;
  }
  int stop()
  {
    {
      std::lock_guard<std::mutex> lock(_mutex);
      _need_to_stop = true;
    }
    _cv.notify_all();

    if (_thread.joinable())
    {
      _thread.join();
    }

    return ec::no_error;
  }

private:
  int _loop_main()
  {
    atlast_easy loop_monitor
    (
      []()
      {
        std::clog << "worker started ["
                  << std::this_thread::get_id()
                  << "]\n";
      },
      []()
      {
        std::clog << "worker finished ["
                  << std::this_thread::get_id()
                  << "]\n";
      }
    );

    std::unique_lock<std::mutex> lock(_mutex);
    while (true)
    {
      if (_cv.wait_for(
            lock,
            std::chrono::microseconds(1),
            [=]()->bool { return _need_to_stop; }))
      {
        std::clog << "force to stop ["
                  << std::this_thread::get_id()
                  << "]\n";
        break;
      }

      if (_parent->todo() != rc::is_good)
      {
        std::clog << "task result is not good\n";
        break;
      }
    }

    return ec::no_error;
  }
};

worker::worker()
  : impl(new implement(this))
{
}
worker::~worker()
{
  if (impl)
  {
    delete impl;
    impl = nullptr;
  }
}

int worker::start()
{
  return impl->start();
}
int worker::stop()
{
  return impl->stop();
}

} // namespace jklim
