/*********************************************************************
 PROGRAM:    CSCI 340 Program 5 - The Josephus Problem.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   02/25/2015
 
 FUNCTION:  This program input to the program the number M and a list
            of N names, which is clockwise ordering of the circle,
            beginning with the soldier from whom the count starts. After
            each removal, the program should print the name tags of all
            soldiers in the circle until only one soldier remains. However,
            to save the printing space, print the name tags for the remaining
            soldiers after only K elimination where K >= 1 is also an input
            to the program. The input arguments N, M, and K can be entered
            from stdin in the given order..
 *********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::exit;
using std::string;
using std::vector;
using std::ifstream;

//////////////////////////////////////////////////////////////////
#ifndef H_PROG5
#define H_PROG5

#define NO_ITEMS 12    // max no of items printed in single line

// class to generate name tags for soldiers

class SEQ {
private:
    string id;         // name tag for soldier
    unsigned size, nd; // no of soldiers, no of digits in name tags
    
    // returns no of digits in name tags
    unsigned find_nd ( const double& sz ) {
        if ( ( sz / 26 ) <= 1 ) return 2;
        else return ( find_nd ( sz / 26 ) + 1 );
    }
    
public:
    // constructor for name-tag generator
    SEQ ( const unsigned& s = 1 ) : size ( s ) {
        double sz = ( double ) size / 9; nd = find_nd ( sz );
        id = string ( nd, 'A' ); id [ nd - 1 ] = '1';
    }
    
    // returns next name tag in sequence
    string operator ( ) ( ) {
        string tmp = id; int i = nd - 1;
        if ( id [ i ] < '9' ) id [ i ]++;
        else {
            id [ i ] = '1'; bool flag = true;
            for ( i--; i >= 0 && flag; i-- )
                if ( id [ i ] < 'Z' ) { id [ i ]++; flag = false; }
                else id [ i ] = 'A';
        }
        return tmp;
    }
};

// reads and initializes all input arguments
void init_vals ( vector <string>&, unsigned&, unsigned&, unsigned& );

// prints all name tags for remaining soldiers after elimination
void print_vector ( const vector <string>&, const unsigned& );
#endif

//////////////////////////////////////////////////////////////////


int main()
{
    // Declared varaibles.
    unsigned N,M,K;
    vector <string> v1; //initial size is zero
    
    // Reads in the file.
    ifstream inFile ("prog5.txt", std::ios::binary);
    
    // Checks for error if file could not be opened.
    // stores values in variables.
    if (!inFile)
        cout << "Error: File could not be opened! ";
    else
        
            cout << "Number of people?" << ' ';
            inFile >> N; cin >> N; cout << endl;
            
            cout << "Index for elimination?" << ' ';
            inFile >> M;cin >> M; cout << endl;
            
            cout << "Index for printing?" << ' ';
            inFile >> K;cin >> K; cout << endl;
    
    
    
    // Prints outs the initial group of people by call the functon inti_vals
    cout << "\nInitial group of people" << endl;
    cout << "-----------------------" << endl;
    init_vals(v1,N,M,K);
    
    return 0;
}

//////////////////////////////////////////////////////////////////
// METHOD: init_vals
// FUNCTION: Function reads the values of N, M, and K when the program prompts
//           for them and prints out those values on stdout. It also changes
//           the size of the vector v to N and fills in the name tags for all
//           soldiers in v
// ARGUMENTS: vector < string >& v, unsigned& N, unsigned& M, unsigned& K
//////////////////////////////////////////////////////////////////
void init_vals ( vector < string >& v, unsigned& N, unsigned& M, unsigned& K )
{
    // Declared variables.
    int i = 0, cnt = 0, cnt2 = 0;
    
    // Resize by the number of people.
    v.resize(N);
    
    // Generates the sequence of soldier name tags, then stores them in the vector.
    generate (v.begin(), v.end(), SEQ(N));
    print_vector(v, cnt);
    cout << "\n";

    // Eliminates soldiers by index 'M' until there is only on soldier left.
    for ( i = ( i + M - 1 ) % v.size ( ); i <  v.size(); i = ( i + M - 1 ) % v.size ( ))
    {
        if (v.size() != 1)
            {
                v.erase(v.begin() + i);
                cnt++;
            
            // Prints out every time 'K' is eliminated.
            if (cnt% K == 0 || v.size() == 1)
                {
                cout << "\n\nAfter eliminating " << cnt <<"th person" << endl;
                cout << "-----------------------------" << endl;
                print_vector(v, cnt2);
                cout << "\n";
                }
                // Exit program when vector size is equal to 1.
                if (v.size() == 1) exit(0);
            }
    }
}

//////////////////////////////////////////////////////////////////
// METHOD: print_vector
// FUNCTION: Function prints out the contents of vector v at the
//           beginning and after removing K name tags from the vector
//           until only one name tag remains, where cnt has an initial
//           value of 0 and it simply indicates the total number of
//           removals so far. At the end, it also prints the name tag
//           of the last remaining soldier. For printout, print only up
//           to 12 name tags in a single line, where the name tags are
//           separated by single spaces.
// ARGUMENTS: const vector < string >& v, const unsigned& cnt
//////////////////////////////////////////////////////////////////
void print_vector ( const vector < string >& v, const unsigned& cnt )
{
    int Length = cnt;
    for(auto i = v.begin(); i!= v.end(); ++i)
    {
     cout << *i << ' ';

    Length++;
    if (Length % NO_ITEMS == 0)
    {
        cout << "\n";
    }
    }
}

