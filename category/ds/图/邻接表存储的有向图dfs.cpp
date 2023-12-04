/*
  8 10
  0 1 2 3 4 5 6 7
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
  6 7
*/
#include"graph.h"

int vis[N]={0};

void dfs(Graph g,int u){
  printf("%d ",u);
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      vis[p->v]=1;
      dfs(g,p->v);
    }
  }
}

void DfsTraversal(Graph g){
  for(int i=0;i<g.vexNum;i++){
    int u=g.list[i].u;
    if(vis[u]==0){
      vis[u]=1;
      dfs(g,u);
    }
  }
}

int main(){
  Graph g=CreatDGraph();
  DfsTraversal(g);
  printf("\n");
  return 0;
}