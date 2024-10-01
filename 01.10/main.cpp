#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>
int main()
{
	/*std::unordered_set<std::string> lovers
	{
		"love", "darling", "honey"
	};*/
	std::unordered_set<std::string> lovers
	{
		"любимый", "любимого", "любимому", "любимого", "любимым", "любимом", "любимая", "любимой", "любимую", "любимой", "любимое", 
	};
	std::string word;
	std::map<std::string, int> freqs;
	while(std::cin >> word)
	{
		for(char& elm: word)
		{
			elm = tolower(elm);
		}
		for(const auto& elm: lovers)
		{
			if(word.find(elm) != std::string::npos)
			{
					++freqs[elm];
			}
		}
	}
	int sum = 0;
	for(const auto& elm: freqs)
	{
		std::cout << elm.second << '-' << elm.first << '\n';
		sum+=elm.second;
	}
	std::cout << "Love words: " << sum << '\n';
	int boxes = sum/1000;
	std::cout << "Rafaello boxes: " << boxes << '\n';
	std::cout << "Rafaello candy: " << (sum%1000)/66  << '\n';
	return 0;
}
