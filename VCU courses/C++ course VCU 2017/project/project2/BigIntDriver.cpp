#include <iostream>
using namespace std;
//#include <cmath>
//#include <string.h>
#include "BigInt.h"
using namespace EGRE246;

int main(){
BigInt       n1(1234567890);
BigInt n2(1345);
BigInt n3(54321);
BigInt n4(-12345);
BigInt n5("  0");
BigInt n6("0");
BigInt n7("1234567890");
BigInt n8("12345678901239");
BigInt n9(1234567);
BigInt n10(17286);

//////DIVISION

std::cout << "n8/n7 = " << n8.div(n7) << '\n';
std::cout << "n1/n2 = " << n1.div(n2) << '\n';
std::cout << "n4/n1 = " << n4.div(n1) << '\n';



/////////////RETURN REMAINDER/////////////////

std::cout << "n9%n1:"<< (n9.mod(n1)) << '\n';
std::cout << "n7%n1:"<< (n7.mod(n1)) << '\n';
std::cout << "n4%n1:"<< (n4.mod(n1)) << '\n';
std::cout << "n10%n1:"<< (n10.mod(n1)) << '\n';
std::cout << "n7%n8:"<< (n7.mod(n8)) << '\n';
std::cout << "n4%n7:"<< (n4.mod(n7)) << '\n';
std::cout << "n9%n3:"<< (n9.mod(n3)) << '\n';


std::cout <<"n1: " << n1 << '\n';
std::cout <<"n2: " << n2 << '\n';
std::cout <<"n3: " << n3 << '\n';
std::cout <<"n4: " << n4 << '\n';
std::cout <<"n5: " << n5 << '\n';
std::cout <<"n6: " << n6 << '\n';
std::cout <<"n7: " << n7 << '\n';
std::cout <<"n8: " << n8 << '\n';

///CHECK LENGTH

std::cout << "length n1: " << n1.getLen() <<'\n';
std::cout << "length n2: " << n2.getLen() <<'\n';
std::cout << "length n3: " << n3.getLen() <<'\n';
std::cout << "length n4: " << n4.getLen() <<'\n';
std::cout << "length n5: " << n5.getLen() <<'\n';
std::cout << "length n6: " << n6.getLen() <<'\n';
std::cout << "length n7: " << n7.getLen() <<'\n';
std::cout << "length n8: " << n8.getLen() <<'\n';


////////check comparation

std::cout << "compare n1 to n1: " << n1.cmp(n1) << '\n';
std::cout << "compare n1 to n2: " << n1.cmp(n2) << '\n';
std::cout << "compare n2 to n1: " << n2.cmp(n1) << '\n';
std::cout << "compare n1 to n3: " << n1.cmp(n3) << '\n';
std::cout << "compare n3 to n1: " << n3.cmp(n1) << '\n';
std::cout << "compare n1 to n4: " << n1.cmp(n4) << '\n';
std::cout << "compare n4 to n1: " << n4.cmp(n1) << '\n';
std::cout <<  '\n';
std::cout << "compare n5 to n5: " << n5.cmp(n5) << '\n';
std::cout << "compare n5 to n6: " << n5.cmp(n6) << '\n';
std::cout << "compare n6 to n5: " << n6.cmp(n5) << '\n';
std::cout << "compare n5 to n7: " << n5.cmp(n7) << '\n';
std::cout << "compare n7 to n5: " << n7.cmp(n5) << '\n';
std::cout << "compare n5 to n8: " << n5.cmp(n8) << '\n';
std::cout << "compare n8 to n5: " << n8.cmp(n5) << '\n';


////////check for absolute

//BigInt n10 = n1.abs();

std::cout << "absolute of n1: " << n1.abs() << '\n';
std::cout << "absolute of n2: " << n2.abs() << '\n';
std::cout << "absolute of n3: " << n3.abs() << '\n';
std::cout << "absolute of n4: " << n4.abs() << '\n';
std::cout << "absolute of n5: " << n5.abs() << '\n';
std::cout << "absolute of n6: " << n6.abs() << '\n';
std::cout << "absolute of n7: " << n7.abs() << '\n';
std::cout << "absolute of n8: " << n8.abs() << '\n';




std::cout << "add n1 and n2: " << n1.add(n2) << '\n';
std::cout << "add n1 and n3: " << n1.add(n3) << '\n';
std::cout << "add n1 and n4: " << n1.add(n4) << '\n';
std::cout << "add n1 and n5: " << n1.add(n5) << '\n';
std::cout << "add n5 and n6: " << n5.add(n6) << '\n';
std::cout << "add n5 and n7: " << n5.add(n7) << '\n';
std::cout << "add n5 and n8: " << n5.add(n8) << '\n';
std::cout << "add n1 and n2: " << n1.add(n2) << '\n';
std::cout << "add n1 and n3: " << n1.add(n3) << '\n';
std::cout << "add n1 and n4: " << n1.add(n4) << '\n';
std::cout << "add n7 and n8: " << n7.add(n8) << '\n';
//integer input added with string input

std::cout << "add n1 and n6: " << n1.add(n6) << '\n';
std::cout << "add n1 and n7: " << n1.add(n7) << '\n';
std::cout << "add n1 and n8: " << n1.add(n8) << '\n';

std::cout << "add n1 and n5: " << n1.add(n5) << '\n';




///SUBTRACT FUNCTION

std::cout << "MINUS TEST"<< n10.sub(n1) << '\n';

std::cout << "n1 minus n2" << n1.sub(n2)<< '\n';
std::cout << "n1 minus n3" << n1.sub(n3)<< '\n';
std::cout << "n1 minus n4" << n1.sub(n4)<< '\n';
std::cout << "n1 minus n5" << n1.sub(n5)<< '\n';
std::cout << "n1 minus n6" << n1.sub(n6)<< '\n';
std::cout << "n1 minus n7" << n1.sub(n7)<< '\n';
std::cout << "n1 minus n8" << n1.sub(n8)<< '\n';
std::cout << "n8 minus n7" << n8.sub(n7)<< '\n';
std::cout << "n8 minus n7 then get the absolute: " << (n8.sub(n7)).abs()<< '\n';
std::cout << "n8 minus n7 then get the absolute then get the len: " << ((n8.sub(n7)).abs()).getLen()<< '\n';
std::cout << "n8 minus n6" << n8.sub(n6)<< '\n';
std::cout << "n8 minus n5" << n8.sub(n5)<< '\n';
std::cout << "n8 minus n4" << n8.sub(n4)<< '\n';
std::cout << "n8 minus n3" << n8.sub(n3)<< '\n';
std::cout << "n8 minus n2" << n8.sub(n2)<< '\n';
std::cout << "n8 minus n1" << n8.sub(n1)<< '\n';
std::cout << "n5 minus n6 length (should be 1): " << (n5.sub(n6)).getLen()<< '\n';
std::cout << "n2 minus n9" << n2.sub(n9)<< '\n';
std::cout << "n9 minus n2" << n9.sub(n2)<< '\n';



std::cout << n1.mul(n2) << '\n';
std::cout << n1.mul(n3) << '\n';
std::cout << n1.mul(n4) << '\n';
std::cout << n1.mul(n5) << '\n';
std::cout << n1.mul(n6) << '\n';
std::cout << n1.mul(n7) << '\n';
std::cout << n1.mul(n8) << '\n';




////RETURN REMAINDER



  return 0;
}
