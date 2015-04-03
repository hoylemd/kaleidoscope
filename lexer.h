// this returns character values or the defined tokens
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
  Token(): code(tok_eof), value("") {}
};

Token getToken();
