#include "pdf-format.h"
using namespace std;

version getVersion(fstream& file) {
	static const streamsize rsize = 8;
	char dump[rsize];
	file.seekg(0, ios_base::beg);
	file.read(dump, rsize);
	version ver = { dump[5] - '0', dump[7] - '0' };

	return ver;
}