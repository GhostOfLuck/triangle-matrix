#include "pch.h"
#include <iostream>
#include "ClassM.h"
#include <iomanip>
#include <exception>

using namespace std;

int main()
{
	try
	{
		setlocale(LC_ALL, ".1251");
		cout << "Создание матриц:\n\n";
		cout << "Размеры матрицы A:\n";
		int n;
		double a;
		cin >> n;
		cout << "Матрица А:\n";
		matrix A(n, n);
		cin >> A;
		cout << "Размеры матрицы B:\n";
		int n1;
		cin >> n1;
		cout << "Матрица В:\n";
		matrix B(n1, n1);
		cin >> B;
		cout << "Константа a:\n";
		cin >> a;
		cout << endl;
		double k;
		cout << "Константа k:\n";
		cin >> k;
		cout << endl;
		cout << "Матрица А:\n";
		cout << A << endl;
		cout << "Матрица B:\n";
		cout << B << endl;
		cout << endl;

		/*if (A!=B)
			cout << "Матрицы  равны" << endl;
		else
			cout <<"Матрицы не равны" <<endl;*/

		cout << " A + B =" << endl;
		cout << A + B << endl;
		cout << "A * B =" << endl;
		matrix C = A * B;
		cout << A * B << endl;
		cout << "(A + B) / a = " << endl;
		cout << (A + B) / a << endl;
		cout << "k * (A + B) / a =  " << endl;
		cout << k * (A + B) / a << endl;
		cout << "k * (A + B) / a  + (A*B) = " << endl;
		cout << k * (A + B) / a + (A*B) << endl;

		A = B;
		cout <<"Проверка =: "<<endl<< A << endl;
		
		if (A == B)
			cout << "Матрицы равны" << endl;
		else
			cout << "Матрицы не равны" << endl;
		
		
		return 0;
	}
	catch (const exception& a)
	{
		cout << a.what() << endl;
	}
}