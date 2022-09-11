#include "stack.h"

struct Stack* StackConstructor()
{
    struct Stack* stack = malloc(sizeof(struct Stack));

    if (stack == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    stack->max_size = -1;

    return stack;
}

void StackDestructor(struct Stack* stack)
{
    if (stack == NULL)
    {
        return;
    }

    struct Node* temp = stack->top;

    while(temp->next != NULL)
    {   
        temp = stack->top;
        stack->top = temp->next;
        NodeDestructor(temp);
    }

    free(stack);
    stack = NULL;
}

void push(struct Stack* stack, int data)
{
    assert(stack != NULL);

    if (stack->max_size != -1 && stack->size >= stack->max_size)
    {
        perror("Stack is full.");
        return;
    }

    struct Node* node = NodeConstructor(data);

    node->next = stack->top;
    stack->top = node;

    stack->size++;
}

void pop(struct Stack* stack)
{
    assert(stack != NULL);

    if (stack->top == NULL)
    {
        return;
    }

    struct Node* temp = stack->top;
    stack->top = temp->next;

    NodeDestructor(temp);

    stack->size--;
}

int peek(struct Stack* stack)
{
    assert(stack != NULL && stack->top != NULL);
    return stack->top->data;
}

void setStackLimit(struct Stack* stack, int size)
{
    assert(size > 0);
    stack->max_size = size;

    while (stack->max_size < stack->size)
    {
        pop(stack);
    }
}

void removeStackLimit(struct Stack* stack)
{
    assert(stack != NULL);
    stack->max_size = -1;
}

/*void main()
{
    struct Stack* s = StackConstructor();
    
    for (int i = 0; i < 10; i++)
    {
        push(s, i);
    }
    for (int i = 0; i < 5; i++)
    {
        pop(s);
    }
    setStackLimit(s, 5);
    printf("%d\nSize: %d\nMax size: %d\n", peek(s), s->size, s->max_size);
    struct Node* temp = s->top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    StackDestructor(s);
}*/