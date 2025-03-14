#include <iostream>
#include <chrono>
#include <future>

int returnTwo() {
	return 1+1;
}

void foo(std::promise<int> p) {
	p.set_value(25);
}
int main() {
	/*std::future<int> f = std::async(std::launch::async, returnTwo);
	if(f.valid()) {
		std::cout << f.get();
	} else {
		std::cout << "Wrong future\n";
	}
	std::cout << f.get() << '\n';*/

	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::thread t(foo, std::move(p));
	t.join();
	std::cout << f.get() << '\n';
	return 0;
}

