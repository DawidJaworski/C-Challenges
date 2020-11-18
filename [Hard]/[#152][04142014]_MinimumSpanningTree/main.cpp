#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

typedef std::pair<int**, size_t> data;
struct edge {
  char v;
  char u;
  int weight;
};

// function declarations

data parseInput(std::string);
data parseInput(std::string, bool);

data getMinSpannigTree(data);
data getMinSpannigTree(data, bool);

int** allocateMatrix(size_t, size_t);
void deallocateMatrix(int**, size_t, size_t);
bool compareEdges(edge, edge);
void printMatrix(int**, size_t, size_t);
void printEdges(std::vector<edge>);

// main function

int main(){
  data input = parseInput("source.txt");
  printf("Input matrix:\n");
  printMatrix(input.first, input.second, input.second);

  getMinSpannigTree(input, true);

  deallocateMatrix(input.first, input.second, input.second);
  
  return 0;
}

// function definitions

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
      s_line.erase(0, match.length()+1);

      col++;
      if(col >= rank) break;
    }
    
    row++;
  }

  fs.close();

  printf("Matrix rank: %d\n", rank);

  return data(matrix, rank);
}

data getMinSpannigTree(data input){
  return getMinSpannigTree(input, false);
}
data getMinSpannigTree(data input, bool verbose){
  data result;

  std::vector<edge> minSpanningTree;
  std::vector<edge> edges;

  // build vector of edges from matrix 
  for (size_t x = 0; x < input.second; x++)
  {
    for (size_t y = 1; y < input.second - 1; y++)
    {
      if(y <= x) continue;
      int distance = input.first[x][y];
      if(distance > 0){
        edge E;
        E.u = 'A' + x;
        E.v = 'A' + y;
        E.weight = distance;

        edges.push_back(E);
      }
    }
  }
  
  std::sort(edges.begin(), edges.end(), compareEdges);

  if(verbose){
    printf("List of valid edges:\n");
    printEdges(edges);
    printf("Building minimum spanning tree...\n");
  }
  // build minimum spanning tree



  return result;
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
bool compareEdges(edge A, edge B){
  return A.weight < B.weight;
}
void printMatrix(int** matrix, size_t rows, size_t cols){
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < cols; col++)
      printf("%4d  ", matrix[row][col]);
    printf("\n");
  }
  return;
}
void printEdges(std::vector<edge> edges){
  for(auto e : edges){
    printf("|%c%c|=%d\n", e.u, e.v, e.weight);
  }
}

