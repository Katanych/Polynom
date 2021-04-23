#pragma once
#include <iostream>

namespace math
{
	class polynom
	{
	private:
		double *coef;
		std::size_t degree;
	public:
		polynom();
		polynom(std::size_t d);
		polynom(std::size_t d, const double* a);
		polynom(std::size_t d, double(*f)(const polynom&, std::size_t));

		polynom(const polynom&);
		polynom(polynom&&);
		~polynom();

		void delete_zeros();
		std::size_t get_degree() const;

		double& operator[](std::size_t i);
		double operator[] (std::size_t i) const;
		double operator()(double) const;

		polynom& operator=(const polynom&);
		polynom& operator=(polynom&&);

		polynom& operator += (const polynom&);
		polynom& operator -= (const polynom&);
		polynom& operator *= (const polynom&);
		polynom& operator /= (const polynom&);
		polynom& operator %= (const polynom&);

		friend polynom operator + (const polynom&, const polynom&);
		friend polynom operator - (const polynom&, const polynom&);
		friend polynom operator * (const polynom&, const polynom&);
		friend polynom operator / (const polynom&, const polynom&);
		friend polynom operator % (const polynom&, const polynom&);

		friend std::ostream& operator << (std::ostream&, const polynom&);
	};
}