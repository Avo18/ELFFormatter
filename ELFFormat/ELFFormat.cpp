// ELFFormat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "ELFStructure.h"
#include "Loader.cpp"
#include "ELFBufferBytes.cpp"
#include "ELFReader.cpp"
#include <mman.c>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <string.h>

//#include <stdio.h>
//#include <string.h>
//#include <sys/mman.h>
//#include <unistd.h>

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
	auto file = std::ifstream{ L"C:\\Users\\vanst\\Downloads\\helloworld\\chello", std::ifstream::binary };
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
	reader.readELFSectionHeader(in);
	reader.readELFLoadDirectives(in);

	// test ASM reading
	// offset 0x274   
	// size 0x30

	std::getchar();
	return 0; // success return
}

