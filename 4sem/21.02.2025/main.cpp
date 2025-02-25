#include <iostream>
#include "dateCheck.h"

int main() {
    std::cout << "Enter date: ";
    std::string str;
    std::getline(std::cin, str);
    if (dateCheck::isValidDate(str)) std::cout << "Valid date\n";
    else std::cout << "Invalid date\n";
    return 0;
}
