//
//  main.cpp
//  Temp
//
//  Created by Abe Rodriguez on 2/26/15.
//  Copyright (c) 2015 ___AbeRodriguez___. All rights reserved.
//

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

//void init_vals ( vector < string >& v, unsigned& N, unsigned& M, unsigned& K );
//void print_vector ( const vector < string >& v, const unsigned& cnt );

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
    vector<string> v1;
    
    int cnt=0;
    unsigned N=0, M=0, K=0;
    
    init_vals(v1,N,M,K);
    print_vector (v1,cnt);
    return 0;
}

/*******************************************************************************
 FUNCTION:     void init_vals(vector& v, unsigned& N, unsigned& M, unsigned& K)
 
 DESCRIPTION:  Reads the values of N, M, and K when the program
 prompts for them and prints out those values on stdout.
 It also changes the size of the vector v to N and
 fills in the name tags for all soldiers in v.
 
 ********************************************************************************/
void init_vals(vector<string>& v, unsigned& N, unsigned& M, unsigned& K)
{
    int i =0, cnt=0;
    cout << "Number of people: ";
    cin>> N;
    cout << "Index for elimination: ";
    cin >> M;
    cout << "Index for printing: ";
    cin>> K;
    
    v.resize(N);
    generate(v.begin(),v.end(),SEQ(N));
    
    while(v.size() > 1)
    {
        i= (i+M-1) % v.size();
        v.erase(v.begin() + i);
        cnt ++;
        print_vector(v, cnt);
        cout<< endl <<endl;
    }

}

/*******************************************************************************
 FUNCTION:     void print_vector(const vector& v, const unsigned& cnt)
 
 DESCRIPTION:  Prints out the contents of vector v at the beginning
 and after removing K name tags from the vector until
 only one name tag remains, where cnt has an initial value
 of 0 and it simply indicates the total number of removals
 so far. At the end, it also prints the name tag of the
 last remaining soldier.
 
 *******************************************************************************/
void print_vector(const vector<string>& v, const unsigned& cnt)
{
    int line=0;
    
    cout<<"After eliminating "<< cnt <<" persons" <<endl <<"--------------------------------" <<endl;
    
    for (auto i=v.begin(); i!=v.end(); i++)
    {
        cout <<*i <<" ";
        line++;
        if(line%12 == 0)
        cout<<endl;
    }

}

