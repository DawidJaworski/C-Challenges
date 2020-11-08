#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>
#include <regex>

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
  std::pair<size_t, size_t> result = countPoints(game);

  return 0;
}

moves parseInput(std::string source){
  return parseInput(source, false);
}
moves parseInput(std::string source, bool verbose){
  moves result;
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
  std::pair<size_t, size_t> result = {0, 0}; //Score White : Score Black
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

  std::regex matchPos ("([a-h][1-8])|([a-h]|[1-8])");
  std::regex matchCastling ("(O(-O){1,2})");
  std::regex matchCapture ("([KQBNR]?(([a-h]|[1-8])|([a-h][1-8]))?x([a-h][1-8]))");
  std::smatch matchResult;
  for (moves::iterator it = input.begin(); it != input.end(); ++it)
  {
    std::string currentMove = it->second;
    std::pair<size_t, size_t> destination = {9, 9};
    bool player = it->first == 'W' ? true : false;
    char pieceType;
    
    printf("%c: \"%s\"\n", it->first ,currentMove.data());
    // remove CHECK mark if present
    if(currentMove[currentMove.length()-1] == CHECK) 
      currentMove = currentMove.substr(0, currentMove.length()-1);
    
    // apply castlig to default board
    bool state = std::regex_search(currentMove, matchResult, matchCastling);
    if(state){
      size_t row = player ? 0 : 7;
      if(currentMove == QUEENSLIDE){
        chessboard[row][0] = ' ';
        chessboard[row][1] = ' ';
        chessboard[row][2] = 'K';
        chessboard[row][3] = 'R';
        chessboard[row][4] = ' ';
      }
      if(currentMove == KINGSLIDE){
        chessboard[row][4] = ' ';
        chessboard[row][5] = 'R';
        chessboard[row][6] = 'K';
        chessboard[row][7] = ' ';
      }
      continue;
    }

    state = std::regex_search(currentMove, matchResult, matchPos);
    if(state){
      
    }
    state = std::regex_search(currentMove, matchResult, matchPos);

    if(std::find(currentMove.begin(), currentMove.end(), 'x') != currentMove.end()){
      
      if(player) 
        result.first += 1;
      else 
        result.second += 1;
    }
  }
  
  return result;
}


void printMove(move input){
  printf("[%c: %s]\n", input.first, input.second.data());
}
