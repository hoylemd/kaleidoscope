// this returns character values or the defined tokens
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>

enum Token {
  tok_eof = -1,
  // keywords
  tok_def = -2, tok_extern = -3,
  // functional
  tok_identifier = -4, tok_number = -5
};

static std::string currentIdentifier; // value of identifier token
static double numberValue;            // value of number token

static int getToken() {
  int lastCharacter = ' ';

  // skip whtespace
  while (isspace(lastCharacter)) {
    lastCharacter = getchar();
  }

  if (isalpha(lastCharacter)) {
    currentIdentifier = lastCharacter;
    while (isalnum((lastCharacter = getchar()))) {
      currentIdentifier += lastCharacter;
    }

    // check for keywords
    if (currentIdentifier == "def") return tok_def;
    if (currentIdentifier == "extern") return tok_extern;

    return tok_identifier;
  }

  return lastCharacter;
}

int main(void) {
  std::cout << getToken();
  return 0;
}
