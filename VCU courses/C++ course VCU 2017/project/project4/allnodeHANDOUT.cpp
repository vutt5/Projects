#include <iostream>
using namespace std;
#include "ALLMem.h"
using namespace EGRE246;

void dumpMem(ALLMem<int> mem);

int main(void){
  ALLMem<int> mem(10);
  ALLMem<int>::address list1, lastnode;

  // create list #1 adding nodes to the end
  for (int i=1; i <= 8; i++) {
    ALLMem<int>::address newnode = mem.alloc();
    mem.setData(newnode,i*10);
    mem.setNext(newnode,NULLADDR);
    if (i==1) {
      list1 = newnode;
      mem.setPrev(newnode,NULLADDR);
    } else {
      mem.setPrev(newnode,lastnode);
      mem.setNext(lastnode,newnode);
    }
    lastnode = newnode;
  }

  ALLMem<int>::address ptr = list1;
  cout << "original list: ";
  while (ptr!=NULLADDR) {
    cout << mem.getData(ptr) << " ";
    ptr = mem.getNext(ptr);
  }
  cout << endl;

  cout << "<<< before deallocation >>>" << endl;
  cout << "list1 = " << list1 << endl;
  dumpMem(mem); cout << endl;
  
  ALLMem<int>::address deallocNode =  mem.getNext(mem.getNext(list1));
  cout << "dealloc node = " << mem.getNext(mem.getNext(list1));
  cout << " (value: " << mem.getData(mem.getNext(mem.getNext(list1))) << ")"<< endl;

  // now you must link the node you wish to deallocate out of list1
  // --- first set the previous node of the deleted node
  //     to point to the node after the deleted node
  mem.setNext(mem.getPrev(deallocNode),mem.getNext(deallocNode));
  // --- now set the previous field in the node after the deleted node
  //     to point to the node before the deleted node
  mem.setPrev(mem.getNext(deallocNode),mem.getPrev(deallocNode));
  // now delete the node
  mem.dealloc(deallocNode);
  
  cout << "<<< after deallocation >>>" << endl;
  cout << "list1 = " << list1 << endl;
  dumpMem(mem); cout << endl;

  ptr = list1;

  cout << "new list: ";
  while (ptr!=NULLADDR) {
    cout << mem.getData(ptr) << " ";
    ptr = mem.getNext(ptr);
  }
  cout << endl;
 }

///////////////////////////////////////
void dumpMem(ALLMem<int> mem) {
  cout << "freeptr = " << mem.getFreePtr() << endl;
  for (int i = 0; i < mem.getMemSize(); i++) {
    cout << "addr " << i << ": ";
    cout << mem.getPrev(i) << " ";
    cout << mem.getData(i) << " ";
    cout << mem.getNext(i) <<  endl;
  }
}

