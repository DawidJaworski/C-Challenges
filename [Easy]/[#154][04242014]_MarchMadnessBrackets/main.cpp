#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef unsigned int uint;
typedef std::pair<std::string, std::string> test;
typedef std::map<uint, test> dictionary;

std::string parseBrackets(std::string);
void printDictionary(dictionary);
void printTest(uint, test);
bool testMethod(test);
int checkInput(std::string);

int main(){
  printf("[4/24/2014] Challenge #154 [Easy] March Madness Brackets\n");

  dictionary dict, results;
  dict.insert(std::pair<uint, test>(0, test(
    "((your[drink {remember to}]) ovaltine)",
    "remember to drink your ovaltine")));
  dict.insert(std::pair<uint, test>(1, test(
    "[racket for {brackets (matching) is a} computers]",
    "matching brackets is a racket for computers")));
  dict.insert(std::pair<uint, test>(2, test(
    "[can {and it(it (mix) up ) } look silly]",
    "mix it up and it can look silly")));
  dict.insert(std::pair<uint, test>(3, test(
    "{years [four score] ago (and seven) our fathers}",
    "four score and seven years ago our fathers")));
  results = dictionary(dict);

  std::cout << "\nPattern:" << std::endl;
  printDictionary(dict);

  for (dictionary::iterator it = results.begin(); it != results.end(); ++it){
    it->second.second = parseBrackets((it->second).first);
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
  while(true){
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
    buffer = buffer.substr(1,buffer.length()-2);

    // remove space if present at the start of the string
    if(buffer.at(0) == ' ')
      buffer.erase(0, 1);

    // add space if not present at the end of string
    if(buffer.at(buffer.length()-1) != ' ')
      buffer.append(" ");

    // remove double spaces from strings inside
    matchPos = buffer.find("  ");
    if(matchPos != std::string::npos)
      buffer.erase(matchPos, 1); 
    
    // appent buffer to output
    output.append(buffer);
    
    counter++;
    if(counter >= 4)
      break;
  }

  return output;
}

bool testMethod(test pattern){
  return (bool) pattern.second.compare(parseBrackets(pattern.first));
}

int checkInput(std::string input){
  bool result = false;
  

  return 0;
}

void printDictionary(dictionary dict){
  for (dictionary::iterator it = dict.begin(); it != dict.end(); ++it)
    printTest(it->first, it->second);
}

void printTest(uint index, test input){
  printf("[%2d]\t%50s\t->\t%-50s\n", index, input.first.data(), input.second.data());
}