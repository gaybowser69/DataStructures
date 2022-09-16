#include "node.h"

#ifndef QUEUE_H
#define QUEUE_H

struct Queue
{
    struct Node* front;
    struct Node* rear;
    int size;
};

struct Queue* QueueConstructor();
void QueueDestructor(struct Queue* queue);
void enQ(struct Queue* queue, int data);
void deQ(struct Queue* queue);

#endif