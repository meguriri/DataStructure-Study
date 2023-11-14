/*
  有向无环图G，邻接表存储。求G中顶点s到顶点d的最短路径
  9 13
  0 1 2 3 4 5 6 7 8
  0 1
  0 2 
  1 2
  1 3 
  2 5
  3 4
  3 7
  5 7
  5 6
  7 4
  4 8
  6 8
  5 8
*/
#include"graph.h"

int vis[N],now[N],ans[N],n=0x3f3f3f3f;

void dfs(Graph g,int u,int v,int s){
  now[s]=u;
  if(u==v){
    if(s<n){
      n=s;
      for(int i=0;i<=n;i++){
        ans[i]=now[i];
      }
      return;
    }
  }
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      vis[p->v]=1;
      dfs(g,p->v,v,s+1);
      vis[p->v]=0;
    }
  }
}

void getPath(Graph g,int u,int v){
  vis[u]=1;
  dfs(g,u,v,0);
  for(int i=0;i<=n;i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
}

int main(){
  Graph g=CreatDGraph();
  getPath(g,0,8);
  return 0;
}