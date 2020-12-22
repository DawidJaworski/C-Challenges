#include <iostream>
#include <typeinfo>
#include <array>

#include "disjonedSet_raw.hpp"

int main(){
  std::cout << "Disjoined Set example:" << std::endl;

  std::vector<char> data {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  disjoinedSet<char> ds(data.begin(), data.end());
  //disjoinedSet<char> ds(data);
  ds.print();

  

  return 0;
}

