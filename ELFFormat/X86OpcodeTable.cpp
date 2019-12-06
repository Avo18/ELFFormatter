#include "X86Opcode.h"

#define instruction(name, ins, start_opcode, end_opcode)\

#define X86(val) X86OpcodeTable::ins_##val

// table https://i.stack.imgur.com/VTxd0.jpg
namespace ASM
{
	const X86OpcodeTable instructionTable[3] =
	{
		instruction("ADD", X86(ADD), 0x00, 0x05)
		instruction("ADC", X86(ADC), 0x10, 0x15)
		instruction("PUSH", X86(PUSH), 0x50, 0x57)
		instruction("MOV", X86(MOV_REG), 0x88, 0x8B)
		instruction("SUB", X86(SUB), 0x83, 0x83)
		instruction("CALL", X86(CALL), 0xE8, 0xE8)
	};

}

#undef X86