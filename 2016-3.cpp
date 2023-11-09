/*
  求邻接表存储结构的无向图的连通分量的个数，并输出每个连通分量的顶点集
  11 9
  0 1 2 3 4 5 6 7 8 9 10
  0 1
  0 2
  1 2
  1 3
  2 3
  4 5
  7 8 
  8 9
  7 9
*/

#include<cstdio>
#include<cstdlib>
#define N 15

typedef struct ArcNode{
  int v;
  ArcNode *next;
}ArcNode;

typedef struct Archead{
  int u;
  ArcNode *first;
}ArcHead,ArcList[N];

typedef struct Graph{
  int vexNum;
  int arcNum;
  ArcList list;
}Graph;

int vis[N]={0};

Graph creatGraph(){
  Graph g;
  int u,v;
  scanf("%d%d",&g.vexNum,&g.arcNum);
  for(int i=0;i<g.vexNum;i++){
    scanf("%d",&g.list[i].u);
    g.list[i].first=nullptr;
  }
  for(int i=0;i<g.arcNum;i++){
    scanf("%d%d",&u,&v);
    ArcNode *p=new(ArcNode);
    p->v=v;
    p->next=g.list[u].first;
    g.list[u].first=p;
    ArcNode *q=new(ArcNode);
    q->v=u;
    q->next=g.list[v].first;
    g.list[v].first=q;
  }
  return g;
}

void dfs(Graph g,int u){
  printf("%d ",g.list[u].u);
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    
    if(vis[p->v]==0){
      vis[p->v]=1;
      dfs(g,p->v);
    }
  }
}

int getConnect(Graph g){
  int cnt=0;
  for(int i=0;i<g.vexNum;i++){
    if(vis[i]==0){
      cnt++;
      vis[i]=1;
      dfs(g,i);
      printf("\n");
    }
  }
  return cnt;
}

int main(){
  Graph g=creatGraph();
  printf("%d\n",getConnect(g));
  return 0;
}