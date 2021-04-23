#include "pch.h"
#include <iostream>
#include "polynom.h"

using namespace std;
using namespace math;

//void mul(polynom &a, size_t &n)
//{
//	if (n > 0)
//	{
//		polynom b(a);
//		for (int i = 0; i < n - 1; i++)
//			a *= b;
//	}
//	else
//	{
//		for (int i = 0; i < a.get_degree() + 1; i++)
//			a[i] = 0;
//		a.delete_zeros();
//	}
//}

//double test(const polynom &a, size_t index)
//{
//	return a[index];
//}

long double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

double g(const polynom& poly, size_t i)
{
	int a = 5;
	size_t n = poly.get_degree();
	return (fact(n) / fact(n) * fact(n - (n - 1))) * pow(a, (n - i));
}

int main()
{
	//cout << "Fraction:" << endl;
	//fraction a(8, 5);
	//fraction b(2);
	//cout << a << endl;
	//cout << b << endl;
	//a += b;
	//cout << a << endl << endl;

	cout << "Unit tests:" << endl;
	polynom p(3, g);
	cout << p << endl;

	///* Основной конструктор */
	//double a1[] = { 1, 0, 4, 0 };
	//double a2[] = { 0, 0, 0, 0 };
	//double a3[] = { 1 };
	//double a4[] = { 1, 2, 3, 4 };

	//polynom p1(3, a1);
	//polynom p2(3, a2);
	//polynom p3(0, a3);
	//polynom p4(3, a4);
	//////	polynom p5(-1, a5);

	//cout << p1 << endl;
	//cout << p2 << endl;
	//cout << p3 << endl;
	//cout << p4 << endl;
	//cout << p4 + p1 << endl;
	//////	cout << p5 << endl;

	///* Конструктор копирования */
	//double a1[] = { 1, 2, 3, 4 };
	//double a6[] = { 4 };
	//polynom p1(3, a1);
	//polynom p2(p1);
	//polynom p3;
	//polynom p4(p3);
	////polynom(-2);
	//polynom p5(-1);
	//polynom p6(0, a6);

	//cout << p5 << endl;
	//cout << p6 << endl;

	/* Получение элементов по интексу */
	//double a1[] = { 2, 4 };
	//polynom p1(1, a1);

	/*polynom &(*f)(polynom, int&) = &p1.mul;
	polynom p2(f);*/

	/* Колбэк функция */
	//double a1[] = { 3, 2 };
	//double a2[] = { 0 };
	//void(*fff)(polynom&, size_t&) = &mul;
	//polynom p2(1, a1, 3, fff);
	//cout << p2 << endl;



	//double a1[] = { 3, 2 };
	//double a2[] = { 0 };
	//polynom p3(1, a1);
	//polynom p4(0, a2);
	//cout << p4 * p3 << endl;

	/* Операции сложения */
	//double a1[] = { 1, 4 };
	//double a2[] = {2};
	//polynom p1;
	//polynom p2(1, a1);
	//polynom p3(0, a2);

	/*cout << p1 * p1 << endl;
	cout << p2 + p2 << endl;
	cout << p3 + p3 << endl;
	cout << p3 + p1 << endl;*/
	//cout << p3 * p3 << endl;

	/* Операции умножения */
	//double a1[] = { 1, 4 };
	//double a2[] = {2};

	//polynom p1;
	//polynom p2(1, a1);
	//polynom p3(0, a2);

	////p3 *= p1;
	//p1 *= p3;
	//cout << p1 << endl;

	/*double a1[] = { 1, 4, 3, 0 };
	double a2[] = { 0, 4, 5, 6 };

	polynom p1;
	polynom p2(3, a2);

	p1 -= p2;
	cout << p1 << endl;*/
	//double a6[] = { 1, 1, 1 };
	//double a1[] = { 3, 0, 1, 2, 5 };

	//polynom p1(1, a6);
	//polynom p2(3, a1);
	//p1 /= p2;
	//cout << "result: " << endl << p1 << endl;

	/*cout << p1 << endl;
	cout << p2 << endl;
	cout << p1[0] << endl;*/



	/* Колбэк функция */

	/*double a1[] = { 1, 2, 3 };
	polynom p1(2, a1);
	cout << g(p1, 2) << endl;*/



	//polynom poly(2, g(p1, 2));
	//void(*fff)(const polynom&, size_t) = &g;
	//cout << poly << endl;






	//double a2[] = { 0, 2, 3, 4 };
	//polynom p2(3, a2);
	//double a3[] = { 0, 0, 0 };
	//polynom p3(2, a3);
	//cout << p2 << endl;
	//cout << p3 << endl;
	////p2 /= p3;
	//cout << p2 << endl;

	//double(*fff)(const polynom&, size_t) = &test;
	//polynom p2(fff(p1, 3));
	//cout << p2 << endl;

	/*double a1[] = { 5, 1 };
	polynom p3(1, a1);
	cout << p3 * p3 * p3 << endl;*/
	return 0;
}