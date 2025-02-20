#include <string>
#include <iostream>

int main()
{
	std::string s1 = "Elementary, Watson";
	std::string s2 = s1;
	s1.clear();
	std::cout << s1 << '\n';
	std::cout << s2 << '\n';
}
