#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct Node
{
    int data;
};

struct Edge
{
    bool** adjMatrix; //Stores all neighbours
    int** adjList; //Stores the neighbours for the node at the nodelist index
};

struct Graph
{
    int V;
    struct Node** nodeList; 
    struct Edge* edge;
};

struct Node* NodeConstructor(int data);
void NodeDestructor(struct Node* node);

struct Graph* GraphConstructor(unsigned int V);
void GraphDestructor(struct Graph* graph);


void GenerateAdjMatrix(struct Graph* graph);
void DestroyAdjMatrix(struct Graph* graph);

void GenerateAdjList(struct Graph* graph); //todo

bool hasEdge(struct Graph* graph, int src, int dest);
void makeEdge(struct Graph* graph, int src, int dest);
void deleteEdge(struct Graph* graph, int src, int dest);

void printAdjMatrix(struct Graph* graph);
void printGraph(struct Graph* graph);
