#pragma once

namespace SectionHeader
{
	enum class Name
	{
		EMPTY = 0x00,
		INTERP = 0xb,
		NOTE_ABI_TAG = 0x13,
		GNU_HASH = 0x21,
		HASH = 0x25,
		DYN_SYM = 0x2b,
		DYN_STR = 0x33,
		GNU_VERSION = 0x3b,
		GNU_VERSION_R = 0x48,
		REL_DYN = 0x57,
		REL_PLT = 0x60,
		PLT = 0x64,
		INIT = 0x69,
		TEXT = 0x6f,
		FINI = 0x75,
		RODATA = 0x7b,
		EH_FRAME = 0x83,
		CTORS = 0x8d,
		DTORS = 0x94,
		JCR = 0x9b,
		DYNAMIC = 0xa0,
		GOT = 0xa9,
		GOT_PLT = 0xae,
		DATA = 0xb7,
	};
	enum class Type
	{
		_NULL = 0x00,
		PROGBIT = 0x01,
		STRTAB = 0x03,
		HASH = 0x05,
		DYNAMIC = 0x06,
		NOTE = 0x07,
		REL = 0x09,
		DYNSYM = 0x0b,
		GNU_HASH = 0x6ffffff6,
		HIOS = 0x6fffffff,
		GNU_VERNEED = 0x6ffffffe,
	};
}
namespace Grant_Access
{
	enum Access
	{
		Read = 0x04,
		Execute_Read = 0x05,
		Write_Read = 0x06
	};
}

namespace LoadDirectivesTag
{
	enum Tag
	{
		_NULL = 0x00,
		NEEDED = 0x01,
		PLTRELSZ = 0x02,
		PLTGOT = 0x03,
		HASH = 0x04,
		STRTAB = 0x05,
		SYMTAB = 0x06,
		RELA = 0x07,
		RELASZ = 0x08,
		RELAENT = 0x09,
		STRSZ = 0xA,
		SYMENT = 0xB,
		INIT = 0xC,
		FINI = 0xD,
		REL = 0x11,
		REL_SZ = 0x12,
		REL_ENT = 0x13,
		PLTREL = 0x14,
		DEBUG = 0x15,
		JUMP_REL = 0x17,
		DT_GNU_HASH = 0x6ffffef5,
		VERSYM = 0x6ffffff0,
		VERNEED = 0x6ffffffe,
		VERNEED_NUM = 0x6fffffff,
		/*
		... check wikipedia for more Tags.
		*/
	};
}

namespace ProgramHeader
{
	enum Types
	{
		_NULL = 0x00,
		LOAD = 0x01,
		DYNAMIC = 0x02,
		INTERP = 0x03,
		NOTE = 0x04,
		SHLIB = 0x05,
		PHDR = 0x06,
		LOOS = 0x60000000,
		GNU_STACK = 0x6474e551
		/*
		... check wikipedia for more types.
		*/
	};
}

namespace InstructionArchitect
{
	enum Instruction
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
}

namespace ObjectFileType
{
	enum Type
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
}

