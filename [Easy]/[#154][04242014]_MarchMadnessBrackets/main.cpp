#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef unsigned int uint;
typedef std::map<std::string, std::string> dictionary;

std::string parseBrackets(std::string);

void printDictionary(dictionary);

dictionary dict = {
  {"((your[drink {remember to}]) ovaltine)","remember to drink your ovaltine"},
  {"[racket for {brackets (matching) is a} computers]","matching brackets is a racket for computers"},
  {"[can {and it(it (mix) up ) } look silly]","mix it up and it can look silly"},
  {"{years [four score] ago (and seven) our fathers}","four score and seven years ago our fathers"}
};

int main(){
  printf("[4/24/2014] Challenge #154 [Easy] March Madness Brackets\n");
  dictionary results= dictionary(dict);

  std::cout << "\nPattern:" << std::endl;
  printDictionary(dict);

  for (dictionary::iterator it = results.begin(); it != results.end(); ++it){
    it->second = parseBrackets(it->first);
  }

  std::cout << "\nResults:" << std::endl;
  printDictionary(results);

  return 0;
}

std::string parseBrackets(std::string input){
  std::string output,buffer;
  std::string inputBuffer = input;
  std::map<char,char> brackets = {
    {'(',')'},
    {'[',']'},
    {'{','}'}
  };
  std::map<char,char>::iterator it;
  size_t openingBracket = input.length();
  size_t closingBracket = input.length();
  size_t matchPos = 0;

  uint counter = 0;
  while(inputBuffer.length() >= 0){
    // find last opening bracket from left
    matchPos = inputBuffer.find_last_of({'(','[','{'}, openingBracket);
    if(matchPos == std::string::npos){
      break;
    }
    openingBracket = matchPos;
  
    // get matching closing bracket
    it = brackets.find(input[matchPos]);
    if(it == brackets.end())
      continue;

    // search for nearest matching closing bracket to right
    matchPos = inputBuffer.find_first_of(it->second, openingBracket);
    if(matchPos == std::string::npos){
      break;
    }
    closingBracket = matchPos;
    
    // extract matched brackets and remove it from input buffer
    buffer = inputBuffer.substr(openingBracket, closingBracket+1-openingBracket);
    inputBuffer = inputBuffer.erase(openingBracket, closingBracket+1-openingBracket);

    // dispose enclosing brackets
    buffer = buffer.substr(1, buffer.length()-2);

    // remove space if present at the start of the string
    if(buffer.at(0) == ' ')
      buffer.erase(0, 1);

    // add space if not present at the end of string
    if(buffer.at(buffer.length()-1) != ' ')
      buffer.append(" ");

    // remove double spaces from strings inside
    for (size_t index = buffer.length()-1; index > 0 ; index--)
    {
      if(buffer[index] == ' ' && buffer[index+1] == ' ')
        buffer.erase(index, 1);
    }

    // append buffer to output
    output.append(buffer);
  }

  return output;
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