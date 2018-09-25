

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include <assert.h>
#include <string.h>

using namespace std;

#define DATA_FILE "/home/cs689/progs/17f/p4/prog4-out.d"

const unsigned MAXWORDS = 1000; 
const unsigned MAXLEN   = 20;   
const unsigned LINESIZE = 5;    

unsigned num_words = 0;         
char word_name [ MAXWORDS ] [ MAXLEN + 1 ]; 
char prog_name1 [ ] = "// Begin Program Data //";
char prog_name2 [ ] = "/* End Program Data */";



void get_words ( );                         
void print_words ( );                       
void clean_entry ( char [ ], char [ ] );    



int main ( )
{
    get_words ( );      
    print_words ( );    

    return 0;
}



void get_words ( )
{
    int c; unsigned n = 0;
    char entry [ MAXLEN + 1 ], save [ MAXLEN + 1 ];
    FILE* fptr = fopen ( DATA_FILE, "r" );

    

    while ( fscanf ( fptr, "%20s", entry ) != EOF ) {
        if ( strlen ( entry) == MAXLEN ) {
            while ( !isspace ( c = cin.get ( ) && c != EOF ) );
            if ( c == EOF ) break;
        }
        clean_entry ( entry, save );

        
        if ( !strlen ( save ) ) continue;

        
        if ( ++n > MAXWORDS ) break;
        assert ( strcpy ( word_name [ num_words++ ], save ) );
    }

    fclose ( fptr );
}



void clean_entry ( char e [ ], char s [ ] )
{
    int i, j;       
    char c;         

    
    for ( i = 0; ( c = e [ i ] ) && !isalnum ( c ); i++ );
    for ( j = i; ( c = e [ j ] ) &&  isalnum ( c ); j++ );

    
    strcpy ( s, e + i );
    s [ j - i ] = 0;
}



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

