#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef std::map<std::string, std::string> dictionary;

typedef std::map<size_t, size_t> coords;
typedef std::map<char,char> symbols;
typedef std::map<size_t, char> data;
typedef std::pair<size_t, char> record;

data findBrackets(std::string);
data findBrackets(std::string, bool);
coords checkErrors(data);
char getMatchingBracket(char);
void printDictionary(dictionary);

std::string _ERROR;
dictionary dict = {
  {"((your[drink {remember to}]) ovaltine)","remember to drink your ovaltine"},
  {"[racket for {brackets (matching) is a} computers]","matching brackets is a racket for computers"},
  {"[can {and it(it (mix) up ) } look silly]","mix it up and it can look silly"},
  {"{years [four score] ago (and seven) our fathers}","four score and seven years ago our fathers"}
};
char brackets [6] = {'(','[','{',')',']','}'};
//symbols bracketMap = {{'(',')'},{')','('},{'[',']'},{']','['},{'{','}'},{'}','{'}};
symbols bracketMap = {{'(',')'},{'[',']'},{'{','}'}};

int main(){
  printf("[4/24/2014] Challenge #154 [Easy] March Madness Brackets\n\n");
  data output;

  output = findBrackets(dict.begin()->first, true);



  printf("Error:\t%s\n", _ERROR.data());

  return 0;
}

data findBrackets(std::string input){
  return findBrackets(input, false);
}
data findBrackets(std::string input, bool verbose){
  data results;
  size_t match = 0;

  match = input.find_first_of(brackets);
  while(match != std::string::npos) {
    results.insert(record(match, input[match]));
    match = input.find_first_of(brackets, ++match);
  }
  
  if(verbose){
    printf("[%3d]\t%s\n", input.length()-1, input.data());
    for (data::iterator it = results.begin(); it != results.end(); ++it) 
      printf("> [%3d]\t\'%c\'\n", it->first, it->second);
  }

  return results;
}

coords checkErrors(data input){
  coords matches;
  data inputCopy = data(input);
  while(inputCopy.size() > 0){
    for (data::iterator it = inputCopy.begin(); it != inputCopy.end(); ++it) {
      if(++it->second == getMatchingBracket(it->second)){
        matches.insert(record(it->first, (++it)->first));
        inputCopy.erase(it, ++it);
        break;
      }
      
      
    }
  }
  
  return matches;
}

char getMatchingBracket(char bracket){
    return bracketMap.find(bracket)->second;
}

void printDictionary(dictionary input){
  size_t maxLength = 0;
  for (dictionary::iterator it = input.begin(); it != input.end(); ++it){
    if(it->first.length() > maxLength)
      maxLength = it->first.length();
    if(it->second.length() > maxLength)
      maxLength = it->second.length();
  }

  for (dictionary::iterator it = input.begin(); it != input.end(); ++it)
    printf("%*s => %-*s\n", maxLength, it->first.data(), maxLength, it->second.data());
}