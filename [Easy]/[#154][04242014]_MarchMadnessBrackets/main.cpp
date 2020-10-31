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

int main(){
  printf("[4/24/2014] Challenge #154 [Easy] March Madness Brackets\n");

  dictionary dict;
  dictionary results;
  dict.insert(std::pair<uint, test>(0, test(
    "((your[drink {remember to}]) ovaltine)",
    "remember to drink your ovaltine")));
  dict.insert(std::pair<uint, test>(1, test(
    "[racket for {brackets (matching) is a} computers]",
    "matching brackets is a  racket for computers")));
  dict.insert(std::pair<uint, test>(2, test(
    "[can {and it(it (mix) up ) } look silly]",
    "mix it up and it can look silly")));
  dict.insert(std::pair<uint, test>(3, test(
    "{years [four score] ago (and seven) our fathers}",
    "four score and seven years ago our fathers")));

  std::cout << "Pattern:" << std::endl;
  printDictionary(dict);

  std::cout << "Results:" << std::endl;
  printDictionary(results);

  return 0;
}

std::string parseBrackets(std::string input){
  std::string output;
  output = "bullshitsssdd";
  return output;
}

bool testMethod(test pattern){
  bool result = false;

  return result;
}

void printDictionary(dictionary dict){
  for (dictionary::iterator it = dict.begin(); it != dict.end(); ++it)
    printTest(it->first, it->second);
}

void printTest(uint index, test input){
  printf("[%d]\t", index);
  // printf() has problems with std::string. I have no negotiating skills for that
  std::cout << input.first << "\t->\t";
  std::cout << input.second << "\n";
}