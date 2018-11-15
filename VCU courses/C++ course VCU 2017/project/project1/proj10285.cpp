

/* Project #1
   EGRE246 Spring 2018
   Tin Vu */

#include <iostream>
using namespace std;
#include <cmath>
#include "Rat.h"
//Return 0/1
Rat::Rat()  {
n = 0;
d = 1;
}
///show error and exit program if d_ ==0;
Rat::Rat(int n_, int d_){
  setN(n_);
  setD(d_);
  if (d_ == 0){
    std::cerr << "Error - denominator can't be zero" << '\n';
    exit(1);
  }
}





//get n from private part
int Rat::getN() const {
  return n;
}   // getters
//get d from private part
int Rat::getD() const {
  return d;
}
//function used to set n from main
void Rat::setN(int n_){
n = n_;
}  // setters
//frunction used to get d from main
void Rat::setD(int d_){
  if(d_ == 0){
    std::cerr << "Error - denominator can't be zero" << '\n';
    exit(1);
  }
  else {
d = d_;
}
}
//return normal form of type Rat
Rat Rat::norm() const{
  Rat Nor;
  Nor.n = n;
  Nor.d = d;
  if (Nor.d < 0){
    Nor.n = -Nor.n;
    Nor.d = -Nor.d;
  }
  else if (((Nor.d<0)) &&((Nor.n)<0)){
    Nor.d = abs(Nor.d);
    Nor.n = abs(Nor.n);
  }
  else {;}
  return (Nor);
}

//return reduced form of type Rat
Rat Rat::reduce() const{
  Rat Red;
  int x,y;
  Red.n = n;
  Red.d = d;
  if(Red.n == 0) {;}

  else if((abs(Red.n)>abs(Red.d)) && ((abs(Red.n)%abs(Red.d)) == 0)){
    if((Red.n>0)&&(Red.d<0)){
      Red.n = Red.n / Red.d;
      Red.d = 1;
    }
    else if((Red.d>0)&&(Red.n<0)){
      Red.n = abs(Red.n / Red.d);
      Red.d = -1;
    }
    else if((Red.n<0)&&(Red.d<0)){
      Red.n = Red.n / Red.d;
      Red.d = -1;
    }
  }

  else if((abs(Red.d)>abs(Red.n)) && (abs(Red.d)%abs(Red.n)) == 0){
    if((Red.n>0)&&(Red.d<0)){
    Red.d = Red.d/Red.n;
    Red.n = 1;
  }
    else if((Red.d>0)&&(Red.n<0)){
    Red.d = abs(Red.d/Red.n);
    Red.n = -1;
  }
    else if((Red.n<0)&&(Red.d<0)){
      Red.d = Red.d / Red.n;
      Red.n = -1;
    }
  }

  else if ((abs(Red.n) > abs(Red.d)) && (abs(Red.n)%abs(Red.d) != 0)) {
    if (((Red.n%2) == 0) && ((Red.d%2) ==0)){
    for(;;){
      Red.n = Red.n/2;
      Red.d = Red.d/2;
    if (((Red.n%2) == 0) && ((Red.d%2) ==0)){;}
      else break;
    }

  }
    else if (((Red.n%3) == 0) && ((Red.d%3) ==0)){
      for(;;){
        Red.n = Red.n/3;
        Red.d = Red.d/3;
      if (((Red.n%3) == 0) && ((Red.d%2) == 0)){;}
        else break;
      }
    }



}
  else if ((abs(Red.n) < abs(Red.d)) && (abs(Red.d)%abs(Red.n) != 0)) {
    if (((Red.n%2) == 0) && ((Red.d%2) ==0)){
    for(;;){
      Red.n = Red.n/2;
      Red.d = Red.d/2;
    if (((Red.n%2) == 0) && ((Red.d%2) ==0)){;}
      else break;
    }
  }
    else if (((Red.n%3) == 0) && ((Red.d%3) ==0)){
      for(;;){
        Red.n = Red.n/3;
        Red.d = Red.d/3;
      if (((Red.n%3) == 0) && ((Red.d%3) == 0)){;}
        else break;
      }
    }
}

return (Red);
}
//return value of 1,0,-1 when comparing two different rats.
int Rat::cmp(Rat &r) const{
  Rat op1, op2;
  float a,b;
  int val;
  op1.n = n;
  //std::cout << op1.n << '\n';

  op1.d = d;
  //std::cout << op1.d << '\n';
  a = (op1.n*1.0)/(op1.d*1.0);
//  std::cout << a << '\n';
  op2.n = r.n;
  //std::cout << op2.n << '\n';
  op2.d = r.d;
  //std::cout << op2.d << '\n';
  b = (op2.n*1.0)/(op2.d*1.0);
  //std::cout << b << '\n';

if (a<b){ val = -1;}
else if(a == b){val =  0;}
else if(a>b){val =  1;}

return (val);
}
//add two rats together.
Rat Rat::add(Rat& op2) const{
  Rat r1, r2,r3;
  int a,b,mult;
  int val;
  r1.n = n;
  r1.d = d;
  r2.n = op2.n;
  r2.d = op2.d;
  mult = r1.d*r2.d;
  r1.n = r1.n*r2.d;
  r2.n = r2.n*r1.d;
  r2.d = r1.d = mult;

  r3.n = r1.n+r2.n;
  r3.d = r2.d;

return (r3.reduce()).norm();



}
//substract two rats from each others.
Rat Rat::sub(Rat& op2) const{
  Rat r1, r2,r3;
  int a,b,mult;
  int val;
  r1.n = n;
  r1.d = d;
  r2.n = op2.n;
  r2.d = op2.d;
  mult = r1.d*r2.d;
  r1.n = r1.n*r2.d;
  r2.n = r2.n*r1.d;
  r2.d = r1.d = mult;

  r3.n = r1.n-r2.n;
  r3.d = r2.d;

return (r3.reduce()).norm();

}

//overloading implimentation for operator << (print output)
ostream& operator <<(ostream& os, Rat rat) {
    os << rat.n << "/" << rat.d;
    return os;
}
