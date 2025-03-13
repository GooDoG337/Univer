#include <iostream>
#include <semaphore>
#include <vector>
#include <random>
#include <boost/multiprecision//cpp_int.hpp>
#include <thread>
#include <chrono>
#include <future>

using namespace boost::multiprecision;
std::vector<int> matrix;


void ReturnSum(size_t start, size_t end, std::promise<cpp_int> p) {
	cpp_int sum = 0;
	for(size_t i = start; i < end; i++) {
		sum += matrix[i];
	}
	p.set_value(sum);
}

void Randomize(size_t num) {
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, );
	for(int i = 0; i < num; i++) {
		matrix.push_back(uniform_dist(e1));
	}
}


int main() {
	std::promise<cpp_int> p;
	std::future<cpp_int> f = p.get_future();
	std::promise<cpp_int> p2;
	std::future<cpp_int> f2 = p2.get_future();
	Randomize(10000000);
	/*for(auto i: matrix) {
		std::cout << i << ' ';
	}
	std::cout << '\n';*/
	std::thread t(ReturnSum, 0, 50000000, std::move(p));
	std::thread t1(ReturnSum, 50000000, 100000000, std::move(p2));
	cpp_int sum = f.get() + f2.get();
	t.join();
	t1.join();
	std::cout << sum;
	return 0;
}
