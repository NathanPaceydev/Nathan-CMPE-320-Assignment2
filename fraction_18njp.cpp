/* Assignment 2 - The Fraction Class
 * Implementation file: fraction_18njp.cpp
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 */


#include "fraction_18njp.h" //include header file

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


//###################### 0 DIVIDE ERROR MESSAGE ###################################################
FractionException::FractionException(const string& fractionExceptionString) : fractionExceptionString(fractionExceptionString) {}
string &FractionException::what() { 
	return fractionExceptionString;
}


//####################### FRACTION CLASS ATTRIBUTES AND METHODS #################################
// numerator attribute
const int& Fraction::numerator()const{
	return numerator_attribute;
}

// denominator attribute
const int& Fraction::denominator()const{
	return denom_attribute;
}

// fraction class implementation
Fraction::Fraction(int numerator, int denom){
	if (denom == 0)
		throw FractionException("Zero value denominator Error:\n Cannot divide by 0!!");

	reduce(numerator, denom, numerator_attribute, denom_attribute);
}

// method to use GCD and inverse to normalize the fraction
void Fraction::reduce(int &numerator, int &denom, int &numerator_attribute, int &denom_attribute){
	int gcd = GCD(numerator, denom);
	numerator_attribute = numerator/ gcd;
	denom_attribute = denom / gcd;

	inverse_negative(numerator_attribute, denom_attribute);
}

// recursive method to calculate the greatest common denominator of ints x and y
const int Fraction::GCD(const int &x, const int &y){
	if (x == 0)
		return 1;
	if (y == 0)
		return x;

	return GCD(y, x % y);
}

// method to normalize the negative in a fraction
void Fraction::inverse_negative(int &numerator_attribute, int &denom_attribute){
	if (numerator_attribute * denom_attribute < 0){
		numerator_attribute = -abs(numerator_attribute);
		denom_attribute = abs(denom_attribute);
	}
	else {
		numerator_attribute = abs(numerator_attribute);
		denom_attribute = abs(denom_attribute);
	}
}



//################## Overloading Operators ########################

//****************** Unary Operators **************************
// negation operator overloading
Fraction& Fraction::operator-() { 
	numerator_attribute = -numerator_attribute;
	return *this;
}

// post-increment operator overloading
Fraction Fraction::operator++(int old_value) {
	Fraction new_fraction; // call new instance of the Fraction class

	// set the attributes to the current values
	new_fraction.numerator_attribute = numerator_attribute;
	new_fraction.denom_attribute = denom_attribute;

	numerator_attribute += denom_attribute; //increase the numerator by denom since 1=1/1
	return new_fraction;
}

// pre-increment operator overloading
Fraction& Fraction::operator++() { 
	numerator_attribute += denom_attribute;//increase the numerator by denom since 1=1/1
	return *this;
}

//***************** Basic Binary Operators *******************
// method that populates the fraction_arr based on the arthimatic operator sent
vector<int> operation_func(const int &old_numer, const int &new_denom, const int &new_numer, const int &old_denom, const int &casevar){
	vector<int> fraction_arr;

	//case var {0:add, 1:subtract, 2:mul, 3:divide}
	switch (casevar) {
		case 0://adding
			fraction_arr.push_back((old_numer * new_denom) + (new_numer * old_denom));//numerator
			fraction_arr.push_back(old_denom * new_denom); //denominator
			break;

		case 1://subtracting
			fraction_arr.push_back((old_numer * new_denom) - (new_numer * old_denom));//numerator
			fraction_arr.push_back(old_denom * new_denom); //denominator
			break;

		case 2://multiply
			fraction_arr.push_back(old_numer * new_numer);//numerator
			fraction_arr.push_back(old_denom * new_denom); //denominator
			break;

		case 3: //divide
			fraction_arr.push_back(old_numer * new_denom);//numerator
			fraction_arr.push_back(old_denom * new_numer); //denominator
			break;
	}

	//		fraction_arr[0]->numerator, fraction_arr[1]->denominator
	return fraction_arr;
}

// addition operator overloading
Fraction operator+(const Fraction &old_frac, const Fraction &new_frac){
	// calls the operation_func with casevar = 0
	vector<int> add_arr =(operation_func(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 0));
	return Fraction(add_arr[0], add_arr[1]);
}

// subtraction operator overloading
Fraction operator-(const Fraction &old_frac, const Fraction &new_frac){
	// calls the operation_func with casevar = 1
	vector<int> sub_arr = (operation_func(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 1));
	return Fraction(sub_arr[0], sub_arr[1]);
}

// mul operator overloading
Fraction operator*(const Fraction &old_frac, const Fraction &new_frac){
	// calls the operation_func with casevar = 2
	vector<int> mul_arr = (operation_func(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 2));
	return Fraction(mul_arr[0], mul_arr[1]);
}

// div operator overloading
Fraction operator/(const Fraction &old_frac, const Fraction &new_frac){
	// calls the operation_func with casevar = 3
	vector<int> div_arr = (operation_func(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 3));
	return Fraction(div_arr[0], div_arr[1]);
}

// addition and assignment operator overloading
Fraction& Fraction::operator+=(const Fraction &new_fraction) {
	// add the new fraction to the numerator and denominator
	numerator_attribute = (numerator_attribute * new_fraction.denom_attribute) + (new_fraction.numerator_attribute * denom_attribute);
	denom_attribute = denom_attribute * new_fraction.denom_attribute;

	// call the reduce() method to reduce & normalize the new fraction
	reduce(numerator_attribute, denom_attribute, numerator_attribute, denom_attribute);
	return *this;
}


// ***************** Comparison Operators ************************
/* Method that retruns the overloaded definition of an opererator for the fraction
after being supplied an int representaton of that operator */
const bool comparison(const int &old_numer, const int &new_denom, const int &new_numer, const int &old_denom, const int &casevar) {
	// {0:== or !0:!=, 1:> or !1:<=, 2:< or !2:>=}
	switch (casevar) {
	case(0): // true for ==. !true for !=
		return (old_numer * new_denom == old_denom * new_numer);
		break;
	case(1): //true for >, !true for <=
		return (old_numer * new_denom > old_denom * new_numer);
		break;
	case(2):// true for <, !true fpr >=
		return (old_numer * new_denom < old_denom * new_numer);
		break;
	}

}


// == operator overloading
bool operator==(const Fraction &old_frac, const Fraction &new_frac){
	// call the comparison method with the equality case 0
	return comparison(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 0);
}

// != operator overloading
bool operator!=(const Fraction &old_frac, const Fraction &new_frac){
	// call the comparison method with the !equality case 0
	return !comparison(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 0);
}

// > operator overloading
bool operator>(const Fraction &old_frac, const Fraction &new_frac){
	// call the comparison method with the greater than case 1
	return comparison(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 1);
}

// <= operator overloading
bool operator<=(const Fraction &old_frac, const Fraction &new_frac){
	// call the comparison method with the !greater than case 1
	return !comparison(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 1);
}

// < operator overloading
bool operator<(const Fraction &old_frac, const Fraction &new_frac){
	// call the comparison method with the less than case 2
	return comparison(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 2);
}

// >= operator overloading
bool operator>=(const Fraction &old_frac, const Fraction &new_frac){
	// call the comparison method with the !less than case 2
	return !comparison(old_frac.numerator(), new_frac.denominator(), new_frac.numerator(), old_frac.denominator(), 2);
}


// ***************** Stream Operators *********************
// output operator overloading
ostream& operator<<(ostream &output, const Fraction &output_frac) {
	output << output_frac.numerator_attribute << "/" << output_frac.denom_attribute;
	return output;
}

// input operator overloading
istream& operator>>(istream &input, Fraction &input_frac) {
	input >> input_frac.numerator_attribute; //read input the numerator

	int current = input.get(); // note if no '/' is inputputted current = 10

	// if the numerator is 0 or a whole number set denom_attribute to 1
	if (current == 10 || input_frac.numerator_attribute == 0) {
		input_frac.denom_attribute = 1;
		return input;
	}
	else {
		// otherwise read the denom
		input >> input_frac.denom_attribute;
		return input;
	}
}

