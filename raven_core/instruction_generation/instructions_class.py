class assm_instruction:
    labeled = False
    label = ""

class reg_reg_32I(assm_instruction):

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
        assert self.alu_op in {"add", "sub", "sll", "slt", "sltu", "xor", "srl", "sra", "or", "and"}
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.rs2) == type(1) and 0 <= self.rs2 <= 31
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31

    def print_assm(self):
        return self.alu_op + " x" + str(self.rd) + ", x" + str(self.rs1) + ", x" + str(self.rs2)

    def assemble(self):
        return self.funct7[self.alu_op] + "{0:05b}".format(self.rs2) + "{0:05b}".format(self.rs1) + self.funct3[self.alu_op] + "{0:05b}".format(self.rd) + "0110011"

class reg_imm_32I(assm_instruction):

    funct3 = {
        "addi" : "000", 
        "slli" : "001", 
        "slti" : "010", 
        "sltui" : "011", 
        "xori" : "100", 
        "srli" : "101", 
        "srai" : "101", 
        "ori" : "110", 
        "andi" : "111"
    }

    funct7 = {
        "slli" : "0000000",  
        "srli" : "0000000", 
        "srai" : "0100000"
    }

    def __init__(self, operands):
        self.alu_op = operands[0]
        self.rd = operands[1]
        self.rs1 = operands[2]
        self.imm = operands[3]
        assert self.alu_op in {"addi", "slli", "slti", "sltui", "xori", "srli", "srai", "ori", "andi"}
        assert type(self.rs1) == type(1) and 0 <= self.rs1 <= 31
        assert type(self.imm) == type(-1) and -2048 <= self.imm <= 2047
        if self.alu_op in {"slli", "srli", "srai"}:
            assert 0 <= self.imm <= 31
        assert type(self.rd) == type(1) and 0 <= self.rd <= 31

    def print_assm(self):
        return self.alu_op + " x" + str(self.rd) + ", x" + str(self.rs1) + ", " + str(self.imm)

    def assemble(self):
        if self.alu_op in {"addi", "slti", "sltui", "xori", "ori", "andi"}:
            if self.imm < 0:
                mod_imm = 4096 + self.imm
            else:
                mod_imm = self.imm
            return "{0:012b}".format(mod_imm) + "{0:05b}".format(self.rs1) + self.funct3[self.alu_op] + "{0:05b}".format(self.rd) + "0010011"
        else:
            return self.funct7[self.alu_op] + "{0:05b}".format(self.imm) + "{0:05b}".format(self.rs1) + self.funct3[self.alu_op] + "{0:05b}".format(self.rd) + "0010011"

