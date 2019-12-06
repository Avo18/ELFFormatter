#ifndef CLASS_ELFReader
#define CLASS_ELFReader

#include <vector>
#include "Loader.cpp"
#include "ELFBufferBytes.cpp"
#include "ELFStructure.h"
#include <algorithm>
#include "VectorSearch.h"
#include "LambdaProgramHeader.h"

class ELFReader
{
private:
	ELFStructur header;
	std::vector<ELFProgramHeader> programHeader = {};
	std::vector<ELFSectionHeader> sectionHeaders = {};
	std::vector<ELFLoadDirectives> loadDirectives = {};

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

	void readELFLoadDirectives(ELFBufferBytes& byteReader)
	{
		ELFProgramHeader* dynamicPH = findInVector(programHeader, LambdaPH_Type(ProgramHeader::DYNAMIC));
		if (dynamicPH == NULL) return;
		loadDirectives.resize(dynamicPH->_filesz / sizeof(struct ELFLoadDirectives));
		byteReader.setPosition(dynamicPH->_offset);
		Loader::fillLoadDirectives(byteReader, loadDirectives);
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
	std::vector<ELFLoadDirectives>* getLoadDirectives()
	{
		return &loadDirectives;
	}
};

#endif