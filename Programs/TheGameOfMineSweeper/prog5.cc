/*Program name   : THE GAME OF MINESWEEPER
 *Program Author : Ankita Upadhyay
 *Z-ID           : z1836412
 *Date Started   : October,16th 2017
 *Date completed : October,23rd 2017
*/

/*Header File : prog5.cc */

#include "prog5.h"
using namespace std;

/*
FUNCTION : MAIN

Declaring the size for the mine field and the probablity for the mines in that mine field and getting input from source in a while loop and then create two vectors for both mine field as well as mine counts field and passing those on to both buildMineField function as well as fixCounts function
*/

int main()
{
   int sizeofMineField;
   double mineProb;
   while(cin>>sizeofMineField && cin>>mineProb)
	{
   		vector<vector<bool>>mines(sizeofMineField,vector<bool>(sizeofMineField));
   		vector<bool>vector1(sizeofMineField);
   		vector<vector<unsigned>>counts(sizeofMineField,vector<unsigned>(sizeofMineField));
   		vector<unsigned>vector2(sizeofMineField);
   		mines[0] = vector1;
   		counts[0] = vector2;
   		cout<<endl<<"Size of Mine Field is: "<<mines.size()<<"x"<<vector2.size()<<endl<<endl<<"Mines are of Probablity: "<<mineProb<<endl;
   		cout<<endl;
   		buildMineField(mines,mineProb);
   		fixCounts(mines,counts);
	}
   return 0;
}

/*
FUNCTION : BUILDMINEFIELD

declaring a random variable and assigning srand to Seed which is 1 so that the random number gets generated from 0-1 and we use the random number generator function and assign the random number to the random variable and checking with the probablity whether the mine is available at the given location or not after the check the mines vector is being passed to displayMineLocations function
*/

void buildMineField ( vector < vector < bool > >& mines, const double& mineProb )
{
    double rnd;
    srand(SEED);
    for(int i=0;i<(int)mines.size();i++)
    {
        for(int j=0;j<(int)mines[i].size();j++)
        {
            rnd = rand ( ) / ( double ( RAND_MAX ) + 1 );
            if(rnd<mineProb)
            {
                mines[i][j]= true;
            }
        }
    }
    displayMineLocations(mines);
}

/*
FUNCTION : FIXCOUNTS

declaring count variable and checking the bounds for each cell as well as whether the cell contains a mine or not and increment the count variable if the statement is true and within the bounds and the count variable is assigned to the counts vector in a for looping structure and the counts vector is being passed to displayMineCounts function
*/

void fixCounts ( const vector < vector < bool > >& mines, vector < vector < unsigned > >& counts )
{
    for(int i=0;i<(int)mines.size();i++)
    {
        for(int j=0;j<(int)mines[i].size();j++)
        {
            int count = 0;
            if(mines[i][j] == true)
            {
                count++;
            }
            if((i+1)<((int)mines.size()) && mines[i+1][j] == true)
            {
                    count++;
            }
            if((i-1)>=0 && mines[i-1][j] == true)
            {
                count++;
            }
            if((j+1)<((int)mines[i].size()) && mines[i][j+1] == true)
            {
                count++;
            }
            if((j-1)>=0 && mines[i][j-1] == true)
            {
                count++;
            }
            if((i-1)>=0 && (j-1)>=0 && mines[i-1][j-1] == true)
            {
                count++;
            }
            if((i-1)>=0 && (j+1)<((int)mines[i].size()) && mines[i-1][j+1] == true)
            {
                count++;
            }
            if((i+1)<((int)mines.size()) && (j-1)>=0 && mines[i+1][j-1] == true)
            {
                count++;
            }
            if((i+1)<((int)mines.size()) && (j+1)<((int)mines[i].size()) && mines[i+1][j+1] == true)
            {
                count++;
            }
            counts[i][j] = count;
        }
    }
    displayMineCounts(counts);
}

/*
FUNCTION : DISPLAYMINELOCATIONS

input output manipulators are being used to design the mine location board and the mines vector from buildMineField is being passed in which if the mines vector is true in that location it prints a X indicating a mine in that location
*/

void displayMineLocations(const vector<vector<bool>>&mines)
{
cout<<" MINE LOCATIONS  "<<endl;
for(size_t i=0;i<mines.size();i++)
    {
    cout<<setw(mines.size()*3+2)<<setfill(DASH);
                cout<<BLANKSPACE<<endl;
                for(size_t j=0;j<mines.size();j++)
                {
                        cout<<setw(2)<<setfill(PIPE);
                        if(mines[i][j] == true)
                                {
                                cout<<MINE<<BLANKSPACE;
                                }
                        else
                                {
                                cout<<mines[i][j]<<BLANKSPACE;
                                }
                }
                cout<<PIPE;
                cout<<endl;
    }
    cout<<setw(mines.size()*3+2)<<setfill(DASH);
    cout<<BLANKSPACE<<endl;
}

/*
FUNCTION : DISPLAYMINECOUNTS

input output manipulators are being used to design the mine counts board and the counts vector from fixCounts is being passed and are assigned in the board accordingly
*/

void displayMineCounts(const vector<vector<unsigned>>&counts)
{
cout<<" MINE COUNTS  "<<endl;
   for(size_t i=0;i<counts.size();i++)
    {
    cout<<setw(counts.size()*3+2)<<setfill(DASH);
                cout<<BLANKSPACE<<endl;
                for(size_t j=0;j<counts.size();j++)
                {
                        cout<<setw(2)<<setfill(PIPE);
                        cout<<counts[i][j]<<BLANKSPACE;
                }
                cout<<PIPE;
                cout<<endl;

    }
    cout<<setw(counts.size()*3+2)<<setfill(DASH);
    cout<<BLANKSPACE<<endl;
}


