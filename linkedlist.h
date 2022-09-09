#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

struct LinkedList
{
    struct Node* head;
    struct Node* tail;
    int length;
    int isDoublyLinked;
};

#endif