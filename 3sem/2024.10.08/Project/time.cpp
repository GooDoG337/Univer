#include "time.h"
using namespace chron;
Time::Time(int h, int m, int s)
{
	if(s < 0 || s > 59)
	{
		s%=60;
		m+= s/60;
	}
	if(m < 0 || m > 59)
	{
		
	}
	if(h < 0 || h > 23)
	{
		
	}
	hours = h;
	minutes = m;
	seconds = s;
}
Time::Time(int h, int m)
{
		
}
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
