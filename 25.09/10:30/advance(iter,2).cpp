#include <iterator>
#include <list>
#include <iostream>

int main()
{
	std::list<int> l {0,10,15,20};
	auto iter = std::next(l.begin());
	std::advance(iter,2);
	auto iter2;
	std::advance(iter2,2);
	
}
