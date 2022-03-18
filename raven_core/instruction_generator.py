def register_instruction(rs1, rs2, rd, alu_op):
	funct3_map = {
		"000" : "ADD",
		"000" : "SUB",
		"001" : "SLL",
		"010" : "SLT",
		"011" : "SLTU",
		"100" : "XOR",
		"101" : "SRL",
		"101" : "SRA",
		"110" : "OR",
		"111" : "AND"
	}
	funct7_map = {
		"0000000" : "ADD",
		"0100000" : "SUB",
		"0000000" : "SLL",
		"0000000" : "SLT",
		"0000000" : "SLTU",
		"0000000" : "XOR",
		"0000000" : "SRL",
		"0100000" : "SRA",
		"0000000" : "OR",
		"0000000" : "AND"
	}
	instruction = funct7_map.get(alu_op, "0000000") + "{0:05b}".format(rs2) + "{0:05b}".format(rs1) + funct3_map.get(alu_op, "000") + "{0:05b}".format(rd) + "0110011"
	return instruction
	
def registerImm_instruction(rs1, immediate, rd, alu_op):
	funct3_map = {
		"000" : "ADD",
		"001" : "SLL",
		"010" : "SLT",
		"011" : "SLTU",
		"100" : "XOR",
		"101" : "SRL",
		"101" : "SRA",
		"110" : "OR",
		"111" : "AND"
	}
	funct7_map = {
		"0000000" : "SLL",
		"0000000" : "SRL",
		"0100000" : "SRA"
	}
	
	if(alu_op == "SLL" or alu_op == "SRL" or alu_op == "SRA"):
		instruction = funct7_map.get(alu_op, "0000000") + "{0:05b}".format(immediate) + "{0:05b}".format(rs1) + funct3_map.get(alu_op, "000") + "{0:05b}".format(rd) + "0110011"
	else:
		if(immediate < 0):
			immediate += 2**12
		instruction = "{0:012b}".format(immediate) + "{0:05b}".format(rs1) + funct3_map.get(alu_op, "000") + "{0:05b}".format(rd) + "0010011"
		
	return instruction


instructions = open("source_code/test_instructions.txt", "w")

for i in range(31):
	instructions.write('b' + registerImm_instruction(0, i, i, "ADD") + '\n')

instructions.write('b' + registerImm_instruction(0, 31, 31, "ADD"))

instructions.close()

print(registerImm_instruction(3, -1, 5, "ADD"))
	
