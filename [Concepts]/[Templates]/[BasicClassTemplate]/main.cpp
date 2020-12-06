#include <stdio.h>
#include <iostream>

template <typename T>
class templatedClass{
  private:
    T counter = 0;
  public:
    T getCounter();
    void incrementCounter();
    void resetCounter();
};

int main(){
  templatedClass<unsigned int> uT;
  templatedClass<int> iT;
  templatedClass<float> fT;
  templatedClass<double> dT;

  printf("counter value: uT=%u\tiT=%d\tfT=%.1f\tdT=%.1f\n", uT.getCounter(), iT.getCounter(), fT.getCounter(), dT.getCounter());

  uT.incrementCounter();
  iT.incrementCounter();
  fT.incrementCounter();
  dT.incrementCounter();

  printf("counter value: uT=%u\tiT=%d\tfT=%.1f\tdT=%.1f\n", uT.getCounter(), iT.getCounter(), fT.getCounter(), dT.getCounter());

  uT.resetCounter();
  iT.resetCounter();
  fT.resetCounter();
  dT.resetCounter();

  printf("counter value: uT=%u\tiT=%d\tfT=%.1f\tdT=%.1f\n", uT.getCounter(), iT.getCounter(), fT.getCounter(), dT.getCounter());

  return 0;
}

template <typename T>
T templatedClass<T>::getCounter(){
  return counter;
}

template <typename T>
void templatedClass<T>::incrementCounter(){
  counter++;
}

template <typename T>
void templatedClass<T>::resetCounter(){
  counter = 0;
}

