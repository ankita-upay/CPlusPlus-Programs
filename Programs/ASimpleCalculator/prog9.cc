/*
 * Program Name: A simple Calculator
 * Program Number: 9
 * Program Author : Ankita Upadhyay
*/
/*Source file prog9.cc*/
/*including header file*/
#include "prog9.h"
/* Function Name : operation
   Return type : double
   Description :  pops two top numbers from
stack S, computes the corresponding operation on these numbers */
double operation(const char &c, const double &x, const double &y) {
    switch (c) {
        case '+':
            return x + y;

        case '-':
            return x - y;

        case '*':
            return x * y;

        case '/':
            return x / y;

        default:
            cerr << "Error! Key-in a proper operator" << endl;
    }
    return false;
}
/* Function Name : emptyStack
   Return type : void
   Description : Pops the top element from stack S and continue
by popping the top element until S becomes empty.*/
void emptyStack ( stack < double >& S )
{
    for(int i = S.size() ;i!=0 ;i--)
    {
        S.pop();
    }
}
/* Function Name : popStack
   Return type : double
   Description :  Checks if stack S is empty, and if it’s, it prints
out an error message on stderr to indicate the error. Otherwise, it removes and
returns the number at the top of S to the calling routine.*/
double popStack(stack<double> &S) {
    double popValue = 0;
    if (S.size () == 0) {
        cerr << "error: stack is empty" << endl;
    } else {
        popValue = S.top ();
        S.pop ();
        return popValue;
    }
    return popValue;
}
/* Function Name : isValidOperator
   Return type : bool
   Description :   Checks if the character c is one of the four valid
operators in { +, -, *, / }*/
bool isValidOperator(const char &c) {

    if (c == '-' || c == '+' || c == '/' || c == '*') {
        return true;
    }
    {
        return false;
    }
}
/* Function Name : unarySign
   Return type : bool
   Description :   Checks if the
character c in position i in token is a valid unary –/+ sign, which is considered
valid if it’s not the last character in the token and the character follows it is either
a digit or a decimal point.
*/
bool unarySign(const char &c, const string &token, const unsigned &i) {
    bool flag = false;
    if (c == '+' || c == '-') {
        if (i < token.length () && (isdigit (token[i + 1]) || token[i + 1] == '.')) { flag = true; }
        else {

            flag = false;
        }
    }
    return flag;
}
/* Function Name : printResult
   Return type : void
   Description :   Checks if stack S is empty, and if it’s, it
prints out an error message on stderr to indicate the error. Otherwise, it prints out
the top number in S on stdout by exactly two digits after the decimal point.
*/
void printResult(const stack<double> &S) {
    if (S.size () == 0) {
        cerr << "error: stack is empty" << endl;
    } else {
        cout << setprecision (2) << fixed;
        cout.width (8);
        std::cout << std::right << S.top () << endl;
    }
}
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
double getNumber(const char &c, const string &token, unsigned &i, const bool &floatPointFlag) {
    unsigned int count = i;
   UNUSED(c);
    string tempnumber = "";
    int decimalcount = 0;
    while (count < token.length () && (floatPoint (token[count], token, count) || isdigit (token[count]))) {

        if (floatPointFlag) {

            if (token[count] == '.') {
                cerr << "error: character '" << tempnumber << "' is invalid" << endl;
            } else {
                tempnumber.push_back ('.');
                tempnumber.push_back (token[count]);
            }
        } else {
            if (token[count] == '.') {
                decimalcount++;
            }
            if (decimalcount <= 1) {
                tempnumber.push_back (token[count]);
            } else {
                string errnbr;
                for(unsigned int j=i;j<token.length();j++){errnbr.push_back(token[j]);}

                cerr << "error: number '" << errnbr<< "' is invalid" << endl ;break;
            }


        }
        count++;

    }
    i = count - 1;


    return stringToDouble (tempnumber);
}
/* Function Name : floatPoint
   Return type : bool
   Description :   Checks if the
character c in position i in token is a valid decimal point, which is considered valid
if it’s not the last character in token and the character follows it is a digit.
*/
bool floatPoint(const char &c, const string &token, const unsigned &i) {

    bool flag = false;
    if (i < token.length () && isdigit (token[i + 1]) && c == '.') { flag = true; }
    else { //int l = token.length();

        flag = false;
    }
    return flag;
}
/* Function Name : stringToDouble
   Return type : double
   Description : convert the processed substring to a number 
*/
double stringToDouble(const std::string &token) {
    double z;
    size_t offset = 0;
    try {
        z = stod (token, &offset);
    }
    catch (const std::invalid_argument &) {
        std::cerr << "Argument is invalid\n";
        throw;
    }
    return z;
}
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
void process_token(const string &token, stack<double> &S) {
    bool floatflag = false;
    string final_number;
    char sign;

    double number;
    for (unsigned i = 0; i < token.size (); i++) {
        char ch = token[i];

        if (unarySign (ch, token, i)) {
            sign = ch; //cout<<"sign"<<ch<<endl;
            continue;
        } else if (isValidOperator (ch)) {
            double Num1 = popStack (S);
            double Num2 = popStack (S);
            S.push (operation (ch, Num2, Num1));
        } else if (floatPoint (ch, token, i)) { floatflag = true; }
        else if (isdigit (ch)) {

            number = getNumber (ch, token, i, floatflag);
            if (sign == '-') { number = number * -1; }
            S.push (number);


        } else if (ch == '=') { printResult (S); }
        else if(ch== 'c'){emptyStack ( S );}else
        {
            cerr<<"error: character '"<<ch<<"' is invalid"<<endl;
        }


    }

}
/*Main Function : Execution starts from here*/
int main() {

    std::stack<double> S;
    char c;
    string token1;
    while (cin.get (c)) {
        if (c == ' ' || c == '\n') {
            process_token (token1, S);
            token1.erase ();
        } else {
            token1.push_back (c);	
        }
    }
    return 0;
}
