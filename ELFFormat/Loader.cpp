#include "ELFStructure.h"
#include "ELFView.h"
#include "Loader.h"
#include "ELFBufferBytes.cpp"

class Loader
{
public:
	static void fillHeader(ELFBufferBytes byteReader, ELFStructur& elfHeader)
	{
		byteReader.read_32bit(elfHeader._magicNumber);
		byteReader.read_8bit(elfHeader._class);
		byteReader.read_8bit(elfHeader._data);
		byteReader.read_8bit(elfHeader._version);
		byteReader.read_8bit(elfHeader._abi);
		byteReader.read_8bit(elfHeader._abiVersion);
		byteReader.setJumpBytes(sizeof(elfHeader._pad));
		byteReader.read_16bit(elfHeader._type);
		byteReader.read_16bit(elfHeader._machine);
		byteReader.read_32bit(elfHeader._entry);
		byteReader.read_32bit(elfHeader._phoff);
		byteReader.read_32bit(elfHeader._shoff);
		byteReader.read_32bit(elfHeader._flag);
	}
};