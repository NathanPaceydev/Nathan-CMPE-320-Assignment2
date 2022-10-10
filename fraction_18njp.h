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

public:
	//Fraction(int numerator = 0, int denominator = 1);
	Fraction(const int numer= 0,const int denom = 1);
	// Accessors
	const int& numerator() const;
	const int& denominator() const;
	// Member Unary operators (no mixed type expressions)
	Fraction operator++(int);
	Fraction& operator++();
	




	//int operation_func(const int x, const int y, const int casevar);

	//array<int,2> operation_func(const int lhs_num, const int rhs_denom, const int rhs_num, const int lhs_denom, const int casevar);

	array<int, 2> operation_func(const int lhs_num, const int rhs_denom, const int rhs_num, const int lhs_denom, const int casevar, const bool mul);

	Fraction& operator-();
	// Member Binary Operator (potential mixed type expression)
	// Just wanted to try it out as a member function instead of non-member
	Fraction& operator+=(const Fraction& right);

	// I/O Operators
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	friend istream& operator>>(istream& in, Fraction& fraction);

	// Non-member Binary Operators
	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

	// Non-member Comparative Operators (better for mixed type expressions)
	// Could compare a fraction with an int
	friend bool operator==(const Fraction& rhs, const Fraction& lhs);
	friend bool operator>(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator!=(const Fraction& lhs, const Fraction& rhs);

};







