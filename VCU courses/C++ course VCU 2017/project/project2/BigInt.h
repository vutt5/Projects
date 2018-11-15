#ifndef BigInt_h
#define BigInt_h
namespace EGRE246 {

  class BigInt{
  public:
    static const int MAX_DIGITS = 100;
    enum class Sign {NEG,ZERO,POS};

    BigInt();            // initializes to 0
    BigInt(long long n); // exits program with error if too large
    BigInt(std::string s);    // exits program with error if too large
    int getLen() const;

    int cmp(BigInt& op2) const; // returns -1, 0, or 1

    BigInt abs() const; // absolute value
    BigInt add(BigInt& op2) const;
    BigInt sub(BigInt& op2) const;
    BigInt mul(BigInt& op2) const; // optional
    BigInt div(BigInt& op2) const; // optional
    BigInt mod(BigInt& op2) const; // returns remainder; optional


    friend std::ostream& operator <<(std::ostream& os, const BigInt& n);

  private:
    int digits[MAX_DIGITS];
    Sign sign;
    int len;
  };

}
#endif

bool extra_credit(); // return true if you do extra credit, false
                     // otherwise
