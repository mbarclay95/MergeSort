/* Main file to test all of the functions
 * and show that they work
 *
 * @author Michael Barclay
 * @version Homework 5
 * @date 03/03/15
 * @file main.cpp
 */
#include <iostream>
#include <cstdlib>
#include "ListP.h"
#include "ListNode.h"


int main()
{
    ListP L1;
    for(int i = 0 ; i < 10 ; i++) //creates unsorted list
        L1.insert(0,i);
    L1.display();
    L1.insert(5,100); //shows that insert works at index other than 0
    L1.display();
    L1.sort_mergesort(); //sorts the list
    L1.display();
    ListP L2(L1); //copies the list
    L2.display();
    L1.remove(4); //removes the 4th item of the list
    L1.display();
}
