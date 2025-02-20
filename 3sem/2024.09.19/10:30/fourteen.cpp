#include <iostream>
#include <vector>

int main()
{
	int x = 42;
	int& ref = x;
	const int& cref = x;
	++x;
	++ref;
	//++cref;
	int* ptr = &x;
	const int* cptr = &x;
	++*ptr;
	//++*cptr;
	int y = 20;
	cptr = &y;
}
