#include <iostream>
#include <string>
/*class Cat
{
private:
    std::string name;
public:
    Cat(const std::string& n):name(n) {};
    const std::string GetName() const { return name; }
    std::string Voice() const { return "Meow"; }
};

class Dog {
private:
    std::string name;
public:
    Dog(const std::string& n):name(n) {};
    const std::string GetName() const { return name; }
    std::string Voice() const { return "Bark"; }
};*/

/*enum class AnimalType {
    Cat,Dog
};
//enum в любое место где ожидается число
//enum class только туда, где ожидается

class Animal {
private:
    AnimalType type;
    std::string name;
public:
    Animal(AnimalType t, const std::string n):type(t),name(n) {};
    const std::string GetName() const { return name; }
    std::string Voice() const {
        switch(type) {
            case AnimalType::Cat:
                return "Meow";
            case AnimalType::Dog:
                return "Bark";
            default:
                return "I don't know this creature";
        }
    }
};

template<typename T>
void WTH(const T& creature) {
    std::cout << creature.GetName() << '\n';
}*/

class Animal {
private:
    std::string name;
public:
    Animal(const std::string n):name(n) {}
    const std::string& GetName() const { return name; }
    virtual std::string Voice() const { return "Generic voice.";}
};

class Cat:public Animal {
public:
    Cat(const std::string n): Animal(n) { }
    std::string Voice() const override { return "Meow"; }
};

class Dog:public Animal {
public:
    Dog(const std::string n): Animal(n) { }
    std::string Voice() const override { return "Bark"; }
};

class Shepherd:public Dog {
public:
    Shepherd(const std::string n): Dog(n) { }
    std::string Voice() const override final;
};
void Process (const Animal& creature) {
    std::cout << creature.Voice() << '\n';
}
int main() {
    Cat c("Tom");
    Dog d("Spark");
    Process(c);
    return 0;
}
