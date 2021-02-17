#include "pdf-format.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <exception>

int main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cout << "Usage : pdfviewer [pdf-file]" << std::endl;
		return 1;
	}

	std::fstream file;
	file.open(argv[1], std::ios_base::binary | std::ios_base::in);

	version ver = getVersion(file);

	std::cout << "PDF Version : " << ver.major << "." << ver.minor << std::endl;

	file.close();
	std::cin.get();
	
	return 0;
}

