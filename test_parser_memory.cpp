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
    new BinaryOperationExpression(
        new NumberExpression(78), '-', new VariableExpression("windows"));
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

  //test FunctionDefinition
  std::vector<std::string>* fdParams = new std::vector<std::string>();
  params->push_back("bar");
  params->push_back("baz");
  Signature* fdSignature = new Signature("foo", fdParams);
  BinaryOperationExpression* body =
    new BinaryOperationExpression(
      new NumberExpression(42), '*', new VariableExpression("buffalo"));
  FunctionDefinition* functionDefinition =
    new FunctionDefinition(fdSignature, body);

  delete expression;
  delete numberExpression;
  delete variableExpression;
  delete binaryExpression;
  delete invocationExpression;
  delete signature;
  delete functionDefinition;

  return 0;
}
