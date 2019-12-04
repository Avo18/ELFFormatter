#ifndef CLASS_ELFReader
#define CLASS_ELFReader

#include <vector>
#include "Loader.cpp"
#include "ELFBufferBytes.cpp"

class ELFReader
{
private:
	ELFStructur header;
	std::vector<ELFSectionHeader> sections = {};
public:

	void readELFHeader(ELFBufferBytes& byteReader)
	{
		Loader::fillHeader(byteReader, header);
	}

	void readELFProgramHeader(ELFBufferBytes& byteReader)
	{
		sections.resize(header.e_phnum);
		Loader::fillSectionHeader(byteReader, sections);
	}

	ELFStructur* getHeader()
	{
		return &header;
	}
	std::vector<ELFSectionHeader>* getProgramHeader()
	{
		return &sections;
	}
};

#endif