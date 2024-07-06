#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

enum opcode
{
	op_nop,
	op_push,
	op_pushn,
	op_pop,
	op_popn,
	op_ldi0,
	op_ldi1,
	op_ldi2,
	op_ldd0,
	op_ldd1,
	op_ldd2,
	op_ineg,
	op_dneg,
	op_iadd,
	op_dadd,
	op_isub,
	op_dsub,
	op_imul,
	op_dmul,
	op_idiv,
	op_ddiv,
	op_imod,
	op_ieq,
	op_deq,
	op_ineq,
	op_dneq,
	op_ilt,
	op_dlt,
	op_ile,
	op_dle,
	op_igt,
	op_dgt,
	op_ige,
	op_dge,
	op_shl,
	op_shr,
	op_bor,
	op_bxor,
	op_band,
	op_bnot,
	op_or,
	op_and,
	op_not,
	op_i2d,
	op_d2i,
	op_outb,
	op_outc,
	op_outi,
	op_outd,
	op_halt
};

struct virtual_machine
{
	int32_t *stack = nullptr;
	uint8_t *code = nullptr;
	int32_t *sp = nullptr;
	uint8_t *ip;

	void init();
	void execution_engine();
};


void virtual_machine::init()
{

}

void virtual_machine::execution_engine()
{
	uint8_t n = 0;
	uint8_t instr = code[0];
	switch (instr) {
	case opcode::op_nop:
		break;
	case opcode::op_push:
		++sp;
		break;
	case opcode::op_pushn:
		n = code[ip++];
		sp += n;
		break;
	case opcode::op_pop:
		--sp;
		break;
	case opcode::op_popn:
		n = code[ip++];
		sp -= n;
		break;	
	case opcode::op_ldi0:
		*(++sp) = 0;
		break;
	case opcode::op_ldi1:
		*(++sp) = 1;
		break;
	case opcode::op_ldi2:
		*(++sp) = 2;
		break;		
	case opcode::op_ldd0:
		*(++sp) = 0.0;
		break;
	case opcode::op_ldd1:
		*(++sp) = 1.0;
		break;
	case opcode::op_ldd2:
		*(++sp) = 2.0;
		break;
	case opcode::op_ineg:
		sp[0] = -sp[0];
		break;
	case opcode::op_dneg:
		sp[0] = -double(sp[0]);
		break;
	case opcode::op_iadd:
		sp[-1] = sp[-1] + sp[0];
		--sp;
		break;
	case opcode::op_dadd:
		*(double*) sp = double(sp[-1]) + double(sp[0]);
		--sp;
		break;	
	case opcode::op_isub:
		sp[-1] = sp[-1] - sp[0];
		--sp;
		break;
	case opcode::op_dsub:
		*(double*) sp = double(sp[-1]) - double(sp[0]);
		--sp;
		break;
	case opcode::op_imul:
		sp[-1] = sp[-1] * sp[0];
		--sp;
		break;
	case opcode::op_dmul:
		*(double*) sp = double(sp[-1]) * double(sp[0]);
		--sp;
		break;
	case opcode::op_idiv:
		sp[-1] = sp[-1] / sp[0];
		--sp;
		break;
	case opcode::op_ddiv:
		*(double*) sp = double(sp[-1]) / double(sp[0]);
		--sp;
		break;
	case opcode::op_imod:
		sp[-1] = sp[-1] % sp[0];
		--sp;
		break;
	case opcode::op_ieq:
		sp[-1] = sp[-1] == sp[0];
		--sp;
		break;
	case opcode::op_ineq:
		sp[-1] = sp[-1] != sp[0];
		--sp;
		break;
	case opcode::op_ilt:
		sp[-1] = sp[-1] == sp[0];
		--sp;
		break;
	case opcode::op_ile:
		sp[-1] = sp[-1] == sp[0];
		--sp;
		break;
	case opcode::op_igt:
		sp[-1] = sp[-1] == sp[0];
		--sp;
		break;
	case opcode::op_ige:
		sp[-1] = sp[-1] == sp[0];
		--sp;
		break;
	case opcode::op_deq:
		sp[-1] = double(sp[-1]) == double(sp[0]);
		--sp;
		break;
	case opcode::op_dneq:
		sp[-1] = double(sp[-1]) != double(sp[0]);
		--sp;
		break;
	case opcode::op_dlt:
		sp[-1] = double(sp[-1]) < double(sp[0]);
		--sp;
		break;
	case opcode::op_dle:
		sp[-1] = double(sp[-1]) <= double(sp[0]);
		--sp;
		break;
	case opcode::op_dgt:
		sp[-1] = double(sp[-1]) > double(sp[0]);
		--sp;
		break;
	case opcode::op_dge:
		sp[-1] = double(sp[-1]) >= double(sp[0]);
		--sp;
		break;
	case opcode::op_or	
	case opcode::op_i2d:
		*(double*) sp = double(sp[0]);
		break;
	case opcode::op_d2i:
		sp[0] = double(sp[0]);
		break;
	case opcode::op_outb:
		printf("%s", sp[0] == 1 ? "true" : "false");
		break;
	case opcode::op_outc:
		printf("%c", char(sp[0]));
		break;
	case opcode::op_outi:
		printf("%d", sp[0]);
		break;
	case opcode::op_outd:
		printf("%g", double(sp[0]));
		break;
	case opcode::op_halt:
		return;	
	}
}

int main(int argc, const char **argv)
{
	std::cout << "saral virtual machine" << std::endl;
	return EXIT_SUCCESS;
}
