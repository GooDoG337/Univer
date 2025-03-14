#include <iostream>
#include <regex>
#include <string>
int main() {
    std::string str/*{"MSU Baku"}*/{"I love MSU Baku?"};
    std::regex r/*{"(MSU)(.*)"}*/{"MSU[a-z, A-Z, ]?"};
    std::regex_replace(str,r, "Low... Lomonosov univer?");
    /*if(std::regex_match(str,r)) {
        std::cout << "I don't see the text, but I have to print\n";
    }
    if(std::regex_match(str.begin(),str.end(),r)) {
        std::cout << "Another one bites the dust?";
    }*/

    /*std::smatch result;
    std::regex_search(str, result, r);
    for(auto x:result) {
        std::cout << x << '\n';
    }*/





    return 0;
}
