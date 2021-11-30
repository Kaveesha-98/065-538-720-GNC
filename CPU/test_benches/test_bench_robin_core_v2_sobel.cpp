#include <stdio.h>
#include <stdlib.h>
#include "Vtest_bench_robin_core_v2_sobel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <string>
#include <iostream>
#include <map>
#include <bitset>
#include <iomanip>
#include <fstream>

using namespace std;

void tick(int tickcount, Vtest_bench_robin_core_v2_sobel *tb, VerilatedVcdC* tfp){
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
	Vtest_bench_robin_core_v2_sobel *tb = new Vtest_bench_robin_core_v2_sobel;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("test_bench_robin_core_sobel_trace.vcd");
	
	ifstream inFile;
	
	inFile.open("test_benches/executables.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    
    getline(inFile, text_line);
    //cout << text_line << endl;
    int n = stoi(text_line)+1;
	//cout << n << endl;
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
    	cout << "Writing instruction address " << count << "     " << '\r';
    	count++;
    }
    
    cout << "Instructions written to memory.                                " << endl;
    
    ifstream dataFile; 
    dataFile.open("test_benches/ImageDataIn.txt");
    
    if (!dataFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    int dataSize = 0;
    
    
    tb-> io_signal_mem_write_data = 1;
    
    while (getline (dataFile, text_line)) {
    	tb-> io_mem_write_data = stoi(text_line);
    	tb-> io_mem_write_address_data = dataSize;
    	dataSize++;
    	tick(++tickcount, tb, tfp);
    	cout << "Writing data address " << dataSize << "     " << '\r';
    }
    
    cout << "Data written to memory.                                " << endl;
    
    tb-> io_signal_mem_write_data = 0;
    
    dataFile.close();
    
    tb-> io_START_PROGRAM = 1;
    tick(++tickcount, tb, tfp);
    tb-> io_START_PROGRAM = 0;
    
    cout << "Starting Program" << endl;
    
    int cycles = 0;
    while(tb-> io_INSTRUCTION != 0){
    	tick(++tickcount, tb, tfp);
    	cycles++;
    	//cout << tb->test_bench_robin_core_v2__DOT__robinCore__DOT__dataPath__DOT__registerFile__DOT__registerFile_20 << '\r';
    	cout << "PC:\t" << tb->io_PC << "\texecuting instruction: " << instructions[(tb->io_PC)/4] << "     " << '\r';
    	
    	if(tb->io_out_mem_write){
    		ofstream intensity ("test_benches/updates.txt",ios::app);
  			intensity << tb->io_out_mem_write_address << ' ' << int(tb->io_out_mem_write_data) << endl;
  			intensity.close();
    	}
    	//cout << tb->io_PC/4 << endl;
    }
    
    cout << "Program Finished, cycles executed: " << cycles << "                             " << endl;
    tick(++tickcount, tb, tfp);
    tick(++tickcount, tb, tfp);
    tick(++tickcount, tb, tfp);
    
    ofstream dataOut; 
    dataOut.open("test_benches/ImageDataOut.txt");
    
    for(int data_index = 0; data_index < dataSize; data_index++){
    	tb-> io_rdAddr = data_index;
    	tick(++tickcount, tb, tfp);
    	dataOut << int(tb->io_rdData) << endl;
    	cout << "Loading data address " << data_index << "     " << '\r';
    }
    
    cout << "Data loaded from memory.                                " << endl;
    
    dataOut.close();
    
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
