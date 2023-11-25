/*
  eg.
  8 10
  0 1 2 3 4 5 6 7
  0 2
  1 2
  2 3
  2 4
  2 5
  3 4
  5 4
  4 6
  4 7
  6 7
*/
#include"graph.h"

int vis[N],ans[N],n;

void dfs(Graph g,int v){
  vis[v]=1;
  for(ArcNode *p=g.list[v].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      dfs(g,p->v);
    }
  }
  ans[n++]=v;
}

void getTopologicSort(Graph g){
  for(int i=0;i<g.vexNum;i++){
    if(vis[i]==0){
      dfs(g,i);
    }
  }
  for(int i=n-1;i>=0;i--){
    printf("%d ",ans[i]);
  }
  printf("\n");
}

int main(){
  Graph g=CreatDGraph();
  getTopologicSort(g);
  return 0;
}