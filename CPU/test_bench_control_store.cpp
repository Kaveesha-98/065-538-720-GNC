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

	std::string instruction_string = "add";
	std::string machine_instruction;
	int register_source_1 = 6;
	int register_source_2 = 7;
	int register_destination = 5;

	//opcode types
	std::string register_type = "0110011";

	//opcodes
	std::map<std::string, std::string> opcode = {{"add", "0110011"}
								};
								
	std::map<std::string, std::string> funct3 = {{"add", "000"}
								};
								
	std::map<std::string, std::string> funct7 = {{"add", "0000000"}
								};
						
	if(opcode[instruction_string] == register_type){
		machine_instruction =  funct7[instruction_string] + std::bitset< 5 >( register_source_2 ).to_string() + std::bitset< 5 >( register_source_1 ).to_string() + funct3[instruction_string] + std::bitset< 5 >( register_destination ).to_string() + opcode[instruction_string];
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
	}
}
