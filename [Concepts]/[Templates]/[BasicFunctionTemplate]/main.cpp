#include <iostream>
#include <stdio.h>

template <typename T>
T templatedFunction(T const&, T const&);

int main(){
  unsigned int uA=2, uB=5, uR;
  int iA=-2, iB= 5, iR;
  float fA=-0.2f, fB=0.5f, fR;
  double dA=-2.5, dB=5.5, dR;

  uR = templatedFunction(uA, uB);
  iR = templatedFunction(iA, iB);
  fR = templatedFunction(fA, fB);
  dR = templatedFunction(dA, dB);

  std::cout << "Result" << std::endl;
  std::printf("%u+%u=%u\n", uA, uB, uR);
  std::printf("%d+%d=%d\n", iA, iB, iR);
  std::printf("%.3f+%.3f=%f\n", fA, fB, fR);
  std::printf("%.3f+%.3f=%f\n", dA, dB, dR);
  return 0;
}

template <typename T>
T templatedFunction(T const& a, T const& b){
  T result;
  result = a + b;
  return result;
}