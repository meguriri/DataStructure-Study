/*
  求邻接表存储的无向图G的连通分量（要求输出每一连通分量的顶点值）
  8 5
  1 2 3 4 5 6 7 8
  1 2
  1 3
  2 4
  5 6
  6 7
*/

#include<cstdio>
#include<cstdlib>
#define N 10

typedef struct ArcNode{
  int v;
  ArcNode *next;
}ArcNode;

typedef struct ArcHead{
  int u;
  int deg;
  ArcNode *first;
}ArcHead,ArcList[N];

typedef struct Graph{
  int vexNum;
  int arcNum;
  ArcList list;
}Graph;

int vis[10];

int getPos(Graph g,int u){
  for(int j=0;j<g.vexNum;j++){
    if(g.list[j].u==u){
      return j;
      break;
    }
  }
  return -1;
}

Graph creatGraph(){
  Graph g;
  scanf("%d%d",&g.vexNum,&g.arcNum);
  for(int i=0;i<g.vexNum;i++){
    scanf("%d",&g.list[i].u);
    g.list[i].first=nullptr;
  }
  for(int i=0;i<g.arcNum;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    int t=getPos(g,u);
    ArcNode *p=new(ArcNode);
    p->v=v;
    p->next=g.list[t].first;
    g.list[t].first=p;
  }
  return g;
}

void dfs(Graph g,int u){
  vis[u]=1;
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    int t=getPos(g,p->v);
    if(vis[t]==0){
      printf("%d ",p->v);
      dfs(g,t);
    }
  }
}

void com(Graph g){
  for(int i=0;i<g.vexNum;i++){
    if(vis[i]==0){
      printf("%d ",g.list[i].u);
      dfs(g,i);
      printf("\n");
    }
  }
}

int main(){
  Graph g=creatGraph();
  com(g);
  return 0;
}