#include <stdio.h>
#include <stdlib.h>
#include "Vregister_file_sobel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, Vregister_file_sobel *tb, VerilatedVcdC* tfp){
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
	Vregister_file_sobel *tb = new Vregister_file_sobel;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("register_file_sobel_trace.vcd");
	
	for(int i = 0; i < 32; i++){
		tb->io_rdData = i;
		tb->io_RD = i;
		tb->io_WRITE_EN = 1;
		tick(++tickcount, tb, tfp);
	}
	
	tb->io_WRITE_EN = 0;
	
	tb-> io_SOBEL_MODE_CHANGE = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_SOBEL_MODE_CHANGE = 0;
	tick(++tickcount, tb, tfp);
	tb-> io_STORE_DATA_IN = 1;
	tick(++tickcount, tb, tfp);
	
	for(int i = 0; i < 32; i++){
		tb-> io_STORE_DATA_IN = 0;
		tb->io_rdData = i;
		tb->io_RD = 10;
		tb->io_WRITE_EN = 1;
		tick(++tickcount, tb, tfp);
		tb->io_WRITE_EN = 0;
		tb-> io_STORE_DATA_IN = 1;
		tb-> io_RS1 = 16;
		tick(++tickcount, tb, tfp);
	}
	
	tb-> io_SOBEL_MODE_CHANGE = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_SOBEL_MODE_CHANGE = 0;
	tick(++tickcount, tb, tfp);
	tb-> io_STORE_DATA_IN = 1;
	tick(++tickcount, tb, tfp);
	
	for(int i = 0; i < 32; i++){
		tb-> io_STORE_DATA_IN = 0;
		tb->io_rdData = i;
		tb->io_RD = 10;
		tb->io_WRITE_EN = 1;
		tick(++tickcount, tb, tfp);
		tb->io_WRITE_EN = 0;
		tb-> io_STORE_DATA_IN = 1;
		tb-> io_RS1 = 16;
		tick(++tickcount, tb, tfp);
	}
	tb-> io_SOBEL_MODE_CHANGE = 1;
	tick(++tickcount, tb, tfp);
	tb-> io_SOBEL_MODE_CHANGE = 0;
	tick(++tickcount, tb, tfp);
	tb-> io_STORE_DATA_IN = 1;
	tick(++tickcount, tb, tfp);
	
	for(int i = 0; i < 32; i++){
		tb-> io_STORE_DATA_IN = 0;
		tb->io_rdData = i;
		tb->io_RD = 10;
		tb->io_WRITE_EN = 1;
		tick(++tickcount, tb, tfp);
		tb->io_WRITE_EN = 0;
		tb-> io_STORE_DATA_IN = 1;
		tb-> io_RS1 = 16;
		tick(++tickcount, tb, tfp);
	}
}
