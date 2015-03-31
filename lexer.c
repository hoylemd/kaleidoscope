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

static int isWhiteSpace(char c) {
  switch (c) {
    case ' ':
    case '\t':
      return 1;
      break;
    default:
      return 0;
  }
}

static int getToken() {
  int lastCharacter = ' ';

  // skip whtespace
  while(isWhiteSpace(lastCharacter)) {
    lastCharacter = getchar();
  }

  return lastCharacter;
}

int main(void) {
  std::cout << getToken();
  return 0;
}
