/*********************************************************************
 PROGRAM:    CSCI 340 Program 4 - Word Scanner.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   02/13/2015
 
 FUNCTION:   This program .
 *********************************************************************/

//#include "/home/courses/340/common/340.h"
#include <map>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>


using namespace std;

#ifndef H_PROG4
#define H_PROG4

const int NO_ITEMS = 3;  // no of words printed in single line
const int ITEM_W   = 16; // no of chars in longest word

typedef map < string, int > M;               // alias for map data type

void get_words ( M& );                       // process input stream
void print_words ( const M& );               // process output list
void clean_entry ( const string&, string& ); // eliminates punctuations

bool is_alnum ( const char& );               // predicate for alphanum chars
bool is_not_alnum ( const char& );           // predicate for non-alphanum chars
void to_lower ( char& );                     // converts char to lowercase
#endif

///////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// METHOD: get_words
// FUNCTION: read in words from input and place into the map m
// ARGUMENTS: map <string, int>& m
//////////////////////////////////////////////////////////////////
void get_words ( map < string, int >& m)
{
    string uncleaned, cleaned;
    
    ifstream inFile("prog4.txt");
    
    if (!inFile)
        cout << "Error: File could not be opened! ";
    else
        while(!inFile.eof())
        {
        inFile >> uncleaned;
            // Calls the clean_enrty() and passes the uncleaned word.
            // returning the cleaned word
            clean_entry (uncleaned, cleaned);
            if (cleaned.length() != 0)
                // Stores the cleaned word in the map.
                m[cleaned]++;
            
        }
   //Closes the file when done.
   inFile.close();
}

//////////////////////////////////////////////////////////////////
// METHOD: print_words
// FUNCTION: Prints all cleaned words stored in the map
// ARGUMENTS: map <string, int>& p
//////////////////////////////////////////////////////////////////
void print_words ( const map < string, int >& p)
{
    int Length = 0;
    int words = 0, out = 0;
    
    const map < string, int >::iterator ii;
    for (auto i = p.begin(); i != p.end(); ++i)
    {
        out++;
        cout << setw(ITEM_W) << left << i->first << ": " << setw(ITEM_W) << i->second << "\t";
        words += i->second;
        Length++;
        if (Length % NO_ITEMS == 0)
            cout << endl;
    }
    
    cout << "\nno of words in input stream  :" << ' ' << words;
    cout << "\nno of words in output stream  :" << ' ' << out;
}

//////////////////////////////////////////////////////////////////
// METHOD: clean_entry
// FUNCTION: finds the first and last alphanumaric to capture just
//           the word by calling the function substr(). Also calls
//           tolower() and for_each() function to converts any
//           uppercase letter to lowercase.
// ARGUMENTS: const string &uncleaned, string &cleaned
//////////////////////////////////////////////////////////////////
void clean_entry ( const string &uncleaned, string &cleaned)
{
    int first_letter;
    
    map<string, int>::iterator i ;
    for(first_letter = 0; first_letter < uncleaned.length(); first_letter++)
        {
            
            if (isalnum (uncleaned[first_letter])) break;
        }
    
    int last_letter = first_letter;
    
    for( ; last_letter < uncleaned.length(); last_letter++)
        {
        if (!isalnum (uncleaned[last_letter])) break;
        }
    cleaned = uncleaned.substr (first_letter, last_letter - first_letter);
  //
    for_each (cleaned.begin(), cleaned.end(), [] (char &x)->void {x = tolower(x);});
}

int main()
    {
        
    map < string, int > word_scanner;
    get_words(word_scanner);
    print_words(word_scanner);
    }
