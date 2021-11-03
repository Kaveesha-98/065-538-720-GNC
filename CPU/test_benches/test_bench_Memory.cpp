#include <stdio.h>
#include <stdlib.h>
#include "VMemory.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, VMemory *tb, VerilatedVcdC* tfp){
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

	unsigned tickcount = 0;

	// Call commandArgs first!
	Verilated::commandArgs(argc, argv);
	
	//Instantiate our design
	VMemory *tb = new VMemory;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("Memorytrace.vcd");
	
	//Loading some data to memory for read testing
	tb->io_mem_write = 1;
	tb->io_mem_write_data = 0x89;
	tb->io_mem_write_address = 16;
	tick(++tickcount, tb, tfp);
	tb->io_mem_write_data = 0xAB;
	tb->io_mem_write_address = 17;
	tick(++tickcount, tb, tfp);
	tb->io_mem_write_data = 0xCD;
	tb->io_mem_write_address = 18;
	tick(++tickcount, tb, tfp);
	tb->io_mem_write_data = 0xEF;
	tb->io_mem_write_address = 19;
	tick(++tickcount, tb, tfp);
	tb->io_mem_write = 0;
	tick(++tickcount, tb, tfp);
	
	//Executing a few cycles before requesting a read
	for(int i = 0; i < 5; i++){
		tick(++tickcount, tb, tfp);
	}
	
	//Requesting a read
	tb->io_rdAddr = 16;
	tick(++tickcount, tb, tfp);
	tb->io_rdAddr = 17;
	tick(++tickcount, tb, tfp);
	tb->io_rdAddr = 18;
	tick(++tickcount, tb, tfp);
	tb->io_rdAddr = 19;
	tick(++tickcount, tb, tfp);
	for(int i = 0; i < 5; i++){
		tick(++tickcount, tb, tfp);
	}
	
}
