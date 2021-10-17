#include <stdio.h>
#include <stdlib.h>
#include "Vcontrol_store.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

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

	unsigned tickcount = 0;

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
	
	tb-> io_INSTRUCTION = 0x007302B3;
	tb-> io_INSTRUCTION_LOADED = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_INSTRUCTION_LOADED = 0;
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
	}
}
