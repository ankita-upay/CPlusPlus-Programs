/*Program name   : THE GAME OF MINESWEEPER
 *Program Author : Ankita Upadhyay
 *Z-ID           : z1836412
 *Date Started   : October,16th 2017
 *Date completed : October,23rd 2017
*/

/*Header File : prog5.h */


/*
FILE: HEADER
All the header files are included and constant variables are defined globally and function prototypes are defined for each function.
*/

#ifndef PROG5_H
#define PROG5_H 
#include <iostream>
#include <vector>
#include <iomanip>
const std::string BLANKSPACE = " ";
const char MINE='X';
const int SEED=1;
const char PIPE='|';
const char DASH='-';
void buildMineField(std::vector < std::vector < bool > >&, const double&);
void fixCounts ( const std::vector < std::vector < bool > >& , std::vector < std::vector < unsigned > >& );
void displayMineLocations ( const std::vector < std::vector < bool > >&);
void displayMineCounts ( const std::vector < std::vector < unsigned > >&);
#endif
