/* Assignment 2 - The Fraction Class
 * 
 * Header file: fraction_18njp.h
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 */


#pragma once // only include header once
#include <iostream>
using namespace std;


class FractionException : public exception{
private:
	string fractionExceptionString;

public:
	FractionException(const string &fractionExceptionString);
	string &what();
};


class Fraction {
	int numerator_attribute;
	int denom_attribute;

private:
	const int GCD(const int &x, const int &y);
	void inverse_negative(int &numerator_attribute, int &denom_attribute);
	void reduce(int &numerator, int &denom, int &numerator_attribute, int &denom_attribute);

public:
	// Fraction Class Implementation
	Fraction(const int numer= 0,const int denom = 1);

	// Accesors for numerator and denominator attributes
	const int &numerator() const;
	const int &denominator() const;

	// Unary operators
	Fraction& operator-();
	Fraction operator++(int old_value);
	Fraction& operator++();

	// Basic Binary arithmatic operators
	friend Fraction operator+(const Fraction &old_frac, const Fraction &new_frac);
	friend Fraction operator-(const Fraction &old_frac, const Fraction &new_frac);
	friend Fraction operator*(const Fraction &old_frac, const Fraction &new_frac);
	friend Fraction operator/(const Fraction &old_frac, const Fraction &new_frac);
	
	
	// Addition and Assignment operator
	Fraction& operator+=(const Fraction &new_fraction);

	// Comparison Operators
	friend bool operator==(const Fraction &old_frac, const Fraction &new_frac);
	friend bool operator!=(const Fraction &old_frac, const Fraction &new_frac);

	friend bool operator>(const Fraction &old_frac, const Fraction &new_frac);
	friend bool operator<=(const Fraction &old_frac, const Fraction &new_frac);

	friend bool operator>=(const Fraction &old_frac, const Fraction &new_frac);
	friend bool operator<(const Fraction &old_frac, const Fraction &new_frac);


	// Output and Input Operators
	friend ostream& operator<<(ostream &output, const Fraction &fraction);
	friend istream& operator>>(istream &in, Fraction &fraction);
};
