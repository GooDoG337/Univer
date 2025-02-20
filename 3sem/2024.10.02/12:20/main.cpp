#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <map>
#include <iterator>
#include <list>
int main()
{
	//std::vector<int> data{2077, 1984, 2004, 1999, 1802, 1913, 1384};
	/*std::sort(data.begin()+1, data.end()-1);
	for(const auto& elm:data)
	{
		std::cout << elm << ' ';
	}*/
	//int counter = 0;
	//std::cout << std::count(data.begin(), data.end(), 1999) << '\n';
	/*for(int elm: data)
	{
		if(elm == 1999)
		{
			++counter;
		}
	}*/
	
	/*std::deque<int> data{2077, 1984, 2004, 1999, 1802, 1913, 1384};
	auto iter1 = std::find(data.begin(), data.end(), 1913);
	std::cout << (iter1-data.begin()) << '\n';
	auto start = data.begin();
	auto end = start+3;
	auto iter2 = std::find(start, end, 2004);
	if(iter2 == end)
	{
		std::cout << "No pick element" << '\n';
	} else
	{
		std::cout << iter2 - data.begin()<< '\n';
	}*/

	//find algorithm = O(n)
	//find in set/map = O(logn)
	//find in unordered set/map = O(1)
	/*std::map<int,int> m {
		{1,30},
		{2,28},
		{3,31},
	};
	auto it1 = m.find(3);
	//auto it2 = std::find(m.begin(), m.end(), 2); 404
	std::pair<const int, int> value {1,30};
	auto it3 = std::find(m.begin(), m.end(),  value);
	*/
	/*std::string s = "Redmi 9S";
	std::cout << std::count_if(
	s.begin(), 
	s.end(), 
	[](char c) { return 'A' <= c && c <= 'Z'; }) << '\n';
	*/
	/*std::string s = "Well, we are doomed.";
	std::reverse(s.begin(), s.end());
	std::cout << s << '\n';*/
	std::vector<int> v {3,5,1,1,6,9,1};
/*	auto iter = std::unique(v.begin(), v.end()); 		//Элемент за очищенным
	for(const auto& elm:v)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';
	v.erase(iter, v.end());
	for(const auto& elm:v)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';
	std::cout << iter-v.begin();
*/
	/*std::list<int> l;
	l.resize(v.size());
	std::copy(v.begin(), v.end(), l.begin());
	for(const auto& elm:l)
	{
		std::cout << elm << ' ';
	}*/
	std::list<int> l(10);
	auto iter = std::copy(v.begin(), v.end(), l.begin());
	for(auto elm:l)
	{
		std::cout << elm << ' ';
	}
	l.erase(iter, l.end());
	std::cout << '\n';
	for(auto elm:l)
	{
		std::cout << elm << ' ';
	}
	return 0;
}
