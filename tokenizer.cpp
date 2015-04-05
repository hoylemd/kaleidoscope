#include "lexer.h"

int main(void) {
  Token tok;

  while ((tok = getToken()).code != tok_eof) {
    std::cout << "token code " << tok.code << ", literally: " << tok.value;
    std::cout << std::endl;
  }

  return 0;
}
