#include <iostream>
int main()
{
	const int c1 = 42;
	int x;
	std::cin >> x;
	const int c2 = 2*x;
	std::cout << c1 << ' ' << c2;
}
