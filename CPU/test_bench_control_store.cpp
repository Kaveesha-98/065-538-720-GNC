#include <stdio.h>
#include <stdlib.h>
#include "Vcontrol_store.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <string>
#include <iostream>
#include <map>
#include <bitset>

int instructionToInt(std::string machine_instruction){
	int int_instruction = 0;
	int multiplier = 1;
	for(int i = 31; i >= 0; i--){
		if(machine_instruction[i] == '1'){
			int_instruction += multiplier;
		}
		multiplier = multiplier*2;
	}
	return int_instruction;
}

void tick(int tickcount, Vcontrol_store *tb, VerilatedVcdC* tfp){
	tb->eval();
	if (tfp){
		tfp->dump(tickcount*10 - 2);
	}
	tb->clock = 1;
	tb->eval();
	if(tfp){
		tfp->dump(tickcount*10);
	}
	tb->clock = 0;
	tb->eval();
	if(tfp){
		tfp->dump(tickcount*10 + 5);
		tfp->flush();
	}
}

int main(int argc, char **argv){

	std::string instruction_string = "lb";
	std::string machine_instruction;
	int register_source_1 = 31;
	int register_source_2 = 4;
	int register_destination = 10;
	int immediate = -7;

	//opcode types
	std::string register_type = "0110011";
	std::string immediate_type = "0010011";
	std::string storing_type = "0100011";
	std::string loading_type = "0000011";
	
	std::string immediate12bit = std::bitset< 12 >( immediate ).to_string();

	//opcodes
	std::map<std::string, std::string> opcode = {
	{"add", "0010011"}, {"sub", "0110011"}, {"sll", "0110011"},
	{"slt", "0110011"}, {"sltu", "0110011"}, {"xor", "0110011"},
	{"srl", "0110011"}, {"sra", "0110011"}, {"or", "0110011"},
	{"and", "0110011"},
	{"addi", "0010011"}, {"slli", "0010011"},
	{"slti", "0010011"}, {"sltui", "0010011"}, {"xori", "0010011"},
	{"srli", "0010011"}, {"srai", "0010011"}, {"ori", "0010011"},
	{"andi", "0010011"},
	{"sb", "0100011"}, {"sh", "0100011"}, {"sw", "0100011"},
	{"lb", "0000011"}, {"lh", "0000011"}, {"lw", "0000011"},
	{"lbu", "0000011"}, {"lhu", "0000011"}
	};
								
	std::map<std::string, std::string> funct3 = {
	{"add", "000"}, {"sub", "000"}, {"sll", "001"}, {"slt", "010"},
	{"sltu", "011"}, {"xor", "100"}, {"srl", "101"}, {"sra", "101"},
	{"or", "110"}, {"and", "111"},
	{"addi", "000"}, {"slli", "001"}, {"slti", "010"},
	{"sltui", "011"}, {"xori", "100"}, {"srli", "101"}, {"srai", "101"},
	{"ori", "110"}, {"andi", "111"},
	{"sb", "000"}, {"sh", "001"}, {"sw", "010"},
	{"lb", "000"}, {"lh", "001"}, {"lw", "010"},
	{"lbu", "100"}, {"lhu", "101"}
	};
								
	std::map<std::string, std::string> funct7 = {
	{"add", "0000000"}, {"sub", "0100000"}, {"sll", "0000000"},
	{"slt", "0000000"}, {"sltu", "0000000"}, {"xor", "0000000"},
	{"srl", "0000000"}, {"sra", "0100000"}, {"or", "0000000"},
	{"and", "0000000"},
	{"slli", "0000000"}, {"srli", "0000000"}, {"srai", "0100000"},
	};
						
	if(opcode[instruction_string] == register_type){
		machine_instruction =  funct7[instruction_string] + std::bitset< 5 >( register_source_2 ).to_string() + std::bitset< 5 >( register_source_1 ).to_string() + funct3[instruction_string] + std::bitset< 5 >( register_destination ).to_string() + opcode[instruction_string];
	} else if(opcode[instruction_string] == immediate_type && (instruction_string == "srli" || instruction_string == "slli" || instruction_string == "srai")){
		machine_instruction =  funct7[instruction_string] + std::bitset< 5 >( immediate ).to_string() + std::bitset< 5 >( register_source_1 ).to_string() + funct3[instruction_string] + std::bitset< 5 >( register_destination ).to_string() + opcode[instruction_string];
	} else if(opcode[instruction_string] == immediate_type){
		machine_instruction = std::bitset< 12 >( immediate ).to_string() + std::bitset< 5 >( register_source_1 ).to_string() + funct3[instruction_string] + std::bitset< 5 >( register_destination ).to_string() + opcode[instruction_string];
	} else if(opcode[instruction_string] == storing_type){
		machine_instruction = immediate12bit.substr(0, 7) + std::bitset< 5 >( register_source_2 ).to_string() + std::bitset< 5 >( register_source_1 ).to_string() + funct3[instruction_string] + immediate12bit.substr(7, 11) + opcode[instruction_string];
	} else if(opcode[instruction_string] == loading_type){
		machine_instruction = std::bitset< 12 >( immediate ).to_string() + std::bitset< 5 >( register_source_1 ).to_string() + funct3[instruction_string] + std::bitset< 5 >( register_destination ).to_string() + opcode[instruction_string];
	}

	unsigned tickcount = 0;
	
	std::cout << "machine instruction: " << machine_instruction << '\n';

	// Call commandArgs first!
	Verilated::commandArgs(argc, argv);
	
	//Instantiate our design
	Vcontrol_store *tb = new Vcontrol_store;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("control_storetrace.vcd");
	
	tb-> reset = 1;
	tick(++tickcount, tb, tfp);
	tb-> reset = 0;
	
	tb-> io_INSTRUCTION = instructionToInt(machine_instruction);
	tb-> io_INSTRUCTION_LOADED = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_INSTRUCTION_LOADED = 0;
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
		if(tb -> io_LOAD_ADDRESS_IN == 1){
			tick(++tickcount, tb, tfp);
			tick(++tickcount, tb, tfp);
			tb-> io_LOAD_READY = 1;
			tick(++tickcount, tb, tfp);
		}
		if(i == 5){
			tb-> io_STORE_READY = 1;
			tick(++tickcount, tb, tfp);
			tb-> io_STORE_READY = 0;
		}
	}
}
