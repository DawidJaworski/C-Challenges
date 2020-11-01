#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>



typedef unsigned int uint;
typedef std::map<std::string, std::string> dictionary;
typedef std::map<char,char> symbols;
typedef std::map<size_t, size_t> coords;
typedef std::map<size_t, char> data;
typedef std::pair<size_t, char> record;

data debugMethod(std::string);
data debugMethod(std::string, bool);
void printDictionary(dictionary);

std::string _ERROR;
dictionary dict = {
  {"((your[drink {remember to}]) ovaltine)","remember to drink your ovaltine"},
  {"[racket for {brackets (matching) is a} computers]","matching brackets is a racket for computers"},
  {"[can {and it(it (mix) up ) } look silly]","mix it up and it can look silly"},
  {"{years [four score] ago (and seven) our fathers}","four score and seven years ago our fathers"}
};
char brackets [6] = {'(','[','{',')',']','}'};

int main(){
  printf("[4/24/2014] Challenge #154 [Easy] March Madness Brackets\n");
  data output;

  output = debugMethod(dict.begin()->first, true);
  printf("Error:\t%s\n", _ERROR.data());

  return 0;
}

data debugMethod(std::string input){
  return debugMethod(input, false);
}

data debugMethod(std::string input, bool verbose){
  data results;
  size_t matchPos = 0;

  while(matchPos = input.find_first_of(brackets, matchPos) != std::string::npos) {
    printf("%d\n", matchPos);
    results.insert(record(matchPos, input[matchPos++]));
  }
  
  if(verbose){
    printf("[3%d]\t%s\n", input.length()-1, input.data());
    for (data::iterator it = results.begin(); it != results.end(); ++it) 
      printf("[%d]\t\'%c\'\n", it->first, it->second);
  }

  return results;
}

void printDictionary(dictionary input){
  uint maxLength = 0;
  for (dictionary::iterator it = input.begin(); it != input.end(); ++it){
    if(it->first.length() > maxLength)
      maxLength = it->first.length();
    if(it->second.length() > maxLength)
      maxLength = it->second.length();
  }

  for (dictionary::iterator it = input.begin(); it != input.end(); ++it)
    printf("%*s => %-*s\n", maxLength, it->first.data(), maxLength, it->second.data());
}