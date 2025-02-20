#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector> 
/*int Max(int x, int y)
{
	if(x>y) return x;
	else return y;
}*/
template <typename T1, typename T2, typename T3> struct Triple
{
	T1 first;
	T2 second;
	T3 third;
};

template<typename T> T Max(const T& x, const T& y)
{
	if(x>y) return x;
	else return y;
}

template<typename T> const std::vector<T>& Max(const std::vector<T>& v1, const std::vector<T>& v2)
{
	if(v1.size() > v2.size())
	{
		return v1;
	}
	else if(v1.size() < v2.size())
	{
		return v2;
	}
	else if(v1>v2)
	{
		return v1;
	}
	else
	{
		return v2;
	}
} 
int main()
{
	/*std::cout << Max(1,2) << '\n';
	std::cout << Max(3.1364, 2.7020) << '\n';
	std::string word {"hello"};
	Max<double> (43523.343,4321.432);
	Max<int>(43523.343,8);
	std::string word2 {"world"};
	std::cout << Max(word,word2) << '\n';
	std::vector<int> v1 = {1,2,3};
	std::vector<int> v2 = {4,5};
	for(const int & x: Max(v1,v2))
	{
		std::cout << x << ' ';
	}
	std::cout << '\n';
	*/
	Triple<int,int,int> point {1,3,2};
	Triple<std::string, std::string, int> wolfenstein {"Hello", "World", 42};
	return 0;
}
