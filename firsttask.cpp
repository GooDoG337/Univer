#include <iostream>
#include <vector>
#include <string>
using std::cout;

std::string FindMostStart(std::vector<std::string> strings)
{
	std::string Begining = strings[0];
	int value = strings[0].size();
	for(std::string elm: strings)
	{
		while(!elm.starts_with(Begining) && value > 0)
		{
			value--;
			Begining = strings[0].substr(0, value);
		}
	}
	return Begining;
}
int main()
{
	std::string phrase;
	std::vector<std::string> strings;
	while(std::cin >> phrase)	//CTRL+D
	{
		strings.push_back(phrase);
	}	
	cout << FindMostStart(strings);
	return 0;
}
