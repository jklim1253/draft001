#include "pdf-format.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Usage : pdfviewer [pdf-file]" << endl;
		return 1;
	}

	fstream file;
	file.open(argv[1], ios_base::binary | ios_base::in);

	version ver = getVersion(file);

	cout << "PDF Version : " << ver.major << "." << ver.minor << endl;

	file.close();
	cin.get();
	
	return 0;
}

