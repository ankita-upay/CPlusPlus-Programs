/*Program name  : Caesar Cipher Updated
 *Program Author : Ankita Upadhyay
 *Z-ID           : z1836412
 *Date Started   : September,15th 2017
 *Date completed : September,25th 2017
 */
/*Header File : prog3.h */
/*Includes all system header files, constant value and the prototypes of all sub-routine used*/

#ifndef ANKITA_CAESAR_CIPHER_UPDATED_H //directive means if the following is defined
#define ANKITA_CAESAR_CIPHER_UPDATED_H // directive defines a preprocessor macro
using namespace std; // std is the standard namespace

#include <iostream> // c++ input/output streams are primarily defined by iostream standard header file
#include <string> // c++ string header file
#include <fstream> // c++ header file for Input/output stream class to operate on files.
#include <cstring> // c++ header file is C++ version of the Standard C Library header string.h

/*creates a macro, which is the association of identifier Shift_key_file*/
#define Shift_key_file "/home/cs689/progs/17f/p3/prog3.d1"

/*creates a macro, which is the association of identifier data file*/
#define data_file "/home/cs689/progs/17f/p3/prog3.d2" 

int shift_value = 0; // declaring & defining a global integer variable shift_value and assigning it value 0
string key; // declaring a global string variable key
string text_message; // declaring a global string variable text_message

/*Defining prototype of sub-routine encodeCaesarCipher which returns a
 * new string formed by shifting every letter in str forward the number of letters
 * indicated by shift and key, cycling back to the beginning of the alphabet if
 * necessary.*/
 
string encodeCaesarCipher(string, const int &,const string &); 

/*defining prototype of sub-routine process_infile which opens the second data file, 
  and if it is unsuccessful, it displays an error message on stderr and exits the program 
  with the exit value EXIT_FAILURE. It prints out the shift and key values on stdout passed as 
  arguments and gets the text input from the data file. To process each input line in the data file, 
  it calls the encodeCaesarCipher () function .It prints out the encrypted text returned by this 
  function on stdout.Finally, it closes the data file.*/
  
void process_infile(const int &, const string &);

/*Defining prototype of sub-routine new_position which returns the new position 
of character c after shifting for the shift value and the second shift value 
obtained from the key*/

int new_position(const char &, const int &, const string &);

#endif //ANKITA_CAESAR_CIPHER_UPDATED_H
