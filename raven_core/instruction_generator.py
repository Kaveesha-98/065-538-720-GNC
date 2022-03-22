def register_instruction(rs1, rs2, rd, alu_op):
	funct3_map = {
		"000" : "ADD",
		"000" : "SUB",
		"001" : "SLL",
		"010" : "SLT",
		"011" : "SLTU",
		"100" : "XOR",
		"SRL" : "101",
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

#------------------------------------------------------------------------------------------------	
def registerImm_instruction(rs1, immediate, rd, alu_op):
	funct3_map = {
		"ADD" : "000",
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

#-----------------------------------------------------------------------------------------------
def store_instruction(rs1, rs2, offset, size):
	#size- the amount of bytes to be stored
	
	funct3_map = {
		"000" : 1,
		"001" : 2,
		"010" : 4
	}
	
	if(offset < 0):
		offset += 2*12
	instruction = "{0:012b}".format(offset)[0:7] + "{0:05b}".format(rs2) + "{0:05b}".format(rs1) + funct3_map.get(size, "000") + "{0:012b}".format(offset)[7:12] + "0100011"
	return instruction

#-------------------------------------------------------------------------------------------------
def load_instruction(rs1, rd, offset, size, extension):
	#size- the amount of bytes to be loaded
	#extension- 1 for unsigned extension
	
	funct3_map = {
		"00" : 1,
		"01" : 2,
		"10" : 4
	}
	
	if(offset < 0):
		offset += 2*12
	instruction = "{0:012b}".format(offset) + "{0:05b}".format(rs1) + str(extension) + funct3_map.get(size, "00") + "{0:05b}".format(rd) + "0000011"
	return instruction

#-------------------------------------------------------------------------------------------------
def branch_instruction(rs1, rs2, branch_type, jump):
	#size- the amount of bytes to be loaded
	#extension- 1 for unsigned extension
	
	branch_map = {
		"000" : "BEQ",
		"BNE" : "001",
		"100" : "BLT",
		"101" : "BGE",
		"110" : "BLTU",
		"111" : "BGEU",
	}
	
	if(jump < 0):
		jump += 2*13
		
	jump_str = "{0:013b}".format(jump) 
		
	instruction = jump_str[0] + jump_str[2:8] + "{0:05b}".format(rs2) + "{0:05b}".format(rs1) + branch_map.get(branch_type, "000") + jump_str[8:12] + jump_str[12] + "1100011"
	return instruction


#----------------------------------------------------------------------------------------------------
#instructions = open("source_code/test_instructions.txt", "w")

#for i in range(32):
#	instructions.write('b' + registerImm_instruction(0, i, i, "ADD") + '\n')
#
#instructions.write('b' + store_instruction(0, 0, 33, 1))

#instructions.close()

print(registerImm_instruction(0, 4, 1, "ADD"))
print(load_instruction(0, 2, 0, 1, 1))
print(register_instruction(1, 2, 1, "SRL"))
print(branch_instruction(1, 0, "BNE", 8))
print(registerImm_instruction(0, 4, 1, "ADD"))
print(registerImm_instruction(0, 4, 1, "ADD"))
print(store_instruction(0, 1, 0, 1))
print( "1" + "1111110110" + "1" + "11111111" + "00000" + "1101111")	

	
