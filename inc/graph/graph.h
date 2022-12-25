#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#ifndef GRAPH_H
#define GRAPH_H

struct GNode
{
    int data;
};

struct Graph
{
    int V;
    struct GNode** nodeList; 
    unsigned int** adjMatrix;
    int** adjList; //Stores the neighbours for the node at the nodelist index
};

struct GNode* GNodeConstructor(int data);
void GNodeDestructor(struct GNode* node);

struct Graph* GraphConstructor(unsigned int V);
void GraphDestructor(struct Graph* graph);


void GenerateAdjMatrix(struct Graph* graph);
void DestroyAdjMatrix(struct Graph* graph);

void GenerateAdjList(struct Graph* graph); //todo

bool hasEdge(struct Graph* graph, int src, int dest);
void makeEdge(struct Graph* graph, int src, int dest);
void deleteEdge(struct Graph* graph, int src, int dest);

void changeWeight(struct Graph* graph, int src, int dest, float weight);
float getWeight(struct Graph* graph, int src, int dest);

void printAdjMatrix(struct Graph* graph);
void printGraph(struct Graph* graph);

#endif