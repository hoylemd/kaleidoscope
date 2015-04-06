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

Signature::Signature(const std::string n, std::vector<std::string>* p) :
  name(n), parameters(p) {
  parameterCount = parameters->size();
}

Signature::~Signature() {
  delete parameters;
}
