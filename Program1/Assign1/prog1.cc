/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 1
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   1/20/2015
 
 FUNCTION:   This program will generate number store then into a vector.
            Then call the sort function to sort ascending. Then calls 
            the print function and displays numbers in a max of 12 olumns.
 
 *********************************************************************/

//#include “/home/courses/340/progs/p1/prog1.h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;
using std::setw;

//Pre-Defined Requirements.
//const int LOW = 1, HIGH = 10000, VEC_SIZE = 250, NO_ITEM = 12, ITEM_W = 5, SEED = 1;
/*
void genRndNums(vector <int>& v)
{
    srand(SEED);
    
    for(int i = 0; i < VEC_SIZE; ++i)
    {
        //Generating Random number and storing it into a vector
        int b = rand() % (HIGH - LOW + 1) + LOW;
        v.push_back(b) ;
    }
}

// PrintVec Funtion will print out 12 numbers per line.
void printVec(const vector<int> &v)
{
    int i = 0;
    while (i < (int) v.size())
    {
        cout << setw(ITEM_W) << left << v[i] << ' ';
        i ++;
        if (i % NO_ITEM == 0)
            cout << endl;
    }
    cout << endl << endl << "The Vector Size is: " << i ;
    if (i % NO_ITEM != 0)
        cout << endl;

    cout << "Numbers Per Line : " << NO_ITEM << endl;
    cout << "The spacing between numbers: " << ITEM_W << endl;
    cout << "Generating numbers from " << LOW << " to " << HIGH << ". " << endl << endl;
}

int main()
{
     // Sort and print list in ascending oreder
    vector <int> v1;
 
    cout << "\nGenerating random numbers and sorting in ascending order:\n\n";
    genRndNums(v1);
  
    // Calls the sort function and sort ascending order.
    sort(v1.begin(), v1.end());
    
    // Calls the print function and sort ascending order.
    printVec(v1);
    // Clears the vector array.
    v1.clear();
}*/


#define VEC_SIZE             250

#define NO_ITEMS        12
#define ITEM_W                5

#define SEED                    1
#define LOW                    1
#define HIGH                    10000



void genRndNums (vector <int> &vec) {
    
    for (int i=0; i < (int) vec.size(); ++i) {
        srand(SEED);
        int n = rand() % ( HIGH - LOW + 1 ) + LOW;
        vec.push_back(n);
    }
}

void printVec (vector <int> &vec) {
    int iCntr = 0;
    for (int i=0; i < vec.size(); ++i) {
        if (iCntr != NO_ITEMS ) {
            cout << setw( ITEM_W) << vec[i];
            iCntr++;
        } else {
            cout << endl;
            cout << setw( ITEM_W) << vec[i];
            iCntr = 1;
            
        }
    }
}

int main() {
    
    vector<int> vec1 (VEC_SIZE);
    
    genRndNums( vec1 );
    
    sort(vec1.begin(), vec1.end ());
    
    printVec( vec1 );
    
    //return 0;
}