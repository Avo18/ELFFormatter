#pragma once
#include <cstdint>
struct ELFStructur
{
	uint32_t _magicNumber; // ELF start
	uint8_t _class;
	uint8_t _data;
	uint8_t _version;
	uint8_t _abi; // welke operating system
	uint8_t _abiVersion; 
	uint8_t _pad[7];
	uint16_t _type; // enum -> ObjectFileType
	uint16_t _machine; // enum -> InstructionArchitect 

	// 32bit = 2bytes start address, 64bit system = 4byte start address
	uint32_t _entry; // geen main maar _start nodig
	uint32_t _phoff; // start headet tabel
	uint32_t _shoff; // start section header tabel
	uint32_t _flag; 
};

enum InstructionArchitect
{
	NONE = 0x00,
	SPARC = 0x02,
	x86 = 0x03,
	MIPS = 0x08,
	POWERPC = 0x14,
	S390 = 0x16,
	ARM = 0x28,
	SUPERH = 0x2A,
	IA_64 = 0x32,
	x86_64 = 0x3E
};

enum ObjectFileType
{
	ET_NONE = 0x00,
	ET_REL = 0x01,
	ET_EXEC = 0x02,
	ET_DYN = 0x03,
	ET_CORE = 0x04,
	ET_LOOS = 0xfe00,
	ET_HIOS = 0xfeff,
	ET_LOPROC = 0xff00,
	ET_HIPROC = 0xffff
};