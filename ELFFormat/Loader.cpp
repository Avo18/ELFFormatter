#ifndef CLASS_LOADER
#define CLASS_LOADER

#include "ELFStructure.h"
#include "ELFView.h"
#include "Loader.h"
#include "ELFBufferBytes.cpp"
#include <vector>

class Loader
{
public:
	static void fillHeader(ELFBufferBytes& byteReader, ELFStructur& elfHeader)
	{
		byteReader.read_array(elfHeader.e_ident);
		byteReader.read_16bit(elfHeader.e_type);    
		byteReader.read_16bit(elfHeader.e_machine); 
		byteReader.read_32bit(elfHeader.e_version); 
		byteReader.read_32bit(elfHeader.e_entry);   

		byteReader.read_32bit(elfHeader.e_phoff);
		byteReader.read_32bit(elfHeader.e_shoff);
		byteReader.read_32bit(elfHeader.e_flags);
		byteReader.read_16bit(elfHeader.e_ehsize);

		byteReader.read_16bit(elfHeader.e_phentsize);
		byteReader.read_16bit(elfHeader.e_phnum);
		byteReader.read_16bit(elfHeader.e_shentsize);
		byteReader.read_16bit(elfHeader.e_shnum);
		byteReader.read_16bit(elfHeader.e_shstrndx);

	}

	static void fillProgramHeader(ELFBufferBytes& byteReader, std::vector<ELFProgramHeader> &section)
	{
		for (int i = 0; i < section.size(); i++)
		{
			section[i] = ELFProgramHeader();
			byteReader.read_32bit(section[i]._type);
			byteReader.read_32bit(section[i]._offset);
			byteReader.read_32bit(section[i]._vaddr);
			byteReader.read_32bit(section[i]._paddr);
			byteReader.read_32bit(section[i]._filesz);
			byteReader.read_32bit(section[i]._memsz);
			byteReader.read_32bit(section[i]._flags);
			byteReader.read_32bit(section[i]._align);
		}
	}

	static void fillSectionHeader(ELFBufferBytes& byteReader, std::vector<ELFSectionHeader>& sectionHeader)
	{
		for (int i = 0; i < sectionHeader.size(); i++)
		{
			sectionHeader[i] = ELFSectionHeader();
			byteReader.read_32bit(sectionHeader[i]._name);
			byteReader.read_32bit(sectionHeader[i]._type);
			byteReader.read_32bit(sectionHeader[i]._flags);
			byteReader.read_32bit(sectionHeader[i]._addr);
			byteReader.read_32bit(sectionHeader[i]._offset);
			byteReader.read_32bit(sectionHeader[i]._size);
			byteReader.read_32bit(sectionHeader[i]._link);
			byteReader.read_32bit(sectionHeader[i]._info);
			byteReader.read_32bit(sectionHeader[i]._addrAlign);
			byteReader.read_32bit(sectionHeader[i]._entSize);
		}
	}
};

#endif