import sys

sys.path.append(".")

from instructions_class import *
from program_constants_class import *

class assm_program:
    labeled = False
    label = ""
    instructions = []

    consts = prog_constants()

    def next_instruction(self, operands):
        if operands[0] in self.consts.r_type_ops_32i:
            self.instructions.append(r_type_32i(operands))
        elif operands[0] in self.consts.i_type_ops_32i:
            self.instructions.append(i_type_32i(operands))
        elif operands[0] in self.consts.u_type_ops_32i:
            self.instructions.append(u_type_32i(operands))
        elif operands[0] in self.consts.s_type_ops_32i:
            self.instructions.append(s_type_32i(operands))
        elif operands[0] in self.consts.b_type_ops_32i:
            self.instructions.append(b_type_32i(operands))
        else:
            print("wrong operands")
            assert 1==2