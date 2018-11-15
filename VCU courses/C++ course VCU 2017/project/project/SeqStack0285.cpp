#include <iostream>
using namespace std;
#include <cassert>
#include "Sequence.h"

namespace EGRE246{

  Sequence::Sequence():used(0),currentIndex(0) {}

  void Sequence::start() { currentIndex = 0; }

  void Sequence::advance() {
    assert(isItem());
    currentIndex++;
  }

  void Sequence::insert(const value_type& entry) {
    assert(size() < Sequence::CAPACITY);
    for (size_type i = used; i > currentIndex; i--) {
      data[i] = data[i-1];
    }
    data[currentIndex] = entry;
    used++;
  }

  void Sequence::attach(const value_type& entry){
    assert(size() < Sequence::CAPACITY);
    for (size_type i = used; i > currentIndex+1; i--) {
      data[i] = data[i-1];
    }
    data[used==0?0:++currentIndex] = entry;
    used++;
  }

  void Sequence::removeCurrent(){
    assert(isItem());
    for (size_type i = currentIndex; i < used; i++) {
      data[i] = data[i+1];
    }
    used--;
  }

  Sequence::size_type Sequence::size() const { return used; }

  bool Sequence::isItem() const {
    return (used != currentIndex);
  }

  Sequence::value_type Sequence::current() const {
    assert(isItem());
    return data[currentIndex];
  }

}
