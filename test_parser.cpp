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

  delete subject;

  return out;
}

result * test_variableExpression() {
  result * out = new result("VariableExpression");
  std::string probe = "foo";
  VariableExpression * subject = new VariableExpression(probe);

  if (subject->name != probe) {
    out->pass = false;
    out->comment = "name was stored incorectly";
    out->expected += probe;
    out->actual += subject->name;
  }

  delete subject;
  return out;
}

result * test_binaryExpression() {
  result * out = new result("BinaryOperatorExpression");
  char op = '+';
  NumberExpression * left = new NumberExpression(4),
                   * right = new NumberExpression(2.5);
  BinaryOperationExpression * subject =
    new BinaryOperationExpression(left, op, right);

  if (subject->leftOperand != left) {
    out->pass = false;
    out->comment = "left operand was stored incorectly";
    out->expected += pointerToString(left);
    out->actual += pointerToString(subject->leftOperand);
  }

  if (out->pass && subject->operatorChar != op) {
    out->pass = false;
    out->comment = "operator was stored incorectly";
    out->expected += op;
    out->actual += subject->operatorChar;
  }

  if (out->pass && subject->rightOperand != right) {
    out->pass = false;
    out->comment = "right operand was stored incorectly";
    out->expected += pointerToString(right);
    out->actual += pointerToString(subject->rightOperand);
  }

  delete subject;
  return out;
}

result * test_invocationExpression() {
  result * out = new result("InvocationExpression");
  std::string callee = "add";
  NumberExpression * firstArg = new NumberExpression(2.5),
                   * secondArg = new NumberExpression(4);
  std::vector<Expression*>* args = new std::vector<Expression*>();
  args->push_back(firstArg);
  args->push_back(secondArg);
  InvocationExpression * subject = new InvocationExpression(callee, args);

  if (subject->callee != callee) {
    out->pass = false;
    out->comment = "callee was stored incorectly";
    out->expected += callee;
    out->actual += subject->callee;
  }

  if (out->pass && (*subject->arguments)[0] != firstArg) {
    out->pass = false;
    out->comment = "first argument was stored incorectly";
    out->expected += pointerToString(firstArg);
    out->actual += pointerToString((*subject->arguments)[0]);
  }

  if (out->pass && (*subject->arguments)[1] != secondArg) {
    out->pass = false;
    out->comment = "second argument was stored incorectly";
    out->expected += pointerToString(secondArg);
    out->actual += pointerToString((*subject->arguments)[1]);
  }

  delete subject;
  return out;
}

int main(void) {
  std::vector<result*>* results = new std::vector<result*>();
  int i = 0;

  results->push_back(test_expression());
  results->push_back(test_numberExpression());
  results->push_back(test_variableExpression());
  results->push_back(test_binaryExpression());
  results->push_back(test_invocationExpression());

  print_results(results);

  for (i = 0; i < results->size(); i += 1) {
    delete (*results)[i];
  }
  delete results;

  return 0;
}
