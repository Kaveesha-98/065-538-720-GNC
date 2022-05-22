import sys

sys.path.append(".")

from instructions_class import *
from assm_program_class import *

newProgram = assm_program()
#newProgram.next_instruction(['li', 2, 0*ord('c')*2**24 + 0*ord('c')*2**16 + 0*ord('u')*2**8 + ord('s')], True, 'start')
#newProgram.next_instruction(['li', 3, 0*ord('\n')*2**24 + 0*ord('s')*2**16 + 0*ord('s')*2**8 + ord('e')], False, '')
newProgram.next_instruction(['li', 2,  ord('s')], True, 'start')
newProgram.next_instruction(['li', 3,  ord('e')], False, '')
newProgram.next_instruction(['li', 4, 4], False, '')
newProgram.next_instruction(['sb', 2, 0, 0], True, 'l1')
newProgram.next_instruction(['srai', 2, 2, 8], False, '')
newProgram.next_instruction(['addi', 4, 4, -1], False, '')
newProgram.next_instruction(['bne', 0, 4, 'l1'], False, '')
newProgram.next_instruction(['li', 4, 4], False, '')
newProgram.next_instruction(['sb', 3, 0, 0], True, 'l2')
newProgram.next_instruction(['srai', 3, 3, 8], False, '')
newProgram.next_instruction(['addi', 4, 4, -1], False, '')
newProgram.next_instruction(['bne', 0, 4, 'l2'], False, '')
newProgram.next_instruction(['beq', 0, 0, 'start'], False, '')

print(newProgram.print_assembly())

newProgram.resolve_branches()

print(newProgram.assemble())

program = newProgram.assembledBitStream(newProgram.assemble())

programFile = open("program.txt", "w")
programFile.write(program)
programFile.close()

print(len(program))