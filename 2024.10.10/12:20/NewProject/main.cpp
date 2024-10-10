#include <iostream>
#include "time.h"
bool isAfternoon(const chron::Time& time)
{
	return time.GetHours() >= 12;
}

int main()
{
	chron::Time t ;
	//std::cout << t;
	std::cin >> t;
	t = t - 5;
	std::cout << t;
	return 0;
}
