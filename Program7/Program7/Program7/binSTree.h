/*********************************************************************
 PROGRAM:    CSCI 340 Program 7 - Binary Search Tree Class.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   3/23/2015
 
 FUNCTION:  This program implement a class for binary serach trees. 
 To deal with variety of data types, implement this class as a template.
 *********************************************************************/

#ifndef BINSTREE_H
#define BINSTREE_H
#include "binTree.h"
#include "Node.h"
//#include "/home/340/progs/p6/Node.h"

template < class T >
class binSTree : public binTree < T >
{
public:
    void insert ( const T& x );                     // inserts node with value x
    void remove ( const T& x );                     // removes node with value x
private:
    void insert ( Node < T >*&, const T& );         // private version of insert
    void remove ( Node < T >*&, const T& );         // private version of remove
    Node < T >* pred ( Node < T >* );               // returns predecessor of node
};

#endif

//////////////////////////////////////////////////////////////////
// METHOD: insert
// FUNCTION: Recursive insert function call
// ARGUMENTS: (const T& x)
//////////////////////////////////////////////////////////////////
template < class T >
void binSTree<T>::insert(const T& x)
{
    insert(this->root,x);
}

//////////////////////////////////////////////////////////////////
// METHOD: remove
// FUNCTION: Recursive remove function call
// ARGUMENTS: (const T &x)
//////////////////////////////////////////////////////////////////
template < class T >
void binSTree<T>::remove (const T& x)
{
    remove(this->root, x);
}

//////////////////////////////////////////////////////////////////
// METHOD: insert
// FUNCTION: Private function is the size of tree.
// ARGUMENTS: ( Node < T >*& leaf, const T& key)
//////////////////////////////////////////////////////////////////
template < class T >
void binSTree<T>::insert ( Node < T >*& leaf, const T& key)
{
    if(leaf == NULL)
    {
        leaf = new Node<T>( key );
    }
    else if( key < leaf->data)
    {
        insert( leaf->left, key );
    }
    else if( key > leaf->data )
    {
        insert( leaf->right, key );
    }
    else
    {
        return; // duplicate
    }
    
}

//////////////////////////////////////////////////////////////////
// METHOD: remove
// FUNCTION: Private function removes item from tree.
// ARGUMENTS: ( Node < T >*& p, const T& Value)
//////////////////////////////////////////////////////////////////
template < class T >
void binSTree<T>::remove ( Node < T >*& p, const T& Value)
{
    
    // Find the item
    bool found = false;
    Node<T>* predecessor=NULL;
    Node<T>* current = p;
    if(current==NULL){
        cout<<"Tree is empty"<<endl;return;}
    while(current!=NULL)
    {
        if(current->data==Value)
        {
            found = true;
            break;
        }
        else
        {
            predecessor = current;
            if(Value > (current->data))
                current=current->right;
            else
                current=current->left;
        }
    }
    if(!found)
    {
        return;
    }
    // CASE 1: Removing a node with a single child
    if((current->left==NULL && current->right != NULL) || (current->left != NULL && current->right==NULL))
    {
        // Right Leaf Present, No Left Leaf
        if(current->left==NULL && current->right != NULL)
        {
            // If predecessor's left tree equals Node n
            if(predecessor->left==current)
            {
                // then predecessor's left tree becomes n's right tree
                // and delete n
                predecessor->left=current->right;
                delete current;
                current=NULL;
            }
            // If predecessor's right tree equals Node n
            else
            {
                // then predecessor's right tree becomes n's right tree
                // and delete n
                predecessor->right=current->right;
                delete current;
                current=NULL;
            }
        }
        else // Left Leaf Present, No Right Leaf Present
        {
            if(predecessor->left==current)
            {
                predecessor->left=current->left;
                delete current;
                current=NULL;
            }
            else
            {
                predecessor->right=current->left;
                delete current;
                current=NULL;
            }
        }
        return;
    }
    // CASE 2: Removing a Leaf Node
    if(current->left==NULL && current->right==NULL)
    {
        if(predecessor->left==current)
            predecessor->left=NULL;
        else
            predecessor->right=NULL;
        delete current;
        return;
    }
    // CASE 3: Node has two children
    // Replace Node with smallest value in right subtree
    if(current->left != NULL && current->right != NULL)
    {
        Node<T>* check;//=current->right;
        if((current->left==NULL)&&(current->right==NULL))
        {
            pred(p);
            delete check;
            current->right = NULL;
        }
        else // Right child has children
        {
            // If the node's right child has a left child
            // Move all the way down left to locate smallest element
            if((current->right)->left!=NULL)
            {
                Node<T>* leftCurrent;
                Node<T>* leftCurrentPred;
                leftCurrentPred=current->right;
                leftCurrent=(current->right)->left;
                while(leftCurrent->left != NULL)
                {
                    leftCurrentPred=leftCurrent;
                    leftCurrent=leftCurrent->left;
                }
                pred(p);
                delete leftCurrent;
                leftCurrentPred->left = NULL;
            }
            else
            {
                Node<T>* temp=current->right;
                current->data=temp->data;
                current->right=temp->right;
                delete temp;
            }
        }
        return;
    }
   
}

//////////////////////////////////////////////////////////////////
// METHOD: pred
// FUNCTION: Private function the predecessor of node.
// ARGUMENTS: ( Node < T >* p)
//////////////////////////////////////////////////////////////////
template <class T>
Node < T >* binSTree<T>::pred ( Node < T >* p)
{
    Node<T>* current = p;
    // CASE 3: Node has two children
    // Replace Node with smallest value in right subtree
    if(current->left != NULL && current->right != NULL)
    {
        Node<T>* check=current->right;
        if((current->left==NULL)&&(current->right==NULL))
        {
            return check;
        }
        else // Right child has children
        {
            // If the node's right child has a left child
            // Move all the way down left to locate smallest element
            if((current->right)->left!=NULL)
            {
                Node<T>* leftCurrent;
                Node<T>* leftCurrentPred;
                leftCurrentPred=current->right;
                leftCurrent=(current->right)->left;
                while(leftCurrent->left != NULL)
                {
                    leftCurrentPred=leftCurrent;
                    leftCurrent=leftCurrent->left;
                }
                return leftCurrent;
            }
            else
            {
                Node<T>* temp=current->right;
                current->data=temp->data;
                current->right=temp->right;
                delete temp;
            }
        }
    }
        return 0;
}



    
  