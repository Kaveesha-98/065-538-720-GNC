#include <stdio.h>
#include <stdlib.h>
#include "Vtest_bench_robin_core_v2.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <string>
#include <iostream>
#include <map>
#include <bitset>
#include <iomanip>
#include <fstream>

using namespace std;

void tick(int tickcount, Vtest_bench_robin_core_v2 *tb, VerilatedVcdC* tfp){
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

int main(int argc, char **argv){
	string text_line;

	unsigned tickcount = 0;

	// Call commandArgs first!
	Verilated::commandArgs(argc, argv);
	
	//Instantiate our design
	Vtest_bench_robin_core_v2 *tb = new Vtest_bench_robin_core_v2;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("test_bench_robin_coretrace.vcd");
	
	ifstream inFile;
	
	inFile.open("test_benches/executables.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    
    getline(inFile, text_line);
    //cout << text_line << endl;
    int n = stoi(text_line)+1;
	cout << n << endl;
	string instructions[n];
	string instruction;
	int binaries[n];
	int i = 0;
	
	while (getline (inFile, text_line)) {
    	instruction = "";
    	//cout << i << endl;
    	for(int index = 0; index < text_line.length(); index++){
    		if(text_line[index] == '|'){
    			if(instruction[0] == '-'){
    				instruction[0] = '0';
    				binaries[i] = 0 - stoi(instruction);
    			}else{
    				binaries[i] = stoi(instruction);
    			}
    			instruction = "";
    		}else{
    			instruction = instruction + text_line[index];
    		}
    	}
    	instructions[i] = instruction;
    	i++;
    }
    tb -> io_START_PROGRAM = 0;
    int count = 0;
    while(count < n){
    	tb->io_mem_write_address_instruction = count;
    	tb->io_mem_write_instruction = binaries[count];
    	tb->io_signal_mem_write_instruction = 1;
    	tick(++tickcount, tb, tfp);
    	count++;
    }
    
    tb-> io_START_PROGRAM = 1;
    tick(++tickcount, tb, tfp);
    tb-> io_START_PROGRAM = 0;
    
    for (int i = 0; i < 20; i++){
    	tick(++tickcount, tb, tfp);
    }
	/*
	assm_translator translator;
	translator.RS1 = 0;
	translator.RS2 = 0;
	translator.RD = 2;
	translator.Op = "addi";
	translator.immediate = 8;
	cout << translator.translate() << endl;
	
	tb-> io_INSTRUCTION = instructionToInt(translator.translate());
	tb-> io_INSTRUCTION_LOADED = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_INSTRUCTION_LOADED = 0;
	translator.RS1 = 2;
	//translator.immediate += 1;
	translator.RD = 1;
	translator.Op = "jal";
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
		tb-> io_INSTRUCTION = instructionToInt(translator.translate());
		tb-> io_INSTRUCTION_LOADED = 1;
		if (tb -> io_RECIEVED == 1){
			tb-> io_INSTRUCTION_LOADED = 0;
			tick(++tickcount, tb, tfp);
			//translator.immediate += 1;
			//translator.RD += 1;
		}
	}*/
    inFile.close();
}
