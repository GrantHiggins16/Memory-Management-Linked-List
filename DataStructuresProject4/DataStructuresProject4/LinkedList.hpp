//
//  LinkedList.hpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
using namespace::std;

#include <stdio.h>

template<class DT>
class LinkedList
{
public:
    LinkedList(); // creates empty linked list
    LinkedList(DT value, LinkedList next); // creates linked list with one value
    LinkedList(LinkedList const &LL); // copy constructor
    
    LinkedList create(); //creates and returns empty linked list
    bool isEmpty(); //returns bool indicating if LL is empty
    int size();//returns number of nodes in list
    void add(const DT& object);//adds an object to beginning of linked list
    void insertAt(const DT& object, int position);//inserts obj at position
    DT& info();//returns data from current node or null if list is empty
    DT& info(int node);//returns data from specific node or null if list is empty
    LinkedList next();//returns next
    void setNext(LinkedList next);//sets next
    DT remove();//removes first node of the linked list
    DT remove(int node);//removes specific node of the linked list
    DT& find(const DT& object);// returns node of object or -1 if not found
    void readLinkedList(LinkedList const &LL);//copies from a linked list into current linked list
    virtual ~LinkedList();//destructor for linked list
private:
    DT* value;
    LinkedList* nextLL;
};

#endif /* LinkedList_hpp */
