/*     Program name  : To Find and Diplay perfect numbers between 1 to 9999
 *     Program Author : Ankita Upadhyay
 *     Z-ID           : z1836412
 *     Date Started   : September,8th 2017
 *     Date completed  : September,13th 2017
 *     */
/*Source File : prog2.cc */
#include "prog2.h"


int main() {
    /* for loop to check for perfect numbers between range 1 to 9999*/

    for (unsigned int i = min_value; i < max_value; i++) {
        /*if condition checks here the Predicate function isPerfect  which returns true if the number is perfect, and false otherwise. */
        if (isPerfect (i)) {
            /*Displaying the perfect numbers as the sequence n=d1+d2...dn eg: 6= 1+2+3*/
            string printStr = printDivisors (i);
            /*using substring constructor to remove the last character while printing the seque3nce*/
            cout << printStr.substr (0, printStr.length () - 2) << endl;


        }
    }
    return 0;
}

/* Function Name : isPerfect
 * Return type   : Boolean
 * Function Use : This is a Predicate function which returns true if the number is perfect, and false otherwise
 *        */

bool isPerfect(int n) {
    int sum = 0;//declaring and initializing a variable sum =0
    for (int i = 1; i < n; i++) // for loop to check for all the perfect numbers between the range
    {
        /*checking if the sum of all divisor is equal to the number itself*/
        if (n % i == 0) {
            sum += i;
        }
    }
    /*if the sum of all divisor is equal to the number itself then the predicate function returns true else returns false*/
    if (sum == n) return true;

    return false;
}

/* Function Name : printDivisors
 *    Return type   : String
 *       Function Use : used to display divisors as sequence n = d1 + d2 + … + dm, where d1, d2, …, dm are the divisors of n with d1 = 1*/
string printDivisors(int n) {
    /*declaring and initializing a string variable named divisor which is converting integer data to string type */
    string divisor = to_string (n) + " = ";
    /* for loop to get the perfect numbers as a string sequence*/
    for (int i = 1; i < n - 1; i++) {
        /*checking if the sum of all divisor is equal to the number itself*/
        if (n % i == 0) {
            /*assinging value to string variable divisor after converting integer type perfect number divisor to string concatenating it with '+'*/
            divisor += to_string (i) + "+";
        }
    }

    return divisor += '\b';// returning the divisor sequence by erasing the last '+'
}
