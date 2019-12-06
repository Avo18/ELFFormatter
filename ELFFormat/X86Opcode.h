#pragma once
#include <cstdint>

enum InstructionX86
{
	ADD,
	ADC,
	PUSH,
	MOV_REG,
	SUB,
	CALL
};

struct X86OpcodeTable
{
	char* name;
	enum InstructionX86 ins;
	uint8_t start_opcode;
	uint8_t end_opcode;

};