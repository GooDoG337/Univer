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

template <typename T>
std::vector<std::vector<T>>::const_iterator Matrix<T>::begin()
{
		return data.cbegin();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix)
{
	const size_t rows = matrix.GetRows();
	const size_t columns = matrix.GetColumns();
	for(size_t i = 0;  i != rows; ++i)
	{
		for(size_t j = 0; j != columns; ++j)
		{
			if(j > 0)
			{
				out << '\t';
			}
			out << matrix(i,j);
		}
		out << '\n';
	}
	return out;
}

template <typename T>
std::istream operator>>(std::istream& in, const Matrix<T>& matrix)
{
	const size_t rows = matrix.GetRows();
	const size_t columns = matrix.GetColumns();
	for(size_t i = 0; i != rows; ++i)
	{
		for(size_t j = 0; j != columns; ++j)
		{
			in >> matrix(i,j);
		}
	}	
	return in;
}
	
#endif //MATRIX_HPP
