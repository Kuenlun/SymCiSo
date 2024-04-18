#include <iostream>
#include <symengine/expression.h>

int main()
{
    using SymEngine::Expression;
    Expression x("x");
    auto ex = pow(x + sqrt(Expression(2)), 6);
    std::cout << SymEngine::expand(ex) << std::endl;
}
