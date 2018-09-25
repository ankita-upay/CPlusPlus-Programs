//
// Created by piyush on 10/30/17.
//

#ifndef PROG1_DATE_CC_H
#define PROG1_DATE_CC_H

#endif //PROG1_DATE_CC_
/*Program name  : Thee Date Class
*  Program Author : Ankita Upadhyay
*   Z-ID           : z1836412
*    Date Started   : October,16th 2017
*     Date completed : October,23rd 2017
*     */

/*Header File : Date.h */

/*Includes all system header files, constant value and the prototypes of all sub-routine used*/

#ifndef ANKITA_THEDATECLASS_H//directive means if the following is defined
#define ANKITA_THEDATECLASS_H//directive means if the following is defined

#include <iostream>// c++ input/output streams are primarily defined by iostream standard header file
#include <string>// c++ string header file
#include <ctime>
using namespace std;// std is the standard namespace

/*Date Class*/
class Date{

private :

    /*private data members: string month, int day, and int year*/
    string month;
    int day;
    int year;
    /*private member function bool isLeapYear ( ) const to find if a year is leap or not*/
    bool isLeapYear ( ) const;

    /*the private member function int daysInMonth ( const string& m ) const to return the number
     *  * of days in the month m to check if the day component is valid. If the month m is February,
     *   * the function daysInMonth ( ) calls the private member function bool isLeapYear ( ) const
     *    * to get the correct number of days in the month m*/
    int daysInMonth ( const string& m ) const;

    /*the private member function bool isValidMonth ( ) const check if the month component is valid*/
    bool isValidMonth () const;
public:


    Date ();//Default Constructor
    Date ( const string&, const int&);
    /*Constructor with valid arguments*/
    Date ( const string&, const int&, const int&);

/*This is a public copy constructor that can be used to create a new Date object
 * from the copy of the Date object d.*/

    Date( const Date& d );


    /*This is a public assignment operator that overwrites an existing Date object with the copy
     of the Date object d.*/

    Date& operator= ( const Date& d );
    int monthIndex ( );
    /*public function can be used to add n number of days to a Date object.*/

    Date& addDay ( const int& n );
    Date& addMonth ( const int& n );
    Date& addYear ( const int& n );
    /* public member functions can be used to set the month, day, and year components
     *      * of a Date object to the values m, d, and y, respectively, by a client program.*/
    void setMonth ( const string& m );
    void setDay ( const int& d );
    void setYear ( const int& y );

    /* public member functions can be used to set the month, day, and year components
     *      * of a Date object to the values m, d, and y, respectively, by a client program.*/
    string getMonth ( ) const;
    int getDay ( ) const;
    int getYear ( ) const;
    int dayIndex ( ) const;

    /*public member function can be used to convert the month component of a Date object by
     *      * changing its first letter to uppercase and the rest of its letters to lowercase, so
     *           * the month of a date can be entered as case insensitive.*/
    void Month ();
    string Monthy(string);

    /*public member function checks a Date object, and if it’s a valid date, it returns true;
     *      * otherwise, it returns false.*/
    bool isValidDate ( ) const ;


/*public member function can be used to convert the
 * month component of a Date object in the form dd–mmm–yyyy, where dd is a
 * one- or two-digit date, mmm the three-letter abbreviation for the month, and
 * yyyy is the four-digit year.*/
    string toString ( );


    /*the non-member function: string intToString ( const int& n ), which takes
     * the integer value n and returns its corresponding value as a string*/
    string intToString ( const int& n );

    /*This non-member function can
     * be implemented as a friend to the Date class, which overloads the extraction
     * operator (>>). It reads the individual date components from the stream is to
     * the Date object d, where a date can be entered either in the form month day
     * year or month day, year.*/
    friend istream& operator >> ( istream& is, Date& d );

    /*This non-member
     * function can also be implemented as a friend to the Date class, which overloads
     * the insertion operator (<<). It gets the individual components from the Date
     * object d and to the stream os, where d is inserted in os in the form month day,
     * year*/
    friend ostream& operator<< ( ostream& os, const Date& d );

};
unsigned dateDiff ( const Date& d1, const Date& d2 );

#endif //ANKITA_THEDATECLASS_HH
