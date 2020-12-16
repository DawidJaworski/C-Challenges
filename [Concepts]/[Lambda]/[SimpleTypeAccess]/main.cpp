#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> data {0,1,2,3,4,5,6,7,8,9};
  int target {11};

  std::cout << "target: " << target << std::endl;

  auto result = std::find_if(data.begin(), data.end(), [target](auto x){ return x == target; });

  std::cout << (result != data.end() ? "Target found" : "Target not found");
  
  return 0;
}