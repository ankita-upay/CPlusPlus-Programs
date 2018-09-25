/*Program name  : Our Friend Atom
 Program Author : Ankita Upadhyay
 Z-ID           : z1836412
 Date Started   : October,3rd 2017
 Date completed : October,11th 2017
*/
/*Source File : prog5.cc */
/*Including user defined header file prog5.h*/
#include "prog5.h"

/*Main Function*/
int main() {
    unsigned maxnoofballs = 0;//declaring and initializing integer variable maxnoofballs
    vector<vector<bool>> traps (GRID_SIZE,
                                vector<bool> (GRID_SIZE));//declaring two dimensional vector variable traps of bool type
    vector<unsigned int> ballCycles;//declaring vector ballCycles of unsigned int type
    init_sim (traps, ballCycles);//calling sub-routine init_sim which initializes every variables and vectors

/*using do-while loop to check cycles and print grids*/
    do {
        /*it check whether the simulation cycle is a multiple of 10 or not , if it is a multiple of 10
          then it calls print_grid sub-routine to print grids*/
        if (clocks % PRN_CYCLES == 0) {
            /*calling sub-routine print_grids*/
            print_grid (traps, clocks, noBallsinAir);
        }
/*calling sub-routine release_balls with the arguments and storing the return value in noBallsinAir variable of integer type*/
        noBallsinAir = release_balls (traps, ballCycles);
        /*if condition to check if balls in air is greater than maxnoofballs, if yes then maxnoofballs is assigned noofballsinair vallue*/
        if (noBallsinAir > maxnoofballs) {
            maxnoofballs = noBallsinAir;
        }
        /*simulation clock is incremented*/
        clocks++;

    } while (noBallsinAir != 0);//if there are balls in air we call sub-routine print_grid and print_stats consecutively

    print_grid (traps, clocks, noBallsinAir);
    print_stat (traps, maxnoofballs, clocks);
    return 0;
}

/* Function Name : init_sim
   Return type   : void
   Function Use : This sub-routine initializes each mousetrap in the traps grid to logical value true, it means
that none of the mousetraps have been sprung yet. It also initializes the RNG by
calling the srand ( ) function with the seed value SEED = time ( 0 ), so each time
you run your program, you’ll get different output values but they all be in the
proximity of each other. Since the first ball is release at the beginning of the
simulation, this routine also inserts the cycle 1 for the first ball in the vector
ballCycles
 */
void init_sim(vector<vector<bool>> &traps, vector<unsigned> &ballCycles) {

    /*for loop to initialize the 2-D vector with value true */
    for (unsigned int i = 0; i < GRID_SIZE; i++) {
        for (unsigned int j = 0; j < GRID_SIZE; j++) {
            traps[i][j] = true;
        }
    }

    srand (SEED);//seeding RNG with value 0
    ballCycles.push_back (1);//initializing the vector ballCycles with 1

}

/* Function Name : release_sim
   Return type   : unsigned
   Function Use : This sub-routine is called in each simulation cycles, and it
prints out the current values of the simulation clock and the total number of balls
noBallsInAir in the air on stdout. After each PRN_CYCLES = 10, it also prints out each
corresponding logical value of the grid traps by printing the character ‘X’ for the
logical value true and the character ‘.’ for the logical value false. The main ( )
routine also calls this routine at the beginning and end of the simulation.
 */
unsigned release_balls(vector<vector<bool> > &traps, vector<unsigned> &ballCycles) {
    unsigned ballsInAir = 0;//declaring and initializing an unsigned variable ballsInAir with 0
    vector<unsigned> ballCycles2;//declaring a vector of unsigned type named ballCycles2
/*starting a for loop for vector ballCycles which will run till the end of it*/
    for (unsigned int i = 0; i < ballCycles.size (); i++) {
        /*if ball cycle is greater than 0 , then it decrements that value by 1*/
        if (ballCycles[i] > 0) {

            ballCycles[i]--;
            /*if ball cycle is =0 , then it  it computes the random cycles for each of its
  two balls by using the expression rand ( ) % ( high – low + 1 ) + low, where low and
  high are the minimum and maximum cycles for a ball, respectively*/
            if (ballCycles[i] == 0) {
                int currentX = rand () % (GRID_SIZE);
                int currentY = rand () % (GRID_SIZE);
                /*if mousetrap selected is sprung then it increments the value of num_of_sprung and changes
 the logical value of that mousetrap to false in the grid traps*/
                if (traps[currentX][currentY]) {
                    num_Of_Sprung++;
                    traps[currentX][currentY] = false;
                    /*increments the ballin air to 2 as every ball with ping two new balls*/
                    ballsInAir += 2;
                    /*for both new balls we call the sub-routine update_cycles*/
                    update_cycles (ballCycles);
                    update_cycles (ballCycles);
                }
            } else {

/*ballsInAir is incremented after every sprung*/
                ballsInAir++;
            }
        }

    }
    /*returns total number of balls in Air*/
    return ballsInAir;
}

/* Function Name : print_grid
   Return type   : void
   Function Use : This sub-routine is called in each simulation cycles, and it
prints out the current values of the simulation clock and the total number of balls
noBallsInAir in the air on stdout. After each PRN_CYCLES = 10, it also prints out each
corresponding logical value of the grid traps by printing the character ‘X’ for the
logical value true and the character ‘.’ for the logical value false. The main ( )
routine also calls this routine at the beginning and end of the simulation.
 */

void print_grid(const vector<vector<bool> > &traps, const unsigned clock, const unsigned &noBallsInAir) {
    /*print simulation clock and no of balls in air according to the alignment mentioned*/
    cout << "clock = " << clock;
    cout << " : noBallsInAir = ";
    cout << noBallsInAir << endl << endl;
    /*for loop to print bool values of the 2-D array */
    for (unsigned int k = 0; k < GRID_SIZE; k++) {
        for (unsigned int j = 0; j < GRID_SIZE; j++) {
            /*if the value in the grid is true we print X , else if its false we print .*/
            if (traps[k][j] == true)
                cout << 'X' << ' ';
            else cout << '.' << ' ';
        }
        cout << endl;
    }
    cout << endl;

}

/* Function Name : update_cycles
   Return type   : void
   Function Use : This sub-routine is called to update
the vector ballCycles for a ball. It computes the initial random cycles for the ball
and searches the vector for the first cycle number 0. If the number is found, then
it replaces the number with the initial cycles of the ball; otherwise, it inserts the
cycle number at the end of the vector.
 */

void update_cycles(vector<unsigned> &ballCycles) {
/*rand function is called to update the cycle for the ball*/
    int cycle1 = rand () % (MAX_CYCLES - MIN_CYCLES + 1) + MIN_CYCLES; // for 1st ball
    bool flag = true;
/*running a for loop for ballcycles.size , where if the ballcycle is 0 then ballcycle is changed to cycle1 value and flag is changed to false*/
    for (unsigned int i = 0; i < ballCycles.size (); i++) {
        if (ballCycles[i] == 0) {
            ballCycles[i] = cycle1;
            flag = false;
            break;
        }

    }
    /*if flag is true cycle1 is pushed back in ballCycles vector*/
    if (flag) {
        ballCycles.push_back (cycle1);
    }

}

/* Function Name : print_stats
   Return type   : void
   Function Use : This sub-routine is called at the end of the simulation. It prints
out the total simulation time clock and the maximum number of balls in the air
maxNoBallsInAir on stdout. It computes the total number of mousetraps have
sprung in the grid traps in the simulation and print out the percentage of sprung
traps.
 */

void print_stat(const vector<vector<bool> > &traps, const unsigned maxNoBallsInAir, const unsigned clock) {
    int sprung = 0;//declaring and initializing variable sprung of int type
    /*for loop to count number of sprung for each false value of trap */
    for (unsigned int k = 0; k < GRID_SIZE; k++) {
        for (unsigned int j = 0; j < GRID_SIZE; j++) {
            if (traps[k][j] == false) {
                sprung++;
            }

        }
    }
    double total_grid = GRID_SIZE * GRID_SIZE;//declaring and calculating value of double variable total grid
    double percentagesprung = sprung / total_grid * 100.0;//calculating value of double variable percentagesprung
    /*displaying total simulation,max no of balls in air and percent of sprung traps*/
    cout << "Total simulation time   = " << clock << endl;
    cout << "Max no of balls in air  = " << maxNoBallsInAir << endl;
    cout << "Percent of sprung traps = " << percentagesprung << endl;

}



