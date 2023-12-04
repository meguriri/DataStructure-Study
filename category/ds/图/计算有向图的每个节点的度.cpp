/*
  eg.
  6 10
  0 1 2 3 4 5
  0 1
  0 2
  1 3
  2 4
  3 4
  2 5
  4 5 
  1 5
  4 1
  5 0
*/
#include"graph.h"

void getDegree(Graph g){
  int degree[N];
  memset(degree,0,sizeof(degree));
  for(int i=0;i<g.vexNum;i++){
    int u=g.list[i].u;
    for(ArcNode *p=g.list[i].first;p!=nullptr;p=p->next){
      degree[u]++;
      degree[p->v]++;
    }
  }
  for(int i=0;i<g.vexNum;i++){
    printf("%d: %d\n",g.list[i].u,degree[i]);
  }
}

int main(){
  Graph g=CreatDGraph();
  getDegree(g);
  return 0;
}