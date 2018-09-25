/*@Program Name        : Leibnitz Formula for Pi π/4=1−1/3+1/5−1/7+1/9
  @Program Author      : Ankita Upadhyay
  @Program Author Z-ID : z1836412
  @Start Date          : Aug/31/2017
  @End Date            : Sep/04/2017
*/

/*This statement is including the header file prog1.h which contains all system header files , subroutine prototypes and constant variables */
#include "prog1.h"

/*Sub-routine add_terms : Adds the first N terms of the series and returns the computed sum to the main ( ) routine.
  It takes number of terms for which value of pi is to be computed as input and returns value of pi as output */
double add_terms(unsigned int no_of_terms)
{
            double temp_pi=0.0;//initializing a variable pi as double type
            for (unsigned int i=1;i<=no_of_terms;i++)// for loop running from 1 to no of terms entered
                {
               /*Calculating the value of pi*/
               /*Deriving +ve & -ve terms in the series via pow function*/
                temp_pi += pow(-1,i+1) / (2*i - 1);//using shorthand assignment operator( pi +=) for adding pi
                }
            return 4*temp_pi;//returns the value of pi
}


/*Main Program*/
int main ()
{
            int no_of_terms;//declaring variable no_of_terms of unsigned int type
            double pi=0.0;//declaring and initializing variable pi of double type
            cout << "Enter number of terms for which you want to run the aproximation :"<< endl;//print statement
            cin >> no_of_terms; // User input for number of terms for which the value of pi will be calculated
            pi=add_terms(no_of_terms);//calling function add_terms with argument no_of_terms
            cout <<" Value of pi "<<"for "<<no_of_terms<<" term"<<" is : " <<pi<< endl;//printing value of pi for user inputted number of terms
            return 0;
}
