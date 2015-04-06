#include "parser.h"

int main(void) {
  // test Expression
  Expression * expression = new Expression();

  // test NumberExpression
  NumberExpression * numberExpression = new NumberExpression(12.567);

  // test VariableExpression
  VariableExpression * variableExpression = new VariableExpression("variable");

  // test BinaryOperationExpression
  BinaryOperationExpression * binaryExpression =
    new BinaryOperationExpression(new Expression(), '+', new Expression());

  // test InvocationExpression
  std::vector<Expression*> * args = new std::vector<Expression*>();
  args->push_back(new Expression());
  args->push_back(new Expression());
  InvocationExpression * invocationExpression =
    new InvocationExpression("foo", args);

  // test Signature
  std::vector<std::string> * params = new std::vector<std::string>();
  params->push_back("bar");
  params->push_back("baz");
  Signature * signature = new Signature("foo", params);

  delete expression;
  delete numberExpression;
  delete variableExpression;
  delete binaryExpression;
  delete invocationExpression;
  delete signature;

  return 0;
}
