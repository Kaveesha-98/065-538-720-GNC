// io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <bitset>

using namespace std;

//opcode types
std::string register_type = "0110011";//done
std::string immediate_type = "0010011";//done
std::string storing_type = "0100011";//done
std::string loading_type = "0000011";
std::string conditional_branching = "1100011";//label extracted, immidiate needed
std::string jalr_type = "1100111";//done
std::string jal_type = "1101111";//label extracted, immidiate needed
std::string lui_type = "0110111";//done

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
		machine_instruction = bitsOf_From_To_(immBranch20bit, 20,  20); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch20bit, 10,  1); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch20bit, 11,  11); 
		machine_instruction = machine_instruction + bitsOf_From_To_(immBranch20bit, 19,  12); 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} else{
		machine_instruction = immediate20bit; 
		machine_instruction = machine_instruction + bitset<5>(RD).to_string(); 
		machine_instruction = machine_instruction + opcode[Op];
	} 
 
	return machine_instruction;
}

struct operand_fields{
	int RS1 =0;
	int RS2 =0;
	int RD =0;
	int immediate = 0;
	string branchLabel;
	bool extracted = false;
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
//Extracting operands-------------------------------------------------
operand_fields get_jal_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index = 5;
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
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
	fields.extracted = true;
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

operand_fields get_register_arithmetic_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index;
	
	if(instruction[2] == ' '){
		char_index = 4;
	}else if(instruction[4] == ' '){
		char_index = 6;
	}else{
		char_index = 5;
	}
	
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
	fields.RD = stoi(RD);
	
	char_index += 3;
	
	string RS1 = "";
	
	while(instruction[char_index] != ','){
		RS1 = RS1 + instruction[char_index];
		char_index++;
	}
	fields.RS1 = stoi(RS1);
	
	char_index += 3;
	
	string RS2 = "";
	
	while(char_index < instruction.length()){
		RS2 = RS2 + instruction[char_index];
		char_index++;
	}
	fields.RS2 = stoi(RS2);
	return fields;
}

operand_fields get_immediate_arithmetic_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index;
	
	if(instruction[3] == ' '){
		char_index = 5;
	}else if(instruction[5] == ' '){
		char_index = 7;
	}else{
		char_index = 6;
	}
	
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
	fields.RD = stoi(RD);
	char_index += 3;
	
	string RS1 = "";
	
	while(instruction[char_index] != ','){
		RS1 = RS1 + instruction[char_index];
		char_index++;
	}
	fields.RS1 = stoi(RS1);
	char_index += 2;
	
	string immediate = "";
	
	while(char_index < instruction.length()){
		immediate = immediate + instruction[char_index];
		char_index++;
	}
	
	if(immediate[0] == '-'){
		immediate[0] = '0';
		//cout << immediate << endl;
		fields.immediate = 0 - stoi(immediate);
	}else{
		fields.immediate = stoi(immediate);
	}
	
	return fields;
}

operand_fields get_lui_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index = 5;
	
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
	fields.RD = stoi(RD);
	char_index += 2;
	
	string immediate = "";
	
	while(char_index < instruction.length()){
		immediate = immediate + instruction[char_index];
		char_index++;
	}
	
	if(immediate[0] == '-'){
		immediate[0] = '0';
		//cout << immediate << endl;
		fields.immediate = 0 - stoi(immediate);
	}else{
		fields.immediate = stoi(immediate);
	}
	
	return fields;
}

operand_fields get_jalr_type_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index = 6;
	
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
	fields.RD = stoi(RD);
	char_index += 2;
	
	string immediate = "";
	
	while(instruction[char_index] != '('){
		immediate = immediate + instruction[char_index];
		char_index++;
	}
	
	if(immediate[0] == '-'){
		immediate[0] = '0';
		//cout << immediate << endl;
		fields.immediate = 0 - stoi(immediate);
	}else{
		fields.immediate = stoi(immediate);
	}
	
	char_index += 2;
	
	string RS1 = "";
	
	while(instruction[char_index] != ')'){
		RS1 = RS1 + instruction[char_index];
		char_index++;
	}
	
	fields.RS1 = stoi(RS1);
	
	return fields;
}

operand_fields get_storing_type_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index = 4;
	
	string RS2 = "";
	
	while(instruction[char_index] != ','){
		RS2 = RS2 + instruction[char_index];
		char_index++;
	}
	fields.RS2 = stoi(RS2);
	char_index += 2;
	
	string immediate = "";
	
	while(instruction[char_index] != '('){
		immediate = immediate + instruction[char_index];
		char_index++;
	}
	
	if(immediate[0] == '-'){
		immediate[0] = '0';
		//cout << immediate << endl;
		fields.immediate = 0 - stoi(immediate);
	}else{
		fields.immediate = stoi(immediate);
	}
	
	char_index += 2;
	
	string RS1 = "";
	
	while(instruction[char_index] != ')'){
		RS1 = RS1 + instruction[char_index];
		char_index++;
	}
	
	fields.RS1 = stoi(RS1);
	
	return fields;
}

operand_fields get_loading_type_operands(string instruction){
	operand_fields fields;
	fields.extracted = true;
	int char_index;
	if(instruction[2] == ' '){
		char_index = 4;
	}else{
		char_index = 5;
	}
	
	string RD = "";
	
	while(instruction[char_index] != ','){
		RD = RD + instruction[char_index];
		char_index++;
	}
	fields.RD = stoi(RD);
	char_index += 2;
	
	string immediate = "";
	
	while(instruction[char_index] != '('){
		immediate = immediate + instruction[char_index];
		char_index++;
	}
	
	if(immediate[0] == '-'){
		immediate[0] = '0';
		//cout << immediate << endl;
		fields.immediate = 0 - stoi(immediate);
	}else{
		fields.immediate = stoi(immediate);
	}
	
	char_index += 2;
	
	string RS1 = "";
	
	while(instruction[char_index] != ')'){
		RS1 = RS1 + instruction[char_index];
		char_index++;
	}
	
	fields.RS1 = stoi(RS1);
	
	return fields;
}

//separating out label and instruction----------------------------------------
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

//Seperating fields---------------------------------------------------
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
	} else if(opcode[Op] == register_type){
		fields.operands = get_register_arithmetic_operands(instruction);
	} else if(opcode[Op] == immediate_type){
		fields.operands = get_immediate_arithmetic_operands(instruction);
	} else if(opcode[Op] == lui_type){
		fields.operands = get_lui_operands(instruction);
	} else if(opcode[Op] == storing_type){
		fields.operands = get_storing_type_operands(instruction);
	} else if(opcode[Op] == jalr_type){
		fields.operands = get_jalr_type_operands(instruction);
	} else if(opcode[Op] == loading_type){
		fields.operands = get_loading_type_operands(instruction);
	}
	
	return fields;

}

int main() {
    int sum = 0;
    int instruction_count = 0;
    string text_line, label;
    ifstream inFile;
    ofstream executables("executables.txt");
    
    assm_translator translator;
	translator.RS1 = 0;
	translator.RS2 = 0;
	translator.RD = 0;
	translator.Op = "addi";
	translator.immediate = 8;
    
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
    	cout << text_line << endl;
    
    	if(text_line[0] != '/'){
    		instruction_parts = isLabeled(text_line);
    		
    		if (instruction_parts.label != ":"){
    			//cout << instruction_parts.instruction << endl;
    			labels.insert(pair<string, int>(instruction_parts.label, instruction_count*4));
    			
    		}
    		
    		breakdown -> instruction = instruction_parts.instruction;
    		breakdown -> instruction_address = instruction_count*4;
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
    
    executables << instruction_count - 1 << endl;
    
    breakdown = start;
    //cout << start-> next -> next -> instruction << endl;
    
    for (int i = 0; i < instruction_count; i++){
    	if(breakdown-> instruction_type == conditional_branching){
    		breakdown-> fields.operands.immediate = labels[breakdown-> fields.operands.branchLabel] - breakdown-> instruction_address;
    		breakdown-> instruction = breakdown-> fields.Op + " x" + to_string(breakdown-> fields.operands.RS1) + ", x" + to_string(breakdown-> fields.operands.RS2) + ", " + to_string(breakdown-> fields.operands.immediate);
    	}else if(breakdown-> instruction_type == jal_type){
    		breakdown-> fields.operands.immediate = labels[breakdown-> fields.operands.branchLabel] - breakdown-> instruction_address;
    		breakdown-> instruction = breakdown-> fields.Op + " x" + to_string(breakdown-> fields.operands.RD) + ", " + to_string(breakdown-> fields.operands.immediate);
    	}
    	translator.RS1 = breakdown-> fields.operands.RS1;
		translator.RS2 = breakdown-> fields.operands.RS2;
		translator.RD = breakdown-> fields.operands.RD;
		translator.Op = breakdown-> fields.Op;
		translator.immediate = breakdown-> fields.operands.immediate;
		executables << to_string(instructionToInt(translator.translate())) + '|' + breakdown-> instruction << endl;
    	breakdown = breakdown->next;
    }
    
    breakdown = start;
    
    for (int i = 0; i < instruction_count; i++){
    	cout << breakdown-> instruction_address
    		 << '\t' << breakdown-> fields.Op
    		 << '\t' << breakdown-> instruction_type
    		 << '\t' << breakdown-> fields.operands.RS1
    		 << '\t' << breakdown-> fields.operands.RS2
    		 << '\t' << breakdown-> fields.operands.RD
    		 << '\t' << breakdown-> fields.operands.branchLabel
    		 << '\t' << breakdown-> fields.operands.immediate
    		 << '\t' << breakdown-> fields.operands.extracted
    		 << '\t' << breakdown-> instruction << endl;
    	breakdown = breakdown->next;
    }
    
    inFile.close();
    executables.close();
    cout << "Total instructions = " << instruction_count -1 << endl; 
    return 0;
}
