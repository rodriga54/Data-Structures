//#include "/home/cs340/common/340.h"

#ifndef H_ENTRY
#define H_ENTRY

#define ID_SZ      3    // size of key
#define ITEM_SZ    24   // max size for item description
#define TBL_SZ     31   // default size for hash table

// entry in hash table
#include <iostream>
#include <vector>
//#include <iomanip>
//#include <fstream>
//#include <complex.h>

using namespace std;

struct Entry {
    string key,   // key
    desc;  // description
    unsigned num; // no of copies
    
    //constructor
    Entry ( const string& k = "", const string& d = "",
           const unsigned& n = 0 ) : key ( k ), desc ( d ),
    num ( n ) { }
};
#endif
