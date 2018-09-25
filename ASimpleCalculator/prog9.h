/*
 * Program Name: A simple Calculator
 * Program Number: 9
 * Program Author : Ankita Upadhyay
*/
/*Header file prog9.h*/
#ifndef ANKITA_PROG9_H //directive means if the following is defined
#define ANKITA_PROG9_H //directive means if the following is defined
#define UNUSED(p) ( (void)(p)        )
 //defining a macro unsed to remove unused variable warnings
#include <iostream>// c++ input/output streams are primarily defined by iostream standard header file
#include <stack>// c++ stack container are primarily defined by stack standard header file
#include <string>// c++ string are primarily defined by string standard header file
#include <iomanip>// c++ manipulators are primarily defined by iomanip standard header file
#include <sstream>// c++ string stream are primarily defined by sstring standard header file
using namespace std;// std is the standard namespace

/* Function Name : process_token
   Return type : void
   Description : Inspects each character in
token in sequence and takes the proper action for the inspected character in token.
If the character is a digit, a unary –/+ sign that can be determined by the
predicate unarySign ( ), or a valid decimal point that can be determined by the
predicate floatPoint ( ), it calls the routine getNumber ( ) to get all characters of the
corresponding number from token (whose description and the descriptions of the
two helper functions in this process are given below) and puts the number in
stack S.
*/
void process_token ( const string& token, stack < double >& S );

/* Function Name : stringToDouble
   Return type : double
   Description : convert the processed substring to a number 
*/
double stringToDouble ( const string& token);

/* Function Name : floatPoint
   Return type : bool
   Description :   Checks if the
character c in position i in token is a valid decimal point, which is considered valid
if it’s not the last character in token and the character follows it is a digit.
*/
bool floatPoint ( const char& c, const string& token, const unsigned& i );

/* Function Name : getNumber
   Return type : double
   Description :   Starts with the character c in position i in token and constructs a
double-precision floating number from a set of consecutive characters in token. It
also counts the total number of decimal points in the corresponding number, and
in case that the number contains more than one decimal point, it indicates this
error by printing out an error message on stderr. Otherwise, it calls the routine
stringToDouble ( ) to convert the processed substring to a number and returns to
the routine process_token ( ). The last argument floatPointFlag indicates that if c is a
decimal point. 
*/
double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag );

/* Function Name : unarySign
   Return type : bool
   Description :   Checks if the
character c in position i in token is a valid unary –/+ sign, which is considered
valid if it’s not the last character in the token and the character follows it is either
a digit or a decimal point.
*/
bool unarySign ( const char& c, const string& token, const unsigned& i );

/* Function Name : isValidOperator
   Return type : bool
   Description :   Checks if the character c is one of the four valid
operators in { +, -, *, / }*/
bool isValidOperator ( const char& c );

/* Function Name : operation
   Return type : double
   Description :  pops two top numbers from
stack S, computes the corresponding operation on these numbers */
double operation ( const char& c, const double& x, const double& y );

/* Function Name : popStack
   Return type : double
   Description :  Checks if stack S is empty, and if it’s, it prints
out an error message on stderr to indicate the error. Otherwise, it removes and
returns the number at the top of S to the calling routine.*/
double popStack ( stack < double >& S );

/* Function Name : printResult
   Return type : void
   Description :   Checks if stack S is empty, and if it’s, it
prints out an error message on stderr to indicate the error. Otherwise, it prints out
the top number in S on stdout by exactly two digits after the decimal point.
*/
void printResult ( const stack < double >& S );

/* Function Name : emptyStack
   Return type : void
   Description : Pops the top element from stack S and continue
by popping the top element until S becomes empty.*/
void emptyStack ( stack < double >& S );
#endif //ANKITA_PROG9_H
