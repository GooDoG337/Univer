#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void Swap(int& a, int& b)
{
	int z = a;
	a = b;
	b = z;
}

std::string Concatenate(const std::vector<std::string>& parts)
{
	std::string result;
	for(const auto& part:parts)
	{
		result+=part;
	}
	return result;
}

struct Date
{
	int year = 1970;
	int month = 1;
	int day = 1;
};

bool operator< (const Date& lhs, const Date& rhs)
{
	return std::tie(lhs.year,lhs.month,lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);

}

bool compare(const Date& lhs, const Date& rhs)
{
	if(lhs.year != rhs.year)
	{
		return lhs.year < rhs.year;
	}
	if(lhs.month != rhs.month)
	{
		return lhs.month < rhs.month;
	}
	return lhs.day < rhs.day;
}
int main()
{
	/*std::vector<std::string> parts {"ab", "ra", "ca", "da", "bra"};
	std::cout << Concatenate(parts);*/
	std::vector<Date> dates 
	{ 
		{2020,3,15},
		{2019,1,21},
		{2021,1,30},
		{}
	};
	//std::sort(dates.begin(), dates.end(), compare);
	std::sort(dates.begin(), dates.end(), [](const Date& lhs, const Date& rhs) {return std::tie(lhs.year,lhs.month,lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);});
	dates[0] < dates[1];
	for(const auto& [year,month,day]:dates)
	{
		std::cout << year << '.' << month << '.' << day << '\n';
	}
}
