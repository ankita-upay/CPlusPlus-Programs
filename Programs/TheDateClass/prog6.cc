#include "Date.h"

// Checks and prints a date.
bool printDate ( const Date& );

// Tests member fuctions of Date class.

int main ( )
{
    Date defaultDate;                       // default date
    printDate ( defaultDate ); cout << endl;

    Date moonLanding ( "jul", 20, 1969 );   // date to moon landing
    printDate ( moonLanding ); cout << endl;
    moonLanding.setMonth ( "july" );        // correct the month
    printDate ( moonLanding ); cout << endl;

    Date leapDay ( "FEBRUARY", 29, 2001 );  // leap day
    printDate ( leapDay ); cout << endl;
    leapDay.setDay ( 28 );                  // correct the leap day
    printDate ( leapDay ); cout << endl;

    // Get and print the individual components of the default date
    // by using the getters.

    Date d;
    cout << d.getMonth ( ) << " " << d.getDay ( )
         << ", " << d.getYear ( ) << endl;

    // Set and print the individual components of the independence day
    // by using the setters.

    d.setMonth ( "July"); d.setDay ( 4 ); d.setYear ( 1776 );
    printDate ( d ); cout << endl;

    // Get several dates from the stdin until EOF. Print each date in
    // a proper format, and if the date is a valid, also print the
    // date in the form dd-mmm-yyy.

    while ( cin >> d ) {
        d.Month ( ); bool flag = printDate ( d ); cout << endl;
        if ( flag ) cout << d.toString ( ) << endl;
    }

    return 0;
}

// Checks and prints a date. If the date is invalid, it prints an
// error message on stderr and returns the logical value false
// to the main ( ) routine to flag the error.

bool printDate ( const Date& d )
{
    if ( !d.isValidDate ( ) ) {
        cerr << "( " << d << " ) : not valid date";
        return false;
    }

    cout << "( " << d << " )"; return true;
}
