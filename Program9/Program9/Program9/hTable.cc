/*********************************************************************
 PROGRAM:    CSCI 340 Program 9 - Hashing with Separate Chaining and Indirect Sorting.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   4/14/2015
 
 FUNCTION:  This program creates, searchs, prints, and sorts an item 
            inventory. The item inventory information will be kept in 
            a sequentially allocated table with a given size of entries 
            with default size TBL_SZ = 31.
 *********************************************************************/

#include "hTable.h"
#include <stdexcept>
#include <iomanip>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
//#include "/home/340/progs/p9/hTable.h"

using namespace std;

//////////////////////////////////////////////////////////////////
// FUNCTION:  HT ()
// ARGUMENTS: none - defualt constructor
// RETURNS:   N/A
// NOTES:     initializes the size of the hTable.
//////////////////////////////////////////////////////////////////
HT :: HT (const unsigned& hs)
{
    hTable.resize(hs);
    hsize = hs;
}

//////////////////////////////////////////////////////////////////
// FUNCTION:  ~HT ()
// ARGUMENTS: none - deconstructor
// RETURNS:   N/A
// NOTES:     Deletes the contents of the hTable and pTable.
//////////////////////////////////////////////////////////////////
HT :: ~HT ()
{
    //delete [] hTable;
    for (int i =0; i < hTable.size(); i++)
    {
        hTable[i].pop_back();
        
    }
   // delete [] pTable;
    for (int i = 0; i < pTable.size(); i++)
    {
        delete pTable[i];
    }
}

int HT :: hash( const string& key)
{    int hash = 0, index;
    
    for (int i = 0; i < key.length(); i++)
    {
        cout << "Hash " << hash << endl;
        hash = hash +(int) key[i];
    }
    index = hash % hsize;
    return index;
}

//////////////////////////////////////////////////////////////////
// FUNCTION:  insert ( const Entry& e)
// ARGUMENTS: const Entry& e
// RETURNS:   void
// NOTES:     Inserts the record of the item e : (key, desc, num)
//            in the hash table. If the key already exists the function
//            prints an error message; otherwise, it prints the index
//            value of the inserted record in the hash table and it also
//            inserts the address of the record (in the hash table) into
//            the pointer table.
//////////////////////////////////////////////////////////////////
void HT :: insert ( const Entry& e)
{
    // hash the key to determine which hash the key would be stored in.
    int index = hash(e.key);
    
    // reference to list
    list<Entry>& index2 = hTable[index];
    
    //list of Entrys iterator
    list <Entry>::iterator newkey;
    
    // search the hash table to see if the key is already in the hash table.
    newkey = find_if (index2.begin(), index2.end(), [&e](Entry t)
    {
     return (t.key.compare(e.key) == 0);
    });
    
    // Check to see if key is duplicate.
    
    if (newkey !=  index2.cend())
        {
        cout << " not inserted - duplicate key!! " << endl;
        }
            else
            {
            cout << "entry =   " << index << endl;
            hTable[index].push_front(e);
            pTable.push_back(&hTable[index].front());
            }
}

//////////////////////////////////////////////////////////////////
// FUNCTION:  search ( const string& key)
// ARGUMENTS: const string& key
// RETURNS:   void
// NOTES:     Searches the hash table for a record with a given key.
//            if found prints out contents else error message.
//////////////////////////////////////////////////////////////////
void HT :: search ( const string& key)
{
    // hash the key to determine which hash the key would be stored in.
    int index = hash(key);
    
    // reference to list
    list<Entry>& index2 = hTable[index];
    
    //list of Entrys iterator
    list <Entry>::iterator newkey;
    
    // search the hash table to see if the key is already in the hash table.
    newkey = find_if (index2.begin(), index2.end(), [key](Entry t)
        {
            return (t.key.compare(key) == 0);
        });
    
            cout << " ==> number: "
            << setw(4) << newkey->num
            << " - item: " << newkey->desc
            << endl;
}

//////////////////////////////////////////////////////////////////
// FUNCTION:  hTable_print ( )
// ARGUMENTS: none
// RETURNS:   void
// NOTES:     prints out the hTable.
//////////////////////////////////////////////////////////////////
void HT :: hTable_print ( )
{
    list<Entry>::iterator itr;
    
    for(unsigned int i = 0; i < hTable[i].size(); i++ )
    {
        for(itr = hTable[i].begin(); itr != hTable[i].end(); itr++)
        {
            if (hTable[i].size() > 0)
            {
                cout << setw(4) << i << ": "
                << setw(4) << (*itr).key << "  -  "
                << setw(4) << (*itr).num << "  -  "
                << setw(4) << (*itr).desc << endl ;
            }
            else
            {
                cout << endl;
            }
        }
    }
    
}

//////////////////////////////////////////////////////////////////
// FUNCTION:  pTable_print ( )
// ARGUMENTS: none
// RETURNS:   void
// NOTES:     Prints the pointer Table in sorted order.
//////////////////////////////////////////////////////////////////
void HT :: pTable_print ( )
{
    sort(pTable.begin(), pTable.end(), [] ( Entry* p, Entry* q ){ return (p->key.compare(q->key) < 0);});
    
    for(int i = 0; i < pTable.size(); i++ )
    {
        for(auto itr = pTable.begin(); itr != pTable.end(); itr++)
        {
            cout << " " << setw(4) << pTable[i]->key << "  -  "
            << setw(5) << pTable[i]->num << "  -  "
            << pTable[i]->desc << endl;
        }
    }
}
