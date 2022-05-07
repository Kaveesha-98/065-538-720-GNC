import sys

sys.path.append(".")

from instructions_class import *

class assm_program:
    labeled = False
    label = ""
    instructions = []

    def next_instruction(self, operands):
        if operands[0] in {"add", "sub", "sll", "slt", "sltu", "xor", "srl", "sra", "or", "and"}:
            self.instructions.append(reg_reg_32I(operands))
        elif operands[0] in {"addi", "slli", "slti", "sltui", "xori", "srli", "srai", "ori", "andi"}:
            self.instructions.append(reg_imm_32I(operands))
        else:
            print("wrong operands")
            assert 1==2