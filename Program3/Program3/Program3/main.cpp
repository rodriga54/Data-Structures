/*********************************************************************
 PROGRAM:    CSCI 340 Program 3 - Sieve of Eratosthenes.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   02/05/2015
 
 FUNCTION:   This program will find and print all prime numbers, which 
             are less than or equal to a given integer value n, using 
             the algorithm known as the Sieve of Eratosthenes.
 *********************************************************************/

#include <iostream>
#include <set>
#include <cstdlib>
#include <iomanip>
#include <math.h>

using namespace std;

////////////////////////////////////

#ifndef H_PROG3
#define H_PROG3

#define NO_ITEMS 16 // no of primes printed on single line
#define ITEM_W   4  // no of spaces for each prime

// routine for Sieve of Eratosthenes algorithm
void sieve ( set < int >&, int );

// prints out set of primes
void print_primes ( const set < int >& );
#endif

////////////////////////////////////

// Removes all nonprime numbers from the integer set container.
// runs through a set of nested for loops.
void sieve(set<int> &s,int n)
{
    for (int j = n; j*j<= (int) s.size(); j+=n)
    {
        // Reset counter.
        int k = 1;
        //int sz = (int) s.size()+2;
        
        // starts the for loop
        for( k = n; k <= (int) s.size(); k++)
        {
            int nonprime = j * k; //
            
            // Finds the varaible nonprime (above) in the set container.
            find(s.begin(), s.end(), nonprime);
            
            // Erases/Deletes the nonprime number from the set container
            // also decreases the size of the container.
            s.erase (nonprime);
        }
    }
    /*    //auto p = s.end();
    
   
    for (auto j = s.begin(); j !=s.end(); ++j)
     {
     // Reset counter.
     //auto k = j;
        // int p = *j;
         
     // starts the for loop
     for( auto k = (*j * *j); k != s.end(); k=+2)
     {
     auto nonprime = (*j * *k); //
     
     // Finds the varaible nonprime (above) in the set container.
     find(s.begin(), s.end(), nonprime);

     // Erases/Delestes the nonprime number from the set container
     // also decreases the size of the container.
     s.erase (nonprime);
     }
     }*/
    
    
}

// Prints all Prime numbers in the set container.
void print_primes ( const set < int >& s )
{
    int Length = 0;
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        
      cout << setw(ITEM_W) << *i << ' ';
        
        Length++;
        if (Length % NO_ITEMS == 0)
            cout << endl;
       
    }
}


int main()
{
    // delcared Varaibles.
    int in, m = 2;
    
    // Create a set container.
    set<int> s;
    
    // User to input the an integer larger than 2.
    cout << "Upper limit for the set of primes: ";
    cin >> in ;
    cout << endl;
    
    // Populates the set contianer from the specified user input.
    // each pass through the loop it calls the insert function.
    for(auto i = m; i < in; i++)
    s.insert(i);
    
    // Calls function sieve
    sieve (s, m);
    
    // Call the print_primes functoin
    print_primes (s);
    cout << endl;
    return 0;
}
