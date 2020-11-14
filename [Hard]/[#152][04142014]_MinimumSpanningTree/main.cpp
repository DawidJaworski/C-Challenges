#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

typedef std::pair<int**, size_t> data;

data parseInput(std::string);
data parseInput(std::string, bool);

int** allocateMatrix(size_t, size_t);
void deallocateMatrix(int**, size_t, size_t);
void printMatrix(int**, size_t, size_t);

int main(){
  data input;
  input = parseInput("source.txt", true);

  printMatrix(input.first, input.second, input.second);

  deallocateMatrix(input.first, input.second, input.second);
  return 0;
}

data parseInput(std::string source){
  return parseInput(source, false);
}
data parseInput(std::string source, bool verbose){
  int **matrix;
  size_t rank = 0;
  std::fstream fs;

  fs.open(source, std::fstream::in);
  if(fs.rdstate() != std::ios_base::goodbit)
    throw -100;
  
  char c_line [64];
  std::string s_line;
  std::smatch match;
  std::regex regexp ("([0-9]+)");

  size_t row = 0, col = 0;
  while(fs.rdstate() != std::ios_base::eofbit){
    fs.getline(c_line, 64);
    if(verbose) printf("Parsing:\t%s\n", c_line);
    s_line = std::string(c_line);

    if(std::regex_match(s_line, regexp)){
      rank = std::atoi(s_line.data());
      matrix = allocateMatrix(rank, rank);
      continue;
    }

    if(row >= rank) break;

    col = 0;
    while (std::regex_search(s_line, match, std::regex("([-]{0,1}[0-9]+)")))
    {
      if(verbose) printf("Assigning value to [%d:%d] pos=%d \"%s\"\n", row, col, match.position(), s_line.data());
      matrix[row][col] = std::atoi(match.str().data());
      s_line = s_line.substr(match.position());

      col++;
      if(col >= rank) break;
    }
    
    row++;
  }

  fs.close();

  printf("Matrix rank: %d\n", rank);

  return data(matrix, rank);
}

int** allocateMatrix(size_t m, size_t n){
  int** result = new int*[m];
  for (size_t row = 0; row < m; row++)
    result[row] = new int[n];
  
  return result;
}
void deallocateMatrix(int** matrix, size_t m, size_t n){
 for (size_t row = 0; row < m; row++)
    delete[] matrix[row];
  delete[] matrix;

  return;
}
void printMatrix(int** matrix, size_t rows, size_t cols){
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < cols; col++)
      printf("%10d  ", matrix[row][col]);
    printf("\n");
  }
  return;
}

