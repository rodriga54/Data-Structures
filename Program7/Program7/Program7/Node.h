//
//  Node.h
//  Program7
//
//  Created by Abe Rodriguez on 3/19/15.
//  Copyright (c) 2015 ___AbeRodriguez___. All rights reserved.
//
#ifndef H_NODE
#define H_NODE

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

// definition for class of nodes in bin tree

template < class T > class binTree; // forward declaration
template < class T > class binSTree; // forward declaration

template < class T >
class Node {
    friend class binTree < T >;          // binTree is friend
    friend class binSTree < T >;         // binSTree is friend
public:
    // default constructor
    Node ( const T& x = T ( ), Node < T >* l = 0, Node < T >* r = 0 ) :
    data ( x ), left ( l ), right ( r ) { }
private:
    T data;                         // data component
    Node < T > *left, *right;       // left and right links
};
#endif

