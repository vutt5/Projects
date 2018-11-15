#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
#include <cassert>
#include "SeqStack.h"



namespace EGRE246{

  SeqStack::SeqStack():used(0),currentIndex(0) {}

  void SeqStack::start() { currentIndex = 0; }

  void SeqStack::advance() {
    assert(isItem());
    currentIndex++;
  }

  void SeqStack::insert(const value_type& entry) {
    assert(size() < SeqStack::CAPACITY);
    for (size_type i = used; i > currentIndex; i--) {
      data[i] = data[i-1];
    }
    data[currentIndex] = entry;
    used++;
  }

  void SeqStack::attach(const value_type& entry){
    assert(size() < SeqStack::CAPACITY);
    for (size_type i = used; i > currentIndex+1; i--) {
      data[i] = data[i-1];
    }
    data[used==0?0:++currentIndex] = entry;
    used++;
  }

  void SeqStack::removeCurrent(){
    assert(isItem());
    for (size_type i = currentIndex; i < used; i++) {
      data[i] = data[i+1];
    }
    used--;
  }

  SeqStack::size_type SeqStack::size() const { return used; }

  bool SeqStack::isItem() const {
    return (used != currentIndex);
  }

  SeqStack::value_type SeqStack::current() const {
    assert(isItem());
    return data[currentIndex];
  }
  bool SeqStack::isEmpty() const{
    if(used == 0){return 1;}
    else {return 0;}
  }
  SeqStack::value_type SeqStack::top(){
    assert(!isEmpty());
    return data[used-1];
  }
  SeqStack::value_type SeqStack::pop(){
    assert(!isEmpty());
    int a = data[used-1];
    used--;
    return a;
  }
  void SeqStack::push(const value_type& entry){
    assert(size() < SeqStack::CAPACITY);
    data[used] = entry;
    used++;
  }


}
