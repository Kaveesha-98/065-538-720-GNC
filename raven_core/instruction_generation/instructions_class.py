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
        self.op = operands[0]
        self.rd = operands[1]
        self.rs1 = operands[2]
        self.rs2 = operands[3]
        assert self.op in self.consts.r_type_ops_32i
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.rs2) == type(1) and 0 <= self.rs2 <= 31
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31

    def print_assm(self):
        return self.op + " x" + str(self.rd) + ", x" + str(self.rs1) + ", x" + str(self.rs2)

    def assemble(self):
        return (self.funct7[self.alu_op] + 
        "{0:05b}".format(self.rs2) + 
        "{0:05b}".format(self.rs1) + 
        self.funct3[self.alu_op] + 
        "{0:05b}".format(self.rd) + 
        "0110011")

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
                return ("{0:012b}".format(mod_imm) + 
                "{0:05b}".format(self.rs1) + 
                self.funct3[self.op] + 
                "{0:05b}".format(self.rd) + 
                "0010011")
            else:
                return (self.funct7[self.op] + 
                "{0:05b}".format(self.imm) + 
                "{0:05b}".format(self.rs1) + 
                self.funct3[self.op] + 
                "{0:05b}".format(self.rd) + 
                "0010011")
        elif self.op in self.consts.i_type_loads_32i:
            return ("{0:012b}".format(mod_imm) + 
            "{0:05b}".format(self.rs1) + 
            self.funct3[self.op] + 
            "{0:05b}".format(self.rd) + 
            "0000011")
        else:
            return ("{0:012b}".format(mod_imm) + 
            "{0:05b}".format(self.rs1) + 
            self.funct3[self.op] + 
            "{0:05b}".format(self.rd) + 
            "1100111")

class u_type_32i(assm_instruction):

    def __init__(self, operands):
        self.op = operands[0]
        self.rd = operands[1]
        self.imm = operands[2]
        assert self.op in self.consts.u_type_ops_32i
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31
        assert 0 <= self.imm < 2**20

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

class s_type_32i(assm_instruction):

    funct3 = {
        "sb" : "000",
        "sh" : "001",
        "sw" : "010"
    }

    def __init__(self, operands):
        self.op = operands[0]
        self.rs1 = operands[2]
        self.rs2 = operands[1]
        self.imm = operands[3]
        assert self.op in self.consts.s_type_ops_32i
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.rs2) == type(1) and 0 <= self.rs2 <= 31
        assert type(self.imm) == type(-1) and -2048 <= self.imm <= 2047

    def print_assm(self):
        return (self.op + 
        " x" + str(self.rs2) + ", "  + 
        str(self.imm) + 
        "(x" + str(self.rs1) + ")")

    def assemble(self):
        if self.imm < 0:
            mod_imm = self.imm + 2**12
        else:
            mod_imm = self.imm
        
        imm_string = "{0:012b}".format(mod_imm)
        imm_string = imm_string[::-1]

        return ((imm_string[5:12])[::-1] + 
        "{0:05b}".format(self.rs2) + 
        "{0:05b}".format(self.rs1) + 
        self.funct3[self.op] + 
        (imm_string[0:5])[::-1] + 
        "0100011")

class b_type_32i(assm_instruction):

    funct3 = {
        "beq" : "000",
        "bne" : "001",
        "blt" : "100",
        "bge" : "101",
        "bltu": "110",
        "bgeu": "111"
    }

    def __init__(self, operands):
        self.op = operands[0]
        self.rs1 = operands[1]
        self.rs2 = operands[2]
        self.jump_label = operands[3]
        self.resolved = False
        assert self.op in self.consts.b_type_ops_32i
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.rs2) == type(1) and 0 <= self.rs2 <= 31

    def resolve_label(self, jump):
        assert -2**12 <= jump < 2**12
        assert jump%2 == 0
        self.imm = jump
        self.resolved = True

    def print_assm(self):
        if self.resolved:
            return self.op + " x" + str(self.rs1) + ", x" + str(self.rs2) + ", " + str(self.imm)
        else:
            return self.op + " x" + str(self.rs1) + ", x" + str(self.rs2) + ", " + self.jump_label

    def assemble(self):
        if self.resolved:
            if self.imm < 0:
                mod_imm = self.imm + 2**13
            else:
                mod_imm = self.imm
        
            imm_string = "{0:013b}".format(mod_imm)
            imm_string = imm_string[::-1]

            return (imm_string[12] + 
            (imm_string[5:11])[::-1] + 
            "{0:05b}".format(self.rs2) + 
            "{0:05b}".format(self.rs1) + 
            self.funct3[self.op] + 
            (imm_string[1:5])[::-1] + 
            imm_string[11] + 
            "1100011") 
        else:
            return "----jump label not resolved-----"

class j_type_32i(assm_instruction):

    def __init__(self, operands):
        self.op = operands[0]
        self.rd = operands[1]
        self.jump_label = operands[2]
        self.resolved = False
        assert self.op in self.consts.j_type_ops_32i
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31

    def resolve_label(self, jump):
        assert -2**20 <= jump < 2**20
        assert jump%2 == 0
        self.imm = jump
        self.resolved = True
    
    def print_assm(self):
        if self.resolved:
            return self.op + " x" + str(self.rd) + ", " + str(self.imm)
        else:
            return self.op + " x" + str(self.rd) + ", " + self.jump_label

    def assemble(self):
        if self.resolved:
            if self.imm < 0:
                mod_imm = self.imm + 2**21
            else:
                mod_imm = self.imm
        
            imm_string = "{0:013b}".format(mod_imm)
            imm_string = imm_string[::-1]

            return (imm_string[20] + 
            (imm_string[1:11])[::-1] + 
            imm_string[11] + 
            (imm_string[12:20])[::-1] + 
            "{0:05b}".format(self.rd) + 
            "1101111") 
        else:
            return "----jump label not resolved-----"