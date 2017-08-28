/*********************************************************************
 PROGRAM:    CSCI 340 Program 8 - Heaps and Heapsort.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   4/2/2015
 
 FUNCTION:  This program implements a Heap and HeapSort template Class. 
            Sorting items from several input files, using the heapsort 
            technique. For each input file, your program first reads the 
            items from the input file and builds a heap structure form 
            items. Then, it retrieves these items from a heap structure 
            in a given order and prints them out. Full path names of the 
            input files.
 *********************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <complex.h>
#include "prog8.h"

using namespace std;
//using std::vector;

//////////////////////////////////////////////////////////////////
// METHOD: void get_list()
// FUNCTION: This function first opens an input file, then reads the
//           items from the file and inserts them in a vector. Finally,
//           it closes the input file.
// ARGUMENTS: ( vector < T >& v, const char* path )
//           The first argument v to this function is the vector and
//  the second argument path is the full path name of the input file.
//////////////////////////////////////////////////////////////////
template < class T >
void get_list ( vector < T >& v, const char* path )
{
    v.clear();
    T temp;
    ifstream inFile;
    inFile.open(path);
    if (!inFile)
        cout << "Error: File could not be opened! ";
    else
        inFile >> temp;
        while(!inFile.eof())
        {
            v.push_back(temp);
            inFile >> temp;
        }
    //Closes the file when done.
    inFile.close();
    
}


//////////////////////////////////////////////////////////////////
// METHOD: void construct_heap()
// FUNCTION: This function constructs a heap structure from the items
//           of vector v and uses the predicate pred to compare the
//           items when building the heap. It calls the function
//           make_heap ( ) to construct the heap and the function
//           sort_heap ( ) to sort the items using the predicate pred.
// ARGUMENTS: ( vector < T >& v, P pred )
//////////////////////////////////////////////////////////////////
template < class T,class P >
void construct_heap ( vector < T >& v, P pred )
{
    make_heap(v.begin(), v.end(), pred);
    sort_heap (v.begin(), v.end(), pred);

}

//////////////////////////////////////////////////////////////////
// METHOD: bool abs_less < T > :: operator ( )
// FUNCTION: This function object compares the items x and y and
//           returns true if the absolute value of x is less than
//           the absolute value of y; otherwise, it returns false.
// ARGUMENTS: ( const T& x, const T& y ) const
//////////////////////////////////////////////////////////////////
template < class T >
bool abs_less < T > :: operator ( ) ( const T& x, const T& y ) const
{
    return abs(x) < abs(y);
}

//////////////////////////////////////////////////////////////////
// METHOD: print_list < T, W, L > :: print_list()
// FUNCTION: This function print_list, where s is the size of the
//           heap and c is used as a counter, with the default value
//           of 0, that can be used to insert the newline characters
//           in printout.
// ARGUMENTS: ( const int& s, const int& c )
//////////////////////////////////////////////////////////////////
template < class T, const int W, const int L >
print_list < T, W, L > :: print_list ( const int& s, const int& c )
{
    cnt = c; sz = s;
}

//////////////////////////////////////////////////////////////////
// METHOD: void print_list < T, W, L > :: operator ( )
// FUNCTION: This function object prints out the item x of type T
//           of a heap, the template argument W is the size of the
//           printed item, and the template argument L is the maximum
//           number of items is printed on a single line.
// ARGUMENTS: ( const T& x )
//////////////////////////////////////////////////////////////////
template < class T, const int W, const int L >
void print_list < T, W, L > :: operator ( ) ( const T& x )
{
    
    if ( cnt <= sz )
        {
            if (cnt == sz)
                cout << "\n";
        if (cnt % L == 0)
            {
            cout << "\n";
            }
            cout  << fixed << setprecision(2) << setw(W) << x << " ";
            cnt++;
        }
            //
            
}

int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings
    
    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";
    
    // first heap
    
    cout << "first heap - ascending order:\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int, INT_SZ, INT_LN > print1 ( v1.size ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    cout << "\n\nfirst heap - descending order:\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    cout << "\n\nfirst heap - ascending order with absolute values:\n";
    get_list ( v1, D1 );
    construct_heap ( v1, abs_less < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );
    
    // second heap
    
    cout << "\n\nsecond heap - ascending order:\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float, FLT_SZ, FLT_LN > print2 ( v2.size ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    cout << "\n\nsecond heap - descending order:\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    cout << "\n\nsecond heap - ascending order with absolute values:\n";
    get_list ( v2, D2 );
    construct_heap ( v2, abs_less < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );
    
    // third heap
    
    cout << "\n\nthird heap - ascending order:\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string, STR_SZ, STR_LN > print3 ( v3.size ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );
    
    cout << "\n\nthird heap - descending order:\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );
    
    // print termination message
    
    cout << "\n\n\t\t\t*** end of program execution ***\n\n";
    return 0;
}
