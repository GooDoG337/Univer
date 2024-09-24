#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
int main()
{
	std::vector<std::pair<int,int>> coords={ {1,2}, {2,3}, {3,4} };
	std::multimap<double,std::pair<int,int>> distance;
	distance.insert({sqrt(coords[0].first*coords[0].first+coords[0].second*coords[0].second), coords[0]});
	//coords.insert(pair<int, int>(6, 10));
	 for(const auto& key_value: distance) {
        double key = key_value.first;
        std::pair<int,int> value = key_value.second;
        std::cout << key << " - " << value.first << ' ' << value.second << '\n';
    }


}
