#pragma once
#include <cstdint>
#include "Enumerations.h"

struct ELFStructur
{
	uint8_t  e_ident[16];         /* Magic number and other info */
	enum ObjectFileType::Type  e_type;   /* Object file type */
	enum InstructionArchitect::Instruction  e_machine;           /* Architecture */
	uint32_t  e_version;           /* Object file version */
	uint32_t  e_entry;             /* Entry point virtual address */
	uint32_t  e_phoff;             /* Program header table file offset */
	uint32_t  e_shoff;             /* Section header table file offset */
	uint32_t  e_flags;             /* Processor-specific flags */
	uint16_t  e_ehsize;            /* ELF header size in bytes */
	uint16_t  e_phentsize;         /* Program header table entry size */
	uint16_t  e_phnum;             /* Program header table entry count */
	uint16_t  e_shentsize;         /* Section header table entry size */
	uint16_t  e_shnum;             /* Section header table entry count */
	uint16_t  e_shstrndx;          /* Section header string table index */

	//uint8_t _magicNumber[16]; // ELF start
	//uint8_t _class;
	//uint8_t _data;
	//uint8_t _version;
	//uint8_t _abi; // welke operating system
	//uint8_t _abiVersion; 
	//uint8_t _pad[7];
};

struct ELFProgramHeader
{
	enum ProgramHeader::Types _type;
	uint32_t _offset;
	uint32_t _vaddr; // virtual address
	uint32_t _paddr; // phisical address;
	uint32_t _filesz; 
	uint32_t _memsz;
	enum Grant_Access::Access _flags;
	uint32_t _align;
};

struct ELFSectionHeader
{
	enum SectionHeader::Name _name;
	enum SectionHeader::Type _type;
	uint32_t _flags;
	uint32_t _addr;
	uint32_t _offset;
	uint32_t _size;
	uint32_t _link;
	uint32_t _info;
	uint32_t _addrAlign;
	uint32_t _entSize;
};

struct ELFLoadDirectives
{
	enum LoadDirectivesTag::Tag _tag; 
	uint32_t _val;
};

