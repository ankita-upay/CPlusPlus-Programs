/*  Progiram name  : To Find and Diplay perfect numbers between 1 to 9999
 *  Program Author : Ankita Upadhyay
 *  Z-ID           : z1836412
 *  Date Started   : September,8th 2017
 *  Date completed  : September,13th 2017
 *     */
/*Header File : prog2.h */

/*Includes all system header files, constant value and the prototypes of all sub-routine used*/

#ifndef prog2 //directive means if the following is defined
#define prog2 // directive defines a preprocessor macro
#include <iostream> // C++ input/output streams are primarily defined by iostream standard header file
#include <string> // c++ string header file

using namespace std;// std is the standard namespace

const unsigned int min_value = 1; // defining a constant unsigned integer variable min_value and assigning it value 1
const unsigned int max_value = 9999; // defining a constant unsigned integer variable max_value and assigning it value 9999

/*Defining the prototype of the sub-routine isPerfect used to check for the perfect numbers within min_value and max_value*/
bool isPerfect(int n);
/* Defining prototype of sub-routine printDivisors used to display divisors as sequence n = d1 + d2 + … + dm, where d1, d2, …, dm are the divisors of n with d1 = 1*/
string  printDivisors(int n);

#endif
