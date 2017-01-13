#ifndef _SRC_COMPLEX_HPP_
#define _SRC_COMPLEX_HPP_

#include <iostream>
#include <cmath>

/**
 * @file complex.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent complex number.
 */

class Complex {
private:
	double real;
	double imaginary;

public:
	// Constructor
	Complex(double=0, double=0);
	// Copy constructor
	Complex(const Complex& rhs);
	// Destructor
	~Complex();
	// Assigment operator
	Complex& operator=(const Complex& rhs);
	// Methods
	double getReal() const;
	double getImag() const;
	double abs() const;
};

#endif // _SRC_COMPLEX_HPP_
