#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

#define CAPTURE 'x'
#define CHECK '+'
#define KINGSLIDE "O-O"
#define QUEENSLIDE "O-O-O"
#define CHECKMATE "#"

typedef std::map<char, size_t> pieces;
typedef std::pair<char, size_t> piece;
typedef std::pair<char, std::string> move;
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
std::pair<size_t, size_t> countPoints(moves);
std::pair<size_t, size_t> countPoints(moves, bool);

void printMove(move);

int main(){
  moves game = parseInput("source_1.txt", false);

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
    if(verbose) printf("Parsing:\t%s\n", line);
    temp = std::string(line);
    splitPos = temp.find_first_of(' ');
    
    result.push_back(move('W', temp.substr(0, splitPos)));
    if(verbose) printMove(result.back());
    result.push_back(move('B', temp.substr(++splitPos, temp.length()-splitPos)));
    if(verbose) printMove(result.back());
  }

  fs.close();

  return result;
}

std::pair<size_t, size_t> countPoints(moves input){
  return countPoints(input, false);
}
std::pair<size_t, size_t> countPoints(moves input, bool verbose){
  std::pair<size_t, size_t> result = std::pair<size_t, size_t>(0, 0); 
  char chessboard [8][8] = {
    {'R','N','B','Q','K','B','N','R'},
    {'p','p','p','p','p','p','p','p'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'p','p','p','p','p','p','p','p'},
    {'R','N','B','Q','K','B','N','R'}
  };

  for (moves::iterator it = input.begin(); it != input.end(); ++it)
  {
    std::string currentMove = it->second;
    
    char pieceType;
    std::pair<size_t, size_t> destination = {9, 9};

    for (size_t i = currentMove.length()-1; i >= 0; i--)
    {



    }
  }
  

  return result;
}


void printMove(move input){
  printf("[%c: %s]\n", input.first, input.second.c_str());
}
