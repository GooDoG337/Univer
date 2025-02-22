#include <iostream>
#include <regex>
#include <string>
#inc
int main() {
    std::cout << "Enter date: ";
    std::string str = "31.03.3852 11:11";
    std::getline(std::cin, str);
    std::regex r{"^((0[1-9]|[1-2][0-9]|3[0-1])(?=\\.01|\\.03|\\.05|\\.07\\.08\\.10\\.12)|(0[1-9]|[1-2][0-9]|30)(?=\\.04|\\.06|\\.09|\\.11)|(0[1-9]|[1-2][0-8])(?=\\.02))\\.(1[0-2]|0[0-9])\\.\\d\\d\\d\\d\\s([0-1][0-9]|2[0-3]):[0-5][0-9]$"};
    if(std::regex_match(str,r)) {
    std::cout << "I don't see the text, but I have to print\n";
    }
    return 0;
}
