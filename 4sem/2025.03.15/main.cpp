#include <iostream>
#include <thread>
#include <atomic>
void add(int a, int b, std::atomic<int>* res) {
	for(int i = a; i != b; i++) {
		res->fetch_add(i);
	}
}
//res = 3 == res->store(5);
int main() {
	std::atomic<int> shared = 0;
	std::thread Thread(add,1,100, &shared);
	while(Thread.joinable()) {
		std::cout << shared.load() << '\n';
	}
	Thread.join();
	return 0;
}
