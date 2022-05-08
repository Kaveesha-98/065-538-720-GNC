import sys

sys.path.append(".")

from program_constants_class import *

class assm_instruction:
    labeled = False
    label = ""
    consts = prog_constants()

class r_type_32i(assm_instruction):

    funct3 = {
        "add" : "000", 
        "sub" : "000", 
        "sll" : "001", 
        "slt" : "010", 
        "sltu" : "011", 
        "xor" : "100", 
        "srl" : "101", 
        "sra" : "101", 
        "or" : "110", 
        "and" : "111"
    }

    funct7 = {
        "add" : "0000000", 
        "sub" : "0100000", 
        "sll" : "0000000", 
        "slt" : "0000000", 
        "sltu" : "0000000", 
        "xor" : "0000000", 
        "srl" : "0000000", 
        "sra" : "0100000", 
        "or" : "0000000", 
        "and" : "0000000"
    }

    def __init__(self, operands):
        self.alu_op = operands[0]
        self.rd = operands[1]
        self.rs1 = operands[2]
        self.rs2 = operands[3]
        assert self.alu_op in self.consts.r_type_ops_32i
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.rs2) == type(1) and 0 <= self.rs2 <= 31
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31

    def print_assm(self):
        return self.alu_op + " x" + str(self.rd) + ", x" + str(self.rs1) + ", x" + str(self.rs2)

    def assemble(self):
        return self.funct7[self.alu_op] + "{0:05b}".format(self.rs2) + "{0:05b}".format(self.rs1) + self.funct3[self.alu_op] + "{0:05b}".format(self.rd) + "0110011"

class i_type_32i(assm_instruction):

    funct3 = {
        "addi" : "000", 
        "slli" : "001", 
        "slti" : "010", 
        "sltui" : "011", 
        "xori" : "100", 
        "srli" : "101", 
        "srai" : "101", 
        "ori" : "110", 
        "andi" : "111",
        "lb" : "000",
        "lbu": "100",
        "lh" : "001",
        "lhu": "101",
        "lw" : "010"
    }

    funct7 = {
        "slli" : "0000000",  
        "srli" : "0000000", 
        "srai" : "0100000"
    }

    def __init__(self, operands):
        self.op = operands[0]
        self.rd = operands[1]
        self.rs1 = operands[2]
        self.imm = operands[3]
        assert self.op in self.consts.i_type_ops_32i
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.imm) == type(-1) and -2048 <= self.imm <= 2047
        if self.op in {"slli", "srli", "srai"}:
            assert 0 <= self.imm <= 31
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31

    def print_assm(self):
        if self.op in self.consts.i_type_alu_imm_ops_32i:
            return self.op + " x" + str(self.rd) + ", x" + str(self.rs1) + ", " + str(self.imm)
        elif self.op in self.consts.i_type_loads_32i:
            return self.op + " x" + str(self.rd) + ", " + str(self.imm) + "(x" + str(self.rs1) + ")"
        else:
            return self.op + " x" + str(self.rd) + ", " + str(self.imm) + "(x" + str(self.rs1) + ")"

    def assemble(self):
        if self.imm < 0:
            mod_imm = 4096 + self.imm
        else:
            mod_imm = self.imm
        if self.op in self.consts.i_type_alu_imm_ops_32i:
            if self.op in {"addi", "slti", "sltui", "xori", "ori", "andi"}:
                return "{0:012b}".format(mod_imm) + "{0:05b}".format(self.rs1) + self.funct3[self.op] + "{0:05b}".format(self.rd) + "0010011"
            else:
                return self.funct7[self.op] + "{0:05b}".format(self.imm) + "{0:05b}".format(self.rs1) + self.funct3[self.op] + "{0:05b}".format(self.rd) + "0010011"
        elif self.op in self.consts.i_type_loads_32i:
            return "{0:012b}".format(mod_imm) + "{0:05b}".format(self.rs1) + self.funct3[self.op] + "{0:05b}".format(self.rd) + "0000011"
        else:
            return "{0:012b}".format(mod_imm) + "{0:05b}".format(self.rs1) + self.funct3[self.op] + "{0:05b}".format(self.rd) + "1100111"

class u_type_32i(assm_instruction):

    def __init__(self, operands):
        self.op = operands[0]
        self.rd = operands[1]
        self.imm = operands[2]
        assert self.op in self.consts.u_type_ops_32i
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31
        assert 0 <= self.imm < 2**19

    def print_assm(self):
        if self.op == "lui":
            return "lui x" + str(self.rd) + ", " + str(self.imm)
        else:
            return "auipc x" + str(self.rd) + ", " + str(self.imm)

    def assemble(self):
        if self.op == "lui":
            return "{0:020b}".format(self.imm) + "{0:05b}".format(self.rd) + "0110111"
        else:
            return "{0:020b}".format(self.imm) + "{0:05b}".format(self.rd) + "0010111"
