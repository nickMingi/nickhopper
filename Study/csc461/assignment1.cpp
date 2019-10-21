#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

//INPUT PATH and FILE name


//const char file_name[] = "p1sol.dat";  // assumes same directory as .exe file
const char file_name[] = "p3sol.dat";  // assumes same directory as .exe file
//==========  SIM SUPPORT ===============

struct INSTRUCTIONS
{
	char inst[12];
};

// --- COMPUTER MEMORY STRUCTURES

int  data[1000]; // actual data memory

INSTRUCTIONS instrmem[1000]; // INSTRUCTION MEMORY SPACE

// --- CARD READER SUPPORT
int card[1000];
int next_card = 0;

// --- INTERPRETER SUPPORT
// Instruction Pointer
int ip = 0;
//======================================

//===== PROTOTYPES =====================
int mainInterpreter(void);
void loader(int datamem[],INSTRUCTIONS instrmem[],int cardreader[]);
void parse_instruction(char instr[], char &sign, char &oper, int &op1, int &op2, int &op3);
void p0(int op1, int op2, int op3);
void p1(int op1, int op2, int op3);
void p2(int op1, int op2, int op3);
void p3(int op1, int op2, int op3);
void p4(int op1, int op2, int op3);
void p5(int op1, int op2, int op3);
void p6(int op1, int op2, int op3);
void p7(int op1, int op2, int op3);
void p8(int op1, int op2, int op3);
void p9(int op1, int op2, int op3);
void n0(int op1, int op2, int op3);
void n1(int op1, int op2, int op3);
void n2(int op1, int op2, int op3);
void n3(int op1, int op2, int op3);
void n4(int op1, int op2, int op3);
void n5(int op1, int op2, int op3);
void n6(int op1, int op2, int op3);
void n7(int op1, int op2, int op3);
void n8(int op1, int op2, int op3);
void n9(int op1, int op2, int op3);


// =========  main()  ==============
int mainInterpreter(void)
{
   char current_instruction[12];
   char sign;
   char oper;
   int op1;
   int op2;
   int op3;
   
   // LOAD CARDS
   loader(data,instrmem,card);
   
   while (1)    // Execution cycle
   {
      //Fetch Instruction
	  strcpy(current_instruction,instrmem[ip].inst);
	  
	  // Increment IP
	  ip++;
	 
      parse_instruction(current_instruction,sign,oper,op1,op2,op3);

	  switch (sign)
	  {
	    case '+' : switch (oper)
		            {
					   case '0' : p0(op1,op2,op3); break;
					   case '1' : p1(op1,op2,op3); break;
					   case '2' : p2(op1,op2,op3); break;
					   case '3' : p3(op1,op2,op3); break;
					   case '4' : p4(op1,op2,op3); break;
					   case '5' : p5(op1,op2,op3); break;
					   case '6' : p6(op1,op2,op3); break;
					   case '7' : p7(op1,op2,op3); break;
					   case '8' : p8(op1,op2,op3); break;
					   case '9' : p9(op1,op2,op3); break;
					}   
		            break;
		case '-' :  switch (oper)
		            {
					   case '0' : n0(op1,op2,op3); break;
					   case '1' : n1(op1,op2,op3); break;
					   case '2' : n2(op1,op2,op3); break;
					   case '3' : n3(op1,op2,op3); break;
					   case '4' : n4(op1,op2,op3); break;
					   case '5' : n5(op1,op2,op3); break;
					   case '6' : n6(op1,op2,op3); break;
					   case '7' : n7(op1,op2,op3); break;
					   case '8' : n8(op1,op2,op3); break;
					   case '9' : n9(op1,op2,op3); break;
					}   
		            break;
	   } 
    };// while    

   return 0;
}

//================ Parse Instruction  ================================
void parse_instruction(char *instr, char &sign, char &oper, int &op1,int &op2,int &op3)
{   char temp[4];

    // parse sign
     sign = instr[0];
	   
	//parse operator
	 oper = instr[1];
	 
	// parse operands
	temp[3] = '\0';
    for (int i = 0; i<3; i++)
          temp[i] = instr[i+2];	
    op1 = atoi(temp);
    for (int i = 0; i<3; i++)
          temp[i] = instr[i+5];	
    op2 = atoi(temp);
	for (int i = 0; i<3; i++)
          temp[i] = instr[i+8];	
    op3 = atoi(temp);
}
// ===========  INTER OPERATIONS ============================
// =========
void p0(int op1, int op2, int op3)
{
    data[op3] = data[op1];
}
// =========
void p1(int op1, int op2, int op3)
{
    data[op3] = data[op1] + data[op2];
}
// =========
void p2(int op1, int op2, int op3)
{
    data[op3] = data[op1] * data[op2];
}
// =========
void p3(int op1, int op2, int op3)
{
    data[op3] = data[op1] * data[op1];
}
// =========
void p4(int op1, int op2, int op3)
{
    if ( data[op1] == data[op2])
	   ip = op3;
}
// =========
void p5(int op1, int op2, int op3)
{
    if ( data[op1] >= data[op2])
	   ip = op3;
}
// =========
void p6(int op1, int op2, int op3)
{
    data[op3] = data[op1+data[op2]]; 
}
// =========
void p7(int op1, int op2, int op3)
{
    data[op1] = data[op1] +1;
	if (data[op1] < data[op2])
	   ip = op3;
}
// =========
void p8(int op1, int op2, int op3)
{
    data[op3] = card[next_card++];
}
// =========
void p9(int op1, int op2, int op3)
{
   //cout << "stop " << endl;  // prints stop for testing only !!!!!
   exit(1);
}
// =========
void n0(int op1, int op2, int op3)
{
    cout << " no op " << endl;
}
// =========
void n1(int op1, int op2, int op3)
{
    data[op3] = data[op1] - data [op2];
}
// =========
void n2(int op1, int op2, int op3)
{
    data[op3] = data[op1] / data [op2];
}
// =========
void n3(int op1, int op2, int op3)
{
    cout <<  "square root "  << endl;  // do not implement
}
// =========
void n4(int op1, int op2, int op3)
{
    if (data[op1] != data[op2])
        ip = op3;
}
// =========
void n5(int op1, int op2, int op3)
{
    if (data[op1] < data[op2])
        ip = op3;
}
// =========
void n6(int op1, int op2, int op3)
{
    data[op2+data[op3]] = data[op1];
}
// =========
void n7(int op1, int op2, int op3)
{
    cout << "no op " << endl;
}
// =========
void n8(int op1, int op2, int op3)
{
    cout << data[op1] << endl;
}
// =========
void n9(int op1, int op2, int op3)
{
    cout << "no op " << endl;
}


// ================ loader  ==========================================
void loader(int datamem[],INSTRUCTIONS instrmem[],int cardreader[])
{	

	char FLAG[] = "+9999999999";
	int count = 0;
	int key_value;
	char buffer[256];

	
	//1) DECLARE A FILE VARIABLE (FV)
	fstream infile;
	//2) ASSIGN PHYSICAL FILE TO FV
	//3) OPEN FILE IN THE CORRECT FORMAT
	infile.open(file_name,ios::in);
	if(!infile){
		cout << "ERROR - File not opened!" << endl;
		exit(1);
	}
	//4) USE FV IN I/O
	
	//===== READ DATA CARDS

	infile.getline(buffer,256,'\n');  // read first card	
	
	while((!infile.fail())&& (strncmp(buffer,FLAG,11)))
	{
	    //cout << "in data cards" << count << endl;
		int d = atoi(buffer);
		data[count] =d;
		count++;
		infile.getline(buffer,256,'\n'); // read next card
	}

	// ===== READ INSTRUCTION CARDS
	count = 0; //reset count
	infile.getline(buffer,256,'\n');  // read card after +9999999999
	while((!infile.fail()) && (strncmp(buffer,FLAG,11)))
	{   //cout << "in instr cards " << count << endl;
		strncpy(instrmem[count].inst,buffer,11);
		count++;
		infile.getline(buffer,256,'\n');
	}
		
	//====== READ INPUT CARDS
	count = 0; //reset count
	if (infile.fail()) return;
	infile.getline(buffer,256,'\n');  // read card after +9999999999	
	while(!infile.fail())
	{   //cout << "in input cards " << count << endl;
	    int d = atoi(buffer);
		card[count] = d;
		count++;
		infile.getline(buffer,256,'\n');
	}
	
	//5) CLOSE THE FILE
	infile.close();
}