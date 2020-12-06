#include <iostream>

#include "typeDefs.h"
#include "templatedClass.hpp"

int main(){
  templatedClass<structType> sC;
  templatedClass<classType> cC;

  sC.setValue(structType(10.5f, 0.1f));
  cC.setValue(classType(10.5f, 0.1f));

  printf("structType:\t%.1f + %.1fi\n", sC.getValue().rational, sC.getValue().imaginary);
  printf("classType:\t%.1f + %.1fi\n", cC.getValue().rational, cC.getValue().imaginary);

  return 0;
}