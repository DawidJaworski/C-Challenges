#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<std::pair<int, double>> data {{0,-5.0},{1,-1.0},{2,1.0},{3,5.0}};
  double target {1.0};

  std::cout << "target: " << target << std::endl;

  auto n = data.begin();

  auto result = std::find_if(data.begin(), data.end(),  
                            [target](auto x){ return x.second == target; });

  std::cout << (result != data.end() ? "Target found" : "Target not found");
  
  return 0;
}