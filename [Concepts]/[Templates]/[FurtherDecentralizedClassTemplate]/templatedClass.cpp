#include "typeDefs.h"
#include "templatedClass.hpp"

template <typename T>
T templatedClass<T>::getValue(){
  return value;
}

template <typename T>
void templatedClass<T>::setValue(T const& input){
   value = input;
}