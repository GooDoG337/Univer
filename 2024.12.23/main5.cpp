#include <boost/algorithm//string.hpp>
#include <iostream>
int main() {
    std::string input = "Msu\tBaku\tLab";
    std::vector<std::string> result;
    boost::split(result,input,boost::is_any_of("\t"));
    for(const auto& itm:result) {
        std::cout << itm << '\n';
    }
}