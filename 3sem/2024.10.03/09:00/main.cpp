#include <iostream>
/*#include <stack>
#include <list>*/
/*#include <queue>*/
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string_view>
int main()
{
	/*std::stack<int, std::list<int>> s;
	s.push(1);
	s.push(13);
	s.pop();
	std::cout << s.top() << '\n';
	if(s.empty())
	{
		std::cout << "Stack is empty\n";
	}*/
	//push_back(), pop_back(), empty(), back() - можно использовать как основу (условия) для Stack
	//pop_front(), front()
	/*std::queue<int> s;
	s.push(4);
	s.push(13);
	std::cout << s.front() << '\n';
	std::cout << s.back() << '\n';
	s.pop();
	if(s.empty())
	{
		std::cout << "Stack is empty\n";
	}*/
	/*std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for(int x: {3,14,15,92,8})
	{
		pq.push(x);
	}
	while(!pq.empty())
	{
		std::cout << pq.top() << ' ';
		pq.pop();
	}
	return 0;*/
	/*std::string s {"Hello, World!"};
	auto sub = s.substr(7);
	sub[0] = '&';
	std::cout << sub << '\n';
	std::cout << s << '\n';*/
	/*std::string s {"Hello, world. How do you do???"};
	std::string_view sv = s;
	sv.remove_prefix(7);
	sv.remove_suffix(16);
	std::cout << s << '\n';
	std::cout << sv << '\n';*/
	std::vector<std::string_view> lines;
	for(int i = 0; i != 5; ++i)
	{
		std::string line;
		std::getline(std::cin, line);
		lines.push_back(line);
	}
	for(auto item:lines)
	{
		std::cout << item << '\n';
	}
}
