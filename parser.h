#include <string>
#include <vector>

/*
class TreeNode;
class TreeNode {
public:
  int childCount;
  TreeNode *firstChild;
  TreeNode *lastChild;
  TreeNode *rightSibling;
  TreeNode *leftSibling;
  TreeNode *parent;
  TreeNode() :
    childCount(0),
    firstChild(NULL),
    lastChild(NULL),
    leftSibling(NULL),
    rightSibling(NULL),
    parent(NULL)
  ~TreeNode() {
    TreeNode * nextChild(firstChild), currentChild = NULL;

    while(nextChild) {
      currentChild = nextChild;
      nextChild = currentChild->rightSibling;
      currentChild->leftSibling = NULL;
      delete currentChild
    }
  }
}
*/

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
    BinaryOperationExpression(char o, Expression * l, Expression * r) :
      leftOperand(l), rightOperand(r), operatorChar(o) {};
    ~BinaryOperationExpression();
};

class InvocationExpression : Expression {
  public:
    std::string callee;
    std::vector<Expression*> arguments;
    InvocationExpression(std::string c, std::vector<Expression*> &a) :
      callee(c), arguments(a) {};
    ~InvocationExpression();
};
