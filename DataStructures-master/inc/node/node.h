#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    struct Node* previous;
    struct Node* next;
};

struct Node* NodeConstructor(int data);
void NodeDestructor(struct Node* node);

#endif
