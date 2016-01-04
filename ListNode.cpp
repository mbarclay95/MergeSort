/* This is where all the functions for creating a ListNode
 * are. You can set the listNodes item and its next.
 *
 * @author Michael Barclay
 * @version Homework 5
 * @date 03/03/15
 * @file ListNode.cpp
 */
#include "ListNode.h"
#include "ListP.h"
#include <iostream>

ListNode::ListNode() //constructor
{}

ListNode::ListNode(const ItemType & x) //constructor
{
    item = x;
}

ListNode::ListNode(const ItemType & x, ListNode * nNode) //constructor
{
    item = x;
    next = nNode;
}

ListNode::~ListNode()
{}

ItemType ListNode::getItem()
{
    return item;
}

ListNode *ListNode::getNext()
{
    return next;
}

void ListNode::setNext(ListNode * nNode)
{
    next = nNode;
}

void ListNode::setItem(const ItemType & x)
{
    item = x;
}


