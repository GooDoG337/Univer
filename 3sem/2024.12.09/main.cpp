#include <iostream>
#include <iterator>
#include <math.h>

#include "calculation.h"

int main() {
    std::string expression;
    std::getline(std::cin, expression);
    if(!calculate::IsValid(expression)) {
        return -1;
    }
    int SignIndex = expression.find('*');
    while(SignIndex != -1) {
        expression.replace(calculate::GetLeftStart(SignIndex, expression), calculate::GetRightEnd(SignIndex, expression)+1,
            std::to_string(calculate::GetRightNum(SignIndex, expression)*calculate::GetLeftNum(SignIndex, expression)));
        std::cout << expression << '\n';
        SignIndex = expression.find('*');
    }
    std::cout << "After * " << expression << '\n';


    SignIndex = expression.find('/');
    while(SignIndex != -1) {
        expression.replace(calculate::GetLeftStart(SignIndex, expression), calculate::GetRightEnd(SignIndex, expression)+1,
            std::to_string(calculate::GetLeftNum(SignIndex, expression)/calculate::GetRightNum(SignIndex, expression)));
        SignIndex = expression.find('/');
    }
    std::cout << "After / " << expression << '\n';


    SignIndex = expression.find('+');
    while(SignIndex != -1) {
        expression.replace(calculate::GetLeftStart(SignIndex, expression), calculate::GetRightEnd(SignIndex, expression)+1,
            std::to_string(calculate::GetRightNum(SignIndex, expression)+calculate::GetLeftNum(SignIndex, expression)));
        SignIndex = expression.find('+');
    }
    std::cout << "After + " << expression << '\n';


    SignIndex = expression.find('-');
    while(SignIndex != -1) {
        expression.replace(calculate::GetLeftStart(SignIndex, expression), calculate::GetRightEnd(SignIndex, expression)+1,
            std::to_string(calculate::GetLeftNum(SignIndex, expression)-calculate::GetRightNum(SignIndex, expression)));
        SignIndex = expression.find('+');
    }
    std::cout << "After - " << expression << '\n';
    return 0;
}