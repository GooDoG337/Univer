#include <iostream>
#include "matrix.h"

int main()
{
	Matrix<int> m({
		{1,2,3,4},
		{4,5,0,0},
		{7,8,9,3},
		{10,0,0,0}
	});
	Matrix<int> mm({
		{10,0,0,0},
		{7,8,9,3},
		{4,5,0,0},
		{1,2,3,4}
	});
	Matrix<int> m2(2,2);
	m+=mm;
	std::cout << m;
	return 0;
}
