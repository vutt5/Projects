#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
#include <cassert>
#include "SeqStack.h"
using namespace EGRE246;

int main(int argc, char const *argv[]) {
  SeqStack ob1;

  ob1.start();
  std::cout << "it should be empty: " << ob1.isEmpty() << '\n';
  std::cout << "insert 4" << '\n';
  ob1.push(4);
  std::cout << "insert 5" << '\n';
  ob1.push(5);
  std::cout << "it shouldn't be empty: "<< ob1.isEmpty() << '\n';
  std::cout << "current top: " << ob1.top() << '\n';
  std::cout << "pop 1:" << ob1.pop() <<'\n';
  std::cout << "current top: " << ob1.top() << '\n';
  ob1.push(6);
  ob1.push(7);
  ob1.push(8);
  std::cout << "current top (should be 8): " << ob1.top() << '\n';
  std::cout << "pop 1(should return 8) "<< ob1.pop() << '\n';
  std::cout << "current top(7): "<< ob1.top() << '\n';


return 0;}
