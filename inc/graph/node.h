#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    int* adjList;
};

struct Node* NodeConstructor();
void NodeDestructor(struct Node* node);

#endif