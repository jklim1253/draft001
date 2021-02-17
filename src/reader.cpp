#include "reader.hpp"
#include "common.hpp"
#include "pdf-format.hpp"

#include <fstream>
#include <iostream>

namespace jklim
{

class object
{

};

class objects
  : public object
{
  version _ver;
  std::fstream& _file;

public:
  objects(std::fstream& file)
    : _file(file)
  {
    init();
  }
private:
  void init()
  {
    int err = ec::no_error;
    if (ec::no_error != (err = getVersion(_file, _ver)))
    {
      std::cerr << "getVersion error: " << err << std::endl;
    }
  }
  friend std::ostream& operator << (std::ostream& _os, objects const& _o)
  {
    _os << _o._ver;
    return _os;
  }
};

class reader::implement
{
  std::fstream _file;
public:
  implement()
  {
  }
  implement(std::string const& _filepath)
  {
    open(_filepath);
  }
  ~implement()
  {
    close();
  }

public:
  int open(std::string const& _filepath)
  {
    _file.open(_filepath, std::ios::binary | std::ios::in);
    if (!_file.good())
    {
      return ec::file_not_found;
    }
    return ec::no_error;
  }
  int close()
  {
    _file.close();
    return ec::no_error;
  }
  objects content()
  {
    objects _objs(_file);
    return std::move(_objs);
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
  _os << "[[Parsing]]\n"
      << _obj.impl->content();
  return _os;
}


} // namespace jklim
