/*
  eg1.
  6 6
  0 1 2 3 4 5
  0 1
  0 2
  1 3
  5 3
  4 5
  2 4

  eg2.
  5 6
  0 1 2 3 4
  0 1
  0 3
  3 1
  1 2
  2 4
  4 3
*/
#include"graph.h"

int vis[N];

int dfs(Graph g,int u){
  int f=0;
  vis[u]=1;
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      f=dfs(g,p->v);
      if(f==1){
        return 1;
      }
    }else if(vis[p->v]==1){
      return 1;
    }
  }
  vis[u]=2;
  return f;
}

int isExistRing(Graph g){
  int ans;
  for(int i=0;i<g.vexNum;i++){
    if(vis[i]==0){
      ans=dfs(g,i);
    }
    if(ans==1){
      return 1;
    }
  }
  return 0;
}

int main(){
  Graph g=CreatDGraph();
  printf("%d\n",isExistRing(g));
  return 0;
}