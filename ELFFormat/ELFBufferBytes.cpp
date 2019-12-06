#ifndef CLASS_ELFBufferBytes
#define CLASS_ELFBufferBytes

#include <cstdint>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "Endian_Swap.cpp"


class ELFBufferBytes
{
private:
	size_t _offset;
	unsigned int _size;
	const char* _buffer;

public:
	ELFBufferBytes(const char* buffer, unsigned int size) : 
		_buffer(buffer), _size(size), _offset(0)
	{
	}

	template<typename Type>	void read_64bit(Type& value)
	{
		value = *reinterpret_cast<const Type*>(_buffer + _offset);
		_offset += 8;
	}
	template<typename Type>	void read_32bit(Type& value)
	{
		value = *reinterpret_cast<const Type*>(_buffer + _offset);
		_offset += 4;
	}
	template<typename Type>	void read_16bit(Type& value)
	{
		value = *reinterpret_cast<const Type*>(_buffer + _offset);
		_offset += 2;
	}
	template<typename Type>	void read_8bit(Type& value)
	{
		value = *reinterpret_cast<const Type*>(_buffer + _offset);
		_offset += 1;
	}

	template<typename Type, size_t count> void read_array(Type(&chars)[count])
	{
		memcpy(chars, _buffer + _offset, sizeof(Type) * count);
		_offset += sizeof(Type) * count;
	}

	void setPosition(size_t position)
	{
		_offset = position;
	}
	void setJumpBytes(size_t jump)
	{
		_offset += jump;
	}
};

#endif