#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger()\n";
    }
    ~Logger() {
        std::cout << "~Logger()\n";
    }
};
int main()
{
    Logger x;
    std::cout << "Hello, World!\n";
    return 0;
}
