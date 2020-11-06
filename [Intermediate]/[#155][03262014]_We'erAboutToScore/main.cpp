#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

#define CAPTURE 'x'
#define CHECK '+'
#define KINGSLIDE "O-O"
#define QUEENSLIDE "O-O-O"
#define CHECKMATE "#"

typedef std::map<char, size_t> pieces;
typedef std::pair<char, size_t> piece;
typedef std::pair<std::string, std::string> move;
typedef std::vector<move> moves;

pieces points = {
  {'p', 1},
  {'N', 3},
  {'B', 3},
  {'R', 5},
  {'Q', 9}
};

moves parseInput(std::string);
moves parseInput(std::string, bool);

int main(){




  return 0;
}

moves parseInput(std::string source){
  return parseInput(source, false);
}
moves parseInput(std::string source, bool verbose){
  moves result = moves();

  

  return result;
}

