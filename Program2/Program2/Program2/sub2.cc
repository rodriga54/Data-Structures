/*********************************************************************
 PROGRAM:    CSCI 340 Program 2 - sub2.cc.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   01/28/2015
 
 FUNCTION:   This program implement two search algorithms (linear search
 and binary search) on randomly generated integers stored in
 vectors.
 *********************************************************************/

#include "prog2.h"

// Generates and stores numbers for the 2 vectors by pre-defined variables.
void Vectors (vector <int> & v1, vector <int> & v2, int s1, int s2)
{
    srand(s1);
    
    for(int i = 0; i < v1.size(); ++i)
    {
        //Generating Random number and storing it into 1st vector
        int b = rand() % (HIGH - LOW + 1) + LOW;
        v1[i]= b;
    }
    
    srand(s2);
    for(int i = 0; i < v2.size(); ++i)
    {
        //Generating Random number and storing it into 2nd vector
        int b = rand() % (HIGH - LOW + 1) + LOW;
        v2[i] = b;
    }
}

// Searches for x from the beginning to the end of vector v
// by calling the find() function.
// Returns TRUE if a match is found, and FALSE if no match is found.
bool linearSearch (const vector <int> & v, int x)
{
    // Calls the find function.
    if (find(v.begin(), v.end(), x) != v.end())
        return true; // Match found.
    else
        return false; // No match Found.
}

//The function searches the v Vector for x by implementing the binary_search ().
//If the search is successful, it returns true; otherwise, it returns false.
bool binarySearch ( const vector <int> & v, int x)
{
    bool exists = binary_search(v.begin(), v.end(), x);
            return exists; // Match found.
}

//takes a pointer to the search routine p ( ), and then it calls p ( )
//for each element of vector v2 in vector v1. It computes the total number
//of successful searches and returns that value to the main ( ) routine as
//an input argument to the print routine printStat ( ), which is used to
//print out the final statistics for a search algorithm.
int search ( const vector <int> & v1, const vector <int> & v2, bool ( *p ) (const vector <int> &v, int ) )
{
    int total = 0;
    
    for (int i =0 ; i < v2.size(); i++)
    {
        if (p(v1, v2[i])) total++;
            //printStat(total, v2.size());
    }
    
    printStat(total, (int) v2.size());
    return false;
}

// Calls the sort function to sort in an ascending order.
void sortVector ( vector <int> & v )
{
    // Calls the sort function and sort ascending order.
    sort(v.begin(), v.end());
    printVector(v);
}

// Calls the printVector to print the contents of the array.
void printVector ( const vector <int> & v )
{
    auto i = 0;
    while (i < v.size())
    {
        cout << setw(ITEM_W) << left <<  v[i] << ' ';
        i ++;
        if (i % NO_ITEMS == 0)
            cout << endl;
    }
    if (i % NO_ITEMS != 0)
        cout << endl;
}

// The printStat calculates the percent of matches found.
void printStat (int totalSucCnt, int vectorSz)
{
    float result = 100 * totalSucCnt / vectorSz;
 
    cout << "\t\tPercent of Successful Searches: "  << right << std::setprecision(2) <<  fixed << result <<  "%" <<  endl;
}