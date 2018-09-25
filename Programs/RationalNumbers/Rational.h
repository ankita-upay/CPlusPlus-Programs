/*
 * Program Name: Rational Number
 * Program Number: 8
 * program Author : Ankita Upadhyay
*/
/* Header File */
#ifndef ANKITA_RATIONAL_H
#define ANKITA_RATIONAL_H
#include <iostream>//HEADER FILE STANDARD INPUT OUTPUT

using namespace std;//USING NAMESPACE STANDARD

/* Declaring class Rational with public and private
* member function and instance variable */

class Rational {
    /*private members of Rational class*/
private:
    int num;//declaring instance variable num of integer type
    int den;//declaring instnce variable den of integer type
	/*prototype for private member function gcd which returns
	the greatest common divisor of the arguments x and y*/
    int gcd(int x,int y);
    /*public members of Rational class*/
public:
/*This public constructor is used to create a Rational object
* with the numerator n and denominator d. If d = 0, it prints out
* an error message on stderr, but it doesnâ€™t stop the execution
* of the program. To reduce a Rational number to its lowest
* terms, it calls the private member function*/
Rational(const int &n = 0, const int &d = 1);
/* Below is a  public copy constructor used to create
 * a Rational object from the copy of the Rational object r. */
    Rational(const Rational &r);
/* Below is the public assignment operator overwrites an
 * existing Rational object with the copy of the Rational
 * object r. */
    Rational &operator=(const Rational &r);
/* The below four public member functions overload the
 * operators +=, –=, *=, and /= operators,
 * respectively, for the Rational class. */
    Rational &operator+=(const Rational &r);
    Rational &operator-=(const Rational &r);
    Rational &operator*=(const Rational &r);
    Rational &operator/=(const Rational &r);
/*The below two public member functions overload the 
 * pre-increment (++) and 
 * pre-decrement (––) operators, 
 * respectively, for the Rational class.*/
    Rational &operator++();
    Rational &operator--();
/* The below two public member functions overload the post-increment (++)
 * and post-decrement (––) operators, respectively, for the Rational class.
 * Note: To differentiate between the pre- and post- versions of the
 * operators (++) and (––), an unused argument is included in the
 * post-versions of these operators.*/
    Rational operator++(int);
    Rational operator--(int);
/* The below four friend functions overload the arithmetic
 * operators +, –, *, and /, respectively,
 * for the Rational class.*/
    friend Rational operator+(const Rational &r1, const Rational &r2);
    friend Rational operator-(const Rational &r1, const Rational &r2);
    friend Rational operator*(const Rational &r1, const Rational &r2);
    friend Rational operator/(const Rational &r1, const Rational &r2);
/* The below six friend functions
overload the relational operators ==, !=, <, <=, >, and >=, 
respectively, for the Rational class.*/
    friend bool operator==(const Rational &r1, const Rational &r2);
    friend bool operator!=(const Rational &r1, const Rational &r2);
    friend bool operator<(const Rational &r1, const Rational &r2);
    friend bool operator<=(const Rational &r1, const Rational &r2);
    friend bool operator>(const Rational &r1, const Rational &r2);
    friend bool operator>=(const Rational &r1, const Rational &r2);
/* This friend function
overloads the stream insertion operator (<<) for the Rational class. It can be
used to print out the Rational number r with the numerator num and
denominator den as num/den on the output stream os, and if den = 1, it only
prints out num.*/
    friend ostream &operator<<(ostream &, const Rational &);
/*This friend function overloads
the stream extraction operator (>>) for the Rational class. It can be used to
read the Rational number r from the input stream is, where each Rational
number is given on a separate line with its three arguments: numerator,
separator (/), and denominator, separated one or more white spaces. If a line
in is does not contain a valid Rational number, it prints out an error message
on stderr, but it doesn’t stop the execution of the program.*/
    friend istream &operator>>(istream &, Rational &);
};
#endif //ANKITA_RATIONAL_H
