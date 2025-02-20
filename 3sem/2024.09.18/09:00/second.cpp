#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
enum class Color
{
	White,
	Red,
	Black,
	Green
};

int main()
{
	//std::string s = "Some string";
	//s+= ' ';
	//s+= "functions";
	//std::string sub1 = s.substr(12,9);
	//std::string sub2 = s.substr(5);
	//size_t sub3 = s.find(' ');
	//size_t sub4 = s.find(' ', sub3+1);
	//size_t sub5 = s.find("str");
	//size_t post4 = s.find("#");
	//std::cout << post4 << "\n";
	//std::cout << std::string::npos;
	//s.insert(5, "std::");
	//s.replace(0, 4, "Special");
	//std::cout<<s<<"\n";
	//s.erase(8, 5);
	//std::cout<<s<<"\n";

	/*std::string phrase;
	std::getline(std::cin, phrase);
	if(phrase.starts_with("hello"))
	{
		std::cout << "Hi\n";
	}
	if(phrase.ends_with("bye"))
	{
		std::cout << "Adios\n";
	}*/
	Color color1 = static_cast<Color>(2);
	Color color2 = Color::White;
	int value = static_cast<int>(color1);
	std::cout << static_cast<int>(color1) << '\n';
}
