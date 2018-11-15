class Rat {
 public:
  Rat();               // constructs 0/1
  Rat(int n_, int d_); // exits prog. with error message if d_==0

  int getN() const;   // getters
  int getD() const;
  void setN(int n_);  // setters
  void setD(int d_);  // exits prog. with error message if d_==0
  
  Rat norm() const;      // returns normalized number
  Rat reduce() const;    // reduces number to lowest terms
  int cmp(Rat &r) const; // returns -1,0, or 1

  Rat add(Rat& op2) const; // adds 2 numbers
  Rat sub(Rat& op2) const; // subtracts op2 from op1
  
  friend std::ostream& operator <<(std::ostream& os, Rat rat);
  
 private:
  int n,d;  // numerator, denominator
  int gcd(int a, int b) const; // greatest common divisor
  int lcm(int x, int y) const; // least common multiple
};
