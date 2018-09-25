#include <iomanip>
#include <iostream>
#include <set>
#include <string>
using namespace std;

#ifndef H_PROG11
#define H_PROG11

#define LSIZE 10 // max number of items printed on single line

// compare criteria for strings in a set
class cmp {
public:
    bool operator( ) ( const string& s1, const string& s2 ) {
        unsigned len1 = s1.length ( ), len2 = s2.length ( );
        return ( len1 < len2 || ( len1 == len2 && s1 < s2 ) );
    }
};

// prints the contents of a set
void print ( const set < string, cmp >&, const unsigned& );

// returns all permutations of a string
set < string, cmp > genPerm ( const string& );

// returns all substrings of a string
set < string, cmp > genSub ( const string& );

#endif