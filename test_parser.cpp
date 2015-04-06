#include "parser.h"
#include "testing.h"
#include <cstdio>
#include <cstdlib>

result* test_expression() {
  Expression * expression = new Expression();
  delete expression;

  return new result("Expression");
}

result* test_numberExpression() {
  result* out = new result("NumberExpression");
  double probe = 12.234;
  NumberExpression * subject = new NumberExpression(probe);

  assertDouble(probe, subject->numberValue, out,
    "number literal store incorrectly");

  delete subject;

  return out;
}

result* test_variableExpression() {
  result* out = new result("VariableExpression");
  std::string probe = "foo";
  VariableExpression * subject = new VariableExpression(probe);

  assertString(probe, subject->name, out, "name stored incorrectly");

  delete subject;
  return out;
}

result* test_binaryExpression() {
  result* out = new result("BinaryOperatorExpression");
  char op = '+';
  NumberExpression * left = new NumberExpression(4),
                   * right = new NumberExpression(2.5);
  BinaryOperationExpression * subject =
    new BinaryOperationExpression(left, op, right);

  assertPointer(left, subject->leftOperand, out,
    "left operand stored incorrectly");

  assertChar(op, subject->operatorChar, out,
    "operator stored incorrectly");

  assertPointer(right, subject->rightOperand, out,
    "right operand stored incorrectly");

  delete subject;
  return out;
}

result* test_invocationExpression() {
  result* out = new result("InvocationExpression");
  std::string callee = "add";
  NumberExpression * firstArg = new NumberExpression(2.5),
                   * secondArg = new NumberExpression(4);
  std::vector<Expression*>* args = new std::vector<Expression*>();
  args->push_back(firstArg);
  args->push_back(secondArg);
  InvocationExpression * subject = new InvocationExpression(callee, args);

  assertString(callee, subject->callee, out,
    "callee stored incorrectly");
  assertPointer(firstArg, (*subject->arguments)[0], out,
    "first argument was stored incorectly");
  assertPointer(secondArg, (*subject->arguments)[1], out,
    "second argument was stored incorectly");

  delete subject;
  return out;
}

result* test_signature() {
  result* out = new result("Signature");
  std::string name = "add", param1 = "left", param2 = "right";
  std::vector<std::string> * params = new std::vector<std::string>();
  params->push_back(param1);
  params->push_back(param2);
  Signature * subject = new Signature(name, params);

  assertString(name, subject->name, out, "name stored incorrectly");
  assertString(param1, (*subject->parameters)[0], out,
    "first parameter stored incorrectly");
  assertString(param2, (*subject->parameters)[1], out,
    "second parameter stored incorrectly");
  assertInteger(2, subject->parameterCount, out,
    "parameterCount calculated incorrectly");

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
  results->push_back(test_signature());

  print_results(results);

  for (i = 0; i < results->size(); i += 1) {
    delete (*results)[i];
  }
  delete results;

  return 0;
}
