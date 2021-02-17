#include "pdf-format.hpp"
#include "common.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <exception>

int main(int argc, char* argv[]) {

	if (argc != 2)
  {
		std::cout << "Usage : pdfviewer [pdf-file]" << std::endl;
		return jklim::ec::invalid_arguments;
	}

	std::fstream file;
	file.open(argv[1], std::ios_base::binary | std::ios_base::in);

  int err;
	jklim::version ver;
  if (jklim::ec::no_error != (err = jklim::getVersion(file, ver)))
  {
    return err;
  }

	std::cout << ver << std::endl;

	file.close();

  std::cout << "press enter to exit...";
	std::cin.get();
	
	return 0;
}

