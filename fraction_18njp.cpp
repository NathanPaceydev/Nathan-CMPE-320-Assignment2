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


Fraction::Fraction(int numer,int denom) {
	if (denom == 0)
		throw FractionException("Zero value denominator Error:\n Cannot divide by 0!!");

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
const int Fraction::GCD(const int& x, const int& y) {
	if (x == 0)
		return 1;
	if (y == 0)
		return x;

	return GCD(y, x % y);
}




// ** OVERLOADING OPERATORS ************************
//TODO figure out a decent way to organize this section

ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numer_attribute << "/" << fraction.denom_attribute;
	return out;
}



istream& operator>>(istream& in, Fraction& fraction)
{
	// read numerator
	in >> fraction.numer_attribute;
	// read next character
	int current = in.get();
	 // note if no '/' is inputted current = 10

	if (fraction.numer_attribute == 0 || current == 10) {
		fraction.denom_attribute = 1;
		return in;
	}
	// else 
	in >> fraction.denom_attribute;
	return in;
}

//**********************************
// operators to be optimized !!!!!

//functions to maybe simplify this garbage idk!!!
vector<int> operation_func(const int lhs_num, const int rhs_denom, const int rhs_num, const int lhs_denom, const int casevar) {
	vector<int> fraction_arr;
	//case var {0:add, 1:subtract, 2:mul, 3:divide}

	switch (casevar) {

		case 0://adding
			fraction_arr.push_back((lhs_num * rhs_denom) + (rhs_num * lhs_denom));//numerator
			fraction_arr.push_back(lhs_denom * rhs_denom); //denominator
			break;

		case 1://subtracting
			fraction_arr.push_back((lhs_num * rhs_denom) - (rhs_num * lhs_denom));//numerator
			fraction_arr.push_back(lhs_denom * rhs_denom); //denominator
			break;

		case 2://multiply
			fraction_arr.push_back(lhs_num * rhs_num);//numerator
			fraction_arr.push_back(lhs_denom * rhs_denom); //denominator
			break;

		case 3: //divide
			fraction_arr.push_back(lhs_num * rhs_denom);//numerator
			fraction_arr.push_back(lhs_denom * rhs_num); //denominator
			break;

	}

	//		fraction_arr[0]->numerator, fraction_arr[1]->denominator
	return fraction_arr;
	
}


Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	vector<int> add_arr =(operation_func(lhs.numerator(), rhs.denominator(), rhs.numerator(), lhs.denominator(), 0));
	return Fraction(add_arr[0], add_arr[1]);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	vector<int> sub_arr = (operation_func(lhs.numerator(), rhs.denominator(), rhs.numerator(), lhs.denominator(), 1));
	return Fraction(sub_arr[0], sub_arr[1]);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	vector<int> mul_arr = (operation_func(lhs.numerator(), rhs.denominator(), rhs.numerator(), lhs.denominator(), 2));
	return Fraction(mul_arr[0], mul_arr[1]);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	vector<int> div_arr = (operation_func(lhs.numerator(), rhs.denominator(), rhs.numerator(), lhs.denominator(), 3));
	return Fraction(div_arr[0], div_arr[1]);
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
