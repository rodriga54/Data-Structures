//
//  binTree.h
//  Program6
//
//  Created by Abe Rodriguez on 3/1/15.
//  Copyright (c) 2015 ___AbeRodriguez___. All rights reserved.
//

#ifndef N_BINTREE
#define N_BINTREE
#include "Node.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::exit;
using std::string;
using std::vector;
using std::ifstream;

/*template < class T >
class binTree
{
public:
    binTree ( );                                    // default constructor
    unsigned height ( ) const;                      // returns height of tree
    virtual void insert (const T&);                 // inserts a node in tree
    void inorder (void (*) (const T&));             // inorder traversal of tree
protected:
    Node < T >* root;                               // root of tree
private:
    unsigned height (Node < T >*) const;            // private version of height()
    void insert (Node < T >*&, const T&);           // private version of insert()
    void inorder (Node < T >*, void (*)(const T&)); // private version of inorder ( )
};
#endif

typedef enum {left_side, right_side} SIDE;
SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side;};

template <class T>
binTree<T>::binTree()
{
    root = 0;
}


template <class T>
unsigned binTree <T>::height ( ) const
{
    return height(root);
}


template <class T>
void binTree<T>::insert (const T &x)
{
    insert(root, x);
}


template <class T>
void binTree<T>::inorder (void (*fn) (const T &))
{
    inorder(root,fn); // Recursive inorder function call
}


template <class T>
unsigned binTree <T>::height (Node < T >*p) const
{
    int leftside;
    int rightside;
    
    if (p == NULL)
        leftside = 0;
    else
        leftside = height(p->left);
    
    if (p == NULL)
        rightside = 0;
    else
        rightside = height(p->right);
    
    return 1 + max(leftside, rightside);
}

template <class T>
void binTree<T>::insert (Node < T >* &p, const T &x)
{
    if( p == 0)
    {
        
        Node <T> * newNode;
        newNode = new Node <T>( x ); // new node with new value
        p = newNode;                 // set pointer p to new node
    }
    else
    {
        if (rnd() == 0)
        {
            insert( p->left, x);
        }
        else
        {
            insert( p->right, x);
        }
    }
}


template <class T>
void binTree<T>::inorder (Node < T >*root, void (*fn)(const T&))
{
    if(root == NULL)return;
    {
        inorder(root->left,fn);
        fn(root->data);
        inorder(root->right,fn);
    }
}*/



//#ifndef H_TREE
//#define H_TREE

template < class T > class binTree {
public:
    binTree(){
        root =0; }
    
  /*  bool empty() const
    {
        if (root == 0)
            return true;
        else
            return false;
    }
    
    unsigned size() const
    {
        if (root == 0)
            return 0;
        else
            return size(root);
    }*/
    
    unsigned height() const
    {
   return height(root);
    }
    
    virtual void insert(const T& t)
    {
     
    insert(root, t);
    }

    void inorder (void (*fn)(const T&))
    {
        inorder(root, fn);
    }
    
    
protected:
    Node < T >* root; // root of tree
private:
   /* unsigned size(Node < T >* node) const
    {
        unsigned leftside;
        unsigned rightside;
        
        if (node->left == 0)
            leftside = 0;
        else
            leftside = size(node->left);
        
        if (node->right == 0)
            rightside = 0;
        else
            rightside = size(node->right);
        
        return(leftside + rightside + 1);
    }*/
    
    unsigned height(Node < T >* node) const
    {
        int leftside;
        int rightside;
        
        if (node == NULL)
            leftside = -1;
        else
            leftside = height(node->left);
        
        if (node == NULL)
            rightside = -1;
        else
            rightside = height(node->right);
        
        return 1 + max(leftside, rightside);
    }
    
    void insert(Node < T >* node, const T& t)
    {
      /*  if (node == 0)
        {
            Node< T >* n;
            n = new Node< T >(t);
            //n->data = t;
            node = n;
            
            //node = n;

        }
        else{
           // unsigned lefth = height(node->left);
            //unsigned righth = height(node->right);
            
            if (node == 0)
            {
                insert(node->left, t);
            }
            else
            {
                insert(node->right, t);
            }
            
    }
    }
    */
    
        if (node == NULL)
        {
            Node< T >* n;
            n = new Node< T >(t);
            //n->data = t;
            node = n;
        }
        //else if (node == 0)
        //{
       //     Node< T >* n;
       //     n = new Node< T >(t);
      //      //n->data = t;
       //     node = n;
      //  }
        
        //unsigned lefth = height(node->left);
        //unsigned righth = height(node->right);
        
        if (node == 0)
        {
            insert(node->left, t);
        }
        else
        {
            insert(node->right, t);
        }
    
    
    }
    
    void inorder (Node < T >*root, void (*fn)(const T&))
    {
        if(root == NULL)return;
        {
            inorder(root->left,fn);
            fn(root->data);
            inorder(root->right,fn);
        }
    }
};

#endif




