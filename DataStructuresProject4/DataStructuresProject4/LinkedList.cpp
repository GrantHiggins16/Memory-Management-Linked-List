//
//  LinkedList.cpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

using namespace::std;

template<class DT>
LinkedList<DT>::LinkedList()
{
    value = NULL;
    nextLL = NULL;
}

template<class DT>
LinkedList<DT>::LinkedList(DT value, LinkedList<DT> next)
{
    value = value;
    nextLL = next;
}

template<class DT>
LinkedList<DT>::LinkedList(LinkedList const &LL)
{
    readLinkedList(LL);
}

template<class DT>
LinkedList<DT> LinkedList<DT>::create()
{
    return LinkedList<DT>();
}

template<class DT>
bool LinkedList<DT>::isEmpty()
{
    if (value == NULL && nextLL == NULL)
        return true;
    else
        return false;
}

template<class DT>
int LinkedList<DT>::size()
{
    int size = 0;
    LinkedList<DT> temp = nextLL;
    if (isEmpty())
    {
        return size;
    }
    else
    {
        size++;
        while (temp != NULL)
        {
            temp = temp->next();
            size++;
        }
    }
    return size;
}

template<class DT>
void LinkedList<DT>::add(const DT& object)
{
    if (value == NULL)
    {
        value = object;
    }
    else
    {
        LinkedList<DT>* newList = new LinkedList<DT>(*value, next);
        *value = object;
        nextLL = newList;
    }
}

template<class DT>
void LinkedList<DT>::insertAt(const DT& object, int position)
{
    if (position == 0)
    {
        add(object);
    }
    else
    {
        if (nextLL == NULL)
        {
            nextLL = new LinkedList(object);
        }
        else
        {
            nextLL->insertAt(object, position - 1);
        }
    }
}

template<class DT>
DT& LinkedList<DT>::info()
{
    return *value;
}

template<class DT>
DT& LinkedList<DT>::info(int node)
{
    if (node == 0)
    {
        return *info();
    }
    else
    {
        if (nextLL == NULL)
        {
            cout << "node does not exist" << endl;
        }
        else
        {
            nextLL->info(node - 1);
        }
    }
}

template<class DT>
LinkedList<DT> LinkedList<DT>::next()
{
    return nextLL;
}

template<class DT>
void LinkedList<DT>::setNext(LinkedList<DT> next)
{
    nextLL = next;
}

template<class DT>
DT LinkedList<DT>::remove()
{
    DT temp = *value;
    delete value;
    if (nextLL == NULL)
    {
        value = NULL;
    }
    else
    {
        LinkedList<DT>* oldnext = nextLL;
        value = nextLL->value;
        nextLL = nextLL->nextLL;
        oldnext->value = NULL;
        oldnext->nextLL = NULL;
        delete oldnext;
    }
    return temp;
}

template<class DT>
DT LinkedList<DT>::remove(int node)
{
    if (isEmpty())
    {
        cout << "linked list bounds error" << endl;
    }
    if (node == 0)
    {
        return remove();
    }
    return nextLL->removeAt(node - 1);
}

template<class DT>
DT& LinkedList<DT>::find(const DT& object)
{
    if (object == value)
    {
        return value;
    }
    if (nextLL == NULL)
    {
        return NULL;
    }
    else
    {
        return nextLL->find(object);
    }
}

template<class DT>
LinkedList<DT>::~LinkedList<DT>()
{
    delete value;
}

template<class DT>
void LinkedList<DT>::readLinkedList(LinkedList<DT> const &LL)
{
    value = LL->info();
    nextLL = LL->next();
    if (LL->next() == NULL)
    {
        return;
    }
    else
    {
        nextLL->readLinkedList(LL->next());
    }
}
