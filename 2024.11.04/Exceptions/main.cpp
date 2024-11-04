#include <iostream>

struct WrongAgeException {
    int age;
};

int RealAge() {
    std::cin.exceptions(std::istream::failbit);
    int age;
    std::cin >> age;
    if(age < 0 || age >= 128) {
        throw WrongAgeException(age);
    }
    return 0;
}

int main() {
    try {
        RealAge();
    } catch(const WrongAgeException& ex) {
        std::cerr << "Age is not correct: " << ex.age << '\n';
        return 1;
    } catch(const std::istream::failure& ex) {
        std::cerr << "Failed to read stream: " << ex.what() << '\n';
        return 2;
    } catch(...) {
        std::cerr << "Unknown exception\n";
        return 3;
    }
    std::cout << "Is real\n";
    return 0;
}
