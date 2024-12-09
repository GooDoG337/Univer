#include <iostream>
#include <iterator>
#include <math.h>
/*struct WrongAgeException {
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
}*/

int main() {
    std::string primer;
	std::getline(std::cin, primer);


    auto it1 = primer.find('*');
    int num = 0;
    int x = 0;
    while(primer[it1-1] <= '9' && primer[it1-1] >= '0') {
        it1--;
        num += (primer[it1]-48)*pow(10,x);
        x++;
    }
    if(it1 != 0 && primer[it1-1]=='-') {
        num*=-1;
    }
    std::cout << num << '\n';
    int result = num;
    int Backup_X = x;

    num = 0;
    it1+=x;
    x = 0;
    if(primer[it1+1] == '-') {
        it1++;
    }
    while(primer[it1+1] <= '9' && primer[it1+1] >= '0') {
        it1++;
        num *= 10;
        num += (primer[it1]-48);
        x++;
    }
    if(primer[it1-x] == '-') {
        num*=-1;
    }
    int Backup_X2 = x;
    std::cout << num << '\n';
    result*=num;
    std::cout << primer << '\n';
    std::cout << Backup_X << "AND" << Backup_X2 << '\n';
    primer.replace(it1-Backup_X-Backup_X2, it1+1, std::to_string(result));
    std::cout << "A house of rising sun...: " << it1-Backup_X-Backup_X2 << ' ' << it1+1 << '\n';
    std::cout << primer << '\n';
    return 0;
    //проверка на верно введенный пример бы по хорошему
    //Так, оно умножает (если вводить как человек)


}
