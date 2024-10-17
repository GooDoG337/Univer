#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <stdexcept>
template <typename T>
class Matrix{
private:
	std::vector<std::vector<T>> data;
	void MakeRectangle();
public:
	size_t GetRows() const;
	size_t GetColumns() const;
	Matrix(const std::vector<std::vector<T>>& d): data{d} { MakeRectangle(); }
	Matrix(size_t rows, size_t columns);
	const std::vector<T>& operator[](size_t i) const
	{
		return data[i];
	}
	/*std::vector<T>& operator[](size_t i)
	{
		return data[i];
	}*/
	T& operator() (size_t i, size_t j)
	{
		return  data[i][j];
	}
	const T& operator()(size_t i, size_t j) const
	{
		return data[i][j];
	}
	using const_iterator = decltype(data.cbegin());
	std::vector<std::vector<T>>::const_iterator begin();
	const_iterator end() const
	{
		return data.cbegin();
	}
	Matrix<T>& operator+=(const Matrix<T>& other)
	{
		const size_t rows = GetRows();
		const size_t columns = GetColumns();
		if(rows != other.GetRows() || columns != other.GetColumns())
		{
			throw std::invalid_argument("Different size");
		}
		for(size_t i = 0; i != rows; ++i)
		{
			for(size_t j = 0; j != columns; ++j)
			{
				data[i][j]+=other.data[i][j];
			}
		}
		return *this;
	} 
};


#include "matrix.hpp"
#endif //MATRIX_H
