#include <iostream>
#include <string>
#include <set>
#include <list>
int main()
{
	std::string word;
	std::cin >> word;
	std::set<char> first;
	//std::multiset letters;
	while(!word.empty())
	{
		first.insert(word[0]);
		word.erase(0,1);
		//std::cout << word << '\n';
	}
	for(auto elm: first)
	{
		std::cout << elm << ' ';
	}
	while(std::cin >> word)
	{
		for(auto elm: first)
		{
			if(word.find(elm) == std::string::npos)
			{
				first.erase(elm);
			}
		}
	}
	for(auto elm: first)
	{
		std::cout << elm << ' ';
	}
	return 0;
}
