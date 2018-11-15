/*  Project #4
    EGRE246 Spring 2018
    Tin Vu*/

#ifndef ALLMEM_H
#define ALLMEM_H
#include "ALLNode.h"

#define SIZE 100 // size of the node array; arbitrary

namespace EGRE246 {
  template <typename Item>
  class ALLMem {
  public:
    typedef Item value_type;
    typedef int size_type;
    typedef size_type address;

    ALLMem(size_type size_=SIZE) {
      size = size_;
      freeMem = size_;
      mem = new ALLNode<Item>[size];
      for (int i=0; i < size; i++) {
        mem[i].setPrevLink(i - 1);
        mem[i].setNextLink(i + 1);
      }
      mem[size - 1].setNextLink(-1);
      freePtr = 0;
    }

    size_type getMemSize() const { return size; } // returns total size of memory
    address getFreePtr() const { return freePtr; }   // returns pointer to free memory list
    size_type memFree() const    { return freeMem; } // returns amount of free memory

    address alloc() {
      if (freeMem < 1) {
        std::cout << "Alloc: No free memory\n";
        exit (1);
      }
      address newPtr = freePtr;

      freePtr = mem[freePtr].getNextLink();
      mem[freePtr].setPrevLink(-1);
      freeMem--;

      mem[newPtr].setPrevLink(-1);
      mem[newPtr].setNextLink(-1);

      return newPtr;
    }
      // allocates and returns address of new node removing it from free
      // memory; prints error message and exits if no memory available

    void dealloc(address addr) {
      if (addr < 0 || addr >= size) {
        std::cout << "Dealloc: Illegal Address\n";
        exit (1);
      }
      address prev = mem[addr].getPrevLink();
      address next = mem[addr].getNextLink();
      if (prev > 0 && prev < size) {
        mem[prev].setNextLink(next);
      }
      if (next > 0 && next < size) {
        mem[next].setPrevLink(prev);
      }

      mem[addr].setNextLink(freePtr);
      mem[addr].setPrevLink(-1);
      mem[freePtr].setPrevLink(addr);
      freePtr = addr;
      freeMem++;
    }
      // deallocates node pointed to by addr (i.e. returns it to free memory list)
      // prints error message and exits if:
      //   1) no memory to deallocate, or
      //   2) address node is not allocated (is free), or
      //   3) address is illegal

    value_type getData(const address& addr) {
      if (addr < 0 || addr >= size) {
        std::cout << "Get Data: Illegal Address\n";
        exit (1);
      }
      return mem[addr].getData();
    }
      // returns data in node pointed to by addr prints error message and
      // exits if illegal address

    address getPrev(const address& addr) {
      if (addr < 0 || addr >= size) {
        std::cout << "Get Prev: Illegal Address\n";
        exit(1);
      }
      return mem[addr].getPrevLink();
    }
    address getNext(const address& addr) {
      if (addr < 0 || addr >= size) {
        std::cout << "Get Next: Illegal Address\n";
        exit(1);
      }
      return mem[addr].getNextLink();
    }
      // returns address of prev/next node, prints error message and exits
      // if illegal address

    void setData(const address& addr, const value_type val){
      if (addr < 0 || addr >= size) {
        std::cout << "Set Data: Illegal Address\n";
        exit (1);
      }
      mem[addr].setData(val);
    }
      // sets node data at addr to val; prints error message and exits
      // if illegal address

    void setPrev(const address& addr, const address naddr) {
      if (addr < 0 || addr >= size) {
        std::cout << "Set Prev: Illegal Address\n";
        exit (1);
      }
      mem[addr].setPrevLink(naddr);
    }

    void setNext(const address& addr, const address naddr) {
      if (addr < 0 || addr >= size) {
        std::cout << "Set Next: Illegal Address\n";
        exit (1);
      }
      mem[addr].setNextLink(naddr);
    }
      // sets prev/next at addr to val; prints error message and exits
      // if illegal address

  private:
    size_type size;     // size of memory
    size_type freeMem;  // size of available memory
    ALLNode<Item> *mem; // memory array of nodes
    address freePtr;    // pointer to available memory list

  };

}

#endif
