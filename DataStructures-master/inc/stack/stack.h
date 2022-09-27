#include "../node/node.h"

#ifndef STACK_H
#define STACK_H

struct Stack
{
    struct Node* top;
    int size;
    int max_size;
};

struct Stack* StackConstructor();
void StackDestructor(struct Stack* stack);
void push(struct Stack* stack, int data);
void pop(struct Stack* stack);
int peek(struct Stack* stack);
void setStackLimit(struct Stack* stack, int size);
void removeStackLimit(struct Stack* stack);

#endif