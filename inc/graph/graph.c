#include "graph.h"

struct Node* NodeConstructor(int data)
{
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;

    return node;
}

void NodeDestructor(struct Node* node)
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

    graph->nodeList = calloc(sizeof(struct Node*), graph->V);

    if(graph->nodeList == NULL)
    {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < graph->V; i++)
    {
        graph->nodeList[i] = NodeConstructor(0);

        if (graph->nodeList[i] == NULL)
        {
            free(graph->nodeList);
            free(graph);
            return NULL;
        }
    }

    graph->edge = malloc(sizeof(struct Edge));

    GenerateAdjMatrix(graph);

    return graph;
}

void GraphDestructor(struct Graph* graph)
{
    assert(graph != NULL);
    
    for (int i = 0; i < graph->V; i++)
    {
        NodeDestructor(graph->nodeList[i]);
    }

    free(graph->nodeList);
    graph->nodeList = NULL;

    DestroyAdjMatrix(graph);
    //DestroyAdjList(graph); //todo

    free(graph->edge);
    graph->edge = NULL;

    graph->V = 0;
    free(graph);
    graph == NULL;
}

void GenerateAdjMatrix(struct Graph* graph)
{
    assert(graph != NULL);

    graph->edge->adjMatrix = calloc(sizeof(int*), graph->V);

    if(graph->edge->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        graph->edge->adjMatrix[i] = calloc(sizeof(int), graph->V);

        if (graph->edge->adjMatrix[i] == NULL)
        {
            return;
        }
    }
}

void DestroyAdjMatrix(struct Graph* graph)
{
    assert(graph != NULL);

    if(graph->edge->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        free(graph->edge->adjMatrix[i]);
        graph->edge->adjMatrix[i] = NULL;
    }

    free(graph->edge->adjMatrix);
    graph->edge->adjMatrix = NULL;
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

    if (graph->edge->adjMatrix[src][dest] == true)
    {      
        return true;
    }

    return false;
}

void makeEdge(struct Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0 && src < graph->V && dest >= 0 && dest < graph->V && src != dest);

    if (hasEdge(graph, src, dest) == false)
    {
        graph->edge->adjMatrix[src][dest] = true;   
    }
}

void deleteEdge(struct Graph* graph, int src, int dest)
{
    assert(graph != NULL);
    assert(src >= 0 && src < graph->V && dest >= 0 && dest < graph->V && src != dest);

    if (hasEdge(graph, src, dest) == true)
    {
        graph->edge->adjMatrix[src][dest] = false;   
    }
}

void printAdjMatrix(struct Graph* graph)
{
    assert(graph != NULL);

    if(graph->edge->adjMatrix == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            printf("%d ", graph->edge->adjMatrix[i][j]);
        }

        printf("\n");
    }
}

void printGraph(struct Graph* graph)
{
    assert(graph != NULL);
    
    if(graph->edge->adjMatrix != NULL)
    {
        for (int i = 0; i < graph->V; i++)
        {
            for (int j = 0; j < graph->V; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (hasEdge(graph, i, j) == true)
                {
                    printf("%d --> %d\n", i, j);
                }
            }
        }
    }
}

int main()
{
    struct Graph* g = GraphConstructor(4);
    makeEdge(g, 1, 0);
    makeEdge(g, 3, 2);
   
    printGraph(g);

    GraphDestructor(g);    
}