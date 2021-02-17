#include "reader.hpp"
#include "common.hpp"

namespace jklim
{

class reader::implement
{
public:
  implement()
  {

  }
  implement(std::string const& _filepath)
  {

  }
  ~implement()
  {

  }

public:
  int open(std::string const& _filepath)
  {
    return ec::not_implemented_yet;
  }
  int close()
  {
    return ec::not_implemented_yet;
  }
};

reader::reader()
  : impl(new implement)
{
}
reader::reader(std::string const& _filepath)
  : impl(new implement(_filepath))
{
}
reader::~reader()
{
  if (impl)
  {
    delete impl;
    impl = nullptr;
  }
}

int reader::open(std::string const& _filepath)
{
  return impl->open(_filepath);
}
int reader::close()
{
  return impl->close();
}

std::ostream& operator << (std::ostream& _os, reader const& _obj)
{
  return _os;
}


} // namespace jklim
