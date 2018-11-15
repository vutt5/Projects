//
//  Rat.cpp
//  project
//
//  Created by <author> on 21/01/2018.
//
//
#include <iostream>
using namespace std;
#include <cmath>
#include "Rat.h"

Rat::Rat()  {
n = 0;
d = 1;
}
Rat::Rat(int n_, int d_){
  setN(n_);
  setD(d_);
  if (d_ == 0){
    std::cerr << "Error - illegal" << '\n';
    exit(1);
  }
}






int Rat::getN() const {
  return n;
}   // getters
int Rat::getD() const {
  return d;
}
void Rat::setN(int n_){
n = n_;
}  // setters
void Rat::setD(int d_){
d = d_;
}
Rat Rat::norm() const{
  Rat Nor;
  Nor.n = n;
  Nor.d = d;
  if (Nor.d < 0){
    Nor.n = -Nor.n;
    Nor.d = -Nor.d;
  }
  return (Nor);
}
Rat Rat::reduce() const{
  Rat Red;
  int x,y;
  Red.n = n;
  Red.d = d;
  if (Red.n == Red.d){
    Red.n = 1;
    Red.d = 1;
}
  else if(Red.n == -Red.d){
    Red.n = -1;
    Red.d = 1;
  }

  else if((abs(Red.n)>abs(Red.d)) && ((abs(Red.n)%abs(Red.d)) == 0)){
    if((Red.n*Red.d)>0){
      Red.n = abs(Red.n / Red.d);
      Red.d = 1;
    }
    else if((Red.n*Red.d)<0){
      Red.n = - abs(Red.n / Red.d);
      Red.d = 1;
    }


  }

  else if((abs(Red.d)>abs(Red.n)) && ((abs(Red.d)%abs(Red.n)) == 0)){
    if((Red.n*Red.d)>0){
    Red.d = abs(Red.d/Red.n);
    Red.n = 1;
  }
    else if((Red.n*Red.d)<0){
    Red.d = abs(Red.d/Red.n);
    Red.n = -1;
  }
  }

  else if ((abs(Red.n) > abs(Red.d)) && (abs(Red.n)%abs(Red.d) != 0)) {
    if((Red.n%2 == 0)&&(Red.d%2)==0){

        int buff1 = Red.n;
        int buff2 = Red.d;
    for (;;){

        buff1 %= 2;
        if  (buff1 == 0){
          Red.n = buff1;
        }
        else break;
      }


    for (;;){
      buff2 %=2;
      if (buff2 ==0){
        Red.d = buff2;
      }
      else break;
    }



  }
  }
  else if ((Red.n < Red.d) && (Red.d%Red.n != 0)) {
    if (Red.d < 0){
      Red.n = -Red.n;
      Red.d = -Red.d;
    }
  }

return (Red);
}

int Rat::cmp(Rat &r) const{
  Rat op1, op2;
  int a,b;
  int val;
  op1.n = n;
  op1.d = d;
  a = op1.n/op1.d;
  op2.n = r.n;
  op2.d = r.d;
  b = op2.n/op2.d;

if (a<b){ val = -1;}
else if(a == b){val =  0;}
else if(a>b){val =  1;}

return (val);
}

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

std::cout << r3 << '\n'; /// for debugging


  Rat Red;
  int x,y;
  Red.n = r3.n;
  Red.d = r3.d;
  if (Red.n == Red.d){
    Red.n = 1;
    Red.d = 1;
  }
  else if(Red.n == -Red.d){
    Red.n = -1;
    Red.d = 1;
  }

  else if((abs(Red.n)>abs(Red.d)) && ((abs(Red.n)%abs(Red.d)) == 0)){
    if((Red.n*Red.d)>0){
      Red.n = abs(Red.n / Red.d);
      Red.d = 1;
    }
    else if((Red.n*Red.d)<0){
      Red.n = - abs(Red.n / Red.d);
      Red.d = 1;
    }


  }

  else if((abs(Red.d)>abs(Red.n)) && ((abs(Red.d)%abs(Red.n)) == 0)){
    if((Red.n*Red.d)>0){
    Red.d = abs(Red.d/Red.n);
    Red.n = 1;
  }
    else if((Red.n*Red.d)<0){
    Red.d = abs(Red.d/Red.n);
    Red.n = -1;
  }
  }

  else if ((Red.n > Red.d) && (Red.n%Red.d != 0)) {
    if (Red.d < 0){
      Red.n = -Red.n;
      Red.d = -Red.d;
    }
  }
  else if ((Red.n < Red.d) && (Red.d%Red.n != 0)) {
    if (Red.d < 0){
      Red.n = -Red.n;
      Red.d = -Red.d;
    }
  }

  return (Red);




}

ostream& operator <<(ostream& os, Rat rat) {
    os << rat.n << "/" << rat.d;
    return os;
}
