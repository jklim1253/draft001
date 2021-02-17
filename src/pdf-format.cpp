#include "pdf-format.hpp"
#include "common.hpp"

#include <functional>
#include <iostream>

namespace jklim
{

std::ostream& operator << (std::ostream& _os, version const& _ver)
{
  _os << "PDF Version: "
      << _ver.major
      << '.'
      << _ver.minor;
  return _os;
}

int getVersion(std::fstream& file, version& _ver)
{
	static const std::streamsize rsize = 8;

  if (!file.good())
  {
    return ec::file_not_opened;
  }

  std::streampos checkpoint;
  AtLast<std::function<void()>, std::function<void()>> rewinder
  (
    [&checkpoint, &file]()
    {
      checkpoint = file.tellg();
      std::clog << "check point saved.\n";
    },
    [&checkpoint, &file]()
    {
      file.seekg(checkpoint);
      std::clog << "check point restored.\n";
    }
  );

	char dump[rsize];
	file.seekg(0, std::ios_base::beg);
	file.read(dump, rsize);
  if ((dump[0] == '%')
    && (dump[1] == 'P')
    && (dump[2] == 'D')
    && (dump[3] == 'F')
    && (dump[4] == '-'))
  {
  	_ver = { dump[5] - '0', dump[7] - '0' };
  }
  else
  {
    return ec::file_format_is_not_supported;
  }

	return ec::no_error;
}

} // namespace jklim
