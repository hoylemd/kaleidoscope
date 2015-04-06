#include <string>
#include <vector>

class Expression {
};

class NumberExpression : Expression {
  public:
    double numberValue;
    NumberExpression(double nv) : numberValue(nv) {}
};

class VariableExpression : Expression {
  public:
    std::string name;
    VariableExpression(std::string n) : name(n) {};
};

class BinaryOperationExpression : Expression {
  public:
    Expression *leftOperand, *rightOperand;
    char operatorChar;
    BinaryOperationExpression(Expression * l, char o, Expression * r) :
      leftOperand(l), rightOperand(r), operatorChar(o) {};
    ~BinaryOperationExpression();
};

class InvocationExpression : Expression {
  public:
    std::string callee;
    std::vector<Expression*>* arguments;
    InvocationExpression(std::string c, std::vector<Expression*>* a) :
      callee(c), arguments(a) {};
    ~InvocationExpression();
};
