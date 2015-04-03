#include "lexer.h"

Token getToken() {
  int lastCharacter = ' ', code = 0;

  std::string currentToken; // value of identifier token

  // skip whtespace
  while (isspace(lastCharacter)) {
    lastCharacter = getchar();
  }

  currentToken = lastCharacter;
  // parse identifiers / keywords
  if (isalpha(lastCharacter)) {
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
  else if (isdigit(lastCharacter)) {
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

  // parse comments
  else if (lastCharacter == '#') {
    do lastCharacter = getchar();
    while (lastCharacter != EOF &&
        lastCharacter != '\n' &&
        lastCharacter != '\r');

    if (lastCharacter != EOF) {
      return getToken();
    }
  }

  // parse EOF
  else if (lastCharacter == EOF) {
    currentToken = "";
    code = tok_eof;
  }

  // parse extras
  else {
   code = lastCharacter;
  }

  return new Token(code, currentToken);
}

