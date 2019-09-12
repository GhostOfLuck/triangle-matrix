#pragma once
#include <iostream>
#include <exception>
using namespace std;
class matrix
{
private:
	int row;
	int colume;
	double **matr;
	void Erase();
	void Clone(const matrix &x);
	double NewC(const matrix &x, int i, int j);
	matrix & Memory(const matrix &x);
public:
	matrix() : row(0), colume(0), matr(NULL) {};
	matrix(int row1, int colume1);
	matrix(const matrix &d);
	~matrix();

	int getRow() const
	{
		return row;
	}
	int getColume() const
	{
		return colume;
	}

	double getElement(int x, int y);
	void setElement(int &x, int &y, double const element);
	matrix& operator = (const matrix &x);

	matrix operator *(const matrix &x);//matrix on matrix
	matrix operator + (const matrix &x);
	matrix operator - (const matrix &x);

	matrix operator +=(const matrix &x);
	matrix operator -=(const matrix &x);
	matrix operator *=(const matrix &x);//matrix on matrix

	matrix operator * (double k);//multiply  right
	matrix operator / (const double k);
	matrix operator /= (double k);
	matrix operator *= (double k);

	friend matrix operator * (double k, const matrix &x);//multiply left
	friend matrix operator *= (double k, const matrix &x);

	bool operator == (matrix const x);
	bool operator != (matrix const x);

	friend istream& operator >> (istream &in, matrix &x);
	friend ostream& operator << (ostream &out, matrix x);
};