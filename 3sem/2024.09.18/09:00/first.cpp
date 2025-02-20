#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;

int main()
{
	/*std::vector<int> data {1,2,3,4,5};
	for(int elm: data)
	{
		cout << elm << " ";
	}
	cout << "\n";*/
	/*std::vector <std::string> v1;
	std::vector <std::string> v2(5);
	std::vector <std::string> v3(5, "Hello");
	*/
	/*int a = data[0];
	int b = data[4];
	data[2]=-3;*/
	/*cout << data[42] << "\n";*/
	//cout << data.at(0) << "\n";
	//cout << data.at(42) << "\n";
	//cout << data.size() << "\n";
	/*cout << data.front() << "\n";
	cout << data.back() << "\n";
	int* t = data.data();	//return ykazatel to first element
	cout << *(t+1) << "\n";
	return 0;*/
	/*int x;
	std::vector<int> data;
	while(std::cin >> x)		//CTRL+D
	{
		data.push_back(x);
	}
	while(!data.empty() && data.back() == 0)
	{
		data.pop_back();
	}*/
	//data.clear(); 
	/*for(int elm: data)
	{
		cout << elm << " ";
	}
	return 0;*/
	/*std::vector<int> data{1,2,3,4,5};
	cout << data.capacity() << "\n";
	data.pop_back();
	cout << data.capacity() << "\n";
	data.push_back(5);
		data.push_back(9);
	cout << data.capacity() << "\n";
*/
	/*std::vector<std::string> words;
	size_t words_count;
	std::cin >> words_count;
	words.reserve(words_count);
	for(size_t i = 0; i != words_count; ++i)
	{
		std::string word;
		std::cin >> word;
		words.push_back(word);
	}

	for(std::string elm: words)
	{
		cout << elm << " ";
	}*/
	/*std::vector<int> data {1,2,3,4,5};
	data.reserve(10);
	data.resize(3);
	for(int elm: data)
	{
		cout << elm << " ";
	}
	data.resize(8);
	cout << "\n";
	for(int elm: data)
	{
		cout << elm << " ";
	}*/
	/*int m = 10;
	int n = 5;
	std::vector<std::vector<int>> matrix (m, std::vector<int> (n));*/
	//std::vector<int> data { 3,2,7,1,9,0,7 };
	//std::sort(data.rbegin(), data.rend());
	//std::ranges::sort(data);
	/*for(int elm: data)
	{
		cout << elm << " ";
	}*/
	std::string s = "Some string";
	s+= ' ';
	s+= "functions";
	std::cout<<s<<"\n";
}
