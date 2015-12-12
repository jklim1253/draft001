#pragma once
#include <fstream>

struct version {
	int major;
	int minor;
};

version getVersion(std::fstream& file);
