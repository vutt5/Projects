#ifndef SEQSTACK0285_H
#define SEQSTACK0285_H

namespace EGRE246 {
  class SeqStack{
  public:
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;
    SeqStack();
    void start();
    void advance();
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void removeCurrent();
    size_type size() const;
    bool isItem() const;
    value_type current() const;
    // new routines to SeqStack
    bool isEmpty() const;
    value_type top();
    value_type pop();
    void push(const value_type& entry);

  private:
    value_type data[CAPACITY];
    size_type used;
    size_type currentIndex;
  };
}
#endif
