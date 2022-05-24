from asyncio import constants
import sys

sys.path.append(".")

from instructions_class import *
from assm_program_class import *

#global constants
labeled = True
notLabeled = False

newClass = r_type_32i(['add', 1, 2, 3])
newProgram = assm_program()
newProgram.next_instruction(['li', 3, 2**10], labeled, 'luck')
newProgram.next_instruction(['add', 1, 2, 3], notLabeled, '')
newProgram.next_instruction(['addi', 1, 2, 3], notLabeled, '')
newProgram.next_instruction(['addi', 1, 2, -2048], notLabeled, '')
newProgram.next_instruction(['srai', 1, 2, 31], notLabeled, '')
newProgram.next_instruction(['lbu', 1, 2, -1], labeled, 'note')
newProgram.next_instruction(['lui', 1, 976], notLabeled, '')
newProgram.next_instruction(['auipc', 1, 976], notLabeled, '')
newProgram.next_instruction(['sh', 1, 2, -2], notLabeled, '')
newProgram.next_instruction(['bne', 1, 2, 'luck'], notLabeled, '')
newProgram.next_instruction(['jal', 1, 'note'], notLabeled, '')

newProgram.resolve_branches()
print(newProgram.print_assembly())

# for i in range(len(newProgram.instructions)):
#     print(newProgram.instructions[i].assemble(), end = " ")
#     print(newProgram.instructions[i].print_assm())
