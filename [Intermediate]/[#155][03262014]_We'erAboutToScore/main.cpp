#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <exception>

#define CAPTURE 'x'
#define CHECK '+'
#define KINGSLIDE "O-O"
#define QUEENSLIDE "O-O-O"
#define CHECKMATE "#"

typedef std::map<char, size_t> pieces;
typedef std::pair<char, size_t> piece;
typedef std::pair<std::string, std::string> move;
typedef std::vector<move> moves;

struct ex : std::exception{
  const char* descript() const noexcept { return "Could not read file!"; }
} err_readfail;

pieces points = {
  {'p', 1},
  {'N', 3},
  {'B', 3},
  {'R', 5},
  {'Q', 9}
};

moves parseInput(std::string);
moves parseInput(std::string, bool);
void printMove(move);

int main(){
  moves game = parseInput("source_1.txt");

  return 0;
}

moves parseInput(std::string source){
  return parseInput(source, false);
}
moves parseInput(std::string source, bool verbose){
  moves result = moves();
  std::fstream fs;

  fs.open(source, std::fstream::in);
  if(fs.rdstate() != std::ios_base::goodbit)
    throw (std::exception*)&err_readfail; //TODO add file name
  
  char line [64];
  std::string temp;
  size_t splitPos = 0;
  while(fs.rdstate() != std::ios_base::eofbit){
    fs.getline(line, 64);
    if(verbose) printf("Parsing:\t%-20s =>\t", line);
    temp = std::string(line);
    splitPos = temp.find_first_of(' ');

    result.push_back(move(temp.substr(0, --splitPos), temp.substr(++splitPos, temp.length()-splitPos)));
    if(verbose) printMove(result.back());
  }

  fs.close();

  return result;
}

void printMove(move input){
  printf("[%s - %s]\n", input.first.c_str(), input.second.c_str());
}
