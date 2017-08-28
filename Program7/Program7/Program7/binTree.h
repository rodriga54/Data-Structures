/*********************************************************************
 PROGRAM:    CSCI 340 Program 7 - Binary Tree Class.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   3/23/2015
 
 FUNCTION:  This program implement a class for binary trees. To deal
 with variety of data types, implement this class as a template.
 *********************************************************************/

//#include "/home/340/progs/p6/Node.h"
#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Node.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::exit;
using std::string;
using std::vector;
using std::ifstream;


template < class T >
class binTree
{
public:
    binTree ( );                                    // default constructor
    unsigned height ( ) const;                      // returns height of tree
    virtual void insert (const T&);                 // inserts a node in tree
    void inorder (void (*) (const T&));             // inorder traversal of tree
    unsigned size ( ) const;                        // returns size of tree
protected:
    Node < T >* root;                               // root of tree
private:
    unsigned height (Node < T >*) const;            // private version of height()
    void insert (Node < T >*&, const T&);           // private version of insert()
    void inorder (Node < T >*, void (*)(const T&)); // private version of inorder()
    unsigned size ( Node < T >* ) const;            // private version of size()
};
#endif

typedef enum {left_side, right_side} SIDE;
SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side;};

//////////////////////////////////////////////////////////////////
// METHOD: binTree()
// FUNCTION: Function initializes the root to 0. default constructor.
// ARGUMENTS: no argument
//////////////////////////////////////////////////////////////////
template <class T>
binTree<T>::binTree()
{
    root = 0;
}

//////////////////////////////////////////////////////////////////
// METHOD: height () const
// FUNCTION: Recursive height function call
// ARGUMENTS: no arguments.
//////////////////////////////////////////////////////////////////
template <class T>
unsigned binTree <T>::height ( ) const
{
    return height(root);
}

//////////////////////////////////////////////////////////////////
// METHOD: insert
// FUNCTION: Recursive insert function call
// ARGUMENTS: (const T &x)
//////////////////////////////////////////////////////////////////
template <class T>
void binTree<T>::insert (const T &x)
{
    insert(root, x);
}

//////////////////////////////////////////////////////////////////
// METHOD: inorder
// FUNCTION: Recursive inorder function call .
// ARGUMENTS: (void (*fn) (const T &))
//////////////////////////////////////////////////////////////////
template <class T>
void binTree<T>::inorder (void (*fn) (const T &))
{
    inorder(root,fn); // Recursive inorder function call
}

//////////////////////////////////////////////////////////////////
// METHOD: size
// FUNCTION: Recursive size function call .
// ARGUMENTS: no arguments.
//////////////////////////////////////////////////////////////////
template <class T>
unsigned binTree<T>::size ( ) const
{
     return size(root) -1;
}

//////////////////////////////////////////////////////////////////
// METHOD: height () const
// FUNCTION: Function determines the height of the tree.
// ARGUMENTS: Node pointer.
//////////////////////////////////////////////////////////////////
template <class T>
unsigned binTree <T>::height (Node < T >*p) const
{
    unsigned leftside;
    unsigned rightside;
    
    if (p == NULL)
        leftside = -1;
    else
        leftside = height(p->left);
    
    if (p == NULL)
        rightside = -1;
    else
        rightside = height(p->right);
    
    return 1 + max(leftside, rightside);
}

//////////////////////////////////////////////////////////////////
// METHOD: insert
// FUNCTION: Private virtual function inserts a node with the data
//           value x in a binary tree. if the tree is empty, then
//           the new node will be the root of the tree with the
//           value x; otherwise, the left or the right subtree is
//           randomly selected and the value x is inserted in that side.
// ARGUMENTS: (Node < T >* &p, const T &x)
//////////////////////////////////////////////////////////////////
template <class T>
void binTree<T>::insert (Node < T >* &p, const T &x)
{
    if( p == 0)
    {
        Node <T> * newNode;          // create new Node pointer.
        newNode = new Node <T>( x ); // new node with new value
        p = newNode;                 // set pointert p to new node
    }
    else
    {
        if (rnd() == 0)              // Randomly picks the sides.
        {
            insert( p->left, x);     // x is inserted in the left side of the tree
        }
        else
        {
            insert( p->right, x);    // x is inserted in the right side of the tree
        }
    }
}

//////////////////////////////////////////////////////////////////
// METHOD: inorder
// FUNCTION: Private function is the inorder traversal of tree.
// ARGUMENTS: (Node < T >*root, void (*fn)(const T&))
//////////////////////////////////////////////////////////////////
template <class T>
void binTree<T>::inorder (Node < T >*root, void (*fn)(const T&))
{
    if(root == NULL)return;
    {
        inorder(root->left,fn);
        fn(root->data);
        inorder(root->right,fn);
    }
}

//////////////////////////////////////////////////////////////////
// METHOD: size
// FUNCTION: Private function is the size of tree.
// ARGUMENTS: ( Node < T >* p) const
//////////////////////////////////////////////////////////////////
template <class T>
unsigned binTree<T>::size ( Node < T >* p) const
{
    if( p != NULL ) // if not empty
        return size( p->left ) + size( p->right ) + 1;
    else
        return 0; // emtpy tree
}