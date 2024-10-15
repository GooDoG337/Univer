#include <iostream>
#include "matrix.h"

int main()
{
	Matrix<int> m({
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12}
	});
	std::cout << m.GetRows() << '\n';
	std::cout << m.GetColumns() << '\n';
	Matrix<int> m2(5,5);
	std::cout << m2.GetRows() << '\n';
	std::cout << m2.GetColumns() << '\n';
	Matrix<double> m3(3,4);
	int el = m[0][1];
	m[1][1] = 3;
	m[0].resize(10);
	return 0;
}
