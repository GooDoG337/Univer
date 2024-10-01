#include <iostream>
#include <string>
int main()
{
	int x = 542;
	//int& ref = x;
	int* ptr = &x;
	++x;
	std::cout << *ptr << '\n';
}
