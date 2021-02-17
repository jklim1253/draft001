#include "pdf-format.h"

version getVersion(std::fstream& file) {
	static const std::streamsize rsize = 8;
	char dump[rsize];
	file.seekg(0, std::ios_base::beg);
	file.read(dump, rsize);
	version ver = { dump[5] - '0', dump[7] - '0' };

	return ver;
}