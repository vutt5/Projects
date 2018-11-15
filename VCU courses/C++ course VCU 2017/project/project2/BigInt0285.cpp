
/* Project #2
   EGRE246 Spring 2018
   Tin Vu */


#include <iostream>
//#include <cmath>
#include <string.h>
#include "BigInt.h"
using namespace std;

namespace EGRE246 {

BigInt::BigInt(){
  digits[0] = 0;
  sign = Sign::ZERO;
//  std::cout << static_cast<int>(sign) << '\n';
  len = 1;
}
BigInt::BigInt(long long n){


//check for under and over flow for long long type.

if((n<-9223372036854775807) || (n>9223372036854775806)){
  std::cout << "ERROR! THE NUMBER IS OUT OF RANGE! BYE" << '\n';
  exit(1);
}

//define sign for the number
long long num = n;
long long num2 = n;
if(n<0){
  num = num*(-1);
  num2 = num2*(-1);
  sign = Sign::NEG;}
else if(n == 0){
  sign = Sign::ZERO;}
else if(n>0){sign = Sign::POS;}

//count the digit of the number
    int count = 0;
    for(count = 0; num>0; count++){
      num = num/10;
    }
    len = count;

  //assign number to the digits array
    for(int i = (count-1);i>=0;i--){
      long long num3 = num2%10;
      num2 = num2/10;
      digits[i] = num3;
   }
  }

BigInt::BigInt(std::string s){
  //to remove spaces-------------------------------
  s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );

  //////////////////////////////////////
//case if the number is negative
  if(s[0] == '-'){
    sign = Sign::NEG;
    s.erase(0,1);

    int test=0;
    for(int i = 0;i<s.length();i++){test = test + (s[i] - '0');}
    if (test == 0){
      len = 1;
      sign = Sign::ZERO;
      digits[0]=0;
    }
    else{
    s.erase(0, s.find_first_not_of('0'));
    len = s.length();
    int check3=0;
    for(int i=0;i<s.length();i++){check3 = check3 + (s[i]-'0');}
    if (check3 == 0){
      len = 1;
      sign = Sign::POS;
      digits[0] = 0;
    }
    else{
      //check if len is longer than 100
    if(len>100){
      std::cout << "THE NUMBER IS TOO LARGE" << '\n';
      exit(1);}
    else{;}

    for(int i = 0;i<len;i++){digits[i] = s[i] - '0';}
  }
  }

  }
  //////////////////////////////////////
//case 2

  else{
    int test1=0;
    for(int i  = 0;i<s.length();i++){test1 = test1 + (s[i] - '0');}
    if (test1 == 0){
      len = 1;
      sign = Sign::POS;
      digits[0]=0;
    }
    else{
    s.erase(0, s.find_first_not_of('0'));
    sign = Sign::POS;
    len = s.length();

    //check if len is longer than 100
    if(len>100){
      std::cout << "THE NUMBER IS TOO LARGE" << '\n';
      exit(1);}
    else{;}
for(int i = 0;i<s.length();i++){digits[i] = s[i] - '0';}
    }
  }
}

int BigInt::getLen() const{return len;}


int BigInt::cmp(BigInt& op2) const{

  // value to be returned 0,1 or -1
  int val = 0;
  //initizlize two object of type BigInt to compare
  BigInt ob1, ob2;
  //transfer digits from the first original array to ob1's array
  for (int i=0;i<len;i++){ob1.digits[i] = digits[i];}
  //transfer lenth and sign of the first object
  ob1.len = len;
  ob1.sign = sign;
  //transfer digits from op2 to ob2;
  for (int i=0;i<op2.len;i++){ob2.digits[i] = op2.digits[i];}
  //transfer length and sign for ob2;
  ob2.len = op2.len;
  ob2.sign = op2.sign;
//convert ob1 to string type
  std::string num1 = "";
  std::string num2 = "";
  int test6 = 0;
  int test7 = 0;

  for(int i=0;i<200;i++){test6 = test6 + ob1.digits[i];}
  for(int i=0;i<200;i++){test7 = test7 + ob2.digits[i];}
if(test6 == 0){
  ob1.len = 1;
  ob1.sign = Sign::ZERO;
  ob1.digits[0] = 0;
}
else {;}

if(test7 == 0){
  ob2.len = 1;
  ob2.sign = Sign::ZERO;
  ob2.digits[0] = 0;
}
else{;}

  for(int i = 0 ; i<ob1.len ; i++){num1 += std::to_string(ob1.digits[i]);}
//convert ob2 to string type for easier comparation

  for(int i = 0 ; i<ob2.len ; i++){num2 += std::to_string(ob2.digits[i]);}
//compare signs
//when the first number is negative and the second one is positive
if((static_cast<int>(ob1.sign)) < (static_cast<int>(ob2.sign)))
{val = -1;}
//when the first number is postive and the second number is negative
else if ((static_cast<int>(ob1.sign)) > (static_cast<int>(ob2.sign))){val = 1;}

//compare number when signs are the same

//when both numbers are negative
else if((static_cast<int>(ob1.sign) == 0) && (static_cast<int>(ob2.sign) == 0)){
  if (ob1.len < ob2.len){val= 1;}
  else if (ob1.len > ob2.len){val = -1;}
  else if (ob1.len == ob2.len){
    for(int i = 0; i < ob1.len; ++i){
    if ((ob1.digits[i] - '0') < (ob2.digits[i] - '0'))
    {
        val = 1;
        break;
    }
    else if ((ob1.digits[i] - '0') == (ob2.digits[i] - '0')){val = 0;}
    else if ((ob1.digits[i] - '0') > (ob2.digits[i] - '0')){
      val = -1;
      break;
    }
  }
  }
}
//when both numbers are postive
else if((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 2)){
  if (ob1.len > ob2.len){val= 1;}
  else if (ob1.len < ob2.len){val = -1;}
  else if (ob1.len == ob2.len){
    for(int i = 0; i < ob1.len; ++i){
    if ((ob1.digits[i] - '0') < (ob2.digits[i] - '0'))
    {
        val = -1;
        break;
    }
    else if ((ob1.digits[i] - '0') == (ob2.digits[i] - '0')){val = 0;}
    else if ((ob1.digits[i] - '0') > (ob2.digits[i] - '0')){
      val = 1;
      break;
    }
  }
}}
return val;
}


///RETURN ABSOLUTE VALUE
BigInt BigInt::abs() const{
BigInt op1;
for(int i = 0;i<len;i++){op1.digits[i] = digits[i];}
op1.len = len;
op1.sign = Sign::POS;

return (op1);
}

BigInt BigInt::add(BigInt& op2) const{

BigInt ob1, ob2, ob3;

for(int i = 0;i<len;i++){ob1.digits[i] = digits[i];}
ob1.len = len;
ob1.sign = sign;

for(int m = 0;m<op2.len;m++){ob2.digits[m] = op2.digits[m];}
ob2.len = op2.len;
ob2.sign = op2.sign;

int check1=0;
int check2=0;
for(int i=0;i<200;i++){
  check1 = check1 + ob1.digits[i];
  check2 = check2 + ob2.digits[i];
}
if (check1 == 0){
  ob1.digits[0] = 0;
  ob1.sign =  Sign::ZERO;
  ob1.len = 1;
}
if (check2 == 0){
  ob2.digits[0] = 0;
  ob2.sign =  Sign::ZERO;
  ob2.len = 1;
}



// place two array to have the same length for easy calculation;
BigInt ob2_extra, ob1_extra;
if(ob1.len == ob2.len){
  for(int i=0;i<ob1.len;i++){ob1_extra.digits[i] = ob1.digits[i];}
  for(int i=0;i<ob1.len;i++){ob2_extra.digits[i] = ob2.digits[i];}
}
else if(ob1.len > ob2.len){
  int LenDiff = ob1.len - ob2.len;
  for(int i=0;i<LenDiff;i++){ob2_extra.digits[i] = 0;}
  for(int j=0;j<ob2.len;j++){ob2_extra.digits[j+LenDiff] = ob2.digits[j];}
ob2_extra.len  = ob1.len;
ob1.len = ob2_extra.len;
ob2.len = ob2_extra.len;

for(int i=0;i<=ob1.len;i++){ob1_extra.digits[i]  = ob1.digits[i];}
}


else if(ob1.len < ob2.len){
  int LenDiff = ob2.len - ob1.len;
  for(int k=0;k<LenDiff;k++){ob1_extra.digits[k] = 0;}
  for(int l=0;l<ob1.len;l++){ob1_extra.digits[l+LenDiff] = ob1.digits[l];}
ob1_extra.len  = ob2.len;
ob2.len = ob1_extra.len;
ob1.len = ob1_extra.len;

for(int i=0;i<=ob2.len;i++){ob2_extra.digits[i]  = ob2.digits[i];}
}

//normalize the array of ob1 and ob2 to the new arranged arrays
for(int i = 0;i<ob1.len;i++){ob1.digits[i] = ob1_extra.digits[i];}
for(int i = 0;i<ob1.len;i++){ob2.digits[i] = ob2_extra.digits[i];}
//THE SIGN OF EACH OBJECTS STAY THE SAME AS original



int carry=0;
  //when two objects have the same sign
  if(static_cast<int>(ob1.sign) == static_cast<int>(ob2.sign)){
    for(int i=ob1.len-1;i>=0;i--){
      ob3.digits[i] = ob1.digits[i] + ob2.digits[i] + carry;
      if(ob3.digits[i] <= 9){carry = 0;}
      else if (ob3.digits[i] > 9){
        carry = 1;
        ob3.digits[i] = ob3.digits[i] - 10;
      }

    }
    ob3.sign = ob1.sign;
    ob3.len = ob1.len;

    }
    //when one is neg and one is ZERO;
    else if(static_cast<int>(ob1.sign) == 0 && static_cast<int>(ob2.sign) == 1){
      ob3.sign =ob1.sign;
      ob3.len = ob1.len;
      for(int i=0;i<200;i++){ob3.digits[i] = ob1.digits[i];}
    }
    //when one is ZERO and one is neg
    else if(static_cast<int>(ob1.sign) == 1 && static_cast<int>(ob2.sign) == 0){
      ob3.sign =ob2.sign;
      ob3.len = ob2.len;
      for(int i=0;i<200;i++){ob3.digits[i] = ob2.digits[i];}
    }
    //when one is pos and one is ZERO
    else if(static_cast<int>(ob1.sign) == 2 && static_cast<int>(ob2.sign) == 1){
      ob3.sign =ob1.sign;
      ob3.len = ob1.len;
      for(int i=0;i<200;i++){ob3.digits[i] = ob1.digits[i];}
    }
    //when one is ZERO and one is postive
    else if(static_cast<int>(ob1.sign) == 1 && static_cast<int>(ob2.sign) == 2){
      ob3.sign =ob2.sign;
      ob3.len = ob2.len;
      for(int i=0;i<200;i++){ob3.digits[i] = ob2.digits[i];}
    }


// when two objects have different signs

  else if((static_cast<int>(ob1.sign)== 2) && (static_cast<int>(ob2.sign) == 0)){
    if(ob1.digits[0] >= ob2.digits[0]){
      for(int i=ob1.len-1;i>=0;i--){
      if(ob1.digits[i] >= ob2.digits[i]){
      ob3.digits[i] = ob1.digits[i] - ob2.digits[i] ;
    }
      else {
        ob1.digits[i] = ob1.digits[i] + 10;
        ob2.digits[i-1] = ob2.digits[i-1]+1;
        ob3.digits[i] = ob1.digits[i] - ob2.digits[i] ;
      }
    }
    ob3.sign = ob1.sign;
    ob3.len = ob1.len;
    std::string u = "";
    for(int i=0;i<ob3.len;i++){u += (ob3.digits[i] + '0');}
    u.erase(0, u.find_first_not_of('0'));
for(int i=0;i<u.length();i++){ob3.digits[i] = u[i]-'0';}
if(u.length() == 0){ ob3.len = 1;}
else{
ob3.len = u.length();
}
}
    else if(ob1.digits[0] < ob2.digits[0]){
      for(int i=ob1.len-1;i>=0;i--){
      if(ob1.digits[i] <= ob2.digits[i]){
      ob3.digits[i] = -ob1.digits[i] + ob2.digits[i] ;
}
    else {
    ob2.digits[i] = ob2.digits[i] + 10;
    ob1.digits[i-1] = ob1.digits[i-1]+1;
    ob3.digits[i] = ob2.digits[i] - ob1.digits[i] ;
  }
}
ob3.sign = ob2.sign;
ob3.len = ob2.len;
std::string u = "";
for(int i=0;i<ob3.len;i++){u +=(ob3.digits[i] + '0');}
u.erase(0, u.find_first_not_of('0'));
for(int i=0;i<u.length();i++){ob3.digits[i] = u[i]-'0';}
ob3.len = u.length();
  }
}

    else if((static_cast<int>(ob1.sign)== 0) && (static_cast<int>(ob2.sign) == 2)){
      if(ob1.digits[0] >= ob2.digits[0]){
        for(int i=ob1.len-1;i>=0;i--){
        if(ob1.digits[i] >= ob2.digits[i]){
        ob3.digits[i] = ob1.digits[i] - ob2.digits[i] ;
      }
        else {
          ob1.digits[i] = ob1.digits[i] + 10;
          ob2.digits[i-1] = ob2.digits[i-1]+1;
          ob3.digits[i] = ob1.digits[i] - ob2.digits[i] ;
        }
      }
      ob3.sign = ob1.sign;
      ob3.len = ob1.len;
  }
      else if(ob1.digits[0] < ob2.digits[0]){
        for(int i=ob1.len-1;i>=0;i--){
        if(ob1.digits[i] <= ob2.digits[i]){
        ob3.digits[i] = -ob1.digits[i] + ob2.digits[i] ;
  }
      else {
      ob2.digits[i] = ob2.digits[i] + 10;
      ob1.digits[i-1] = ob1.digits[i-1]+1;
      ob3.digits[i] = ob2.digits[i] - ob1.digits[i] ;
    }
  }
  ob3.sign = ob2.sign;
  ob3.len = ob2.len;
    }
      }
return ob3;
}

BigInt BigInt::sub(BigInt& op2) const{
  BigInt ob1, ob2,ob3;

  for(int i = 0;i<len;i++){ob1.digits[i] = digits[i];}
  ob1.len = len;
  ob1.sign = sign;
  for(int m = 0;m<op2.len;m++){ob2.digits[m] = op2.digits[m];}
  ob2.len = op2.len;
  ob2.sign = op2.sign;

  //when two objects have the same sign
  //both are ZERO;

  if((static_cast<int>(ob1.sign) == 1) && ( static_cast<int>(ob2.sign) == 1) ){
    ob3.digits[0] = 0;
    ob3.len = 1;
    ob3.sign = Sign::ZERO;
    return ob3;
  }
  //when one is neg and one is ZERO;
  else if(static_cast<int>(ob1.sign) == 0 && static_cast<int>(ob2.sign) == 1){
    ob2.sign = Sign::NEG;}
  //when one is ZERO and one is negative;
  else if(static_cast<int>(ob1.sign) == 1 && static_cast<int>(ob2.sign) == 0){
    ob2.sign = Sign::POS;}
  //when one is pos and one is ZERO
  else if(static_cast<int>(ob1.sign) == 2 && static_cast<int>(ob2.sign) == 1){;}
  //when one is ZERO and one is postive
  else if(static_cast<int>(ob1.sign) == 1 && static_cast<int>(ob2.sign) == 2){
    ob2.sign = Sign::NEG;}
  //WHEN BOTH ARE negative
  else if(static_cast<int>(ob1.sign) == 0 && static_cast<int>(ob2.sign) == 0){
    ob2.sign = Sign::POS;}
  //when two objects have the same sign
  //all postive
  else if((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 2)){
    ob2.sign = Sign::NEG;}
  //all negative
  else if((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 2)){
    ob2.sign = Sign::POS;}
  // when two objects have different signs
//first is pos and second is neg
    else if((static_cast<int>(ob1.sign)== 2) && (static_cast<int>(ob2.sign) == 0)){
      ob2.sign = Sign::POS;
    }
    //first is neg and second is pos
  else if((static_cast<int>(ob1.sign)== 0) && (static_cast<int>(ob2.sign) == 2)){
    ob2.sign = Sign::NEG;}
  return ob1.add(ob2);
}

///////////////////////////////MULTIPLICAITON///////////////////////////////////
BigInt BigInt::mul(BigInt& op2) const{
  BigInt ob1, ob2, ob3;

  for(int i = 0;i<len;i++){ob1.digits[i] = digits[i];}
  ob1.len = len;
  ob1.sign = sign;
  for(int m = 0;m<op2.len;m++){ob2.digits[m] = op2.digits[m];}
  ob2.len = op2.len;
  ob2.sign = op2.sign;

  // place two array to have the same length for easy calculation;
  BigInt ob2_extra, ob1_extra;
  if(ob1.len == ob2.len){
    for(int i=0;i<ob1.len;i++){ob1_extra.digits[i] = ob1.digits[i];}
    for(int i=0;i<ob1.len;i++){ob2_extra.digits[i] = ob2.digits[i];}
  }
  else if(ob1.len > ob2.len){
    int LenDiff = ob1.len - ob2.len;
    for(int i=0;i<LenDiff;i++){ob2_extra.digits[i] = 0;}
    for(int j=0;j<ob2.len;j++){ob2_extra.digits[j+LenDiff] = ob2.digits[j];}
  ob2_extra.len  = ob1.len;
  ob1.len = ob2_extra.len;
  ob2.len = ob2_extra.len;
  for(int i=0;i<=ob1.len;i++){ob1_extra.digits[i]  = ob1.digits[i];}
  }


  else if(ob1.len < ob2.len){
    int LenDiff = ob2.len - ob1.len;
    for(int k=0;k<LenDiff;k++){ob1_extra.digits[k] = 0;}
    for(int l=0;l<ob1.len;l++){ob1_extra.digits[l+LenDiff] = ob1.digits[l];}
  ob1_extra.len  = ob2.len;
  ob2.len = ob1_extra.len;
  ob1.len = ob1_extra.len;
  for(int i=0;i<=ob2.len;i++){ob2_extra.digits[i]  = ob2.digits[i];}
  }

  //normalize the array of ob1 and ob2 to the new arranged arrays
  for(int i = 0;i<ob1.len;i++){
    ob1.digits[i] = ob1_extra.digits[i];
  }
  for(int i = 0;i<ob1.len;i++){
    ob2.digits[i] = ob2_extra.digits[i];
  }
  //THE SIGN OF EACH OBJECTS STAY THE SAME AS original
int ob1_digits[200];
for(int i = 0;i< 200-ob1.len;i++){
  ob1_digits[i] = 0;
}
int a=0;
for(int i = 200-ob1.len;i<200;i++){
  ob1_digits[i] = ob1.digits[a];
  a++;
}
int ob2_digits[200];
for(int i = 0;i< 200-ob2.len;i++){
  ob2_digits[i] = 0;
}
int b=0;
for(int i = 200-ob2.len;i<200;i++){
  ob2_digits[i] = ob2.digits[b];
  b++;
}


  //////when two objects have the same sign
int carry =0;
int move = 0;
int buff = 199;
int digits_2[200][200];
for(int i=0;i<200;i++){
  for(int j=0;j<200;j++){digits_2[i][j] = 0;}
}
int digits_3[200];
if((static_cast<int>(ob1.sign) == 1) && (static_cast<int>(ob2.sign) == 1)){ob3.sign = Sign::ZERO;}
if(static_cast<int>(ob1.sign) ==  static_cast<int>(ob2.sign)){ob3.sign = Sign::POS;}
else if((static_cast<int>(ob1.sign) == 0 )&& (static_cast<int>(ob2.sign) == 2)){ob3.sign = Sign::NEG;}
else if((static_cast<int>(ob1.sign) == 2 )&& (static_cast<int>(ob2.sign) == 0)){ob3.sign = Sign::NEG;}

  for(int i =0;i<199;i++){
    for(int j=199;j>=1;j--){
      digits_2[i][j-move] = ((ob1_digits[j])*(ob2_digits[buff]))+carry;
        if(digits_2[i][j-move] <= 9){carry = 0;}
        else if (digits_2[i][j-move] >=10){
          carry = (digits_2[i][j-move])/10;
          digits_2[i][j-move] = digits_2[i][j-move] % 10;
        }
    }
    buff--;
    move++;
  }
///////GOOOD HERE



for(int i=0;i<200;i++){digits_3[i]= 0 ;}
int carry2 = 0;
for(int i=0;i<=199;i++){
  for(int j=199;j>=0;j--){
    digits_3[j] = digits_3[j] + digits_2[i][j]+ carry2;
    if(digits_3[j] <=9){
      carry2 = 0;
    }
    else if (digits_3[j] >=10) {
      carry2 = (digits_3[j])/10;
      digits_3[j] = (digits_3[j])%10;
      }
    }
  }
int test5 = 0;
for(int i=0;i<200;i++){test5 = test5 + digits_3[i];}
if(test5 == 0){
  ob3.len = 1;
  ob3.sign = Sign::ZERO;
  ob3.digits[0] = 0;
}
else{

std::string num3 = "";
for(int i = 0 ; i<200 ; i++){
num3 += std::to_string(digits_3[i]);
}
num3.erase(0, num3.find_first_not_of('0'));
if(num3.length() > 100){std::cout << "ERROR! THE OUTPUT EXCCEDED 100 NUMBERS" << '\n';}
else if (num3.length() <= 100) {
  for (int i=0;i<num3.length();i++){ob3.digits[i] = num3[i]-'0';}
}
ob3.len = num3.length();
}
return ob3;
}

/////////////////////////////DIV////////////////////////////////////////////////
BigInt BigInt::div(BigInt& op2) const{
  BigInt ob1, ob2, ob3, ob4;

  for(int i = 0;i<len;i++){ob1.digits[i] = digits[i];}
  ob1.len = len;
  ob1.sign = sign;

  for(int m = 0;m<op2.len;m++){ob2.digits[m] = op2.digits[m];}
  ob2.len = op2.len;
  ob2.sign = op2.sign;

int m=0;
int n=0;
///to check for ZEROS
for(int i=0;i<ob1.len;i++){m+=ob1.digits[i];}
for(int i=0;i<ob2.len;i++){n+=ob2.digits[i];}
///EXIT PROGRAM WHEN THE DENOMINATOR IS ZERO
if(n==0){
  std::cout << "ERROR. CAN'T BE ZERO ON THE DENOMINATOR" << '\n'; exit (1);}

//ASSIGN 0 TO THE OUTPUT IF OTHERWISE
else if(m == 0){
  ob3.digits[0]=  0;
  ob3.sign = Sign::ZERO;
  ob3.len = 1;
  return ob3;
}

////check the signs to elimitate them before comparing

else if ((static_cast<int>(ob1.sign) == 0) && (static_cast<int>(ob2.sign) == 2)){
  ob3.sign = Sign::NEG;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}
else if ((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 0)){
  ob3.sign = Sign::NEG;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}

else if ((static_cast<int>(ob1.sign) == 0) && (static_cast<int>(ob2.sign) == 0)){
  ob3.sign = Sign::POS;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}
else if ((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 2)){
  ob3.sign = Sign::POS;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}

//////COMPARE THEM signs

std::string count2= "";
if (ob1.cmp(ob2) == -1){
  ob3.digits[0]=  0;
  ob3.sign = Sign::ZERO;
  ob3.len = 1;
}

else if(ob1.cmp(ob2) == 0){
  ob3.digits[0]=  1;
  ob3.len = 1;
}
else if (ob1.cmp(ob2) == 1){
std::string track = ""; ///used to keep track of the array
long long p=0; //used to keep track of the number
for(;;){
  ob1 = ob1.sub(ob2);
  if(static_cast<int>(ob1.sign) == 0){break;}
  else {p++;}

//      1234567890123456789
  if (p>9223372036854775800){
    std::cout << ":(" << '\n';
    ob3.digits[0] = 0;
    ob3.len = 1;
    break;
  }
}
long long numm = p;
long long numm2 = p;
    int count = 0;
    for(count = 0; numm>0; count++){
      numm = numm/10;
    }
   ob3.len = count;

  //assign number to the digits array
    for(int i = (count-1);i>=0;i--){
      long long numm3 = numm2%10;
      numm2 = numm2/10;
      ob3.digits[i] = numm3;
   }



  }


return ob3;
}
/////////////////////////////////////RETURN remainder///////////////////////////
BigInt BigInt::mod(BigInt& op2) const{
  BigInt ob1, ob2, ob3, ob4;

  for(int i = 0;i<len;i++){ob1.digits[i] = digits[i];}
  ob1.len = len;
  ob1.sign = sign;
  for(int m = 0;m<op2.len;m++){ob2.digits[m] = op2.digits[m];}
  ob2.len = op2.len;
  ob2.sign = op2.sign;
int m=0;
int n=0;
///to check for ZEROS
for(int i=0;i<ob1.len;i++){m+=ob1.digits[i];}
for(int i=0;i<ob2.len;i++){n+=ob2.digits[i];}
///EXIT PROGRAM WHEN THE DENOMINATOR IS ZERO
if(n==0){
  std::cout << "ERROR. CAN'T BE ZERO ON THE DENOMINATOR" << '\n';
  exit (1);
}
//ASSIGN REMAINDER TO THE OUTPUT IF OTHERWISE
else if(m == 0){
  ob3.len = ob2.len;
  for(int i=0;i<ob2.len;i++){
  ob3.digits[i]=  ob2.digits[i];}
  ob3.sign = ob2.sign;
  return ob3;
}
////check the signs to elimitate them before comparing
else if ((static_cast<int>(ob1.sign) == 0) && (static_cast<int>(ob2.sign) == 2)){
  ob3.sign = Sign::NEG;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}
else if ((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 0)){
  ob3.sign = Sign::NEG;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}

else if ((static_cast<int>(ob1.sign) == 0) && (static_cast<int>(ob2.sign) == 0)){
  ob3.sign = Sign::POS;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}
else if ((static_cast<int>(ob1.sign) == 2) && (static_cast<int>(ob2.sign) == 2)){
  ob3.sign = Sign::POS;
  ob1.sign = Sign::POS;
  ob2.sign = Sign::POS;
}
//////COMPARE THEM signs
std::string count2= "";
if (ob1.cmp(ob2) == -1){
  ob3.len = ob1.len;
  for(int i=0;i<ob1.len;i++){
  ob3.digits[i]=  ob1.digits[i];}
}
else if(ob1.cmp(ob2) == 0){
  ob3.digits[0]=  0;
  ob3.sign = Sign::ZERO;
  ob3.len = 1;
  return ob3;
}
else if (ob1.cmp(ob2) == 1){
BigInt ob4 = ob1;
BigInt ob5;
int checkcheck=0;
  for(;;){
    ob1 = ob1.sub(ob2);
    if(static_cast<int>(ob1.sign) == 0){
      ob1.sign = Sign::POS;
      ob3 = ob2.sub(ob1);
      break;
    }
    else {;}
  }
}
//------------THIS PART IS USED TO ASSIGN THE SIGN TO THE OUTPUT--------------

BigInt ob7, ob8;
ob7.sign = sign;
ob8.sign = op2.sign;
if ((static_cast<int>(ob7.sign) == 0) && (static_cast<int>(ob8.sign) == 2)){ob3.sign = Sign::NEG;}
else if ((static_cast<int>(ob7.sign) == 2) && (static_cast<int>(ob8.sign) == 0)){ob3.sign = Sign::POS;}
else if ((static_cast<int>(ob7.sign) == 0) && (static_cast<int>(ob8.sign) == 0)){ob3.sign = Sign::NEG;}
else if ((static_cast<int>(ob7.sign) == 2) && (static_cast<int>(ob8.sign) == 2)){ob3.sign = Sign::POS;}
return ob3;
}
//////////////////////////////OUTPUT OVERLOADING OPERATOR///////////////////////

ostream& operator <<(ostream& os, const BigInt& n){
std::string a,b;
//print sign
if (static_cast<int>(n.sign) == 0){a = "-";}
else if (static_cast<int>(n.sign) == 1 ){a = " ";}
else if (static_cast<int>(n.sign) == 2 ){a = " ";}
//print the number
std::string num = "";
num += a;
for(int i = 0 ; i<n.len ; i++){
num += std::to_string(n.digits[i]);
}
    os << num ;
    return os;
  }
}
bool extra_credit() {
  return true; // or ’return false’ if you did not do the extra credit
}
