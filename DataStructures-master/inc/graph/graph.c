#include "graph.h"

void generateAdjMatrix(struct Graph* graph);

struct Graph* GraphConstructor(int V)
{
    struct Graph* graph = malloc(sizeof(struct Graph));

    if (graph == NULL)
    {
        return NULL;
    }

    graph->V = V;

    graph->nodeList = calloc(sizeof(struct Node), graph->V);

    if (graph->nodeList == NULL)
    {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < graph->V; i++)
    {
        graph->nodeList[i] = NodeConstructor(); 

        if (graph->nodeList[i] == NULL)
        {
            free(graph->nodeList);
            free(graph);
            return NULL;
        }
    }

    generateAdjMatrix(graph);

    return graph;
}

void generateAdjMatrix(struct Graph* graph)
{
    graph->adjMatrix = calloc(sizeof(int*), graph->V);

    for (int i = 0; i < graph->V; i++)
    {
        graph->adjMatrix[i] = calloc(sizeof(int), graph->V);
    }
}

void generateAdjList(struct Graph* graph, int index)
{
    if (graph->nodeList[index]->adjList != NULL)
    {
        //AdjList already exists. Realloc to add more nodes maybe?
    }

    int num_neighbours = 0;
    for (int i = 0; i < graph->V; i++)
    {
        if (graph->adjMatrix[index][i] == 1)
        {
            num_neighbours++;
        }
    }

    graph->nodeList[index]->adjList = calloc(sizeof(int), num_neighbours); //Use linked list instead?
}

void main()
{
    struct Graph* g = GraphConstructor(10);

    for (int i = 0; i < g->V; i++)
    {
        printf("%d ", g->nodeList[i]->data);
    }
    printf("\n\n");

    

    for (int i = 0; i < g->V; i++)
    {
        for (int j = 0; j < g->V; j++)
        {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}