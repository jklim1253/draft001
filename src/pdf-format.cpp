#include "pdf-format.hpp"
#include "common.hpp"

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

int getVersion(std::fstream& file, version& _ver) {
	static const std::streamsize rsize = 8;

  if (!file.good())
  {
    return ec::file_not_opened;
  }

  auto check = file.tellg();

	char dump[rsize];
	file.seekg(0, std::ios_base::beg);
	file.read(dump, rsize);
	_ver = { dump[5] - '0', dump[7] - '0' };

  file.seekg(check);

	return ec::no_error;
}

} // namespace jklim
