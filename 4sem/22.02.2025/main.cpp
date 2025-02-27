#include <iostream>
#include <regex>
#include <string>
enum class operation{none, plus, minus, times, divide};

operation ExpressionOperation(const std::string& str)
{
    if (str.find('*') != std::string::npos) return operation::times;
    if (str.find('/') != std::string::npos) return operation::divide;
    if (str.find('+') != std::string::npos) return operation::plus;
    if (str.find('-') != std::string::npos) return operation::minus;
    return operation::none;
}
int ExpressionResult(const std::string& expr, operation op) {
    std::smatch result;
    std::regex_search(expr, result, std::regex{"^\\d+"});
    //std::cout << "SHIUT: " << expr << std::endl;
    int lvalue = 0;
    for(const char& itm:result.str()) {
        lvalue*=10;
        lvalue += itm-48;
    }
    //std::cout << "expr: " << expr << std::endl;

    std::regex_search(expr, result, std::regex{"\\d+$"});
    int rvalue = 0;
    for(const char& itm:result.str()) {
        rvalue*=10;
        rvalue += itm-48;
    }
    switch (ExpressionOperation(expr))
    {
    case operation::times:
        return lvalue * rvalue;
    case operation::plus:
        return lvalue + rvalue;
    case operation::minus:
        return lvalue - rvalue;

    case operation::divide:
        return lvalue / rvalue;
    default:
        throw std::invalid_argument("invalid operation");
    }
}
int main() {
    std::string expression;
    //std::regex r {R"( *\d+ *(\+|\-|\*|\/) *\d+ *)"};
    std::regex r {R"( *\d+ *\* *\d+ *)"};
    //std::regex r {R"( *\d+ *\+ *\d+ *)"};
    std::cout << "Enter expression";
    std::getline(std::cin, expression);
    std::smatch result;
    std::regex_search(expression, result, r);
    operation op = ExpressionOperation(expression);
    while (op != operation::none)
    {
        try
        {
            ExpressionResult(result.str(), op);
        } catch (...)
        {
            break;
        }
        expression.replace(expression.find(result.str()), result.str().length(), std::to_string(ExpressionResult(result.str(), op)));
        std::regex_search(expression, result, r);
        op = ExpressionOperation(expression);
    }
    std::cout << "Expression end: " << expression << std::endl;
    r = {R"( *\d+ *\/ *\d+ *)"};
    std::regex_search(expression, result, r);
    op = ExpressionOperation(expression);
    while (op != operation::none)
    {
        try
        {
            ExpressionResult(result.str(), op);
        } catch (...)
        {
            break;
        }
        expression.replace(expression.find(result.str()), result.str().length(), std::to_string(ExpressionResult(result.str(), op)));
        std::regex_search(expression, result, r);
        op = ExpressionOperation(expression);
    }
    std::cout << "Expression end: " << expression << std::endl;
    r = {R"( *\d+ *\+ *\d+ *)"};
    std::regex_search(expression, result, r);
    op = ExpressionOperation(expression);
    while (op != operation::none)
    {
        try
        {
            ExpressionResult(result.str(), op);
        } catch (...)
        {
            break;
        }
        expression.replace(expression.find(result.str()), result.str().length(), std::to_string(ExpressionResult(result.str(), op)));
        std::regex_search(expression, result, r);
        op = ExpressionOperation(expression);
    }
    std::cout << "Expression end: " << expression << std::endl;
    r = {R"( *\d+ *\+ *\d+ *)"};
    std::regex_search(expression, result, r);
    op = ExpressionOperation(expression);
    while (op != operation::none)
    {
        try
        {
            ExpressionResult(result.str(), op);
        } catch (...)
        {
            break;
        }
        expression.replace(expression.find(result.str()), result.str().length(), std::to_string(ExpressionResult(result.str(), op)));
        std::regex_search(expression, result, r);
        op = ExpressionOperation(expression);
    }
    std::cout << "Expression end: " << expression << std::endl;
    return 0;
}


// \d*[\.]?\d*

// *\d+ *(\+|\-|\*|\\) *\d+ *