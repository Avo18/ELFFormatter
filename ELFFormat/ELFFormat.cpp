// ELFFormat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "ELFView.h"
#include "ELFStructure.h"
#include "Loader.cpp"
#include "ELFBufferBytes.cpp"


int main()
{
	auto file = std::ifstream { L"C:\\Users\\vanst\\Downloads\\helloworld\\chello", std::ifstream::binary };
	auto buffer = std::vector<char>{};
	//check insteken! 

	// lees u file tot einde
	file.seekg(0, std::istream::end);
	auto size = (unsigned int)file.tellg();
	file.seekg(0, std::istream::beg);

	// lees volledig file
	buffer.resize(size);
	file.read(buffer.data(), size);

	ELFBufferBytes in { buffer.data(), size };
	ELFStructur header { };

	Loader::fillHeader(in, header);



	return 0; // success return
}

