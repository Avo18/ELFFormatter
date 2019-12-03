#ifndef CLASS_ELFBufferBytes
#define CLASS_ELFBufferBytes

#include "ELFView.h"
#include <cstdint>
#include <cstdlib>

class ELFBufferBytes
{
private:
	size_t _offset;
	unsigned int _size;
	const char* _buffer;

	template<typename DesType, typename SrcType> DesType cast(SrcType src)
	{
		if (sizeof(SrcType) != sizeof(DesType))
			throw "not same type size";
		return *reinterpret_cast<DesType*>(&src);
	}

	template<typename Type> Type swap_Endian_32bit(Type src)
	{
		return cast<Type>(_byteswap_ulong(cast<uint32_t>(src)));
	}
	template<typename Type> Type swap_Endian_16bit(Type src)
	{
		return cast<Type>(_byteswap_ushort(cast<uint16_t>(src)));
	}

	template<typename Type> Type swap_Endian_8bit(Type src)
	{
		return src;
	}

public:
	ELFBufferBytes(const char* buffer, unsigned int size) : 
		_buffer(buffer), _size(size), _offset(0)
	{
	}

	// bytes zijn little endian, moet omgezet worden naar big endian
	template<typename Type>	void read_32bit(Type& value)
	{
		value = swap_Endian_32bit(*reinterpret_cast<const Type*>(_buffer + _offset));
		_offset += sizeof(Type*);
	}
	template<typename Type>	void read_16bit(Type& value)
	{
		value = swap_Endian_16bit(*reinterpret_cast<const Type*>(_buffer + _offset));
		_offset += sizeof(Type*);
	}
	template<typename Type>	void read_8bit(Type& value)
	{
		value = swap_Endian_8bit(*reinterpret_cast<const Type*>(_buffer + _offset));
		_offset += sizeof(Type*);
	}

	template<typename Type, size_t count> void read(Type(&chars)[count])
	{
		//memcpy()
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