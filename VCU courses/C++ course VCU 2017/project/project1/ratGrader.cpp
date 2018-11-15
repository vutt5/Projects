#include <iostream>
using namespace std;
#include "Rat.h"

string spaces(int);

int main() {

  int k = 6;
  int count = 0;

  cout << "Grading Program for EGRE246 Proj. #1" << endl;
  Rat r0;
  
  count++; //1
  cout << (count<10?" ":"") << count << ": " << r0.getD() ;
  cout << spaces(k) << "<-- 1" << endl;

  count++; //2
  cout << (count<10?" ":"") << count << ": " << Rat(1,2).getD() ;
  cout << spaces(k) << "<-- 2" << endl;

  Rat r1(1,2); r1.setN(2);
  count++;//3
  cout << (count<10?" ":"") << count << ": " << r1.getN();
  cout << spaces(k) << "<-- 2" << endl;

  count++;//4
  cout << (count<10?" ":"") << count << ": " << Rat(90,228).reduce();
  cout << spaces(k-4) << "<-- 15/38" << endl;

  count++;//5
  cout << (count<10?" ":"") << count << ": " << Rat(15,38).reduce();
  cout << spaces(k-4) << "<-- 15/38" << endl;

  count++;//6
  cout << (count<10?" ":"") << count << ": " << Rat(-15,-38).norm();
  cout << spaces(k-4) << "<-- 15/38" << endl;

  count++;//7
  cout << (count<10?" ":"") << count << ": " << Rat(15,-38).norm();
  cout << spaces(k-5) << "<-- -15/38" << endl;

  count++;//8
  cout << (count<10?" ":"") << count << ": " << Rat(-15,38).norm();
  cout << spaces(k-5) << "<-- -15/38" << endl;

  count++;//9
  cout << (count<10?" ":"") << count << ": " << Rat(15,-38).reduce();
  cout << spaces(k-5) << "<-- 15/-38" << endl;

  r1 = Rat(2,3);
  count++;//10
  cout << (count<10?" ":"") << count << ": " << Rat(2,3).cmp(r1);
  cout << spaces(k) << "<-- 0" << endl;

  count++;//11
  r1 = Rat(18,576);
  cout << (count<10?" ":"") << count << ": " << Rat(26,832).cmp(r1);
  cout << spaces(k) << "<-- 0" << endl;
  
  count++;//12
  r1 = Rat(0,576);
  cout << (count<10?" ":"") << count << ": " << Rat(0,-832).cmp(r1);
  cout << spaces(k) << "<-- 0" << endl;

  count++;//13
  r1 = Rat(5,7);
  cout << (count<10?" ":"") << count << ": " << Rat(9,7).cmp(r1);
  cout << spaces(k) << "<-- 1" << endl;

  count++;//14
  cout << (count<10?" ":"") << count << ": " << Rat(0,7).cmp(r1);
  cout << spaces(k-1) << "<-- -1" << endl;

  r1 = Rat(1,8);
  count++;//15
  cout << (count<10?" ":"") << count << ": " << Rat(2,8).add(r1);
  cout << spaces(k-2) << "<-- 3/8" << endl;

  count++;//16
  cout << (count<10?" ":"") << count << ": " << Rat(1,8).add(r1);
  cout << spaces(k-2) << "<-- 1/4" << endl;

  count++;//17
  cout << (count<10?" ":"") << count << ": " << r1.add(r1);
  cout << spaces(k-2) << "<-- 1/4" << endl;

  r1 = Rat(1,4);
  count++;//18
  cout << (count<10?" ":"") << count << ": " << Rat(0,3199).add(r1);
  cout << spaces(k-2) << "<-- 1/4" << endl;

  r1 = Rat(1,-4);
  count++;//19
  cout << (count<10?" ":"") << count << ": " << Rat(1,2).add(r1);
  cout << spaces(k-2) << "<-- 1/4" << endl;

  r1 = Rat(1,-8);
  count++;//20
  cout << (count<10?" ":"") << count << ": " << Rat(1,8).sub(r1);
  cout << spaces(k-2) << "<-- 1/4" << endl;

  r1 = Rat(0,-8);
  count++;//21
  cout << (count<10?" ":"") << count << ": " << Rat(9111,36444).sub(r1);
  cout << spaces(k-2) << "<-- 1/4" << endl;

  r1 = Rat(1,-8);
  count++;//22
  cout << (count<10?" ":"") << count << ": " << Rat(-4,32).sub(r1);
  cout << spaces(k-2) << "<-- 0/<anything>" << endl;

  r1 = Rat(0,312);
  count++;//23
  cout << (count<10?" ":"") << count << ": " << Rat(0,7).sub(r1);
  cout << spaces(k-5) << "<-- 0/<anything>" << endl;

  count++;//24
  cout << (count<10?" ":"") << count
       << ": <error message on next line, program then exits>" << endl;
  r1 = Rat(9,0);
  Rat(1,2).sub(r1);
  cout << "<last test failed>" << endl;
}

string spaces(int n) {
  string res;
  for (int i=1; i<=n; i++) res += " ";
  return res;
}
  

