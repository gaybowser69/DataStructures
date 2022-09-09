#include "node.h"

struct Node* NodeConstructor(int data)
{
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        free(node);
        return NULL;
    }

    node->data = data;

    node->next = NULL;
    node->previous = NULL;

    return node;
}

void NodeDestructor(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    node->data = 0;
    node->next = NULL;
    node->previous = NULL;

    free(node);
    node = NULL;
}