/* Assignment 2 - The Fraction Class
 * 
 * Header file: fraction_18njp.h
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 */


#pragma once // only include header once
#include <iostream>
using namespace std;

// Class to throw an exception when the user divides by 0
class FractionException : public exception{
private:
	string fractionExceptionString; // error message

public:
	FractionException(const string &fractionExceptionString);
	string &what();
};

// Class that defines the fraction objects
// note that more detailed comments were put in the .cpp file
class Fraction {
	int numerator_attribute;
	int denom_attribute;

private:
	// method to find GCD of 2 ints
	const int GCD(const int &x, const int &y); 
	// method to normalize the negative in a fraction
	void inverse_negative(int &numerator_attribute, int &denom_attribute);
	// method to redce any given fraction using the other methods
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

	// Addition and Assignment operator
	Fraction& operator+=(const Fraction& new_fraction);
	

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


// Basic Binary arithmatic operators   - note that these do not need to be implemented as member friends
Fraction operator+(const Fraction& old_frac, const Fraction& new_frac);
Fraction operator-(const Fraction& old_frac, const Fraction& new_frac);
Fraction operator*(const Fraction& old_frac, const Fraction& new_frac);
Fraction operator/(const Fraction& old_frac, const Fraction& new_frac);


