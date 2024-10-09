#include "time.h"
using namespace chron;
Time::Time(int h, int m, int s):
	hours(h), minutes{m}, seconds(s) { normalise(); }

int Time::GetHours() const
{
	return hours;
}
int Time::GetMinutes() const
{
	return minutes;
}
int Time::GetSeconds() const
{
	return seconds;
}

void Time::AddSeconds(int s)
{
	seconds+=s;
	normalise();
}

void Time::normalise()
{
	minutes += seconds/60;
	seconds %= 60;
	while(seconds < 0)
	{
		minutes -= 1;
		seconds += 60;
	}
	hours += minutes/60;
	minutes %= 60;
	hours %= 24;
	while(hours < 0) 
	{
		hours += 24;
	}
}
