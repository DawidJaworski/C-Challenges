#include <winnt.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

typedef std::map<std::string, std::string> dictionary;

typedef std::queue<std::pair<size_t, size_t>> coords;
typedef std::map<char,char> symbols;
typedef std::map<size_t, char> data;
typedef std::pair<size_t, size_t> coord;
typedef std::pair<size_t, char> record;

// Public methods
data findBrackets(std::string);
data findBrackets(std::string, bool);
coords matchBrackets(data);
coords matchBrackets(data, bool);
std::string reverseBrackets(std::string, coords);
std::string reverseBrackets(std::string, coords, bool);

std::string parse(std::pair<std::string, std::string>);
std::string parse(std::pair<std::string, std::string>, bool);

// Private supporting methods
char getMatchingBracket(char);
bool isClosingBracket(char);
void printDictionary(dictionary);

std::string _ERROR;
const dictionary dict = {
  {"((your[drink {remember to}]) ovaltine)","remember to drink your ovaltine"},
  {"[racket for {brackets (matching) is a} computers]","matching brackets is a racket for computers"},
  {"[can {and it(it (mix) up ) } look silly]","mix it up and it can look silly"},
  {"{years [four score] ago (and seven) our fathers}","four score and seven years ago our fathers"},
  {"((your[drink {remember to))) ovaltine)", "Mismatched bracket ) instead of } found"},
  {"[can {and it(it (mix) up ) look silly]", "Missing closing bracket"},
  {"[racket for brackets (matching) is a} computers]", "Missing opening bracket"}
};
static const char brackets [6] = {'(','[','{',')',']','}'};
static const symbols bracketMap = {{'(',')'},{'[',']'},{'{','}'}};

int main(){
  printf("[4/24/2014] Challenge #154 [Easy] March Madness Brackets\n\n");
  data foundBrackets;
  coords foundMatchingBrackets;

  for (auto input = dict.begin(); input != dict.end(); ++input)
  {
    std::cout << "=======================================" << std::endl;
    printf("Parsing:\t%s ...\n", input->first.data());
    foundBrackets = findBrackets(input->first);
    foundMatchingBrackets = matchBrackets(foundBrackets, true);


    if(_ERROR != "")
      printf("Error:\t\t%s\n", _ERROR.data());
    else
      printf("Result:\t\t%s\n", input->second.data());
  }

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

coords matchBrackets(data input){
  return matchBrackets(input, false);
}
coords matchBrackets(data input, bool verbose){
  coords results;
  bool exitLoop = false;
  record lastOperningBracket = record(-1, '#');
  record firstClosingBracket = record(-1, '#');
  _ERROR = "";

  data inputCopy = data(input);
  if(verbose) printf("[%6s]\tinputCopy size = %d\n", "Before", inputCopy.size());
  while(inputCopy.size() > 0){
    for (data::iterator it = inputCopy.begin(), itt = ++(inputCopy.begin()); it != --(inputCopy.end()); ++it, ++itt) {
      char matchingBracket = getMatchingBracket(it->second);
      char nextBracket = itt->second;
      if(verbose) printf("Checking: %2d: '%c'->'%c' == %2d: '%c'\n", it->first, it->second, matchingBracket, itt->first, itt->second);
      if(itt->second == matchingBracket){
        if(verbose) printf("Found match: %2d '%c' & %2d '%c'\n", it->first, it->second, itt->first, itt->second);
        results.push(coord(it->first, itt->first));
        inputCopy.erase(itt);
        inputCopy.erase(it);
        break;
      }else if(isClosingBracket(itt->second)){
        char err [50];
        sprintf(err, "Mismatched bracket %c instead of %c found at %d", itt->second, matchingBracket, itt->first);
        _ERROR = std::string(err);
        exitLoop = true;
        break;
      }
    }
    if(exitLoop) break;
  }

  if(verbose) printf("results size = %d\n", results.size());

  return results;
}

std::string reverseBrackets(std::string input, coords params){
  return reverseBrackets(input, params, false);
}
std::string reverseBrackets(std::string input, coords params, bool verbose){
  std::string result;



  return result;
}

std::string parse(std::pair<std::string, std::string> input){
  return parse(input, false);
}
std::string parse(std::pair<std::string, std::string> input, bool verbose){
  return "";
}

char getMatchingBracket(char bracket){
    char result = '#';
    symbols::const_iterator it = bracketMap.find(bracket);
    if(it != bracketMap.end())
      result = it->second;
    return result;
}

bool isClosingBracket(char bracket){
  for(size_t index = 3; index < 6; index++)
    if(bracket == brackets[index])
      return true;
  return false;
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