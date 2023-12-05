/*
  eg1.
  8 11
  0 1 2 3 4 5 6 7 
  0 1
  0 2
  1 2
  1 3
  2 3
  3 4
  3 5
  4 5
  7 2
  2 6
  6 4

  eg2.
  8 11
  0 1 2 3 4 5 6 7 
  7 6
  7 5
  6 4
  4 2
  5 4
  4 3
  3 2
  5 1
  1 3
  0 5
  6 5
*/
#include"graph.h"

int vis[N];
int ans[N],n=0;
void dfs(Graph g,int u){
  vis[u]=1;
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      dfs(g,p->v);
    }
  }
  ans[n++]=u;
}

void getTopoLogicSort(Graph g){
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
  getTopoLogicSort(g);
  return 0;
}