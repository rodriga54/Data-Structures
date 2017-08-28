/////////////////////////////////////////////////////
//  Name:    Abe Rodriguez
//
//  Program: Extra Credit
//
//  Purpose: Program adds every number from 1 to 500
//           and prints the sum total.
//
//  Due Date: 8/5/15
/////////////////////////////////////////////////////


#include <iostream>

int main() {
    int sum =0;
    for(int i = 0; i<=500; i++)
    {
        sum = sum+i;
    }
    std::cout << "THE SUM OF THE NUMBERS 1 TO 500: " << sum << std::endl;
    return 0;
}
