#include "ELFView.h"
#include <cstdint>
#include <cstdlib>

template<typename DesType, typename SrcType> DesType cast(SrcType src)
{
	if (sizeof(SrcType) != sizeof(DesType))
		throw "not same type size";
	return *reinterpret_cast<DesType*>(&src);
}

template<typename Type> Type swap_64bit(Type src)
{
	return cast<Type>(_byteswap_uint64(cast<uint64_t>(src)));
}
template<typename Type> Type swap_32bit(Type src)
{
	return cast<Type>(_byteswap_ulong(cast<uint32_t>(src)));
}
template<typename Type> Type swap_16bit(Type src)
{
	return cast<Type>(_byteswap_ushort(cast<uint16_t>(src)));
}
template<typename Type> Type swap_8bit(Type src)
{
	return src;
}