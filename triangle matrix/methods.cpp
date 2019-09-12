#include "pch.h"
#include "class.h"
#include <iostream>
#include <exception>
#include <iomanip>

using namespace std;

matrix & matrix::Memory(const matrix &x)
{
	int n = x.row, n = x.colume;
	matr = new double *[n];
	for (int i = 0; i < n; i++)
		for (int j = n-i-1; j<n; j++)
		{
			matr[j] = new double[n];
		}
	return *this;
}

void matrix::Erase()
{
	for (int i = 0; i < row; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}
void matrix::Clone(const matrix &x)
{
	int n = x.row, n = x.colume;
	row = x.row;
	colume = x.colume;
	for (int i = 0; i < n; i++)
		for (int j = n - i - 1; j < n; j++)
			matr[i][j] = x.matr[i][j];
}

matrix::matrix(int row1, int colume1)
{
	if (row1 != colume1)
		throw (exception("Matrix can't be created!"));
	this->row = n;
	this->colume = n;
	matr = new double *[n];
	for (int i = 0; i < n; i++)
		for (int j = n - i - 1; j < n; j++)
		{
			matr[j] = new double[n];
		}
	for (int i = 0; i < n; i++)
		for (int j = n - i - 1; j < n; j++)
			matr[i][j] = 0.0;
	}
}

matrix::matrix(const matrix &d)
{
	Memory(d);
	Clone(d);
}

matrix::~matrix()
{
	Erase();
}

double matrix::getElement(int x, int y)
{
	if (x < 0 || x >= this->row || y < 0 || y >= this->colume)
	{
		throw (exception("Out of index range"));
	}
	double el = matr[x][y];
	return el;
}
void matrix::setElement(int &x, int &y, double const element)
{
	if (x < 0 || x >= this->row || y < 0 || y >= this->colume)
	{
		throw (exception("Out of index range"));
	}
	this->matr[x][y] = element;
}

matrix& matrix::operator = (const matrix &x)
{
	if (this == &x)
	{
		return (*this);
	}

	for (int i = 0; i < row; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
	//matrix t(x.row, x.colume);
	row = x.row;
	colume = x.colume;


	matr = new double*[row];
	for (int i = 0; i < row; i++)
		for (int j = row - i - 1; j < row; j++)
	{
		matr[j] = new double[row];
	}

	//matr = new double *[n];
	for (int i = 0; i < row; i++)
	{
		for (int j = row - i - 1; j < row; j++)
		{
			matr[i][j] = x.matr[i][j];
			//t.setElement(i, j, x.matr[i][j]);
			//matr[i][j] = x.matr[i][j];
		}
	}
	//*this = t;
	return *this;
}

double matrix::NewC(const matrix &x, int i, int j)
{
	double c = 0;
	for (int r = 0; r < colume; r++)
	{
		c += matr[i][r] * x.matr[r][j];
	}
	return c;
}

matrix matrix:: operator *(const matrix &x)//matrix on matrix
{
	if (this->colume != x.row)
	{
		throw (exception("These matrixes can not be multiplied"));
	}
	else
	{
		int n = x.getRow();
		int n = x.getColume();
		matrix result(this->row, x.colume);
		for (int i = 0; i < n; i++)
		{
			for (int j = n - i - 1; j < n; j++)
			{
				result.matr[i][j] = NewC(x, i, j);
			}
		}
		return result;
	}

}
matrix matrix::operator + (const matrix &x)
{
	if (this->row != x.row || this->colume != x.colume)
	{
		throw (exception("These matrixes can not be summarized"));
	}
	else
	{
		matrix result(x.row, x.colume);
		for (int i = 0; i < x.row; i++)
		{
			for (int j = x.row - i - 1; j < x.row; j++)
			{
				result.matr[i][j] = this->matr[i][j] + x.matr[i][j];
			}
		}
		return result;
	}
}
matrix matrix::operator - (const matrix &x)
{
	if (this->row != x.row || this->colume != x.colume)
	{
		throw (exception("These matrixes can not be subtracted"));
	}
	else
	{
		matrix result(x.row, x.colume);
		for (int i = 0; i < x.row; i++)
		{
			for (int j = x.row - i - 1; j < x.row; j++)
			{
				result.matr[i][j] = this->matr[i][j] - x.matr[i][j];
			}
		}
		return result;
	}
}

matrix matrix:: operator +=(const matrix &x)
{
	if (this->row != x.row || this->colume != x.colume)
	{
		throw (exception("These matrixes can not be summarized"));
	}
	else
	{
		matrix result(x.row, x.colume);
		for (int i = 0; i < x.row; i++)
		{
			for (int j = x.row - i - 1; j < x.row; j++)
			{
				result.matr[i][j] = this->matr[i][j] + x.matr[i][j];
			}
		}
		return *this;
	}
}
matrix matrix::operator -=(const matrix &x)
{
	if (this->row != x.row || this->colume != x.colume)
	{
		throw (exception("These matrixes can not be subtracted"));
	}
	else
	{
		matrix result(x.row, x.colume);
		for (int i = 0; i < x.row; i++)
		{
			for (int j = x.row - i - 1; j < x.row; j++)
			{
				result.matr[i][j] = this->matr[i][j] - x.matr[i][j];
			}
		}
		return *this;
	}
}
matrix matrix::operator *=(const matrix &x)
{
	if (this->colume != x.row)
	{
		throw (exception("These matrixes can not be multiplied"));
	}
	else
	{
		int rows = x.getRow();
		int cols = x.getColume();
		matrix result(this->row, x.colume);
		for (int i = 0; i < rows; i++)
		{
			for (int j = rows- i - 1; j <rows; j++) 
			{
				for (int k = 0; k < rows; k++) 
				{
					result.matr[i][j] += this->matr[i][k] * x.matr[k][j];
				}
			}
		}
		return *this;
	}
}

matrix matrix ::operator * (const double k)
{
	matrix Result(this->row, this->colume);
	for (int i = 0; i < Result.row; i++)
	{
		for (int j = Result.row-i-1; j < Result.row; j++)
		{
			Result.matr[i][j] = matr[i][j] * k;
		}
	}
	return (Result);
}
matrix matrix::operator / (const double k)
{
	if (k == 0)
	{
		throw (exception("Division on zero"));
	}
	matrix temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = row-i-1; j < row; j++)
			temp.matr[i][j] /= k;
	return temp;
}
matrix matrix::operator /= (double k)
{
	if (k == 0)
	{
		throw (exception("Division on zero"));
	}
	matrix temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = row-i-1; j < row; j++)
			temp.matr[i][j] = matr[i][j] / k;
	return temp;
}
matrix matrix::operator *= (double k)
{
	matrix Result(this->row, this->colume);
	for (int i = 0; i < Result.row; i++)
	{
		for (int j = Result.row-i-1; j < Result.colume; j++)
		{
			(Result.matr)[i][j] = matr[i][j] * k;
		}
	}
	return Result;
}

matrix operator * (double k, const matrix &x)
{
	matrix Result(x.row, x.colume);
	for (int i = 0; i < Result.row; i++)
	{
		for (int j = Result.row-i-1; j < Result.colume; j++)
		{
			double el = x.matr[i][j] * k;
			Result.setElement(i, j, el);
		}
	}
	return Result;
}
matrix operator *= (double k, const matrix &x)
{
	matrix Result(x.row, x.colume);
	for (int i = 0; i < Result.row; i++)
	{
		for (int j = Result.row-i-1; j < Result.colume; j++)
		{
			(Result.matr)[i][j] = x.matr[i][j] * k;
		}
	}
	return Result;
}

bool matrix:: operator == (matrix const x)
{
	if (this->row == x.row && this->colume == x.colume)
	{
		for (int i = 0; i < x.row; i++)
		{
			for (int j = x.row-i-1; j < x.colume; j++)
			{
				if (this->matr[i][j] == x.matr[i][j])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
}
bool matrix:: operator != (matrix const x)
{
	if (this->row != x.row && this->colume != x.colume)
	{
		for (int i = 0; i < x.row; i++)
		{
			for (int j = x.row - i - 1; j < x.colume; j++)
			{
				if (this->matr[i][j] != x.matr[i][j])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
}

istream& operator >> (istream &in, matrix &x)
{
	double element;
	for (int i = 0; i < x.row; i++)
	{
		for (int j = x.row - i - 1; j < x.colume; j++)
		{
			in >> element;
			x.setElement(i, j, element);
		}
	}
	return in;
}
ostream& operator << (ostream &out, matrix x)
{
	for (int i = 0; i < x.row; i++)
	{
		for (int j = x.row - i - 1; j < x.colume; j++)
		{
			out << setw(10) << x.matr[i][j];
		}
		out << endl;
	}

	out << endl;

	return out;
}