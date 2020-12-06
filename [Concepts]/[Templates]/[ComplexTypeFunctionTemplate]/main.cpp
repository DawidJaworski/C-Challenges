#include <iostream>

#include "typeDefs.h"

template <typename T>
T templatedFunction(T const&);

int main(){

  structType sT;
  sT.rational = 10.0f;
  sT.imaginary = 0.1f;

  classType cT;
  cT.rational = 10.0f;
  cT.imaginary = 0.1f;

  printf("structType:\t%.1f + %.1fi\n", sT.rational, sT.imaginary);
  printf("classType:\t%.1f + %.1fi\n", cT.rational, cT.imaginary);
  return 0;
}

template <typename T>
T templatedFunction(T const& input){
  return input;
}