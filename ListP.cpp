/* Has all the functions for the listP class so that
 * you can insert, remove, and sort the list
 *
 * @author Michael Barclay
 * @version Homework 5
 * @date 03/03/15
 * @file ListP.cpp
 */
#include "ListP.h"
#include "ListNode.h"

ListP::ListP(): size(0), head(NULL)
{}

ListP::ListP(const ListP & l)
{
    size = l.getSize(); //copies the size
    head = new ListNode(*l.head); //copies the head
    ListNode * ptr = l.head;
    ListNode * ptr2 = head;
    while(ptr -> next != NULL) //iterates through and copies each ListNode
    {
        ptr2 = new ListNode(ptr -> item);
        ptr = ptr -> next;
        ptr2 = ptr2 -> next;
    }

}

ListP::~ListP()
{
    while(!isEmpty())
        remove(0);
}

bool ListP::isEmpty() const
{
    return head == NULL;
}

int ListP::getSize() const
{
    return size;
}

void ListP::insert(int pos, const ItemType & x)
{
    if (isEmpty()) //adds the first ListNode
    {
        head = new ListNode(x,NULL);
    }
    else if(pos == 0) //Adds to the front of the List
    {
        ListNode * ptr = new ListNode(x,head);
        head = ptr;
    }
    else //Adds to the index of the list
    {
        ListNode * ptr = head;
        for(int i = 1 ; i < pos ; i++)
            ptr = ptr -> next;
        if((pos+2) == size)
        {
            ptr -> next = new ListNode(x,NULL);
        }
        else
            ptr -> next = new ListNode(x,ptr -> next);
    }
    size++;
}

void ListP::remove(int pos)
{
    if(!isEmpty()) //checks if list is empty
    {
        ListNode * ptr = head;
        if(pos == 0) //if removing the first item
        {
            head = head -> next;
            delete ptr;
            ptr = NULL;
            if(size == 1) //if the list has one element just delete it
            {
                delete head;
                head = NULL;
            }
        }
        else //if you are removing any other item
        {
            for(int i = 1 ; i < pos ; i++)
                ptr = ptr -> next;
            ListNode * ptr2 = ptr -> next;
            ptr -> next = ptr2 -> next;
            delete ptr2;
            ptr2 = NULL;
        }
        size--;
    }
}

void ListP::display()
{

    ListNode * ptr = new ListNode;
    ptr = head;
    for(int i = 0 ; i < size ; i++) //displays each ListNode
    {
        cout << ptr -> getItem() << " ";
        ptr = ptr -> getNext();
    }
    cout << endl;
}

void ListP::sort_mergesort()
{
    ListNode *ptr = head;
	head = mergesort(head, size);
}

ListNode * ListP::merge(ListNode * list1, ListNode * list2)
{
    if (list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    else if(list1 -> getItem() < list2 -> getItem())
    {
        list1 -> next = merge(list1 -> next, list2);
        return list1;
    }
    else
    {
        list2 -> next = merge(list1, list2 -> next);
        return list2;
    }
}

ListNode * ListP::mergesort(ListNode * begin, int lsize)
{
    if (begin == NULL || begin -> next == NULL)
        return begin;
    int left = lsize / 2;
	int right = lsize - left;
	ListNode * half = begin;
	for(int i = 0 ; i < left ; i++) //finds half way point of list
        half = half -> next;
    ListNode * ptr = half -> next;
    half -> next = NULL;
    return merge(mergesort(begin, left), mergesort(ptr, right));
}
