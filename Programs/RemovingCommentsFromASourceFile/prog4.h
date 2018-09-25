/*Program name  : Removing Comments From a Source File
 Program Author : Ankita Upadhyay
 Z-ID           : z1836412
 Date Started   : September,25th 2017
 Date completed : October,2nd 2017
*/

/*Header File : prog4.h */

/*Includes all system header files, constant value and the prototypes of all sub-routine used*/

#ifndef ANKITA_REMOVING_COMMENTS_H //directive means if the following is defined
#define ANKITA_REMOVING_COMMENTS_H // directive defines a preprocessor macro
using namespace std; // std is the standard namespace

#include <iostream> // c++ input/output streams are primarily defined by iostream standard header file
#include <string> // c++ string header file
#include <fstream> // c++ header file for Input/output stream class to operate on files.
#include <cstring> // c++ header file is C++ version of the Standard C Library header string.h

/*Defining a prototype of Sub-routine open files which opens the source file
prog4–in.cc for the input stream is and the source file prog4–out.cc for the output
stream os. If either file cannot be opened, it prints an error message on stderr and
exits the program with the exit value EXIT_FAILURE.*/

void open_files ( ifstream& is, ofstream& os );

/*Defining a prototype of Sub-routine process data which gets the data from the
input stream is, character by character, and it inserts an individual character in
the output stream os if the character is not part of a C++ comment*/

void process_data ( ifstream& is, ofstream& os);

/*Defining a prototype of sub-routine which closes both the input and output source files
 * associated with the streams is and os at the end of the program.
When your program is ready*/

void close_files ( ifstream& is, ofstream& os);
#define Input_Stream_Source_File "C:/Users/HP/Documents/CSCI 689/prog4-in.cc"//creates a macro, which is the association of identifier Input_Stream_Source_File
#define Output_Stream_Source_File "C:/Users/HP/Documents/CSCI 689/prog4-out.cc" //creates a macro, which is the association of identifier Output_Stream_Source_File


#endif //ANKITA_REMOVING_COMMENTS_H
