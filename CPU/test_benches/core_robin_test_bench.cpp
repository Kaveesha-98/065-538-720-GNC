#include <stdio.h>
#include <stdlib.h>
#include "Vcore_robin.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <string>
#include <iostream>
#include <map>
#include <bitset>

using namespace std;

void tick(int tickcount, Vcore_robin *tb, VerilatedVcdC* tfp){
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

class assm_translator{
	public:
		int RS1, RS2, RD, immediate;
		string translate();
		string Op;
		
		//opcode types
		std::string register_type = "0110011";
		std::string immediate_type = "0010011";
		std::string storing_type = "0100011";
		std::string loading_type = "0000011";
		std::string conditional_branching = "1100011";
		std::string jalr_type = "1100111";
		std::string jal_type = "1101111";
		
		map<string, string> opcode = {
			{"add", "0110011"}, {"sub", "0110011"}, {"sll", "0110011"},
			{"slt", "0110011"}, {"sltu", "0110011"}, {"xor", "0110011"},
			{"srl", "0110011"}, {"sra", "0110011"}, {"or", "0110011"},
			{"and", "0110011"},
			{"addi", "0010011"}, {"slli", "0010011"},
			{"slti", "0010011"}, {"sltui", "0010011"}, {"xori", "0010011"},
			{"srli", "0010011"}, {"srai", "0010011"}, {"ori", "0010011"},
			{"andi", "0010011"},
			{"sb", "0100011"}, {"sh", "0100011"}, {"sw", "0100011"},
			{"lb", "0000011"}, {"lh", "0000011"}, {"lw", "0000011"},
			{"lbu", "0000011"}, {"lhu", "0000011"},
			{"beq", "1100011"}, {"bne", "1100011"}, {"blt", "1100011"},
			{"bge", "1100011"}, {"bltu", "1100011"}, {"bgeu", "1100011"},
			{"jalr", "1100111"},
			{"jal", "1101111"},
			{"auipc", "0010111"}, {"lui", "0110111"}
			};
		map<string, string> funct3 = {
			{"add", "000"}, {"sub", "000"}, {"sll", "001"}, {"slt", "010"},
			{"sltu", "011"}, {"xor", "100"}, {"srl", "101"}, {"sra", "101"},
			{"or", "110"}, {"and", "111"},
			{"addi", "000"}, {"slli", "001"}, {"slti", "010"},
			{"sltui", "011"}, {"xori", "100"}, {"srli", "101"}, {"srai", "101"},
			{"ori", "110"}, {"andi", "111"},
			{"sb", "000"}, {"sh", "001"}, {"sw", "010"},
			{"lb", "000"}, {"lh", "001"}, {"lw", "010"},
			{"lbu", "100"}, {"lhu", "101"},
			{"beq", "000"}, {"bne", "001"}, {"blt", "100"},
			{"bge", "101"}, {"bltu", "110"}, {"bgeu", "111"},
			{"jalr", "000"}
			};
		map<string, string> funct7 = {
			{"add", "0000000"}, {"sub", "0100000"}, {"sll", "0000000"},
			{"slt", "0000000"}, {"sltu", "0000000"}, {"xor", "0000000"},
			{"srl", "0000000"}, {"sra", "0100000"}, {"or", "0000000"},
			{"and", "0000000"},
			{"slli", "0000000"}, {"srli", "0000000"}, {"srai", "0100000"},
			};
}; 

string bitsOf_From_To_(string bits, int end, int start){
	int lengthOfBits = bits.length();
	int returnStringStart = lengthOfBits - end - 1;
	int returnStringEnds = lengthOfBits - start - 1;
	string returnSlice = "";
	
	for(int i = returnStringStart; i <= returnStringEnds; i++){
		returnSlice = returnSlice + bits[i];
	}
	
	return returnSlice;
}

string assm_translator::translate(){
	string immediate12bit = bitset< 12 >( immediate ).to_string();
	string immBranch12bit = bitset< 13 >( immediate ).to_string();
	string immBranch20bit = bitset< 21 >( immediate ).to_string();
	string immediate20bit = bitset< 20 >( immediate ).to_string();
	string machine_instruction;
 
 	if(opcode[Op] == register_type){
		machine_instruction = funct7[Op];
		machine_instruction = machine_instruction + bitset<5>(RS2).to_string(); 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == immediate_type && (Op == "srli" || Op == "slli" || Op == "srai")){
		machine_instruction = funct7[Op];
		machine_instruction = machine_instruction + bitset<5>(immediate).to_string(); 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == immediate_type){
		machine_instruction = immediate12bit; 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == storing_type){
		machine_instruction = bitsOf_From_To_(immediate12bit, 11,  5); 
		machine_instruction = machine_instruction + bitset<5>(RS2).to_string(); 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitsOf_From_To_(immediate12bit,  4,  0); 
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == loading_type){
		machine_instruction = immediate12bit; 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == conditional_branching){
		machine_instruction = bitsOf_From_To_(immBranch12bit, 12,  12); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch12bit, 10,  5); 
		machine_instruction = machine_instruction + bitset<5>(RS2).to_string(); 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch12bit,  4,  1);  
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch12bit,  11,  11);  
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == jalr_type){
		machine_instruction = immediate12bit; 
		machine_instruction = machine_instruction + bitset<5>(RS1).to_string(); 
		machine_instruction = machine_instruction + funct3[Op]; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else if(opcode[Op] == jal_type){
		machine_instruction = bitsOf_From_To_(immBranch12bit, 20,  20); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch12bit, 10,  1); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch12bit, 11,  11); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch12bit, 19,  12); 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else{
		machine_instruction = immediate20bit; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} 
 
	return machine_instruction;
}

int main(int argc, char **argv){

	unsigned tickcount = 0;

	// Call commandArgs first!
	Verilated::commandArgs(argc, argv);
	
	//Instantiate our design
	Vcore_robin *tb = new Vcore_robin;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("core_robintrace.vcd");
	
	assm_translator translator;
	translator.RS1 = 0;
	translator.RS2 = 0;
	translator.RD = 19;
	translator.Op = "sw";
	translator.immediate = 8;
	cout << translator.translate() << endl;
	
	tb-> io_INSTRUCTION = instructionToInt(translator.translate());
	tb-> io_INSTRUCTION_LOADED = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_INSTRUCTION_LOADED = 0;
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
	}
}
