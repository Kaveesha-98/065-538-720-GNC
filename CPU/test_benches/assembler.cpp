// io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

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
			{"slti", "0010011"}, {"sltiu", "0010011"}, {"xori", "0010011"},
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

struct operand_fields{
	int RS1 =0;
	int RS2 =0;
	int RD =0;
	string branchLabel;
};

struct instruction_fields{
	string Op;
	string branch_label;
	operand_fields operands;
};

struct instruction_breakdown{
	string instruction;
	int instruction_address;
	instruction_fields fields;
	string instruction_type;
	instruction_breakdown* next;
};

//defining parts of a text_line
struct text_line_parts{
	string instruction;
	string label;
};

operand_fields get_jal_operands(string instruction){
	operand_fields fields;
	int char_index = 5;
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
	cout << RD << endl;
	fields.RD = stoi(RD);
	
	char_index += 2;
	string branch_label = "";
	while(char_index < instruction.length()){
		branch_label = branch_label + instruction[char_index];
		char_index++;
	}
	fields.branchLabel = branch_label;
	return fields;
}

operand_fields get_conditional_branch_operands(string instruction){
	operand_fields fields;
	int char_index;
	
	if(instruction[3] == ' '){
		char_index = 5;
	}else{
		char_index = 6;
	}
	
	string RS1 = "";
	
	while(instruction[char_index] != ','){
		RS1 = RS1 + instruction[char_index];
		char_index++;
	}
	fields.RS1 = stoi(RS1);
	
	char_index += 3;
	
	string RS2 = "";
	
	while(instruction[char_index] != ','){
		RS2 = RS2 + instruction[char_index];
		char_index++;
	}
	fields.RS2 = stoi(RS2);
	
	char_index += 2;
	
	string branch_label = "";
	while(char_index < instruction.length()){
		branch_label = branch_label + instruction[char_index];
		char_index++;
	}
	fields.branchLabel = branch_label;
	return fields;
}

//separating out label and instruction
text_line_parts isLabeled(string text_line){
	int char_index = 0;
	
	
	//if a labeled instruction extracting label
	string label = "";
	while(text_line[char_index] != ' ' && text_line[char_index] != ':'){
		label = label + text_line[char_index];
		char_index++;
	}
	if(text_line[char_index] == ':'){
		char_index++;
	}else{
		label = ":";
		char_index = 0;
	}

	//getting the instruction without label
	string instruction = "";
	while(char_index < text_line.length()){
		instruction = instruction + text_line[char_index];
		char_index++;
	}
	
	text_line_parts instruction_parts = {instruction, label};
	return instruction_parts;

}

instruction_fields get_fields(string instruction){
	instruction_fields fields;
	string Op = "";
	int char_index = 0;
	while(instruction[char_index] != ' '){
		Op = Op + instruction[char_index];
		char_index++;
	}
	fields.Op = Op;
	
	if(opcode[Op] == jal_type){
		fields.operands = get_jal_operands(instruction);
	} else if(opcode[Op] == conditional_branching){
		fields.operands = get_conditional_branch_operands(instruction);
	}
	
	return fields;

}

int main() {
    int sum = 0;
    int instruction_count = 0;
    string text_line, label;
    ifstream inFile;
    
    text_line_parts instruction_parts;
    instruction_breakdown* breakdown = new instruction_breakdown();
    instruction_breakdown* start = breakdown;
    
    map<string, int> labels;
    
    inFile.open("test_instructions.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (getline (inFile, text_line)) {
    
    	if(text_line[0] != '/'){
    		instruction_parts = isLabeled(text_line);
    		
    		if (instruction_parts.label != ":"){
    			//cout << instruction_parts.instruction << endl;
    			labels.insert(pair<string, int>(instruction_parts.label, instruction_count*4));
    			
    		}
    		
    		breakdown -> instruction = instruction_parts.instruction;
    		breakdown -> instruction_address = instruction_count;
    		breakdown -> fields = get_fields(instruction_parts.instruction);
    		breakdown -> next = new instruction_breakdown();
    		breakdown -> instruction_type = opcode[breakdown -> fields.Op];
    		breakdown = breakdown -> next;
    		//cout << breakdown -> instruction << endl;
    		instruction_count++;
    	}
    	
    }
    
    map<string, int>::iterator itr;
    for (itr = labels.begin(); itr != labels.end(); ++itr) {
        cout << itr->second
             << '\t' << itr->first << '\n';
    }
    
    breakdown = start;
    //cout << start-> next -> next -> instruction << endl;
    
    for (int i = 0; i < instruction_count; i++){
    	cout << breakdown-> instruction_address
    		 << '\t' << breakdown-> fields.Op
    		 << '\t' << breakdown-> instruction_type
    		 << '\t' << breakdown-> fields.operands.RS1
    		 << '\t' << breakdown-> fields.operands.RS2
    		 << '\t' << breakdown-> fields.operands.RD
    		 << '\t' << breakdown-> fields.operands.branchLabel
    		 << '\t' << breakdown-> instruction << endl;
    	breakdown = breakdown->next;
    }
    
    inFile.close();
    cout << "Sum = " << instruction_count -1 << endl; 
    return 0;
}
