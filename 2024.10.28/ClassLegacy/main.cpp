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

class C {
private:
    A a;
    int y;
public:
    void Func1() { return a.Func1(); }
    void Func2() { }
    void Func3() { }
    const A& GetA() const { return a; }
};
int main()
{
    C c;
    c.Func1();
    c.Func2();
    c.Func3();
//    DoSomething(c.GetA());
    return 0;
}
