#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <vector>

int main()
{
	/*std::vector<int> v {3, 14, 15, 5, 2, 8 };
	std::list<int> l;
	std::copy(v.begin(), v.end(), std::back_inserter(l));
	for(auto elm: l)
	{
		std::cout << elm << ' ';
	}*/
	/*std::list<int> data {3, 14, 15, 5, 2, 8 };	
	//std::sort(data.begin(), data.end());	404
	data.sort();
	for(auto elm: data)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';*/
	/*std::vector<int> data {3,14,15,9,2,3};
	std::partial_sort(data.begin(), data.begin()+3 , data.end());
	for(auto elm: data)
	{
		std::cout << elm << ' ';
	}*/
	//std::vector<int> data {1,4,5,9,9,0,5};
/*	if(std::binary_search(data.begin(), data.end(), 5))
	{
		std::cout << "Found\n";
	}
	else
	{
		std::cout << "Not Found\n";
	}*/ 	//std::is_sorted()
	/*std::vector<int> data {1,4,5,9,9,12,47};
	auto iter1 = std::lower_bound(data.begin(), data.end(), 2); //первое число не меньше заданного
	auto iter2 = std::upper_bound(data.begin(), data.end(), 47); //первое число больше заданного
	std::cout << *iter1 << '\n';
	for(auto iter = iter1; iter != iter2; ++iter)
	{
		std::cout << *iter << ' ';
	} 
	std::cout << '\n';*/
	std::vector<int> m1 {1,3,5,5,7};
	std::list<int> m2 {5,5,6,7,8};
	std::deque<int> out;
	
	std::merge(m1.begin(), m1.end(),
		m2.begin(), m2.end(), std::back_inserter(out));
	for(auto elm: out)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';
	out.clear();
	
	std::set_intersection(m1.begin(), m1.end(),
		m2.begin(), m2.end(), std::back_inserter(out));
	for(auto elm: out)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';
	out.clear();
	std::set_union(m1.begin(), m1.end(),
		m2.begin(), m2.end(), std::back_inserter(out));
	for(auto elm: out)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';
	out.clear();
	std::set_difference(m1.begin(), m1.end(),
		m2.begin(), m2.end(), std::back_inserter(out));
	for(auto elm: out)
	{
		std::cout << elm << ' ';
	}
	std::cout << '\n';
	out.clear();
	std::set_symmetric_difference(m1.begin(), m1.end(),
		m2.begin(), m2.end(), std::back_inserter(out));
	for(auto elm: out)
	{
		std::cout << elm << ' ';
	}
	return 0;
}
