/*
编写算法判断一个以邻接表存储结构的无向图G是否连通，若连通，返回1，否则返回0
eg1.
  4 3
  0 1 2 3 
  0 1
  0 2
  1 2
eg2.
  5 5
  0 1 2 3 4
  0 1
  0 2
  1 3
  1 4
  3 4
*/
#include"graph.h"

int vis[N]={0};

void dfs(Graph g,int u){
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      vis[p->v]=1;
      dfs(g,p->v);
    }
  }
} 

int isConnect(Graph g){
  int u=g.list[0].u;
  vis[0]=1;
  dfs(g,u);
  for(int i=0;i<g.vexNum;i++){
    if(vis[i]==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  Graph g=CreatUDGraph();
  printf("%d\n",isConnect(g));
  return 0;
}
