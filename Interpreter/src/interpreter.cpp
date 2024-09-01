#include <Expression.hpp>


int main() {

    NumberExpression* five = new NumberExpression("5");
    NumberExpression* three = new NumberExpression("3");

    OperationExpression* operationExpression = new OperationExpression("+",five,three);

    std::cout << operationExpression->evaluate() << std::endl;

    NumberExpression* thirteen = new NumberExpression("13");

    OperationExpression* complexExpression = new OperationExpression("+",operationExpression,thirteen);

    std::cout << complexExpression->evaluate() << std::endl;

}