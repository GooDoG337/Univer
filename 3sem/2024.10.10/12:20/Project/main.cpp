#include <iostream>
#include "time.h"
bool isAfternoon(const chron::Time& time)
{
	return time.GetHours() >= 12;
}

int operator- (const chron::Time& t1, const chron::Time& t2)
{
	return t1.TotalSeconds()-t2.TotalSeconds();
}



int main()
{
	chron::Time t ;
	//std::cout << t;
	std::cin >> t;
	std::cout << t;
	return 0;
}
