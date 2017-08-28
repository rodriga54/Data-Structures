/*********************************************************************
 PROGRAM:    CSCI 340 Program 2 - prog2.cc.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   01/28/2015
 
 FUNCTION:   This program implement two search algorithms (linear search 
             and binary search) on randomly generated integers stored in
             vectors.
 *********************************************************************/

#include "prog2.h"
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <iomanip>
//#include "sub2.cc"

using namespace std;
using std::setw;


//#include “/home/courses/340/progs/p2/prog2.h”
//#include "prog2.h"
int main()
{
    // Create 2 objects to store randomly generated numbers.
    vector <int> v1 (ARR_SIZE);
    vector <int> v2 (TEST_ARR_SIZE);
    
    // Vectors function will generate 2 sets of random numbers by pre-defined
    //array sizes and SEED values.
    Vectors(v1, v2, SEED1, SEED2);
    
    //Calls the PrintVector and displays unsorted numbers.
    cout << "\nRandom Numbers Before Sorting: \n\n";
    printVector(v1);
    
    // Calls the Sort and PrintVector function ascending order.
    cout << "\nRandom Numbers After Sorting: \n\n";
    sortVector(v1);
   
    cout << "\nRandom Numbers Searched: \n\n";
    printVector(v2);
    
    // Calls the search and linearsearch Functions
    // within the BinarySearch the PrintStat function is called
    // to calculate the percent of matches found.
    cout << "\nLinear Search: \n";
    search(v1, v2, linearSearch);
    
    // Calls the search and binarySearch Functions
    // within the BinarySearch the PrintStat function is called
    // to calculate the percent of matches found.
    cout << "\nBinary Search: \n";
    search(v1, v2, binarySearch);
    
    return 0;
}
