#include <string>
#include <utility>
#include <iostream>

int main()
{
	std::pair<std::string, int> p = {"Hello", 42};
	auto[work, freg] = p;
	std::cout << freg << '\n';
	std::cout << work << '\n';
	return 0;
}
