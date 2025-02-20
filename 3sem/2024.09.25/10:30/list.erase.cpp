#include <list>
#include <iostream>

int main()
{
	std::list<int> l {0, 10, 15, 20};
	auto iter = l.begin();
	++iter;
	l.insert(iter,5);
	for(auto iter = l.begin(); iter != l.end(); ++iter)
	{
		if(*iter % 2 == 0)
			iter=l.erase(iter);
	}
	for(int x:l)
	{
		std::cout << x << ' ';
	}
}
