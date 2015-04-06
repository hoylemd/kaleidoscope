#include "parser.h"
#include "testing.h"
#include <cstdio>
#include <cstdlib>

result * test_expression() {
  Expression * expression = new Expression();
  delete expression;

  return new result("Expression");
}

result * test_numberExpression() {
  result * out = new result("NumberExpression");
  double probe = 12.234;
  NumberExpression * subject = new NumberExpression(probe);

  if (subject->numberValue != probe) {
    out->pass = false;
    out->comment = "number literal was stored incorectly";
    out->expected += doubleToString(probe);
    out->actual += doubleToString(subject->numberValue);
  }

  return out;
}

int main(void) {
  std::vector<result*>* results = new std::vector<result*>();
  int i = 0;

  results->push_back(test_expression());
  results->push_back(test_numberExpression());

  /*
  // test VariableExpression
  VariableExpression * variableExpression = new VariableExpression("variable");

  // test BinaryOperationExpression
  BinaryOperationExpression * binaryExpression =
    new BinaryOperationExpression(new Expression(), '+', new Expression());

  // test InvocationExpression
  std::vector<Expression*> * args =
    new std::vector<Expression*>(2, NULL);
  args->push_back(new Expression());
  args->push_back(new Expression());
  InvocationExpression * invocationExpression =
    new InvocationExpression("foo", args);

  delete expression;
  delete numberExpression;
  delete variableExpression;
  delete binaryExpression;
  delete invocationExpression;*/

  print_results(results);

  for (i = 0; i < results->size(); i += 1) {
    delete (*results)[i];
  }
  delete results;

  return 0;
}
