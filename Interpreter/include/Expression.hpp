#include <iostream>

class Expression {
  public: 
    virtual int evaluate() = 0;
};


class OperationExpression:public Expression {
    std::string m_operatorSymbol; 
    Expression* m_lhs; 
    Expression* m_rhs;

    public: 
      OperationExpression(const std::string& operatorSymbol, Expression* lhs, Expression* rhs):m_operatorSymbol(operatorSymbol),m_lhs(lhs),m_rhs(rhs){}

      int evaluate() override {
        if (m_operatorSymbol == "+") {
            return m_lhs->evaluate() + m_rhs->evaluate();
        }

        return 0;
      }
};

class NumberExpression:public Expression { 
    std::string m_numberExpression; 

    public: 
     NumberExpression(std::string numberExpresison):m_numberExpression(numberExpresison){};

    int evaluate() override {
      return std::stoi(m_numberExpression);
    }

};