// ELFFormat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "ELFView.h"
#include "ELFStructure.h"
#include "Loader.cpp"
#include "ELFBufferBytes.cpp"
#include "ELFReader.cpp"

void printELFHeader(ELFStructur& header)
{
	/*std::cout << std::hex << "magic number: " << "0x" << header._magicNumber << std::endl;
	std::cout << std::hex << "class: " << "0x" << header._class << std::endl;
	std::cout << std::hex << "data: " << "0x" << header._data << std::endl;
	std::cout << std::hex << "version: " << "0x" << header._version << std::endl;
	std::cout << std::hex << "abi: " << "0x" << header._abi << std::endl;*/
};

std::vector<char> readFile()
{
	auto file = std::ifstream{ L"C:\\Users\\vanst\\Downloads\\helloworld\\hello", std::ifstream::binary };
	auto buffer = std::vector<char>{};
	//check insteken! 

	// lees u file tot einde
	file.seekg(0, std::istream::end);
	auto size = (unsigned int)file.tellg();
	file.seekg(0, std::istream::beg);

	// lees volledig file
	buffer.resize(size);
	file.read(buffer.data(), size);

	return buffer;
}

int main()
{
	auto buffer = readFile();
	ELFBufferBytes in { buffer.data(), (unsigned int)buffer.size() };
	ELFReader reader = ELFReader();
	reader.readELFHeader(in);
	reader.readELFProgramHeader(in);

	std::getchar();
	return 0; // success return
}

