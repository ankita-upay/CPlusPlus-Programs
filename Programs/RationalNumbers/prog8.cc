
#include "Rational.h"

int main ( )
{
    Rational r0; cout << "\nr0 = " << r0 << endl;
    Rational r1 ( 1, 3 ); cout << "r1 = " << r1 << endl;
    Rational r2 ( 2, 6 ); cout << "r2 = " << r2 << endl;
    Rational r3 ( 100, 300 ); cout << "r3 = " << r3 << endl;
    Rational r4 ( -1, -3 ); cout << "r4 = " << r4 << endl << endl;

    Rational r5 ( 1, 0 ); cout << endl;
    Rational r6 ( 0, -5 ); cout << "r6 =  " << r6 << endl;
    Rational r7 ( -2, 5 ); cout << "r7 = " << r7 << endl;
    Rational r8 ( 2, -5 ); cout << "r8 = " << r8 << endl << endl;

    Rational r9 = r1 + r7;
    cout << r1 << " + " << r7 << " = " << r9 << endl;
    Rational r10 = r1 - r7;
    cout << r1 << " - " << r7 << " = " << r10 << endl;
    Rational r11 = r1 * r7;
    cout << r1 << " * " << r7 << " = " << r11 << endl;
    Rational r12 = r1 / r7;
    cout << r1 << " / " << r7 << " = " << r12 << endl << endl;

    cout << r1 << " == " << r7 << '\t'
               << ( r1 == r7 ? 'T' : 'F' ) << endl;
    cout << r1 << " != " << r7 << '\t'
               << ( r1 != r7 ? 'T' : 'F' ) << endl;
    cout << r1 << " <  " << r7 << '\t'
               << ( r1 <  r7 ? 'T' : 'F' ) << endl;
    cout << r1 << " <= " << r7 << '\t'
               << ( r1 <= r7 ? 'T' : 'F' ) << endl;
    cout << r1 << " >  " << r7 << '\t'
         << ( r1 >  r7 ? 'T' : 'F' ) << endl;
    cout << r1 << " >= " << r7 << '\t'
               << ( r1 >= r7 ? 'T' : 'F' ) << endl << endl;

    Rational ra ( r1 ); r1 += r7;
    cout << "(  " << ra << "  += " << r7 << " ) = " << r1 << endl;
    ra = r1; r1 -= r7;
    cout << "( " << ra << " -= " << r7 << " ) =  " << r1 << endl;
    ra = r1; r1 *= r7;
    cout << "(  " << ra << "  *= " << r7 << " ) = " << r1 << endl;
    ra = r1; r1 /= r7;
    cout << "( " << ra << " /= " << r7 << " ) =  " << r1 << endl << endl;

    cout << "r1 = " << r1 << '\t'; cout << "++r1 = " << ++r1 << endl;
    cout << "r1 = " << r1 << '\t'; cout << "--r1 = " << --r1 << endl;
    cout << "r1 = " << r1 << '\t'; cout << "r1++ = " << r1++ << '\t';
    cout << "r1 = " << r1 << endl;
    cout << "r1 = " << r1 << '\t'; cout << "r1-- = " << r1-- << '\t';
    cout << "r1 = " << r1 << endl << endl;

    cin >> r1 >> r2 >> r3;
    cout << "r1 = " << r1  << "\tr2 = " << r2 << "\tr3 = " << r3
         << endl << endl;

    cin >> r4 >> r5; cout << endl;
    return 0;
}
