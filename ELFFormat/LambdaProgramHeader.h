#pragma once
#include "ELFStructure.h"

struct LambdaPH_Type
{
	uint32_t _value;
	LambdaPH_Type(uint32_t value)
	{
		_value = value;
	}
	bool operator()(const ELFProgramHeader& val)
	{
		if (val._type == _value)
			return true;
		return false;
	}
};