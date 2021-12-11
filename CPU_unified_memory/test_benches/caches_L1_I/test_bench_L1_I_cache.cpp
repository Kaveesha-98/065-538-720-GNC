#include <stdio.h>
#include <stdlib.h>
#include "Vtest_bench_L1_I_cache.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void tick(int tickcount, Vtest_bench_L1_I_cache *tb, VerilatedVcdC* tfp){
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
	Vtest_bench_L1_I_cache *tb = new Vtest_bench_L1_I_cache;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb->trace(tfp, 99);
	tfp->open("test_benches/trace_files/test_bench_L1_I_cachetrace.vcd");
	
	
	
	for(int i = 0; i < 20; i++){
		tick(++tickcount, tb, tfp);
		if(i == 1){
			tb -> io_instruction_address = 4100;
			tb -> io_new_cache_line_word = 4294967295;
		}else if(i == 2){
			tb-> io_write_new_cache = 1;
		}
	}
}
