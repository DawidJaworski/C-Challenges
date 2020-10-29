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

  for (unsigned int n = 0; n <= rank; n++)
  {
    std::vector<unsigned int> row;
    std::vector<unsigned int> lastRow;

    for (unsigned int index = 0; index < n+2; index++)
    {
      row = std::vector<unsigned int>();
      printf("n: %d\tindex: %d \n",index, n);
      if(index == 0 || index == n) {
        row.push_back(1);
      } 
      else{
        printf("%d", lastRow.size());
        unsigned int A = result.back().at(index - 1);
        unsigned int B = result.back().at(index);

        row.push_back(A + B);
      }
    }
    
    result.push_back(row);
    printPiramidRow(row);
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
  for (size_t i = 0; i < row.size(); i++)
  {
    printf("%d ", row.at(i));
  }
  printf("\n");
}