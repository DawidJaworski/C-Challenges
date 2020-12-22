//#include <header/typeDefs.hpp>
//#include <header/functions.hpp>
#include "header/typeDefs.hpp"
#include "header/functions.hpp"

int main(){
  data input = parseInput("source.txt");
  printf("Input matrix:\n");
  printMatrix(input.first, input.second, input.second);
  getMinSpannigTree(input, true);
  return 0;
}
