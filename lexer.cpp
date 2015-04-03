// this returns character values or the defined tokens
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>

enum TokenValues {
  tok_eof = -1,
  // keywords
  tok_def = -2, tok_extern = -3,
  // functional
  tok_identifier = -4, tok_number = -5
};

class Token {
public:
  int code;
  std::string value;
  Token(int c, std::string v) : code(c), value(v) {}
  Token(Token *t) : code(t->code), value(t->value) {}
};

static Token getToken() {
  int lastCharacter = ' ', code = 0;

  std::string currentToken; // value of identifier token

  // skip whtespace
  while (isspace(lastCharacter)) {
    lastCharacter = getchar();
  }

  // parse identifiers / keywords
  if (isalpha(lastCharacter)) {
    currentToken = lastCharacter;
    while (isalnum(lastCharacter = getchar())) {
      currentToken += lastCharacter;
    }

    // check for keywords
    if(currentToken == "def") {
      code = tok_def;
    } else if (currentToken == "extern") {
      code = tok_extern;
    } else {
      code = tok_identifier;
    }
  }

  // parse numbers
  if (isdigit(lastCharacter)) {
    currentToken = lastCharacter;
    while (isdigit(lastCharacter = getchar())) {
      currentToken += lastCharacter;
    }

    if (lastCharacter == '.') {
    currentToken += lastCharacter;
      while (isdigit(lastCharacter = getchar())) {
        currentToken += lastCharacter;
      }
    }

    code = tok_number;
  }

  return new Token(code, currentToken);
}

int main(void) {
  Token tok =  getToken();

  std::cout << "token code " << tok.code << ", literally: " << tok.value;

  return 0;
}
