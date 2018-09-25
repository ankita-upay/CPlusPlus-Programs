/*
 * Program Name: Rational Number
 * Program Number: 8
 * Program Author : Ankita Upadhyay
*/
/*Source file Rational.cc*/
/*including header file*/
#include "Rational.h"
/*This public constructor is used to create a Rational object
 * with the numerator n and denominator d. If d = 0, it prints out
 * an error message on stderr, but it does not stop the execution
 * of the program. To reduce a Rational number to its lowest
 * terms, it calls the private member function*/
Rational::Rational(const int &n, const int &d){
    /*initializing instance variable num and den
     * value to input value n and d respectively*/
    num=n;
    den=d;
    int g = 1;//declaring a integer variable g with value 1
    /*if the denominator is equal to 0 , the stderr
     * displays an error message */
    if (den == 0) {
        cerr << "Error: division by zero" << endl;
    }
        /*else if the denominator is a negative value ,
         * denominator and numerator both are multiplied by -1*/
    else if (den < 0) {
        den = -d;
        num = -n;
    }
        /*we call private member function gcd ,and store
         * the value in g,numerator and denominator are both
         * divided by g to get the simplified form*/
    else {
        g = gcd (num, den);
        num = (num / g);
        den = (den / g);
    }
}
/* Below is a  public copy constructor used to create
 * a Rational object from the copy of the Rational object r. */
Rational::Rational(const Rational &r) {
    int g = 1;//declaring a integer variable g with value 1
    /*Assigning the created objects numerator and denominator
     * value in instance variable num and den respectively*/
    num = r.num;
    den = r.den;
    /*we call private member function gcd ,and store
        * the value in g,numerator and denominator are both
        * divided by g to get the simplified form*/
    g = gcd (num, den);
    num = (num / g);
    den = (den / g);
}
/* Below is the public assignment operator overwrites an
 * existing Rational object with the copy of the Rational
 * object r. */
Rational &Rational::operator=(const Rational &r) {
    /*Assigning the created objects numerator and denominator
     * value in instance variable num and den respectively*/
    num = r.num;
    den = r.den;
    return *this;//return the reference to the pointer of the current object
}
/* The below four public member functions overload the
 * operators +=, –=, *=, and /= operators,
 * respectively, for the Rational class. */
/*Overloading operator +=*/
Rational &Rational::operator+=(const Rational &r) {
    int g = 1;//declaring a integer variable g with value 1
    /* Mathematical equation :
     * num/den+=r.num/r.den
     * => num=num*r.den + r.num*den , den = den*r.den*/
    num = ((num*r.den) + (r.num*den));
    den = den*r.den;
    /*we call private member function gcd ,and store
        * the value in g,numerator and denominator are both
        * divided by g to get the simplified form*/
    g = gcd (num, den);
    num = (num / g);
    den = (den / g);
    return *this;//return the reference to the pointer of the current object
}

/*Overloading -=*/
Rational &Rational::operator-=(const Rational &r) {
    int g = 1;//declaring a integer variable g with value 1
    /* Mathematical equation :
     * num/den-=r.num/r.den
     * => num=num*r.den - r.num*den , den = den*r.den*/
    num = ((num * r.den) - (r.num*den));
    den = den*r.den;
    /*we call private member function gcd ,and store
        * the value in g,numerator and denominator are both
        * divided by g to get the simplified form*/
    g = gcd (num, den);
    num = (num / g);
    den = (den / g);
    return *this;//return the reference to the pointer of the current object
}
/*Overloading *= */
Rational &Rational::operator*=(const Rational &r) {
    int g = 1;//declaring a integer variable g with value 1
    /* Mathematical equation :
     * num/den*=r.num/r.den
     * => num=num*r.num, den = den*r.den*/
    num = num*r.num;
    den = den*r.den;
    /*we call private member function gcd ,and store
       * the value in g,numerator and denominator are both
       * divided by g to get the simplified form*/
    g = gcd (num, den);
    num = (num / g);
    den = (den / g);
    return *this;//return the reference to the pointer of the current object
}
/*overloading operator /= */
Rational &Rational::operator/=(const Rational &r) {
    int g = 1;//declaring a integer variable g with value 1
    /* Mathematical equation :
     * num/den/=r.num/r.den
     * => num=num*r.den, den = den*r.num*/
    if (r.num == 0) {
        cerr << "Error: Numerator cannot be 0";
    } else {
        num = num * r.den;
        den = den * r.num;
        /*we call private member function gcd ,and store
       * the value in g,numerator and denominator are both
       * divided by g to get the simplified form*/
        g = gcd (num, den);
        num = (num / g);
        den = (den / g);
        /*if denominator is -ve multiply denominator and numerator by -1*/
        if (den < 0) {
            den = -(den);
            num = -(num);
        }
    }
    return *this;//return the reference to the pointer of the current object
}
/*The below two public member functions overload the 
 * pre-increment (++) and 
 * pre-decrement (––) operators, 
 * respectively, for the Rational class.*/
/*overloading pre-increment (++)*/
Rational &Rational::operator++() {
    int g = 1;//declaring a integer variable g with value 1
    num += den;
	 /*we call private member function gcd ,and store
       * the value in g,numerator and denominator are both
       * divided by g to get the simplified form*/
    g = gcd (num, den);
    num = (num / g);
    return *this;//return the reference to the pointer of the current object
}

/*overloading pre-decrement (--)*/
Rational &Rational::operator--() {
    int g = 1;//declaring a integer variable g with value 1
    num -= den;
	 /*we call private member function gcd ,and store
       * the value in g,numerator and denominator are both
       * divided by g to get the simplified form*/
    g = gcd (num, den);
    num = (num / g);
    return *this;//return the reference to the pointer of the current object
}

/* The below two public member functions overload the post-increment (++)
 * and post-decrement (––) operators, respectively, for the Rational class.
 * Note: To differentiate between the pre- and post- versions of the
 * operators (++) and (––), an unused argument is included in the
 * post-versions of these operators.*/
/*overloading post increment operator (++)*/
Rational Rational::operator++(int unused) {
    int i = unused;// declaring a variable i of integer type and assigning it 
    i += 0;
    Rational c (*this);
    operator++ ();
    return c;
}
/*overloading post decrement operator (--)*/
Rational Rational::operator--(int unused) {
    int i = unused;
    i += 0;
    Rational c (*this);
    operator-- ();
    return c;
}

/* The below private member function: 
int gcd ( int x, int y ) that returns the 
greatest common divisor of the arguments x and y */
int Rational::gcd(int x, int y) {
    int divisor = 1;//declaring a variable divisor of integer type and assigning value 1 to it
	/*if the second value that is denominator is 0 stderr returns error message*/
    if (y == 0) {
        cerr << "Error: division by zero";
    } else {
		/*takes absolute value of the numerator and denominator to find gcd */
        x = abs (x);
        y = abs (y);
		/*for loop to start prime factorization for two numbers */
        for (int i = 2; i <= x; i++) {
			
            if (x % i == 0 && y % i == 0)
                divisor = i;
        }
    }
    return divisor;//return the greatest common divisor
}

/* The below four friend functions overload the arithmetic
 * operators +, –, *, and /, respectively,
 * for the Rational class.*/
/*overloading operator +*/
Rational operator+(const Rational &r1, const Rational &r2) {
    Rational f = r1;
    f += r2;
    return f;
}
/*overloading operator -*/
Rational operator-(const Rational &r1, const Rational &r2) {
    Rational f = r1;
    f -= r2;
    return f;
}
/*overloading operator * */
Rational operator*(const Rational &r1, const Rational &r2) {
    Rational f = r1;
    f *= r2;
    return f;
}
/*overloading operator -*/
Rational operator/(const Rational &r1, const Rational &r2) {
    Rational f = r1;
    f /= r2;
    return f;
}

/* The below six friend functions
overload the relational operators ==, !=, <, <=, >, and >=, 
respectively, for the Rational class.*/
/*overloading operator == and return true if both rational 
numbers have same numerator and denominator*/
bool operator==(const Rational &r1, const Rational &r2) {
    if (r1.num == r2.num && r1.den == r2.den)
        return true;
    else
        return false;
}
/*overloading operator != */
bool operator!=(const Rational &r1, const Rational &r2) {
    return !(operator== (r1, r2));
}
/*overloading operator < */
bool operator<(const Rational &r1, const Rational &r2) {
    int f = 0, i = 0;
    f = abs (r1.num - r1.den);
    i = abs (r2.num - r2.den);
    if (f > i && r1.num < r2.num && r1.den < r2.den)
        return true;
    else
        return false;
}
/*overloading operator <= */
bool operator<=(const Rational &r1, const Rational &r2) {
    int f = 0, i = 0;
    f = abs (r1.num - r1.den);
    i = abs (r2.num - r2.den);
    if (f >= i && r1.num <= r2.num && r1.den <= r2.den)
        return true;
    else
        return false;
}
/*overloading operator > */
bool operator>(const Rational &r1, const Rational &r2) {
    return !(operator< (r1, r2));
}
/*overloading operator >= */
bool operator>=(const Rational &r1, const Rational &r2) {
    return !(operator<= (r1, r2));
}

/* This friend function
overloads the stream insertion operator (<<) for the Rational class. It can be
used to print out the Rational number r with the numerator num and
denominator den as num/den on the output stream os, and if den = 1, it only
prints out num.*/
/*overloading operator <<*/
ostream &operator<<(ostream &os, const Rational &r) {
    if (r.den == 1 || r.num == 0)
        os << r.num;
    else
        os << r.num << "/" << r.den;
    return os;
}

/*This friend function overloads
the stream extraction operator (>>) for the Rational class. It can be used to
read the Rational number r from the input stream is, where each Rational
number is given on a separate line with its three arguments: numerator,
separator (/), and denominator, separated one or more white spaces. If a line
in is does not contain a valid Rational number, it prints out an error message
on stderr, but it doesn’t stop the execution of the program.*/
/*operator overloading*/
istream &operator>>(istream &is, Rational &r) {
    char c;//declaring variable c of character type
    char ln;//declaring variable ln of character type
    int l;//declaring variable l of integer type
    is >> r.num;//inputting numerator part of object r
    is >> c;//inputting character 
    /*if the character entered is digit then we unget the character*/
    if (isdigit (c)) {
        is.unget ();
    }
    /*if the character entered is / then the next entered digit will be denominator*/
    if (c == '/') {
        is >> r.den;
/*stream is inputting whitespace and then checking the next charcter */
        ln = (is >> ws).peek ();
        /*if the next charcter is equal to 9 then stderr displays error message */
        if (ln == 9) {
            cout << "Error: line \"" << r.num << c << r.den << " " << ln << ln << ln << "\" contains invalid number"
                 << endl;
            is >> l;
        }
    } 
	/*if istream encounters ':' displays error message on stderr */
	else if (c == ':') {
        is >> r.den;
        cout << "Error: line \"" << "   " << r.num << " " << c << " " << r.den << "\" contains invalid number" << endl;
    } else {
        r.den = 1;
    }
    return is;//return the input stream
}






