#ifndef CLASS_LOADER
#define CLASS_LOADER

#include "ELFStructure.h"
#include "ELFView.h"
#include "Loader.h"
#include "ELFBufferBytes.cpp"
#include <vector>

/*
need to fix endian
*/

class Loader
{
public:
	static void fillHeader(ELFBufferBytes& byteReader, ELFStructur& elfHeader)
	{
		byteReader.read_array(elfHeader.e_ident);
		byteReader.read_16bit(elfHeader.e_type);    // 0x02
		byteReader.read_16bit(elfHeader.e_machine); // 0x03
		byteReader.read_32bit(elfHeader.e_version); // 0x00001
		byteReader.read_32bit(elfHeader.e_entry);   // 0x08048080

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

	static void fillSectionHeader(ELFBufferBytes& byteReader, std::vector<ELFSectionHeader> &section)
	{
		for (int i = 0; i < section.size(); i++)
		{
			section[i] = ELFSectionHeader();
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
};

#endif