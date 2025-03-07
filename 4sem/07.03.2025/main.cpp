#include <iostream>
#include <variant>
/*union student {
    int age;
    float averageScore;
    char* name;
};*/


int main() {
    /*student Ivan;
    Ivan.age = 15;
    std::cout << "Ivan age: " << Ivan.age << '\n';
    Ivan.averageScore = 2.5;
    std::cout << "Ivan score: " << Ivan.averageScore << '\n';
    Ivan.name = "Ivan?";
    std::cout << "Ivan's name: " << Ivan.name << '\n';
    std::cout << "Address: " << &Ivan.name << '\n';
    std::cout << "Address: " << &Ivan.age << '\n';
    std::cout << "Address: " << &Ivan.averageScore << '\n';
    std::cout << "Size: " << sizeof(student) << '\n';
    return 0;*/
    std::variant<int,double> myExample;
    myExample = 11.09;
    std::cout << std::get<double>(myExample) << '\n';
    return 0;
}
