#include <iostream>
#include <list>

class Logger {
private:
    int val = 0;
public:
    Logger() {
        std::cout << "Logger()\n";
    }
    Logger(int x) {
        val = x;
        std::cout << "Logger(int): "<< val << '\n';
    }
    Logger(const Logger&  other) {
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
};
int main() {
    /*Logger* ptr = new Logger(1);
    Logger* ptr2 = new Logger(2);
    delete ptr;
    delete ptr2;*/
    /*std::list<Logger> loggers(2);
    loggers.pop_front();
    loggers.pop_back();*/
    Logger x1(1);
    Logger x2{x1};
    x1=x2;
    return 0;
}
