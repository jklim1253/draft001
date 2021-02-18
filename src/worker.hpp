#ifndef __WORKER_HPP__
#define __WORKER_HPP__

namespace jklim
{

struct task
{
protected:
  virtual int todo() = 0;
};

class worker
  : public task
{
public:
  worker();
  virtual ~worker();

  int start();
  int stop();

private:
  class implement;
  implement* impl;
};

} // namespace jklim

#endif // __WORKER_HPP__