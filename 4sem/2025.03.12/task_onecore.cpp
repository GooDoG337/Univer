#include <iostream>
#include <vector>
#include <random>
#include <boost/multiprecision//cpp_int.hpp>

using namespace boost::multiprecision;
std::vector<int> matrix;


cpp_int ReturnSum(size_t start, size_t end) {
	cpp_int sum = 0;
	for(size_t i = start; i < end; i++) {
		sum += matrix[i];
	}
	return sum;
}

void Randomize(size_t num) {
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 100);
	for(int i = 0; i < num; i++) {
		matrix.push_back(uniform_dist(e1));
	}
}


int main() {
	Randomize(100000000);
    std::cout << ReturnSum(0,100000000);
	return 0;
}
