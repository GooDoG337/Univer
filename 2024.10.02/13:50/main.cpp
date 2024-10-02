#include <iostream>
#include <vector>
template<typename T>
void Duplicate(std::vector<T>& v)
{
	v.reserve(3*v.size());
	for(auto it = v.begin(); it != v.end(); it++)
	{
		v.push_back(*it);
	}
}

int main()
{
	std::vector<int> vect {1,2,3};
	//Duplicate(vect);
	std::cout << '\n';
	for(auto elm:vect)
	{
		std::cout << elm << ' ';
	}
	return 0;
}
