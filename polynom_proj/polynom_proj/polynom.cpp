#include "pch.h"
#include "polynom.h"
#include <sstream>

using namespace std;

namespace math
{
	polynom::polynom() : polynom(0)
	{
		coef[0] = 0;
	}

	polynom::polynom(std::size_t d)
	{
		degree = d;
		coef = new double[degree + 1];
	}

	polynom::polynom(std::size_t d, const double* a) : polynom(d)
	{
		for (std::size_t i = 0; i <= degree; i++)
			coef[i] = a[i];

		delete_zeros();
	}

	polynom::polynom(std::size_t d, double(*f)(const polynom &, std::size_t)) : polynom(d)
	{
		for (std::size_t i = 0; i <= degree; i++)
			coef[i] = f(*this, i);
	}

	polynom::polynom(const polynom& a) : polynom(a.degree, a.coef) {}

	polynom::polynom(polynom&& a) : degree(0), coef(nullptr)
	{
		swap(degree, a.degree);
		swap(coef, a.coef);
	}

	polynom::~polynom()
	{
		if (coef) delete[] coef;
	}

	void polynom::delete_zeros()
	{
		if (degree > 0 && coef[degree] == 0)
		{
			while (coef[degree] == 0 && degree != 0)
				degree--;

			polynom new_p(degree);

			for (std::size_t i = 0; i <= degree; i++)
				new_p[i] = coef[i];

			*this = new_p;
		}
	}

	std::size_t polynom::get_degree() const
	{
		return degree;
	}

	double& polynom::operator[](std::size_t i)
	{
		if (i > degree)
			throw out_of_range("Такого элемента не существует!");
		return *(coef + i);
	}

	double polynom::operator[](std::size_t i) const
	{
		if (i > degree)
			throw out_of_range("Такого элемента не существует!");
		return coef[i];
	}

	double polynom::operator()(double x) const
	{
		double solution = coef[degree];
		for (std::size_t i = 1; i <= degree; i++)
		{
			solution *= x;
			solution += coef[degree - i];
		}
		return solution;
	}

	polynom& polynom::operator=(const polynom& a)
	{
		if (this == &a) return *this;

		if (degree != a.degree)
		{
			delete[] coef;
			degree = a.degree;
			coef = new double[degree + 1];
		}

		for (std::size_t i = 0; i <= degree; ++i)
			coef[i] = a.coef[i];

		return *this;
	}

	polynom& polynom::operator=(polynom&& a)
	{
		if (this == &a) return *this;

		delete[] coef;

		degree = 0;
		coef = nullptr;

		swap(degree, a.degree);
		swap(coef, a.coef);

		return *this;
	}

	polynom& polynom::operator+=(const polynom& a)
	{
		if (degree >= a.degree)
		{
			for (std::size_t i = 0; i < a.degree + 1; i++)
				coef[i] += a.coef[i];
		}
		else
		{
			for (std::size_t i = 0; i <= degree; i++)
				a.coef[i] += coef[i];
			*this = a;
		}

		delete_zeros();

		return *this;
	}

	polynom& polynom::operator-=(const polynom& a)
	{
		if (degree >= a.degree)
		{
			for (std::size_t i = 0; i < a.degree + 1; i++)
				this->coef[i] -= a.coef[i];
		}
		else
		{
			for (std::size_t i = 0; i <= degree; i++)
				a.coef[i] -= coef[i];
			*this = a;
		}

		delete_zeros();

		return *this;
	}

	polynom& polynom::operator*=(const polynom& a)
	{
		polynom result(degree + a.degree);
		/* Обнуление
		Необходимо для корректного подсчета
		коэффициентов результирующего полинома
		(операция += вместо =, накапливающий
		эффект).
		*/
		for (std::size_t i = 0; i <= degree + a.degree; i++)
			result.coef[i] = 0;

		for (std::size_t i = 0; i <= degree; i++)
			for (int j = 0; j <= a.degree; j++)
				result[i + j] += coef[i] * a.coef[j];

		result.delete_zeros();

		return *this = result;
	}

	polynom& polynom::operator/=(const polynom& a)
	{
		if (a.degree == 0 && a.coef[0] == 0)
			throw logic_error("Хэй, хэй, салага! Не торопись полином делить на ноль!");

		if (degree < a.degree)
			return *this = polynom();

		std::size_t size = degree - a.degree;
		polynom result(size);

		for (std::size_t i = 0; i < size + 1; i++)
		{
			result.coef[size - i] = coef[degree - i] / a.coef[a.degree];
			for (std::size_t j = 0; j <= a.degree; j++)
				coef[degree - j - i] -= a.coef[a.degree - j] * result.coef[size - i];
		}

		result.delete_zeros();

		return *this = result;
	}

	polynom& polynom::operator%=(const polynom& a)
	{
		if (a.degree == 0 && a.coef[0] == 0)
			throw logic_error("Хэй, хэй, салага! Не торопись получить остаток от деления на ноль!");

		if (degree < a.degree)
			return *this;

		std::size_t size = degree - a.degree;
		double k;

		for (std::size_t i = 0; i < size + 1; i++)
		{
			k = coef[degree - i] / a.coef[a.degree];
			for (std::size_t j = 0; j < a.degree; j++)
				coef[degree - i - j] -= a.coef[a.degree - j] * k;
		}

		delete_zeros();

		return *this;
	}

	polynom operator+(const polynom& a, const polynom& b)
	{
		return polynom(a) += b;
	}

	polynom operator-(const polynom& a, const polynom& b)
	{
		return polynom(a) -= b;
	}

	polynom operator*(const polynom& a, const polynom& b)
	{
		return polynom(a) *= b;
	}

	polynom operator/(const polynom& a, const polynom& b)
	{
		return polynom(a) /= b;
	}

	polynom operator%(const polynom& a, const polynom& b)
	{
		return polynom(a) %= b;
	}

	ostream& operator<<(ostream& stream, const polynom& a)
	{
		streamsize size = stream.width();
		for (std::size_t i = 0; i < a.degree + 1; i++)
		{
			stream.width(size);
			stream.setf(ios::showpos);
			stream << a.coef[a.degree - i];
			stream.unsetf(ios::showpos);
			if (a.degree - i == 1)
				stream << 'X';
			else if (a.degree - i != 0)
				stream << 'X' << '^' << a.degree - i;
		}

		return stream;
	}
}