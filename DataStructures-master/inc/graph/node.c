#include "node.h"   

struct Node* NodeConstructor()
{
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        free(node);
        return NULL;
    }

    node->data = 0;
    node->adjList = NULL;

    return node;
}

void NodeDestructor(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    free(node->adjList);
    free(node);
}