#include "parser.h"
#include "testing.h"

result * test_expression() {
  // test Expression
  Expression * expression = new Expression();
  delete expression;

  return new result(true, "Expression", "allocation and delete successful");
}

int main(void) {
  std::vector<result*>* results = new std::vector<result*>();
  int i = 0;

  results->push_back(test_expression());

 /* // test NumberExpression
  NumberExpression * numberExpression = new NumberExpression(12.567);

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
