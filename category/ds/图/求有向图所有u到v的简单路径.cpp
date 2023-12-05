/*
  eg.
  10 15
  0 1 2 3 4 5 6 7 8 9
  0 1
  0 2
  1 2
  1 3
  1 4
  3 4
  2 8
  5 7
  7 9
  3 5
  4 6
  6 9
  4 7
  8 4
  8 9
*/
#include"graph.h"

int vis[N]={0},ans[N]={0};

void findAllPath(Graph g,int u,int v,int s){
  vis[u]=1;
  ans[s]=u;
  if(u==v){
    for(int i=0;i<=s;i++){
      printf("%d ",ans[i]);
    }
    printf("\n");
    return;
  }
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      findAllPath(g,p->v,v,s+1);
      vis[p->v]=0;
    }
  }
}

int main(){
  Graph g=CreatDGraph();
  findAllPath(g,0,9,0);
  return 0;
}