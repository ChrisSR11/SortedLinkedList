
#include "SortedList.h"
#include <iostream>
using namespace std;

template<class T>
SortedList<T>::SortedList() {
    head = nullptr;
    length = 0;
}

template<class T>
void SortedList<T>::MakeEmpty() {
    while(head != nullptr)
    {
        NodeT* tmp = head;
        head = head->next;
        delete tmp;
        length--;
    }
}

template<class T>
bool SortedList<T>::IsFull() const {
    return false;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    if(head == nullptr)
        return false;

    NodeT* nodePtr = head;

    while(nodePtr != nullptr)
    {
        if(nodePtr->info == someItem)
            return true;

        nodePtr = nodePtr->next;
    }

    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    NodeT* newNode = new NodeT;
    newNode->info = item;
    length++;
    if(head == nullptr)//empty
        head = newNode;
    else if(item < head->info)//begin
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    else
    {
        NodeT* pre = head;
        NodeT* nodePtr = head->next;

        while(nodePtr != nullptr)
        {
            if(item < nodePtr->info)//middle
            {
                pre->next = newNode;
                newNode->next = nodePtr;
                length++;
                return;
            }
            pre = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr == nullptr)// end
             pre->next = newNode;
    }
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    if(head == nullptr)
        return;

    if(head->info == item)
    {
        NodeT* tmp = head;
        head = head->next;
        delete tmp;
        length--;
    }
    else
    {
        NodeT* pre = head;
        NodeT* nodePtr = head->next;

        while(nodePtr != nullptr)
        {
            if(nodePtr->info == item)
            {
                pre->next = nodePtr->next;
                length--;
                return;
            }
            pre = nodePtr;
            nodePtr = nodePtr->next;
        }
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    iter = head;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (iter != nullptr) {
        throw "Out of bounds";
    }

    int v = iter->info;
    iter = iter->next;

    return v;
}

template<class T>
void SortedList<T>::print()
{
    if(head == nullptr)
        return;

    NodeT* nodePtr = head;
    while(nodePtr != nullptr)
    {
        cout << nodePtr->info << ' ';
        nodePtr = nodePtr->next;
    }
    cout << endl;
}