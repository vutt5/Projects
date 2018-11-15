#ifndef ALLNODE_H
#define ALLNODE_H

namespace EGRE246 {
  const static int NULLADDR = -1;

  template <typename Item>
  class ALLNode {
  public:
    typedef Item value_type;

    ALLNode(const value_type& initData = value_type(),
	    int prevLink = NULLADDR, int nextLink = NULLADDR){
      data = initData; prev = prevLink; next = nextLink;
    }

    void setData(const value_type& newData) { data = newData; }
    void setPrevLink(int newLink) { prev = newLink; }
    void setNextLink(int newLink) { next = newLink; }

    value_type getData() const { return data; }
    const int getPrevLink() const { return prev; }
    const int getNextLink() const { return next; }

  private:
    value_type data;
    int prev;
    int next;
  };
}

#endif
