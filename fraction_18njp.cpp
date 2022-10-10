/* Assignment 2 - The Fraction Class
 * Implementation file: fraction_18njp.cpp
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 */

#include "fraction_18njp.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;



FractionException::FractionException(const string& fractionExceptionString) : fractionExceptionString(fractionExceptionString) {}
string &FractionException::what() { 
	return fractionExceptionString;
}


const int& Fraction::numerator() const {
	return numer_attribute;
}

const int& Fraction::denominator() const {
	return denom_attribute;
}

Fraction::Fraction(const int numer, const int denom) {
	if (denom == 0) {
		throw FractionException("Zero value denominator Error:\n Cannot divide by 0!!");
	}

	int gcd = GCD(numer, denom);
	numer_attribute = numer/gcd;
	denom_attribute = denom/gcd;

	inverse_negative(numer_attribute, denom_attribute);
}


void Fraction::inverse_negative(int &numer_attribute, int &denom_attribute) {
	if (numer_attribute * denom_attribute < 0) {
		numer_attribute = -abs(numer_attribute);
		denom_attribute = abs(denom_attribute);
	}
	else {
		numer_attribute = abs(numer_attribute);
		denom_attribute = abs(denom_attribute);
	}
}


// recursive method to calculate the greatest common denominator of ints a and y
const int Fraction::GCD(const int &x, const int &y){
	if (x == 0) return 1;
	if (y == 0) return x;
	return GCD(y, x%y);
}


// ** OVERLOADING OPERATORS ************************
//TODO figure out a decent way to organize this section



ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numer_attribute << "/" << fraction.denom_attribute;
	return out;
}

/*
// Use string stream to split input by '/' and store values in vector (container)
// If '/' is not in input, container will be of size 1 containing int
// container[0] should be numerator
// container[1] should be denominator
// Convert string values to int using stoi
istream& operator>>(istream& in, Fraction& fraction) {
	string input;
	in >> input;
	stringstream ss(input);
	string number;
	vector<string> container;
	while (getline(ss, number, '/')) {
		container.push_back(number);
	}
	if (container.size() < 2) {
		fraction.numer_attribute = stoi(input);
		fraction.denom_attribute = 1;
	}
	else if (stoi(container[1]) == 0) {
		throw FractionException("Denominator is equal to 0, invalid fraction.");
	}
	else {
		fraction.numer_attribute = stoi(container[0]);
		fraction.denom_attribute = stoi(container[1]);
	}
	return in;
}*/



//*/
istream& operator>>(istream& in, Fraction& fraction)
{
	// read numerator
	in >> fraction.numer_attribute;
	// read next character
	int current = in.get();
	// if the user entered a zero, or a whole number, set denominator to 1 and return from input stream
	if (fraction.numer_attribute == 0 || current == 10) {
		fraction.denom_attribute = 1;
		return in;
	}
	// read denominator and return from input stream
	in >> fraction.denom_attribute;
	return in;
}//*/



//**********************************




Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	int num = (lhs.numerator() * rhs.denominator()) + (rhs.numerator() * lhs.denominator());
	int denom = lhs.denominator() * rhs.denominator();
	return Fraction(num, denom);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	int num = (lhs.numerator() * rhs.denominator()) - (rhs.numerator() * lhs.denominator());
	int denom = lhs.denominator() * rhs.denominator();
	return Fraction(num, denom);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	int num = lhs.numerator() * rhs.numerator();
	int denom = lhs.denominator() * rhs.denominator();
	return Fraction(num, denom);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	int num = lhs.numerator() * rhs.denominator();
	int denom = lhs.denominator() * rhs.numerator();
	return Fraction(num, denom);
}

Fraction& Fraction::operator-() {
	numer_attribute = -numer_attribute;
	return *this;
}



Fraction Fraction::operator++(int unused) {
	Fraction frac;
	frac.numer_attribute = numer_attribute;
	frac.denom_attribute = denom_attribute;
	numer_attribute += denom_attribute;
	return frac;
}

Fraction& Fraction::operator++() {
	numer_attribute = numer_attribute + denom_attribute;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& right) {
	numer_attribute = (numer_attribute * right.denom_attribute) + (right.numer_attribute * denom_attribute);
	denom_attribute = denom_attribute * right.denom_attribute;

	
	int divisor = GCD(numer_attribute, denom_attribute);
	numer_attribute /= divisor;
	denom_attribute /= divisor;
	inverse_negative(numer_attribute, denom_attribute);

	return *this;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() == lhs.denominator() * rhs.numerator())
		return true;

	return false;
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() < lhs.denominator() * rhs.numerator())
		return true;

	return false;
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() > lhs.denominator() * rhs.numerator())
		return true;
	
	return false;
}

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() <= lhs.denominator() * rhs.numerator())
		return true;

	return false;
}


bool operator>=(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() >= lhs.denominator() * rhs.numerator())
		return true;

	return false;
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
	if (lhs.numerator() * rhs.denominator() != lhs.denominator() * rhs.numerator())
		return true;

	return false;
}
