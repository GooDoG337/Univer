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
	template <typename T1>
	bool operator==(const Matrix<T1>& other) const
	{
		const size_t rows = GetRows();
		const size_t columns = GetColumns();
		if(rows != other.GetRows() || columns != other.GetColumns())
		{
			return false;
		}
		for(size_t i = 0; i != rows; ++i)
		{
			for(size_t j = 0; j != columns; ++j)
			{
				if(!(*this)(i,j) ==other(i,j))
				{
					return false;
				}
			}
		}
		return true;
	}
};

template <typename T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
	auto tmp {lhs};
	tmp+=rhs;
	return tmp;
}	

template<typename T1, typename T2>
bool operator!=(const Matrix<T1>& other, const Matrix<T2>& other2)
{
	return !(other==other2);
}
#include "matrix.hpp"
#endif //MATRIX_H
