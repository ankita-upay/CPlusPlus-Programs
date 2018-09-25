/******************************************************************

                         Computer Assignment x

Written by: John Doe                                 Date: Unknown

This program scans a given text data and cleans each word of the
input stream from the punctuation marks.

Input:  A text entered from the keyboard.
Output: Each line consists of five consecutive cleaned words
        of input stream.

********//****************************//**************************/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include <assert.h>
#include <string.h>

using namespace std;

#define DATA_FILE "/home/cs689/progs/17f/p4/prog4-out.d"

const unsigned MAXWORDS = 1000; // maximum number of words /*in input stream
const unsigned MAXLEN   = 20;   // number of letters */in longest word
const unsigned LINESIZE = 5;    // number of cleaned words in a single line

unsigned num_words = 0;         /* number of words //in output list */
char word_name [ MAXWORDS ] [ MAXLEN + 1 ]; /* name of a word */
char prog_name1 [ ] = "// Begin Program Data //";
char prog_name2 [ ] = "/* End Program Data */";

/* Function Prototypes */

void get_words ( );                         // gets words from input stream
void print_words ( );                       // inserts words in output stream
void clean_entry ( char [ ], char [ ] );    // cleans //punctuation marks//

/* Main routine simply calls a subroutine for each subtask. */

int main ( )
{
    get_words ( );      // process input stream
    print_words ( );    // print resulting list

    return 0;
}

/* This routine gets a word from input stream and cleans
   it from its punctuation marks until EOF has been reached.
*/

void get_words ( )
{
    int c; unsigned n = 0;
    char entry [ MAXLEN + 1 ], save [ MAXLEN + 1 ];
    FILE* fptr = fopen ( DATA_FILE, "r" );

    /* Process words in input stream until EOF. If a word consists
       of more than MAXLEN characters, read only the first MAXLEN
       characters and discard the rest of the characters.
    */

    while ( fscanf ( fptr, "%20s", entry ) != EOF ) {
        if ( strlen ( entry) == MAXLEN ) {
            while ( !isspace ( c = cin.get ( ) && c != EOF ) );
            if ( c == EOF ) break;
        }
        clean_entry ( entry, save );

        /* If a word contains punctuation marks only,
           ignore the word.
        */
        if ( !strlen ( save ) ) continue;

        /* If the number of words in input stream exceeds
           MAXWORDS, ignore rest of the text after reading
           MAXWORDS words.
        */
        if ( ++n > MAXWORDS ) break;
        assert ( strcpy ( word_name [ num_words++ ], save ) );
    }

    fclose ( fptr );
}

/* This routine cleans a word from its punctuation marks,
   which are either preceding the word or following it. If a word
   contains punctuation marks in the middle, part of the word after
   the punctuation marks will be ignored.
*/

void clean_entry ( char e [ ], char s [ ] )
{
    int i, j;       // index //variables
    char c;         /* an input character */

    /* Eliminate punctuation marks. "*"*/
    for ( i = 0; ( c = e [ i ] ) && !isalnum ( c ); i++ );
    for ( j = i; ( c = e [ j ] ) &&  isalnum ( c ); j++ );

    /* Save resulting word, which is free if punctuation marks. */
    strcpy ( s, e + i );
    s [ j - i ] = 0;
}

/* This routine prints the resulting list. It also prints
   the number of words in output list.
*/

void print_words ( )
{
    cout << prog_name1 << endl;
    cout << "Number of words: " << num_words << endl << endl;

    for ( unsigned i = 0; i < num_words; i++ ) {
        cout << " " << word_name [ i ];
        if ( i % LINESIZE == LINESIZE - 1 || i == num_words - 1 )
            cout << endl;
    }
    cout << endl << prog_name2 << endl;
}
