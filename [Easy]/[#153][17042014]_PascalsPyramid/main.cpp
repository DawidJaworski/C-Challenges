#include <stdio.h>
#include <vector>

std::vector<std::vector<unsigned int>> generatePiramid(unsigned int rank);
void printPiramid(std::vector<std::vector<unsigned int>> piramid);
void printPiramidRow(std::vector<unsigned int>);

int main(){
  std::vector<std::vector<unsigned int>> piramid;
  unsigned int N = 5;

  printf("[17042014] Challenge #153 [Easy] Pascal's Pyramid:\n");

  piramid = generatePiramid(N);
  printPiramid(piramid);

  return 0;
}

std::vector<std::vector<unsigned int>> generatePiramid(unsigned int rank){
  std::vector<std::vector<unsigned int>> result = std::vector<std::vector<unsigned int>>();
  printf("Generating piramid...\n");
  // first row is always [1]
  result.push_back(std::vector<unsigned int>(1));

  // consecutive n=0+ rows has n+3 elements
  for (unsigned int n = 0; n <= rank; n++)
  {
    std::vector<unsigned int> row = std::vector<unsigned int>();
    for (unsigned int rowRank = 0; rowRank < n+3; rowRank++)
    {
      row.push_back(rowRank);
    }
    
    result.push_back(row);
  }
  printf("Finished generating piramid.\n");
  return std::vector<std::vector<unsigned int>>();
}

void printPiramid(std::vector<std::vector<unsigned int>> piramid){
  for (std::vector<std::vector<unsigned int>>::iterator it = piramid.begin() ; it != piramid.end(); ++it){
    printPiramidRow(*it);
  }
}

void printPiramidRow(std::vector<unsigned int> row){
  for (std::vector<unsigned int>::iterator it = row.begin(); it != row.end(); ++it){
    printf("%d ", *it);
  }
  printf("\n");
}