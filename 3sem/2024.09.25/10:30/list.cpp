#include <list>
#include <iostream>

int main()
{
	std::list<int> l {10,15,20};
	l.push_back(5);
	l.push_front(0);
	l.push_back(25);
	l.push_back(35);
	l.pop_back();
	l.push_front(0);
	l.push_front(-1);
	l.pop_front();
	for(int x: l)
	{
		std::cout << x << ' ';
	}
}
