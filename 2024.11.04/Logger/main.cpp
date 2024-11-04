#include <iostream>
#include <utility>
#include <exception>


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

class C {
private:
    Logger x;
public:
    C() {
        std::cout << "C()\n";
        Logger y;
        throw std::exception();
    }
    ~C() {
        std::cout << "~C()\n";
    }
};

void f() {
    std::cout << "f() func\n";
    Logger x;
    throw std::exception();
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
    try {
        C c;
    } catch(const std::exception& ex) {
        std::cerr << "It's maybe error\n";
        return 1;
    }
    return 0;
}
