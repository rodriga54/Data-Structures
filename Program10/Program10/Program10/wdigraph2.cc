/*********************************************************************
 PROGRAM:    CSCI 340 Program 10 - Weighted Digraphs.
 PROGRAMMER: Abraham Rodriguez
 LOGON ID:   Z1758468
 DUE DATE:   4/24/2015
 
 FUNCTION:  This program implement several graph algorithms on weighted 
            digraphs..
 *********************************************************************/

#include "wdigraph.h"

using namespace std;

//////////////////////////////////////////////////////////////////
// FUNCTION:  depth_first ( int u ) const
//
// ARGUMENTS: The index value u of the starting node is given as
//            an input argument to this function.
//
// RETURNS:   N/A
//
// NOTES:     Function is used to traverse a digraph in the depth-first
//            order and it can also be used to print the resulting path.
//////////////////////////////////////////////////////////////////
void wdigraph :: depth_first ( int u ) const
{
    static int firstVertex = -1;
    static int* visited = 0;
    
    if (firstVertex == -1)
    {
        firstVertex = u;
        
        //allocate visited array of size elements
        visited =  new int(size);
        
        //set all elements of visited to false
        for(int i = 0; i < size; i++)
        {
            visited[i] = 0;
        }
    }
    //prints the next vertex
    cout << label[u];
    visited[u] = true;
    
    for(int w = 0; w != size; w++)
    {
        if (adj_matrix[u][w] != 0 && visited[w] != 1)
        {
            //print an arrow to next vertex
            cout << "->";
            
            //call depth_first() with w as the argument
            depth_first(w);
        }
    }
        // Checks
        if (u == firstVertex)
        {
        cout << endl << endl;
        firstVertex = -1;
        }
}

//////////////////////////////////////////////////////////////////
// FUNCTION:  print_graph ( ) const
// ARGUMENTS: none
// RETURNS:   N/A
// NOTES:     Prints out the Adjacency Matrix.
//////////////////////////////////////////////////////////////////
void wdigraph :: print_graph ( ) const
{
    //Prints out the number of Nodes and Adjacency Matrix
    cout << endl << "Number of Nodes = " << label.size() << endl;
    cout << endl << "Adjacency Matrix" << endl << endl;
    cout << "  | ";
    
    // Prints out the Column labels
    for(int i = 0; i < label.size(); ++i)
    {
        cout << right << setw(2) << label[i] << " ";
       
    }
    
    cout << endl << "--|";
    
    // Prints out 3 dashes per node label
    for(int i = 0; i < label.size(); ++i)
    {
        if (label[i] > 0)
            cout <<  "---" ;
    }
    
    //Starts a newline
    cout << endl;
    
    //loop first prints the label
    for(int i = 0; i < label.size(); ++i)
    {
        cout << label[i] << " | ";
    
    // Second loop starts to fill in the matrix
    for(int j = 0; j < adj_matrix.size(); ++j)
    {
        // Statements prints element of node if not equal to zero
        // else prints a dash for element is equal to zero
        if ( adj_matrix[i][j] != 0)
        {
            cout << right << setw(2) << adj_matrix[i][j] << " ";
        }
        else
        {
            cout << setw(2) << " - ";
        }
    }
        //prints a new line between labels for readability.
        if (i != label.size() -1)
        {
        cout << endl << "  |" << endl;
        }
        else
        {
            cout << endl;
        }
    }
cout << endl;
}