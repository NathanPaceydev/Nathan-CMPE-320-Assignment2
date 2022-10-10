/* Assignment 2 - The Fraction Class
 * Header file: fraction_18njp.h
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 */

#pragma once
#include <iostream>
using namespace std;



class FractionException {
private:
	string fractionExceptionString;
public:
	FractionException(const string& fractionExceptionString);
	string& what();
};



class Fraction {
	int numer_attribute;
	int denom_attribute;
private:

	
	const int GCD(const int& n, const int& m);
	void inverse_negative(int& numer_attribute, int& denom_attribute);
	void operation(int& num, int& denom, const Fraction& lhs, const Fraction& rhs, const char& opt_string);

public:
	//Fraction(int numerator = 0, int denominator = 1);
	Fraction(const int numer= 0,const int denom = 1);
	// Accessors
	const int& numerator() const;
	const int& denominator() const;
	// Member Unary operators (no mixed type expressions)
	Fraction operator++(int);
	Fraction& operator++();
	



	Fraction& operator-();
	// Member Binary Operator (potential mixed type expression)
	// Just wanted to try it out as a member function instead of non-member
	Fraction& operator+=(const Fraction& right);

	// I/O Operators
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	friend istream& operator>>(istream& in, Fraction& fraction);

};

// Non-member Binary Operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

// Non-member Comparative Operators (better for mixed type expressions)
// Could compare a fraction with an int
bool operator==(const Fraction& rhs, const Fraction& lhs);
bool operator>(const Fraction& lhs, const Fraction& rhs);
bool operator>=(const Fraction& lhs, const Fraction& rhs);
bool operator<(const Fraction& lhs, const Fraction& rhs);
bool operator<=(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);





