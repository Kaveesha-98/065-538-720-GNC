#include <stdio.h>
#include <stdlib.h>
#include "Vled_mover.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, Vled_mover *tb, VerilatedVcdC* tfp){
	tb->eval();
	if (tfp){
		tfp->dump(tickcount*10 - 2);
	}
	tb->i_clk = 1;
	tb->eval();
	if(tfp){
		tfp->dump(tickcount*10);
	}
	tb->i_clk = 0;
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
	Vled_mover *tb = new Vled_mover;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("led_movertrace.vcd");
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
	}
}
