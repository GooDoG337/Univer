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
double ExpressionResult(const std::string& expr, operation op) {
    std::cout << expr << std::endl;
    std::smatch result;
    std::regex_search(expr, result, std::regex{R"(^\d*[\.]?\d*)"});
    //std::cout << "SHIUT: " << expr << std::endl;
    double lvalue = 0;
    bool dotdigits = false;
    double drob = 0.1;
    for (const auto& i : result.str())
    {
        if (i == '.')
        {
            dotdigits = true;
        }
        else
        {
            if (!dotdigits)
            {
                lvalue*=10;
                lvalue += i-48;
            }
            if (dotdigits)
            {
                lvalue += (i-48)*drob;
                drob/=10;
            }
        }
    }
    std::cout << "lvalue: " << lvalue << std::endl;

    std::regex_search(expr, result, std::regex{R"(\d*[\.]?\d*$)"});
    double rvalue = 0;
    dotdigits = false;
    drob = 0.1;
    for (const auto& i : result.str())
    {
        if (i == '.')
        {
            dotdigits = true;
        }
        else
        {
            if (!dotdigits)
            {
                rvalue*=10;
                rvalue += i-48;
            }
            if (dotdigits)
            {
                rvalue += (i-48)*drob;
                drob/=10;
            }
        }
    }
    std::cout << "rvalue: " << rvalue << std::endl;

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
    std::regex r {R"( *\d*[\.]?\d* *\* *\d*[\.]?\d* *)"};
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
    r = {R"( *\d*[\.]?\d* *\/ *\d*[\.]?\d* *)"};
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
    r = {R"( *\d*[\.]?\d* *\+ *\d*[\.]?\d* *)"};
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
    r = {R"( *\d*[\.]?\d* *\- *\d*[\.]?\d* *)"};
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