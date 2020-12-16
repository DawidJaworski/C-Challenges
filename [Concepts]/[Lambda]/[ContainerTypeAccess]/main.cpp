#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>
#include <typeinfo>

int main(){
  std::vector<std::forward_list<int>> containers {{0,1,2},{10,11,12},{20,21,22},{30,31,32}};

  int target {21};

  std::cout << "target: " << target << std::endl;

  /* std::for_each(std::begin(containers), std::end(containers), [target](auto x){ 
    std::cout << typeid(x).name() << "\t";
    std::cout << (std::find(std::begin(x), std::end(x), target) != std::end(x)) << std::endl;}); */

  auto result = std::find_if(std::begin(containers), std::end(containers), [target](auto x){ return (std::find(std::begin(x), std::end(x), target) != std::end(x)); });
  std::cout << typeid(result).name() << std::endl;
  std::cout << (result != containers.end() ? "Target found" : "Target not found");
  
  return 0;
}