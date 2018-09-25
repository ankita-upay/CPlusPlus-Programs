/*Program name  : Removing Comments From a Source File
 Program Author : Ankita Upadhyay
 Z-ID           : z1836412
 Date Started   : September,25th 2017
 Date completed : October,2nd 2017
*/
/*Source File : prog4.h */
/*Includes all system header files, constant value and the prototypes of all sub-routine used*/
#include "Removing_comments.h"//including the user-defined header file

/*Main Program*/
int main() {
    ifstream is (
            Input_Stream_Source_File);// declaring a ifstream type variable shift key which open the identifier Input_Stream_Source_File
    ofstream os (
            Output_Stream_Source_File);// declaring a ofstream type variable shift key which open the identifier Output_Stream_Source_File
    open_files (is, os);
}

/* Function Name : open_files
   Return type   : void
   Function Use : This opens the source file prog4–in.cc for the input stream is and the source file
   prog4–out.cc for the output stream os. If either file cannot be opened, it prints an error message
   on stderr and exits the program with the exit value EXIT_FAILURE.
 */
void open_files(ifstream &is, ofstream &os) {

    /*if the ifstream message object is in a bad state or unable to open the data file we output an error message to stderr*/
    if (is.fail ()) {
        cerr << "Error in Opening the Input Stream File." << endl;
        exit (EXIT_FAILURE);
    }
        /*if the ofstream message object is in a bad state or unable to open the data file we output an error message to stderr*/
    else {
        if (!os.is_open ()) {
            cerr << "Error in Opening the Output Stream File." << endl;
            exit (EXIT_FAILURE);
        } else {
            cout << "Input and Output Stream File Opened Successfully" << endl;
            /*if the ifstream and ofstream object is in a good state then call sub-routine process_data */
            while (is.good ()) {
                process_data (is, os);
            }

        }
    }
}

/* Function Name : process_data
   Return type   : void
   Function Use : This gets the data from the input stream is, character by character, and it inserts an
   individual character in the output stream os if the character is not part of a C++ comment.
 */
int count = 0;//declaring and initializing integer type variable count
bool flag = false;//declaring and initializing boolean type variable flag
bool singlelinecomment = false;//declaring and initializing boolean type variable singlelinecomment
bool multilinecomment = false;//declaring and initializing boolean type variable multilinecomment
bool dbquotes = false;//declaring and initializing boolean type variable dbquotes
int dbquotescount = 0;//declaring and initializing integer type variable dbquotes
bool multicommentfinish = false;//declaring and initializing boolean type variable multicommentfinish

void process_data(ifstream &is, ofstream &os) {
    /*while not end of file we do the following*/
    while (!is.eof ()) {
        char input;//declaring character type variable input
        is.get (input);//getting each character at a time from the input file
        /*if character is double quotes and flags singlelinecomment and multilinecomment are false we write the character in the output file*/
        if (input == '"' && multilinecomment == false && singlelinecomment == false)
        {
            os.put (input);
            cout << input;
            /*if double quotes count is greater than equal to 1 we are setting dbquotes flag as false and resetting dbquotescount to 0*/
            if (dbquotescount >= 1) {
                dbquotes = false;
                dbquotescount = 0;
                continue;


            } else
            /*if double quotes not found then set flag as true and increment the dbquotescount*/
            {
                dbquotes = true;
                dbquotescount++;
            }

        } else
        /*if character is backslash and flags set false then increement and move to next character*/
        {
            if (input == '/' && multilinecomment == false && singlelinecomment == false && dbquotes == false) {

                if (count == 0) {
                    flag = true;
                    count++;
                } else
                /*else set flag singlecomment true and ignore the character*/{
                    singlelinecomment = true;
                    flag = false;
                    count = 0;
                }

            } else {
                count = 0;
                if (flag) {
/*if the second input character after backslash is * then set multilinecomment flag as true */
                    if (input == '*') {
                        multilinecomment = true;
                    }
                    flag = false;
                } else {
                    count = 0;
                    /*if consecutive * / found set multilinecomment and multicommentfinish as true and ignore in between characters */
                    if (multilinecomment) {
                        if (input == '*') {
                            multilinecomment = true;
                            multicommentfinish = true;
                            continue;
                        } else
                        /*else if consecutive * / not found set flags as false and continue reading characters*/
                        {

                            if (input == '/' && multicommentfinish) {
                                multilinecomment = false;
                                multicommentfinish = false;
                                continue;
                            }

                        }

                    } else {
                        /*if both singlelinecomment and multilinecomment is set false and input character is in the next line then
                         set singlelinecomment as false else continue*/
                        if (singlelinecomment && multilinecomment == false) {
                            if (input == '\n') {
                                singlelinecomment = false;

                            } else {
                                continue;
                            }

                        }
                        /*writing the characters in output file*/
                        os.put (input);
                        cout << input;
                    }
                }

            }
        }
    }
    close_files (is, os);
}

/* Function Name : close_files
   Return type   : void
   Function Use : This sub-routine closes both the input and output source files
   associated with the streams is and os at the end of the program When your program is ready
 */
void close_files(ifstream &is, ofstream &os) {
    is.close ();
    os.close ();
}
