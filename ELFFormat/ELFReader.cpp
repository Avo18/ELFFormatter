#ifndef CLASS_ELFReader
#define CLASS_ELFReader

#include <vector>
#include "Loader.cpp"
#include "ELFBufferBytes.cpp"

class ELFReader
{
private:
	ELFStructur header;
	std::vector<ELFProgramHeader> programHeader = {};
	std::vector<ELFSectionHeader> sectionHeaders = {};
public:

	void readELFHeader(ELFBufferBytes& byteReader)
	{
		Loader::fillHeader(byteReader, header);
	}

	void readELFProgramHeader(ELFBufferBytes& byteReader)
	{
		programHeader.resize(header.e_phnum);
		byteReader.setPosition(header.e_phoff);
		Loader::fillProgramHeader(byteReader, programHeader);
	}

	void readELFSectionHeader(ELFBufferBytes& byteReader)
	{
		sectionHeaders.resize(header.e_shnum);
		byteReader.setPosition(header.e_shoff);
		Loader::fillSectionHeader(byteReader, sectionHeaders);
	}

	ELFStructur* getHeader()
	{
		return &header;
	}
	std::vector<ELFProgramHeader>* getProgramHeader()
	{
		return &programHeader;
	}
	std::vector<ELFSectionHeader>* getSectionHeader()
	{
		return &sectionHeaders;
	}
};

#endif