#include <iostream>
#include "time.h"
bool isAfternoon(const chron::Time& time)
{
	return time.GetHours() >= 12;
}

int main()
{
	chron::Time t (15,30,0);
	if(isAfternoon(t))
	{
		std::cout << t.GetHours()-12 << "PM\n";
	}
	else
	{
		std::cout << t.GetHours() << "AM\n";
	}
	return 0;
}
