#include "Date.h"

// Checks and prints a date.
bool printDate ( const Date& );

// Tests member fuctions of Date class.

int main ( )
{

    Date defDate;
    cout << " 1: defDate: "; printDate ( defDate ); cout <<  endl;

    Date date1 ( "january", 15 );
    cout << " 2: date1: "; printDate ( date1 ); cout <<  endl;

    Date date2 ( "march", 15 );
    cout << " 3: date2: "; printDate ( date2 ); cout <<  endl;

    Date date3 ( "July", 4, 1776 );
    cout << " 4: date3: "; printDate ( date3 ); cout <<  endl;

    Date finDate ( "May", 8, 2000 );
    cout << " 5: finDate: "; printDate ( finDate ); cout <<  endl;

    finDate.addYear ( 2 );
    cout << " 6: finDate: "; printDate ( finDate ); cout <<  endl;

    Date datex ( "February", 29, 2000 );
    Date date4 ( datex ); date4.addYear ( 1 );
    cout << " 7: date4: "; printDate ( date4 ); cout <<  endl;

    Date date5 ( datex ); date5.addYear ( 4 );
    cout << " 8: date5: "; printDate ( date5 ); cout <<  endl;

    date3.addMonth ( 1 );
    cout << " 9: date3: "; printDate ( date3 ); cout <<  endl;

    date3.addMonth ( 8 );
    cout << "10: date3: "; printDate ( date3 ); cout <<  endl;

    date3.addMonth ( 10 ).addYear ( 200 );
    cout << "11: date3: "; printDate ( date3 ); cout <<  endl;

    date3.addMonth ( -10 ).addYear ( -200 );
    cout << "12: date3: "; printDate ( date3 ); cout <<  endl;

    date3.addMonth ( -4 );
    cout << "13: date3: "; printDate ( date3 ); cout <<  endl;

    date3.addMonth ( 277 ).addYear ( 200 );
    cout << "14: date3: "; printDate ( date3 ); cout <<  endl;

    defDate.addYear ( -2000 );
    cout << "15: defDate: "; printDate ( defDate ); cout <<  endl;

    defDate.addYear ( -2000 );
    cout << "16: defDate: "; printDate ( defDate ); cout <<  endl;

    defDate.addYear ( 1 );
    cout << "17: defDate: "; printDate ( defDate ); cout <<  endl;

    defDate.addYear ( 2000 );
    cout << "18: defDate: "; printDate ( defDate ); cout <<  endl;

    datex = Date ( "January", 31, 2016 );
    datex.addMonth ( 1 );
    cout << "19: datex: "; printDate ( datex ); cout <<  endl;

    datex.setDay ( 29 );
    cout << "20: datex: "; printDate ( datex ); cout <<  endl;

    datex.addMonth ( -1 );
    cout << "21: datex: "; printDate ( datex ); cout <<  endl;

    datex.addYear ( 1 );
    cout << "22: datex: "; printDate ( datex ); cout <<  endl;

    Date date6;
    date6.addDay ( 10 );
    cout << "23: date6: "; printDate ( date6 ); cout <<  endl;

    date6.addDay ( 30 );
    cout << "24: date6: "; printDate ( date6 ); cout <<  endl;

    date6.addDay ( 30 );
    cout << "25: date6: "; printDate ( date6 ); cout <<  endl;

    date6.addDay ( 365 );
    cout << "26: date6: "; printDate ( date6 ); cout <<  endl;

    date6.addDay ( -1 );
    cout << "27: date6: "; printDate ( date6 ); cout <<  endl;

    date6.addDay ( -365 );
    cout << "28: date6: "; printDate ( date6 ); cout <<  endl;

    date6.addDay ( -70 );
    cout << "29: date6: "; printDate ( date6 ); cout <<  endl;

    Date date7, date8 ( "December", 31 );
    unsigned d = dateDiff ( date7, date8 );
    cout << "30: from "; printDate ( date7 ); cout << " to ";
    printDate ( date8 ); cout <<  " : ";
    cout << d << " day" << ( d != 1 ? "s" : "" ) << endl;

    d = dateDiff ( defDate, date8 );
    cout << "31: from "; printDate ( defDate ); cout << " to ";
    printDate ( date8 ); cout <<  " : ";
    cout << d << " day" << ( d != 1 ? "s" : "" ) << endl;

    Date date9 ( "December", 31, -1 );
    d = dateDiff ( date9, defDate );
    cout << "32: from "; printDate ( date9 ); cout <<  " to ";
    printDate ( defDate ); cout << " : ";
    cout << d << " day" << ( d != 1 ? "s" : "" ) << endl;

    Date date10 ( defDate );
    date10.addDay ( 1000000 );
    cout << "33: date10: "; printDate ( date10 ); cout << endl;

    cout << "34: date10: dayIndex = " << date10.dayIndex ( ) << endl;

    Date date11 ( defDate );
    date11.addDay ( -1000000 );
    cout << "35: date11: "; printDate ( date11 ); cout <<  endl;

    cout << "36: date11: dayIndex = " << date11.dayIndex ( );
    cout <<  endl;

    date10 = date3;
    cout << "37: date10: "; printDate ( date10 ); cout <<  endl;

    date10.addDay ( 56 ).addYear ( -2000 ).addMonth ( 12).
        addYear ( 1999 ).addDay ( 14 );
    cout << "38: date10: "; printDate ( date10 ); cout <<  endl;

    Date date12 ( "February", 29, 1900 );
    cout << "39: date12: "; printDate ( date12 ); cout <<  endl;

    Date date13 ( "March", 15, 0 );
    cout << "40: date13: "; printDate ( date13 ); cout <<  endl;

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
