#include <iostream>
#include <typeinfo>

#include "disjoinedSet.hpp"

int main(){
  std::cout << "Disjoined Set example:" << std::endl;

  disjoinedSet<int> ds;
  ds.makeSet(1);
  ds.makeSet(2);
  ds.makeSet(3);
  ds.makeSet(4);
  ds.makeSet(5);

  std::cout << "No. sets: " << ds.getCount() << std::endl;

  int target[2] {3,100};
  std::for_each(std::begin(target), std::end(target), [&ds, target](auto x){
    std::cout << "Find target set containing: " << x << std::endl;
    std::cout << (ds.find(x) != ds.End() ? "Target found" : "Target not found") << std::endl;
  });

  

  return 0;
}

