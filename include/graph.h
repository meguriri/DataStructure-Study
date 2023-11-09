#ifndef GRAPH_H
#define GRAPH_H
#include"proto.h"

typedef struct ArcNode{
  int v;
  ArcNode *next;
}ArcNode;

typedef struct ArcHead{
  int u;
  ArcNode *first;
}ArcHead,ArcList[N];

typedef struct Graph{
  int vexNum;
  int arcNum;
  ArcList list;
}Graph;

Graph CreatUDGraph();
Graph CreatDGraph();
void printGraph(Graph);

#endif