#include <stdio.h>
#include <stdlib.h>
#include "VLoad_Unit.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, VLoad_Unit *tb, VerilatedVcdC* tfp){
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
	VLoad_Unit *tb = new VLoad_Unit;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("Load_Unittrace.vcd");
	
	tb->io_LOAD_ADDRESS_IN = 1;
	tb->io_load_data = 10;
	tb->io_load_begin = 1;
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
	}
}
