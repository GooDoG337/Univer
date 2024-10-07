#include <iostream>
#include <string>
#include <deque>
#include <iterator>
void doTrain(std::deque<int>& train)
{
	std::string command;
	int num;
	while(std::cin >> command)		//CTRL+D
	{
		if(command.starts_with("+l"))
		{
			//std::cout << "LEFT\n";
			std::cin >> num;
			train.push_front(num);
		}
		else if(command.starts_with("+r"))
		{
			//std::cout << "RIGHT\n";
			std::cin >> num;
			train.push_back(num);
		}
		else if(command.starts_with("-l"))
		{
			//std::cout << "MINUS LEFT\n";
			std::cin >> num;
			if(!train.empty())
			{
				if((long unsigned int)num >= train.size())
					train.clear();
				else
					train.erase(train.begin()+train.size()-num, train.end());
			}
			
		}
		else if(command.starts_with("-r"))
		{
			//std::cout << "MINUS RIGHT\n";
			std::cin >> num;
			if(!train.empty())
			{
				if((long unsigned int)num >= train.size())
					train.clear();
				else
					train.erase(train.begin(), train.begin()+num);
			}
		}
	}
}

int main()
{
	std::deque<int> train { };
	doTrain(train);
	for(int itm: train)
	{
		std::cout << itm << ' ';
	}
}
