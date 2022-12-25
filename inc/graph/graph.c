#include "graph.h"

struct GNode* GNodeConstructor(int data)
{
    struct GNode* node = malloc(sizeof(struct GNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;

    return node;
}

void GNodeDestructor(struct GNode* node)
{
    if (node == NULL)
    {
        return;
    }

    node->data = 0;
    free(node);
    node = NULL;
}

struct Graph* GraphConstructor(unsigned int V)
{
    struct Graph* graph = malloc(sizeof(struct Graph));

    if (graph == NULL)
    {
        return NULL;
    }

    graph->V = V;

    graph->nodeList = calloc(sizeof(struct GNode*), graph->V);

    if(graph->nodeList == NULL)
    {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < graph->V; i++)
    {
        graph->nodeList[i] = GNodeConstructor(0);

        if (graph->nodeList[i] == NULL)
        {
            free(graph->nodeList);
            free(graph);
            return NULL;
        }
    }

    GenerateAdjMatrix(graph);

    return graph;
}

void GraphDestructor(struct Graph* graph)
{
    assert(graph != NULL);
    
    for (int i = 0; i < graph->V; i++)
    {
        GNodeDestructor(graph->nodeList[i]);
    }

    free(graph->nodeList);
    graph->nodeList = NULL;

    DestroyAdjMatrix(graph);
    //DestroyAdjList(graph); //todo

    graph->V = 0;
    free(graph);
    graph == NULL;
}

void GenerateAdjMatrix(struct Graph* graph)
{
    assert(graph != NULL);

    graph->adjMatrix = calloc(sizeof(int*), graph->V);

    if(graph->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        graph->adjMatrix[i] = calloc(sizeof(int), graph->V);

        if (graph->adjMatrix[i] == NULL)
        {
            return;
        }
    }
}

void DestroyAdjMatrix(struct Graph* graph)
{
    assert(graph != NULL);

    if(graph->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        free(graph->adjMatrix[i]);
        graph->adjMatrix[i] = NULL;
    }

    free(graph->adjMatrix);
    graph->adjMatrix = NULL;
}

void GenerateAdjList(struct Graph* graph)
{
    assert(graph != NULL);
    //todo
}

bool hasEdge(struct Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0 && src < graph->V && dest >= 0 && dest < graph->V && src != dest);

    if (graph->adjMatrix[src][dest] != 0)
    {      
        return 1;
    }

    return 0;
}

void makeEdge(struct Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0 && src < graph->V && dest >= 0 && dest < graph->V && src != dest);

    if (hasEdge(graph, src, dest) == 0)
    {
        graph->adjMatrix[src][dest] = 1;   
    }
}

void deleteEdge(struct Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0 && src < graph->V && dest >= 0 && dest < graph->V && src != dest);

    if (hasEdge(graph, src, dest) != 0)
    {
        graph->adjMatrix[src][dest] = 0;   
    }
}

void printAdjMatrix(struct Graph* graph)
{
    assert(graph != NULL);

    if(graph->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }

        printf("\n");
    }
}

void printGraph(struct Graph* graph)
{
    assert(graph != NULL);
    
    if(graph->adjMatrix != NULL)
    {
        for (int i = 0; i < graph->V; i++)
        {
            for (int j = 0; j < graph->V; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (hasEdge(graph, i, j) == 1)
                {
                    printf("%d --> %d\n", i, j);
                }
            }
        }
    }
}
