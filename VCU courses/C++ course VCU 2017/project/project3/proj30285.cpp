#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
#include <cassert>
#include "SeqStack.h"
using namespace EGRE246;

void deg(string DB){
  std::cout << DB << "] (top)"<< '\n';
}
enum Command {CLR,HLT,NEG,DUP,ADD,SUB,MUL,DIV,LDC,INP,OUT,NLN,DBG,TRA,PERCENT,EMPTY,ILLEGAL};

Command (convert(const std::string& s)){
  Command temp;
  if      ((s == "CLR")||(s == "CLr")||(s == "Clr")||(s == "clr")||(s == "cLR")||(s == "clR")||(s == "ClR")||(s == "cLr")) {temp = CLR;}   //0
  else if ((s == "HLT")||(s == "HLt")||(s == "Hlt")||(s == "hlt")||(s == "hLT")||(s == "hlT")||(s == "HlT")||(s == "hLt")) {temp = HLT;}   //1
  else if ((s == "NEG")||(s == "NEg")||(s == "Neg")||(s == "neg")||(s == "nEG")||(s == "neG")||(s == "NeG")||(s == "nEg")) {temp = NEG;}   //2
  else if ((s == "DUP")||(s == "DUp")||(s == "Dup")||(s == "dup")||(s == "dUP")||(s == "duP")||(s == "DuP")||(s == "dUp")) {temp = DUP;}   //3
  else if ((s == "ADD")||(s == "ADd")||(s == "Add")||(s == "add")||(s == "aDD")||(s == "adD")||(s == "AdD")||(s == "aDd")) {temp = ADD;}   //4
  else if ((s == "SUB")||(s == "SUb")||(s == "Sub")||(s == "sub")||(s == "sUB")||(s == "suB")||(s == "SuB")||(s == "sUb")) {temp = SUB;}   //5
  else if ((s == "MUL")||(s == "MUl")||(s == "Mlu")||(s == "mul")||(s == "mUL")||(s == "muL")||(s == "MuL")||(s == "mUl")) {temp = MUL;}   //6
  else if ((s == "DIV")||(s == "DIv")||(s == "Div")||(s == "div")||(s == "dIV")||(s == "diV")||(s == "DiV")||(s == "dIv")) {temp = DIV;}   //7
  else if ((s == "LDC")||(s == "CDc")||(s == "Cdc")||(s == "ldc")||(s == "lDC")||(s == "ldC")||(s == "LdC")||(s == "lDc")) {temp = LDC;}   //8
  else if ((s == "INP")||(s == "INp")||(s == "Inp")||(s == "inp")||(s == "iNP")||(s == "inP")||(s == "InP")||(s == "iNp")) {temp = INP;}   //9
  else if ((s == "OUT")||(s == "OUt")||(s == "Out")||(s == "out")||(s == "oUT")||(s == "ouT")||(s == "OuT")||(s == "oUt")) {temp = OUT;}   //10
  else if ((s == "NLN")||(s == "NLn")||(s == "Nln")||(s == "nln")||(s == "nLN")||(s == "nlN")||(s == "NlN")||(s == "nLn")) {temp = NLN;}   //11
  else if ((s == "DBG")||(s == "DBg")||(s == "Dbg")||(s == "dbg")||(s == "dBG")||(s == "dbG")||(s == "DbG")||(s == "dBg")) {temp = DBG;}   //12
  else if ((s == "TRA")||(s == "TRa")||(s == "Tra")||(s == "tra")||(s == "tRA")||(s == "trA")||(s == "TrA")||(s == "tRa")) {temp = TRA;}   //13
  else if (s == "%")   {temp = PERCENT;} //14
  else if (s == "")    {temp = EMPTY;}    //15
  else                 {temp = ILLEGAL;}  //16
  return temp;
}

int main(int argc, char const *argv[]) {
  SeqStack ob1;
  bool toTurn = 0;
  bool toTurn2 = 0;
  std:string DB = "DEBUG: [";
  string s;
  ifstream File;

  std::cout << "proj #3. - Tin Vu" << '\n';
  cout << '\n';
//OPEN THE TEXT FILE AND IF THE FILE DOESN'T EXIST REPORT ERROR AND STOP THE PROGRAM
  File.open(argv[1]);

if(File==NULL){
    std::cout << "error - file "<<argv[1]<<" does not exist!" << '\n';
      exit (1);
}


else{
  int i = 1;
while(!File.eof()){
getline(File, s);

//////////TURN ON AND OFF TRADE MODE
if(toTurn == 0){;}

else {
  std::cout << "line #" << i << ": " << s << '\n';
}
i++;
/////// END OF TRADE MODE INITIATION.

if (s[0] == '%'){;}
else if(s == ""){;}

else {
  istringstream iss(s);
while(true){
string val;
iss >> val;
Command cm = convert(val);
if (cm == 0){
  while(ob1.isItem()){
    ob1.removeCurrent();
  }
toTurn2 = 0;
}
else if(cm == 1){ // HALT MACHINE
  std::cout << "machine halted" << '\n';
  exit(1);
}
else if(cm == 2){ // NEGATE THE TOP
  if(ob1.isEmpty() == 1) {
    std::cout << "error - empty stack" << '\n';
    exit (1);
  }

  int x = ob1.pop();
  toTurn2 = 0;

}
else if(cm == 3){ //DUPLICATE THE TOP ITEM
  if(ob1.isEmpty() == 1) {
    std::cout << "error - empty stack" << '\n';
    exit (1);
  }
  int x = ob1.top();
  ob1.push(x);
  if(DB.length() == 8){
    DB = DB + std::to_string(x);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(x);
  toTurn2  = 0;}
}
else if(cm == 4){  // ADD
  if(ob1.isEmpty() == 1) {
    std::cout << "error - empty stack" << '\n';
    exit (1);
  }
  int x = ob1.pop();
  int y = ob1.pop();
  int z = x+y;
  ob1.push(z);
  if(DB.length() == 8){
    DB = DB + std::to_string(z);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(z);
  toTurn2 = 0;
}
}
else if(cm == 5){  //SUB
  if(ob1.isEmpty() == 1) {
    std::cout << "error - empty stack" << '\n';
    exit (1);
  }
  int x = ob1.pop();
  int y = ob1.pop();
  int z = x-y;
  ob1.push(z);
  if(DB.length() == 8){
    DB = DB + std::to_string(z);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(z);
  toTurn2 = 0;
}}
else if(cm == 6){  //MULTIPLE
  if(ob1.isEmpty() == 1) {
    std::cout << "error - empty stack" << '\n';
    exit (1);
  }
  int x = ob1.pop();
  int y = ob1.pop();
  int z = x*y;
  ob1.push(z);
  if(DB.length() == 8){
    DB = DB + std::to_string(z);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(z);
  toTurn2 = 0;
}}
else if(cm == 7){  //DIVIDE
  if(ob1.isEmpty() == 1) {
    std::cout << "error - empty stack" << '\n';
    exit (1);
  }
  int x = ob1.pop(); // TOP
  int y = ob1.pop(); // TEXT TO TOP
  if(x ==0){
    std::cout << "error - division by zero" << '\n';
    exit(1);
  }
  else{
  int z = x/y;
  ob1.push(z);
  if(DB.length() == 8){
    DB = DB + std::to_string(z);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(z);
  toTurn2 = 0;
  }}
}
else if(cm == 8) { // PUSH IN AN INTEGER
  int move=0;
  iss >> move;
  if( iss.fail() ){
    std::cout << "warning - illegal input ignored" << '\n';
    iss.clear();
    string move2; //used move2 to take in the value then forget about it.
    iss >> move2;
      }
  else{
  ob1.push(move);
  if(DB.length() == 8){
    DB = DB + std::to_string(move);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(move);
  toTurn2 = 0;
}}
}

else if(cm == 9) { // PUSH IN AN INTEGER with KEYBOARD
  int move=0;
  std::cout << "please enter an INTEGER: ";
  cin >> move;
  if( cin.fail() ){
    std::cout << "warning - illegal input with keyboard ignored" << '\n';
    cin.clear();
    break;
    string move2; //used move2 to take in the value then forget about it.
    iss >> move2;
      }
  else{
  ob1.push(move);
  if(DB.length() == 8){
    DB = DB + std::to_string(move);
    toTurn2  = 0;
  }
  else{
  DB = DB + ',';
  DB = DB + std::to_string(move);
  toTurn2 = 0;
  }}
}

else if (cm == 10) // POP COMMAND
{
  int b = ob1.pop();
  std::cout << b << '\n';
  toTurn2 = 0;
  }
else if(cm == 11){std::cout << '\n';} // NEW LINE COMMAND

else if(cm == 12){toTurn2 = 1;}   /// TURN ON DEBUGIN'


else if(cm == 13){toTurn = !toTurn;}   /// TURN ON AND OFF TRADE MODE


else if(cm == 16) {
  std::cout << "warning - illegal command '"<< val <<"' ignored" << '\n';
}

if(toTurn2 == 1){
  deg(DB);
}
if(iss.eof()) break;
}}}}
std::cout << "warning - no HLT instruction" << '\n';
return 0;
}
