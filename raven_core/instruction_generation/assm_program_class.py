import sys

from numpy import True_

sys.path.append(".")

from instructions_class import *
from program_constants_class import *

class assm_program:
    instructions = []

    consts = prog_constants()

    def next_instruction(self, operands, isLabeled, label):
        if operands[0] in self.consts.r_type_ops_32i:
            self.instructions.append(r_type_32i(operands))
            self.instructions[-1].labeled = isLabeled
            self.instructions[-1].label = label
        elif operands[0] in self.consts.i_type_ops_32i:
            self.instructions.append(i_type_32i(operands))
            self.instructions[-1].labeled = isLabeled
            self.instructions[-1].label = label
        elif operands[0] in self.consts.u_type_ops_32i:
            self.instructions.append(u_type_32i(operands))
            self.instructions[-1].labeled = isLabeled
            self.instructions[-1].label = label
        elif operands[0] in self.consts.s_type_ops_32i:
            self.instructions.append(s_type_32i(operands))
            self.instructions[-1].labeled = isLabeled
            self.instructions[-1].label = label
        elif operands[0] in self.consts.b_type_ops_32i:
            self.instructions.append(b_type_32i(operands))
            self.instructions[-1].labeled = isLabeled
            self.instructions[-1].label = label
        elif operands[0] in self.consts.j_type_ops_32i:
            self.instructions.append(j_type_32i(operands))
            self.instructions[-1].labeled = isLabeled
            self.instructions[-1].label = label
        elif operands[0] == 'li':
            #see if the immediate is in range addi immediate
            if -2**11 <= operands[2] < 2**11:
                inAddiRange = True
            else:
                inAddiRange = False

            rd = operands[1]
            imm = operands[2]

            if inAddiRange:
                self.instructions.append(i_type_32i(['addi', rd, 0, imm]))
                self.instructions[-1].labeled = isLabeled
                self.instructions[-1].label = label
            else:
                if imm < 0:
                    immUnsignedRep = imm + 2**32
                else:
                    immUnsignedRep = imm
                #finding the immediates
                addiImm = immUnsignedRep%(2**12)
                luiImm = immUnsignedRep//(2**12)
                if addiImm >= 2**11:
                    luiImm += 1
                #constant of lui is positive
                self.instructions.append(u_type_32i(['lui', rd, luiImm]))
                self.instructions[-1].labeled = isLabeled
                self.instructions[-1].label = label
                self.instructions.append(i_type_32i(['addi', rd, rd, addiImm]))
        else:
            print("wrong operands")
            assert 1==2

    def print_assembly(self):

        assembly = []

        for instruction in self.instructions:
            assembly.append(instruction.print_assm())

        return '\n'.join(assembly)

    def resolve_branches(self):

        label_addresses = {}#instruction labels and addresses

        branching_address = []#address of branches

        for instruction_number, instruction in enumerate(self.instructions):
            #finding the addresses and the corresponding labels
            if instruction.labeled:
                label_addresses[instruction.label] = instruction_number*4#recording address of the label
            
            if(instruction.op in self.consts.i_type_branchops):
                branching_address.append(instruction_number*4)
            
        
        for address in branching_address:
            label = self.instructions[address//4].jump_label
            jump = label_addresses[label] - address
            self.instructions[address//4].resolve_label(jump)

    def assemble(self):

        assembly = []

        for instruction in self.instructions:
            assembly.append(instruction.assemble())

        return '\n'.join(assembly)

    def assembledBitStream(self, binaryString):
        instructionsString = binaryString.split('\n')
        bitStream = ''

        for line in instructionsString:
            bitStream = bitStream + line[::-1]

        return bitStream