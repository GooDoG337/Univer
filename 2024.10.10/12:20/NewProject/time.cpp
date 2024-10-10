#include "time.h"
using namespace chron;
Time::Time(int h, int m, int s)
{
	seconds=3600*h+60*m+s;
	normalise(); 
}

int Time::GetHours() const
{
	return seconds/3600;
}

int Time::GetMinutes() const
{
	return (seconds%3600)/60;
}

int Time::GetSeconds() const
{
	return (seconds%3600)%60;
}
void Time::AddSeconds(int s)
{
	seconds+=s;
	normalise();
}
void Time::normalise()
{
	while(seconds < 0)
	{
		seconds+=86400;
	}
	seconds %= 86400;
}
Time& Time::operator+=(int s)
{
	seconds+=s;
	normalise();
	return *this;
}

Time Time::operator+(int s) const
{
	return Time(seconds/3600,(seconds%3600)/60,(seconds%3600)%60+s);
}

int Time::TotalSeconds() const
{
	return seconds;
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

int operator- (const chron::Time& t1, const chron::Time& t2)
{
	return t1.TotalSeconds()-t2.TotalSeconds();
}

