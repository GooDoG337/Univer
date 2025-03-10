#include <iostream>
#include <thread>
void foo(int z) {
	for(int i = 0; i != z; i++) {
		std::cout << "Thread using FOOnction\n";
	}
}
class thread_obj {
public:
	void operator()(int n) {
		for(int i = 0; i != n; i++) {
			std::cout << "Thread using thread_obj\n";
		}
	}
};

class Base {
public:
	void Foo() {
		std::cout << "Thread using member function(foo)\n";
	}
	static void foo1() {
		std::cout << "Thread using static member foo1()\n";
	}
};

int main()
{
	//std::cout << std::thread::hardware_concurrency() << '\n';
	std::thread t1(foo, 3);
	std::thread t2(thread_obj(),3);
	auto f=[](int n) {
		for(int i = 0; i != n; ++i)
			std::cout << "Thread using bubble?\n";
	};
	std::thread t3(f, 3);
	Base b;
	std::thread t4(&Base::Foo, &b);
	std::thread t5(&Base::foo1);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
    return 0;
}
