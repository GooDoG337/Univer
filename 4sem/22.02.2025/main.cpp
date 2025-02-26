#include <iostream>
#include <regex>
#include <string>

void ReturnSign() {};

/*void ExpressionResult(const std::string& expr) {
    auto indx = std::find(expr.begin(), expr.end(), '+')+1;
    int rvalue = 0;
    for(auto lsearch = indx; lsearch < expr.end()-1; ++lsearch) {
        lvalue*=10;
        lvalue += *rsearch-48;
    }
    std::cout << "AND " << lvalue << '\n';
    int rvalue = 0;
    for(auto rsearch = expr.begin(); rsearch < indx-1; ++rsearch) {
        rvalue*=10;
        lvalue += *lsearch-48;
    }
    std::cout << "SHIT: " << lvalue << '\n';
} САМОЕ ТУПОЕ *** НА ЗЕМЛЕ
*/
void ExpressionResult(const std::string& expr) {
    std::regex r {R"(\d+)"};
    std::smatch result;
    std::regex_search(expr, result, r);
    int lvalue = 0;
    for(auto itm:result.str()) {
        lvalue*=10;
        lvalue += itm-48;
    }
    int rvalue = 0;
std::cout << "lvalue: " << lvalue << '\n';
}
int main() {
    /*std::string str{"MSU Baku"}{"I love MSU Baku?"};
    std::regex r/*{"(MSU)(.*)"}{"MSU[a-z, A-Z, ]?"};
    std::regex_replace(str,r, "Low... Lomonosov univer?");
    if(std::regex_match(str,r)) {
        std::cout << "I don't see the text, but I have to print\n";
    }
    if(std::regex_match(str.begin(),str.end(),r)) {
        std::cout << "Another one bites the dust?";
    }

    std::smatch result;
    std::regex_search(str, result, r);
    for(auto x:result) {
        std::cout << x << '\n';
    }*/
    std::string expression;
    std::regex r {R"( *\d+ *(\+|\-|\*|\/) *\d+ *)"};
    std::cout << "Enter expression";
    std::getline(std::cin, expression);
    std::smatch result;
    std::regex_search(expression, result, r);
    for(auto i: result) {
        std::cout << i;
    }
    std::cout << "SHIT\n";
    ExpressionResult(result.str());


    return 0;
}


// \d*[\.]?\d*

// *\d+ *(\+|\-|\*|\\) *\d+ *