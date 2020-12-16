#include <iostream>

#include "disjoinedSet.hpp"

int main(){

  std::cout << "Disjoined Set:" << std::endl;

  disjoinedSet<int> ds;
  ds.makeSet(1);
  ds.makeSet(2);
  ds.makeSet(3);
  ds.makeSet(4);
  ds.makeSet(5);

  std::cout << "No. sets: " << ds.getCount() << std::endl;

  ds.find(3);
  return 0;
}

