#include <iostream>
#include <utility>
class Logger {
private:
    int val = 0;
    inline static int counter = 0;
public:
    Logger():val(++counter) {
        std::cout << "Logger()\n";
    }
    Logger(int x) {
        val = x;
        std::cout << "Logger(int): "<< val << '\n';
    }
    Logger(const Logger&  other):val(++counter) {
        val = other.val;
        std::cout << "Logger(const Logger&): "<< val << '\n';
    }
    ~Logger() {
        std::cout << "~Logger(" << val << ")\n";
    }
    Logger& operator=(const Logger& other) {
        val=other.val;
        std::cout << "Logger&(const Logger&): "<< val << '\n';
        return *this;
    }
    Logger(Logger&& other):val(++counter) {
        std::cout << "Logger(&&):" << val << '\n';
    }
    Logger& operator=(Logger&& other) {
        val = other.val;
        std::cout << "=(Logger&&): " << val << '\n';
        return *this;
    }
};

void f(const Logger& x) {
    std::cout << "void f(logger&)\n";
}

void f(Logger&& x) {
    std::cout << "void f(temp)\n";
}

class WellIGuessItLater:public Logger {
public:
    WellIGuessItLater() {
        std::cout << "WellIGuessItLater()\n";
    }
    ~WellIGuessItLater() {
        std::cout << "~WellIGuessItLater()\n";
    }
};
int main() {
    /*Logger x1;
    Logger x2;
    x2 = x1;
    x2 = std::move(x1);
    //Logger x3 = Logger();
    //Logger x4 = std::move(x1);
    */
    WellIGuessItLater a;
    return 0;
}
