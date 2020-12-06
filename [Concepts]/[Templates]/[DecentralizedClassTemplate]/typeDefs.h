#ifndef TYPEDEFS_H
#define TYPEDEFS_H

struct structType {
  double rational;
  double imaginary;
  structType(double r = 0.0f, double i = 0.0f) : rational(r), imaginary(i) {};
};

class classType{
  public:
    double rational;
    double imaginary;
    classType(double r = 0.0f, double i = 0.0f) : rational(r), imaginary(i) {};
};

#endif