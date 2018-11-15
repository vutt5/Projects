#include <iostream>
using namespace std;
#include "BigInt.h"
using namespace EGRE246;

string spaces(int);

BigInt maxint();
BigInt minint();
string maxString();
string border(string s);

int main() {

  int count = 0;
  long long x, x1, x2;
  string str;

  BigInt n1;

#ifdef OVER1
  BigInt(maxString()+"9");
#elif defined(OVER2)
  BigInt b = maxint();
  BigInt(1).add(b);
#elif defined(UNDER)
  BigInt("-"+maxString()+"9");
#elif defined(XC_OVER)
  BigInt b = maxint();
  maxint().mul(b);
#else
  
  count++; 
  cout << (count<10?" ":"") << count << ": " << BigInt();
  cout << spaces(1) << "<-- 0";
  cout << "\t\t\t[ ==== constructor tests ==== ]" << endl;

  count++; //2
  cout << (count<10?" ":"") << count << ": " << maxint() << endl;
  cout << spaces(4) << maxString() << " (expected)" << endl;

  count++; 
  cout << (count<10?" ":"") << count << ": " << minint() << endl;
  cout << spaces(4) << "-" << maxString() << " (expected)" << endl;

  count++; //4
  cout << (count<10?" ":"") << count << ": " << BigInt(999999999999) << endl;
  cout << spaces(4) << "999999999999" << " (expected)" << endl;

  count++; 
  cout << (count<10?" ":"") << count << ": " << BigInt(-999999999999) << endl;
  cout << spaces(4) << "-999999999999" << " (expected)" << endl;

  count++; //6
  cout << (count<10?" ":"") << count << ": " << BigInt("-0");
  cout << spaces(10) << "<-- 0" << endl;

  count++;
  cout << (count<10?" ":"") << count << ": " << BigInt("      00002");
  cout << spaces(10) << "<-- 2" << endl;

  count++; //8
  cout << (count<10?" ":"") << count << ": " << BigInt("      -00002");
  cout << spaces(9) << "<-- -2" << endl;

  count++;
  n1 = BigInt("1234567890");
  cout << (count<10?" ":"") << count << ": " << n1.getLen();
  cout << spaces(9) << "<-- 10";
  cout << "\t\t[ ==== getLen() test ==== ]" << endl;

  count++; //10
  n1 = BigInt(-123);
  cout << (count<10?" ":"") << count << ": " << BigInt("0").cmp(n1);
  cout << spaces(10) << "<-- 1";
  cout << "\t\t[ ==== cmp() tests ==== ]" << endl;

  count++;
  n1 = BigInt(maxString());
  cout << (count<10?" ":"") << count << ": " << BigInt(maxString()).cmp(n1);
  cout << spaces(10) << "<-- 0" << endl;

  count++; //12
  n1 = BigInt(-50);
  cout << (count<10?" ":"") << count << ": " << BigInt(-999).cmp(n1);
  cout << spaces(9) << "<-- -1" << endl;

  count++;
  cout << (count<10?" ":"") << count << ": " << BigInt(-555).abs();
  cout << spaces(8) << "<-- 555";
  cout << "\t\t[ ==== abs() tests ==== ]" << endl;

  count++; //14
  cout << (count<10?" ":"") << count << ": " << BigInt(555).abs();
  cout << spaces(8) << "<-- 555" << endl;

  count++;
  n1 = BigInt(0);
  cout << (count<10?" ":"") << count << ": " << BigInt(0).add(n1) ;
  cout << spaces(10) << "<-- 0";
  cout << "\t\t[ ==== add() tests ==== ]" << endl;
  
  count++; //16
  x = 99999999999999;
  str = to_string(x);
  n1 = BigInt(-x);
  cout << (count<10?" ":"") << count << ": " << BigInt(x).add(n1) ;
  cout << spaces(10) << "<-- " << x + -x << endl;

  count++;
  x1 = -10006;
  x2 = 10016;
  n1 = BigInt(x2);
  cout << (count<10?" ":"") << count << ": " << BigInt(x1).add(n1) ;
  cout << spaces(9) << "<-- " << x1 + x2 << endl;

  count++; //18
  x1 = 59173; x2 = -59163;
  n1 = BigInt(x2);
  cout << (count<10?" ":"") << count << ": " << BigInt(x1).add(n1) ;
  cout << spaces(9) << "<-- " << x1 + x2 << endl;
  
  count++;
  x1 = 1000; x2 = -1;
  n1 = BigInt(x2);
  cout << (count<10?" ":"") << count << ": " << BigInt(x1).add(n1) ;
  cout << spaces(8) << "<-- " << x1 + x2 << endl;

  count++; //20
  x1 = 999519; x2 = 480;
  n1 = BigInt(x2);
  cout << (count<10?" ":"") << count << ": " << BigInt(x1).add(n1) ;
  cout << spaces(5) << "<-- " << x1 + x2 << endl;

  if (extra_credit()) {
#ifdef XTRA
    cout << endl << "<<< HIT ENTER TO SEE EXTRA CREDIT >>>" << endl;
    std::cin.get();
    
    count++; 
    x1 = 600000; x2 = 99;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).sub(n1);
    cout << spaces(5) << "<-- " << x1 - x2;
    cout << "\t[ ==== sub() tests ==== ]" << endl;
 
    count++; //22
    x1 = 0; x2 = -10;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).sub(n1) ;
    cout << spaces(9) << "<-- " << x1 - x2 << endl;
   
    count++; 
    x1 = 10; x2 = 0;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).sub(n1) ;
    cout << spaces(9) << "<-- " << x1 - x2 << endl;
    
    count++; //24
    x1 = -99999999999999999; x2 = -99999999999999999;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).sub(n1);
    cout << spaces(10) << "<-- " << x1 - x2 << endl;

    count++; 
    x1 = 0; x2 = 0;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).sub(n1);
    cout << spaces(10) << "<-- " << x1 - x2 << endl;

    count++; //26
    x1 = -218218000; x2 = 218;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).sub(n1);
    cout << spaces(1) << "<-- " << x1 - x2 << endl;

    count++; 
    x1 = 100000000000000; x2 = 100;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mul(n1);
    cout << "\t\t[ ==== mul() tests ==== ]" << endl;
    cout << spaces(4) << x1 * x2 << " (expected)" << endl;

    count++; //28
    x1 = -5000; x2 = -125;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mul(n1) << endl;
    cout << spaces(4) << x1 * x2 << " (expected)" << endl;

    count++; 
    x1 = -5000; x2 = 0;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mul(n1);
    cout << spaces(1) << "<-- " << x1 * x2 << endl;

    count++; //30
    x1 = 0; x2 = 0;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mul(n1);
    cout << spaces(1) << "<-- " << x1 * x2 << endl;
    
    count++; 
    x1 = 1; x2 = 1000000000;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).div(n1);
    cout << spaces(1) << "<-- " << x1 / x2 << "\t\t\t[ ==== div() tests ==== ]" << endl;

    count++; //32
    x1 = 0; x2 = -1234;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).div(n1);
    cout << spaces(1) << "<-- " << x1 / x2 << endl;

    count++; 
    n1 = BigInt(1);
    cout << (count<10?" ":"") << count << ": " << BigInt(1).div(n1);
    cout << spaces(1) << "<-- 1" << endl;

    count++; //34
    x1 = 100000000000000; x2 = 1000000000;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).div(n1) << endl;
    cout << spaces(4) << x1 / x2 << " (expected)" << endl;

    count++; 
    x1 = 100000; x2 = 1;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).div(n1) << endl;
    cout << spaces(4) << x1 / x2 << " (expected)" << endl;

    count++; //36
    x1 = 0; x2 = 1000000000;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mod(n1);
    cout << spaces(1) << "<-- " << x1 % x2 << "\t\t\t[ ==== mod() tests ==== ]" << endl;

    count++; 
    x1 = 10; x2 = 2;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mod(n1);
    cout << spaces(1) << "<-- " << x1 % x2 << endl;
    
    count++; //38
    x1 = 10; x2 = -4;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mod(n1);
    cout << spaces(1) << "<-- " << x1 % x2 << endl;
    
    count++; 
    x1 = -10; x2 = 4;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mod(n1);
    cout << spaces(1) << "<-- " << x1 % x2 << endl;

    count++; //40
    x1 = -10; x2 = -4;
    n1 = BigInt(x2);
    cout << (count<10?" ":"") << count << ": " << BigInt(x1).mod(n1);
    cout << spaces(1) << "<-- " << x1 % x2 << endl;
#endif    
  } else {
    cout << "\nextra_credit() returns false" << endl; 
  }

#endif


}

string spaces(int n) {
  string res;
  for (int i=1; i<=n; i++) res += " ";
  return res;
}

string maxString() {
  string s;
  for (int i = 1; i <= EGRE246::BigInt::MAX_DIGITS; i++) s += "9";
  return s;
}

BigInt maxint() { return BigInt(maxString()); }
BigInt minint() { return BigInt("-"+maxString()); }

