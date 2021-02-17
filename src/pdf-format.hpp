#ifndef __PDF_FORMAT_HPP__
#define __PDF_FORMAT_HPP__

#include <fstream>

namespace jklim
{

struct version {
	int major;
	int minor;

  friend std::ostream& operator << (std::ostream&, version const&);
};

int getVersion(std::fstream& file, version& _version);

} // namespace jklim

#endif // __PDF_FORMAT_HPP__