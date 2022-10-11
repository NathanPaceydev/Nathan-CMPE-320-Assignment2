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
	int numerator_attribute;
	int denom_attribute;
private:

	
	const int GCD(const int& n, const int& m);
	void inverse_negative(int& numerator_attribute, int& denom_attribute);
	void reduce(int& numerator, int& denom, int& numerator_attribute, int& denom_attribute);

public:
	//Fraction(int numerator = 0, int denominator = 1);
	Fraction(const int numer= 0,const int denom = 1);
	// Accessors
	const int& numerator() const;
	const int& denominator() const;
	// Member Unary operators (no mixed type expressions)
	Fraction operator++(int old_value);
	Fraction& operator++();

	Fraction& operator-();
	// Member Binary Operator (potential mixed type expression)
	// Just wanted to try it output as a member function instead of non-member
	Fraction& operator+=(const Fraction& new_fraction);

	// I/O Operators
	friend ostream& operator<<(ostream& output, const Fraction& fraction);
	friend istream& operator>>(istream& in, Fraction& fraction);

	// Non-member Binary Operators
	friend Fraction operator+(const Fraction& old_frac, const Fraction& new_frac);
	friend Fraction operator-(const Fraction& old_frac, const Fraction& new_frac);
	friend Fraction operator*(const Fraction& old_frac, const Fraction& new_frac);
	friend Fraction operator/(const Fraction& old_frac, const Fraction& new_frac);

	// Non-member Comparative Operators (better for mixed type expressions)
	// Could compare a fraction with an int
	friend bool operator==(const Fraction& old_frac, const Fraction& new_frac);
	friend bool operator>(const Fraction& old_frac, const Fraction& new_frac);
	friend bool operator>=(const Fraction& old_frac, const Fraction& new_frac);
	friend bool operator<(const Fraction& old_frac, const Fraction& new_frac);
	friend bool operator<=(const Fraction& old_frac, const Fraction& new_frac);
	friend bool operator!=(const Fraction& old_frac, const Fraction& new_frac);

};







