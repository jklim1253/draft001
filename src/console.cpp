#include "console.hpp"
#include "common.hpp"
#include "worker.hpp"

#include <iostream>
#include <mutex>
#include <deque>

namespace jklim
{
console& con = console::GetInstance();

class printer
  : public worker
{
  std::mutex _mu;
  std::deque<std::string> _depot;
public:
  int push(std::string const& line)
  {
    std::lock_guard<std::mutex> lock(_mu);
    _depot.push_back(line);

    return ec::no_error;
  } 
protected:
  int todo() override
  {
    std::string buffer;
    {
      std::lock_guard<std::mutex> lock(_mu);
      if (_depot.empty())
      {
        return rc::is_good;
      }
      buffer = _depot.front();
      _depot.pop_front();
    }

    std::cout << buffer << std::endl;

    return rc::is_good;
  }
};

class console::implement
{
  printer _printer;
public:
  implement()
  {
    _printer.start();
  }
  ~implement()
  {
    _printer.stop();
  }
  int push(std::string const& line)
  {
    _printer.push(line);
    return ec::no_error;
  }
};

int console::push(std::string const& line)
{
  return impl->push(line);
}
console& operator << (console& con, std::string const& line)
{
  con.push(line);
  return con;
}

console::console()
  : impl(new implement)
{
}
console::~console()
{
  if (impl)
  {
    delete impl;
    impl = nullptr;
  }
}


} // namespace jklim