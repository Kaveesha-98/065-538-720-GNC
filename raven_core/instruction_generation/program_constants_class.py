class prog_constants:
    r_type_ops_32i = {"add", "sub", "sll", "slt", "sltu", "xor", "srl", "sra", "or", "and"}
    i_type_alu_imm_ops_32i = {"addi", "slli", "slti", "sltui", "xori", "srli", "srai", "ori", "andi"}
    i_type_loads_32i = {"lb", "lbu", "lh", "lhu", "lw"}
    i_type_jalr_32i = {"jalr"}
    u_type_ops_32i = {"lui", "auipc"}
    i_type_ops_32i = set().union(*[i_type_alu_imm_ops_32i, i_type_loads_32i, i_type_jalr_32i])
    s_type_ops_32i = {"sb", "sh", "sw"}
    b_type_ops_32i = {"beq", "bne", "blt", "bge", "bltu", "bgeu"}
    j_type_ops_32i = {"jal"}
    i_type_branchops = set().union(*[b_type_ops_32i, j_type_ops_32i])