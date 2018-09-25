/*Program name  : Our Friend Atom
 Program Author : Ankita Upadhyay
 Z-ID           : z1836412
 Date Started   : October,3rd 2017
 Date completed : October,11th 2017
*/
/*Header File : prog5.h */
/*Includes all system header files, constant value and the prototypes of all sub-routine used*/
#include <vector>//c++ vector container's header file
#include <iostream>// c++ input/output streams are primarily defined by iostream standard header file
#include <ctime>// c++ header file is C++ version of the Standard C Library header time.h

using namespace std;// std is the standard namespace

const int GRID_SIZE = 25;//declaring and Initializing a constant variable int GRID_SIZE
const int Balls_per_trap = 2;//declaring and Initializing a constant variable int Balls_per_trap
const int MIN_CYCLES = 1;//declaring and Initializing a constant variable int MIN_CYCLES
const int MAX_CYCLES = 4;//declaring and Initializing a constant variable int MAX_CYCLES

int clocks = 0;//declaring and Initializing a variable int clocks
unsigned noBallsinAir = 0;//declaring and Initializing a variable unsigned noBallsinAir
int num_Of_Sprung = 0;//declaring and Initializing a variable int num_of_Sprung
int SEED = time (0);//declaring and Initializing a variable int SEED
int PRN_CYCLES = 10;//declaring and Initializing a variable int PRN_CYCLES

/*Defining prototype of sub-routine void init_sim ( vector < vector < bool > >& traps, vector < unsigned >& ballCycles): This
routine initializes each mousetrap in the traps grid to logical value true, it means
that none of the mousetraps have been sprung yet. It also initializes the RNG by
calling the srand ( ) function with the seed value SEED = time ( 0 ), so each time
you run your program, you’ll get different output values but they all be in the
proximity of each other. Since the first ball is release at the beginning of the
simulation, this routine also inserts the cycle 1 for the first ball in the vector
ballCycles */
void init_sim(vector<vector<bool> > &traps, vector<unsigned> &ballCycles);

/*Defining prototype of sub-routine unsigned release_balls which is called in each simulation cycles, and it takes the necessary steps
in that cycle. It checks the value of each element in the vector ballCycles, and if the
value is not 0, then it decrements that value by 1, and the final value becomes 0, it
randomly selects a mousetrap in the grid trap to fall the ball on it. If the chosen
mousetrap has not been sprung yet, it computes the random cycles for each of its
two balls by using the expression rand ( ) % ( high – low + 1 ) + low, where low and
high are the minimum and maximum cycles for a ball, respectively, and changes
the logical value of that mousetrap to false in the grid traps. At the end, this
routine compute and returns the total number of balls in the air to the main ( )
routine, and the main ( ) routine can update the maximum number of balls in the
air by this value. To update the vector ballCycles, the auxiliary routine
update_cycles ( ) can be called for each of the two balls of a mousetrap.*/
unsigned release_balls(vector<vector<bool> > &traps, vector<unsigned> &ballCycles);

/*Defining prototype of sub-routine void print_grid ( const vector < vector < bool > >& traps, const unsigned& clock, const
unsigned& noBallsInAir ): which is called in each simulation cycles, and it
prints out the current values of the simulation clock and the total number of balls
noBallsInAir in the air on stdout. After each PRN_CYCLES = 10, it also prints out each
corresponding logical value of the grid traps by printing the character ‘X’ for the
logical value true and the character ‘.’ for the logical value false. The main ( )
routine also calls this routine at the beginning and end of the simulation.*/
void print_grid(const vector<vector<bool> > &traps, const unsigned clock, const unsigned &noBallsInAir);

/*Defining prototype of sub-routine void print_stat ( const vector < vector < bool >& traps, const unsigned& maxNoBallsInAir,
const unsigned& clock ) which is called at the end of the simulation. It prints
out the total simulation time clock and the maximum number of balls in the air
maxNoBallsInAir on stdout. It computes the total number of mousetraps have
sprung in the grid traps in the simulation and print out the percentage of sprung
traps.*/
void print_stat(const vector<vector<bool> > &traps, const unsigned maxNoBallsInAir, const unsigned clock);

/*Defining prototype of sub-routine void update_cycles ( vector < unsigned >& ballCycles ) which is called to update
the vector ballCycles for a ball. It computes the initial random cycles for the ball
and searches the vector for the first cycle number 0. If the number is found, then
it replaces the number with the initial cycles of the ball; otherwise, it inserts the
cycle number at the end of the vector*/
void update_cycles(vector<unsigned> &ballCycles);

