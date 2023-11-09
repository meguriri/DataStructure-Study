/*
  判断邻接表存储的无向图，给定两个点之间是否存在一条长度为k的路径
*/



#include<cstdio>
#include<cstdlib>
#define N 15

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

int f=0,vis[N];

void dfs(Graph g,int u,int v,int k,int s){
  if(f==1){
    return;
  }
  if(u==v&&s==k){
    f=1;
    return;
  }
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(f==1){
      return;
    }
    if(vis[p->v]==0){
      vis[p->v]=1;
      dfs(g,p->v,v,k,s+1);
      vis[p->v]=0;
    }
  }
}

int main(){

  return 0;
}