#include <stdio.h>
#include <iostream>
#include <vector>

typedef unsigned int uint;

std::vector<std::vector<uint>> generatePiramid(uint rank);
void printPiramid(std::vector<std::vector<uint>> piramid);
void printPiramidRow(std::vector<uint>);

int main(){
  std::vector<std::vector<uint>> piramid;

  printf("[17042014] Challenge #153 [Easy] Pascal's Pyramid:\n");

  piramid = generatePiramid(14);
  printPiramid(piramid);

  return 0;
}

std::vector<std::vector<uint>> generatePiramid(uint rank){
  std::vector<std::vector<uint>> result = std::vector<std::vector<uint>>();
  std::vector<uint> row, lastRow;

  for (uint i = 0; i < rank; i++)
  {
    row = std::vector<uint>();

    for (uint index = 0; index <= i; index++)
    {
      if(index == 0 || index == i)
        row.push_back(1);
      else
        row.push_back(lastRow.at(index-1) + lastRow.at(index));
    }

    lastRow = std::vector<uint>(row);
    result.push_back(row);
  }
  
  return result;
}

void printPiramid(std::vector<std::vector<uint>> piramid){
  for (std::vector<std::vector<uint>>::iterator it = piramid.begin() ; it != piramid.end(); ++it) 
    printPiramidRow(*it);
}

void printPiramidRow(std::vector<uint> row){
  for (size_t i = 0; i < row.size(); i++) 
    printf("%d ", row.at(i));
  printf("\n");
}