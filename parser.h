#include <string>
#include <vector>

class Expression {
};

class NumberExpression : public Expression {
  public:
    double numberValue;
    NumberExpression(double nv) : numberValue(nv) {}
};

class VariableExpression : public Expression {
  public:
    std::string name;
    VariableExpression(const std::string n) : name(n) {};
};

class BinaryOperationExpression : public Expression {
  public:
    Expression *leftOperand, *rightOperand;
    char operatorChar;
    BinaryOperationExpression(Expression * l, char o, Expression * r) :
      leftOperand(l), rightOperand(r), operatorChar(o) {};
    ~BinaryOperationExpression();
};

class InvocationExpression : public Expression {
  public:
    std::string callee;
    std::vector<Expression*>* arguments;
    InvocationExpression(const std::string c, std::vector<Expression*>* a) :
      callee(c), arguments(a) {};
    ~InvocationExpression();
};

class Signature {
  public:
    std::string name;
    std::vector<std::string>* parameters;
    int parameterCount;
    Signature(const std::string n, std::vector<std::string>* p);
    ~Signature();
};

class FunctionDefinition {
  public:
    Signature* signature;
    Expression* body;
    FunctionDefinition(Signature* s, Expression* b) : signature(s), body(b) {};
    ~FunctionDefinition();
};
