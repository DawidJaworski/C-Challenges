#include <iostream>

#include "typeDefs.h"

template <typename T>
class templatedClass {
  private:
    T value;
  public:
    T getValue();
    void setValue(T const&);
};

int main(){

  structType sT;
  sT.rational = 10.0f;
  sT.imaginary = 0.1f;

  classType cT;
  cT.rational = 10.0f;
  cT.imaginary = 0.1f;

  templatedClass<structType> sC;
  templatedClass<classType> cC;

  sC.setValue(sT);
  cC.setValue(cT);

  printf("structType:\t%.1f + %.1fi\n", sC.getValue().rational, sC.getValue().imaginary);
  printf("classType:\t%.1f + %.1fi\n", cC.getValue().rational, cC.getValue().imaginary);
  
  return 0;
}

template <typename T>
T templatedClass<T>::getValue(){
  return value;
}

template <typename T>
void templatedClass<T>::setValue(T const& input){
   value = input;
}