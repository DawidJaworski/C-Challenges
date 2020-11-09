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

// global variables
pieces points = {
  {'p', 1},
  {'N', 3},
  {'B', 3},
  {'R', 5},
  {'Q', 9}
};

std::regex matchPos ("([a-h][1-8])|([a-h]|[1-8])");
std::regex matchCastling ("(O(-O){1,2})");
std::regex matchCapture ("([KQBNR]?(([a-h]|[1-8])|([a-h][1-8]))?x([a-h][1-8]))");
std::regex matchFigure ("[KQBNR]");

// method definitions
moves parseInput(std::string);
moves parseInput(std::string, bool);
std::pair<size_t, size_t> countPoints(moves);
std::pair<size_t, size_t> countPoints(moves, bool);
void printMove(move);
move removeCheckMark(move);
char reversePieceSearch(char[8][8], moves::iterator, moves::iterator, std::string);

// Main function
int main(){
  std::string sources[2] = {
    "source_1.txt",
    "source_2.txt"
  };

  for(auto source : sources){
    moves game = parseInput(source);
    std::pair<size_t, size_t> result = countPoints(game);
    printf("%s\nScore:\n\tW:%d - B:%d\n\n", source.data(), result.first, result.second);
  }

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
  std::smatch matchResult;

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

  // remove CHECK mark if present - it's irrelvant in this task
  std::transform(input.begin(), input.end(), input.begin(), removeCheckMark);

  for (moves::iterator it = input.begin(); it != input.end(); ++it){
    std::string currentMove = it->second;
    bool player = it->first == 'W';

    // apply castling to default board
    if(std::regex_search(currentMove, matchResult, matchCastling)){
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

    // count points if capture move
    if(std::regex_search(currentMove, matchResult, matchCapture)){
      std::string target = currentMove.substr(currentMove.length()-2);
      char capturedPiece = reversePieceSearch(chessboard, input.begin(), it, target);
      if(player)
        result.first += points[capturedPiece];
      else
        result.second += points[capturedPiece];

      if(verbose) printf("%c: \"%s\"\tcapture %s[%c] Score: %d - %d\n", it->first, currentMove.data(), target.data(), capturedPiece, result.first, result.second);
    }
  }
  
  return result;
}

char reversePieceSearch(char chessboard[8][8] , moves::iterator first, moves::iterator last, std::string target){
  char result ('#');
  int count = 1;

  // search for first occurence of target coordinates and save piece CHAR
  for(auto it = --last; it >= first; it--){
    if(it->second.find(target) != std::string::npos){
      std::smatch matchResult;
      if(std::regex_search(it->second, matchResult, matchFigure))
        result = it->second[0];
      else
        result = 'p';
      break;
    }
  }

  // if no result matched in moves list then get piece CHAR from actual chessboard
  if(result == '#')
    result = chessboard[target[0]-'a'][target[1]-'1'];

  return result;
}

move removeCheckMark(move input){
  if(input.second[input.second.length()-1] == CHECK) 
      input.second = input.second.substr(0, input.second.length()-1);
  return input;
}

void printMove(move input){
  printf("[%c: %s]\n", input.first, input.second.data());
}
