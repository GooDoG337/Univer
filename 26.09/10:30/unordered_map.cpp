#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
int main()
{
	std::unordered_map<std::string, int> freqs;
	std::string word;
	while(std::cin >> word)
	{
		++freqs[word];
	}
	std::vector<std::pair<std::string, int>> sortedByFreq(freqs.begin(), freqs.end());
	std::sort(sortedByFreq.begin(), sortedByFreq.end(), [](const auto& p1, const auto& p2) 
	{
		return std::tie(p2.second,p1.first)<std::tie(p1.second,p2.first);
	});
		
		for(const auto& elm: sortedByFreq)
		{
			std::cout << elm.second << '-' << elm.first << '\n';
		}
}
