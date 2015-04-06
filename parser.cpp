#include "parser.h"

BinaryOperationExpression::~BinaryOperationExpression () {
  delete leftOperand;
  delete rightOperand;
}

InvocationExpression::~InvocationExpression () {
  int i=0, size = arguments->size();
  for (i=size - 1; i >= 0; i -= 1) {
    delete (*arguments)[i];
  }
  delete arguments;
}
