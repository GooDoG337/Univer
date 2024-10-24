#include <iostream>
class C {
public:
    int x = 0;
    inline static int sx = 0;       //из-за статика меняется у всего класса, из-за инлайна можно ставть =0
    static const int scx =  100;
};

class Logger {
private:
    inline static int counter = 0;
    int val = 0;
public:
    Logger():val(++counter) {
        std::cout << "Logger()\n";
    }
    Logger(int x) {
        val = x;
        std::cout << "Logger(int): "<< val << '\n';
    }
    Logger(const Logger&  other):val{++counter} {
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
int main(){

    std::cout << C::sx << ' ' << C::scx << '\n';
    C::sx = 1;
    std::cout << C::sx << ' ' << C::scx << '\n';
    C c1,c2;
    c1.x = 42;
    c2.x = 17;
    c2.sx = 13;
    std::cout << c1.x << ' ' << c1.sx << ' ' << c1.scx << '\n';
    std::cout << c2.x << ' ' << c2.sx << ' ' << c2.scx << '\n';
    return 0;
}
