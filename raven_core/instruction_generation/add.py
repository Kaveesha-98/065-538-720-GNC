import sys

sys.path.append(".")

from instructions_class import *
from assm_program_class import *

newClass = reg_reg_32I(['add', 1, 2, 3])
newProgram = assm_program()
newProgram.next_instruction(['add', 1, 2, 3])
newProgram.next_instruction(['addi', 1, 2, 3])
newProgram.next_instruction(['addi', 1, 2, -2048])
newProgram.next_instruction(['srai', 1, 2, 31])

for i in range(len(newProgram.instructions)):
    print(newProgram.instructions[i].assemble(), end = " ")
    print(newProgram.instructions[i].print_assm())
