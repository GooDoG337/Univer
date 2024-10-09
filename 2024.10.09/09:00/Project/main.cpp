#include <iostream>
#include "time.h"
bool isAfternoon(const chron::Time& time)
{
	return time.GetHours() >= 12;
}

int main()
{
	chron::Time t (15,30,0);
	chron::Time t1(10,10,-5);
	chron::Time t2(25,10,42);
	chron::Time t3(23,54,64);
	chron::Time t4;
	chron::Time t5(300);
	std::cout << t1.GetHours() << ':' << t1.GetMinutes() << ':' << t1.GetSeconds() << '\n';
	std::cout << t2.GetHours() << ':' << t2.GetMinutes() << ':' << t2.GetSeconds() << '\n';
	std::cout << t3.GetHours() << ':' << t3.GetMinutes() << ':' << t3.GetSeconds() << '\n';
	std::cout << t4.GetHours() << ':' << t4.GetMinutes() << ':' << t4.GetSeconds() << '\n';
	std::cout << t5.GetHours() << ':' << t5.GetMinutes() << ':' << t5.GetSeconds() << '\n';
	t5.AddSeconds(300);
	std::cout << t5.GetHours() << ':' << t5.GetMinutes() << ':' << t5.GetSeconds() << '\n';
	return 0;
}
