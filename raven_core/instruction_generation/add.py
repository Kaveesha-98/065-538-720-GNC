import sys

sys.path.append(".")

from instructions_class import *
from assm_program_class import *

newClass = r_type_32i(['add', 1, 2, 3])
newProgram = assm_program()
newProgram.next_instruction(['add', 1, 2, 3])
newProgram.next_instruction(['addi', 1, 2, 3])
newProgram.next_instruction(['addi', 1, 2, -2048])
newProgram.next_instruction(['srai', 1, 2, 31])
newProgram.next_instruction(['lbu', 1, 2, -1])
newProgram.next_instruction(['lui', 1, 976])
newProgram.next_instruction(['auipc', 1, 976])
newProgram.next_instruction(['sh', 1, 2, -2])
newProgram.next_instruction(['bne', 1, 2, 'luck'])
newProgram.instructions[-1].resolve_label(-2)
newProgram.next_instruction(['jal', 1, 'note'])
newProgram.instructions[-1].resolve_label(-2)

for i in range(len(newProgram.instructions)):
    print(newProgram.instructions[i].assemble(), end = " ")
    print(newProgram.instructions[i].print_assm())
