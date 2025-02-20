#include <iostream>

class A {
private:
    int x;
public:
    void Func1() {
        std::cout << "Func1 from A\n";
    }
    void Func2() {
        std::cout << "Func2 from A\n";
    }
};

class B:public A {
private:
    int y;
public:
    void Func2() {
        std::cout << "Func2 from B\n";
    }
    void Func3() {
        std::cout << "Func3 from B\n";
        std::cout << "Func3 from B\n";
    }
};

int main()
{
    B b;
    b.Func1();
    b.Func2();
    b.A::Func2();
    b.Func3();
    std::cout << sizeof(A) << ' ' << sizeof(B) << '\n';
    return 0;
}
