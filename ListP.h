/* This is the class file that contains all the
 * functions for listP
 *
 * @author Michael Barclay
 * @version Homework 5
 * @date 03/03/15
 * @file ListP.h
 */
#include <iostream>
#include "ListNode.h"


#ifndef _LISTP
#define _LISTP
using namespace std;

class ListP
{
public:
   ListP();
   ListP(const ListP & l); // copy constructor
   ~ListP();

   bool isEmpty() const;
   int getSize() const;

   void insert(int pos, const ItemType & x); // insert the new item x into the position "pos"
   void remove(int pos);// remove the item at the position "pos"
   void display(); // for debugging purpose, print out the list
   void sort_mergesort();
/*   void erase(iterator & pos);

*/
private:
   int size; // how many items in the list
   ListNode * head;
   ListNode * mergesort(ListNode * begin, int lsize);
   ListNode * merge(ListNode * list1, ListNode * list2);
};
#endif
