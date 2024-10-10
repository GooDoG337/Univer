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

Time& Time::operator+=(int s)
{
	seconds+=s;
	normalise();
	return *this;
}

Time Time::operator+(int s) const
{
	return Time(hours,minutes,seconds+s);
}

int Time::TotalSeconds() const
{
	return seconds+60*minutes+hours*3600;
}

std::ostream& operator<< (std::ostream& out, const chron::Time& t)
{
	out << t.GetHours() << ':' << t.GetMinutes() << ':' << t.GetSeconds() << '\n';
	return out;
}

std::istream& operator>> (std::istream& in, chron::Time& t)
{
	int h,m,s;
	char tmp;
	in >> h >> tmp;
	in >> m >> tmp;
	in >> s >> tmp;
	t=Time(h,m,s);
	return in;
}


