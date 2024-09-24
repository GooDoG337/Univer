#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<int>> TranspMatrix(const std::vector<std::vector<int>>& matrix)
{
	std::vector<std::vector<int>> transp;
	for(size_t x = 0; x < matrix[0].size(); x++)
	{
		transp.push_back( {} );
		for(size_t y = 0; y < matrix.size(); y++)
		{
			transp[x].push_back(matrix[y][x]);
		}
	}
	return transp;
}

void CoutMatrix(const std::vector<std::vector<int>>& matrix)
{
	for(size_t x = 0; x < matrix.size(); x++)
	{
		for(size_t y = 0; y < matrix[0].size(); y++)
		{
			std::cout << matrix[x][y] << ' ';
		}
		std::cout << '\n';
	}
}
int main()
{
    std::vector<std::vector<int>> matrix { {1,2,3,4}, {4,5,6,7}, {7,8,9,10} };
    std::vector<std::vector<int>> transp = TranspMatrix(matrix);
    CoutMatrix(matrix);
    std::cout << '\n';
	CoutMatrix(transp);
	return 0;
}
