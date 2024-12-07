#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    Node* first = nullptr;
    Node* last = nullptr;
    int elementsCount = 0;
public:
    size_t Size() const {
        return elementsCount;
    }
    void PushBack(const T& elem) {
        Node* node = new Node(elem,last,nullptr);
        if(last != nullptr) {
            last->next = node;
        }
        else {
            first = node;
        }
        last = node;
        ++elementsCount;
    }
};

class C {
public:
    void f() noexcept {};   //optimization no exception
};

//Гарантии
//1.Отсуствие сбоев.
//2.Строгая гарантия:состояние класса не меняется при Exception: количество элементов одинаково, ссылки и итераторы остаются рабочими
//3.Базовая гарантия: состояние обьекта может меняться, но это логически собранный обьект и ним можно продолжать пользоваться.
//4.Отсуствие гарантий

int main() {
    List<C> data;
    C element;
    try {
        data.PushBack(element);
    } catch(...) {
        std::cout << data.Size() << '\n';
    }
}
