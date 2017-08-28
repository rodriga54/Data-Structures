//
//  prog2.h
//  Program2
//
//  Created by Abe Rodriguez on 1/22/15.
//  Copyright (c) 2015 ___AbeRodriguez___. All rights reserved.
//


// Header file for program, which implements two search
// algorithms - linear and binary search.

//#include "/home/courses/340/common/340.h"

#ifndef PROG2_H
#define PROG2_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include <algorithm>
#include <array>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <assert.h>
#include <string.h>

using namespace std;
using namespace std::placeholders;


#define ARR_SIZE      200  // size of input vector
#define TEST_ARR_SIZE 100  // size of test vector

#define SEED1    1         // seed value for RNG1
#define SEED2    3         // seed value for RNG2

#define LOW      1         // lower bound for random nums
#define HIGH     1000      // upper bound for random nums

#define NO_ITEMS 16        // num of items printed on single line
#define ITEM_W   4         // num of spaces allocated for each item

// constructs vectors of ints
void Vectors ( vector <int> &, vector < int >&, int, int );

// routine for linear search
bool linearSearch ( const vector <int> &, int );

// routine for binary search
bool binarySearch ( const vector < int >&, int );

// routine for generic search
int search ( const vector < int >&, const vector < int >&, bool ( * ) ( const vector < int >&, int ) );

// routine for sort
void sortVector ( vector < int >& );

// prints vector of ints
void printVector ( const vector < int >& );

// prints final statistics
void printStat ( int, int );

#endif
