#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "matrix.h"
template <typename T>
size_t Matrix<T>::GetRows() const
{
	return data.size();
}

template <typename T>
size_t Matrix<T>::GetColumns() const
{
	if(data.empty())
		return 0;
	else
		return data[0].size();
}

template <typename T>
void Matrix<T>::MakeRectangle()
{
	size_t maxSize = 0;
	for(const auto& row: data)
	{
		if(row.size() > maxSize)
		{
			maxSize = row.size();
		}
	}
	for(auto& row: data)
	{
		row.resize(maxSize);
	}
}
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns)
{
	data.resize(rows);
	for(auto& m:data)
	{
		m.resize(columns);
	}
}

	
#endif //MATRIX_HPP
