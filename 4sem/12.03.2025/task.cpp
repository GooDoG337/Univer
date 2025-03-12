#include <iostream>
#include <semaphore>
#include <vector>
#include <random>
#include <boost/multiprecision//cpp_int.hpp>
#include <thread>
#include <chrono>
#include <future>

using namespace boost::multiprecision;
std::counting_semaphore<2> semaphore(3);


void ReturnSum(size_t start, size_t end, const std::vector<int>& matrix, std::promise<cpp_int> result) {
	cpp_int sum = 0;
	for(int i = start; i < end; i++) {
		sum += matrix.back();
	}
	result.set_value(sum);
	return;
}

void Randomize(size_t num, std::vector<int>& matrix) {
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 100);
	for(int i = 0; i < num; i++) {
		matrix.push_back(uniform_dist(e1));
	}
}
int main() {
 	std::vector<int> matrix;
	Randomize(100000, matrix);
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::thread t(ReturnSum, 0, 50000, matrix, std::move(p));
	std::cout << f.get() << '\n';
	t.join();
	std::thread t1(ReturnSum, 50001, 100000, matrix, std::move(p));
	f.get();
	t1.join();
	std::cout << f.get() << '\n';
	return 0;
}
