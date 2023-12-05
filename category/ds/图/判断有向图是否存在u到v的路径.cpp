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

int vis[N]={0};

int isUToVPath(Graph g,int u,int v){
  vis[u]=1;
  if(u==v){
    return 1;
  }
  int f=0;
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      f=isUToVPath(g,p->v,v);
      if(f==1){
        return 1;
      }
    }
  }
  return 0;
}

int main(){
  Graph g=CreatDGraph();
  printf("%d\n",isUToVPath(g,1,9));
  memset(vis,0,sizeof(vis));
  printf("%d\n",isUToVPath(g,8,9));
  memset(vis,0,sizeof(vis));
  printf("%d\n",isUToVPath(g,3,2));
  return 0;
}