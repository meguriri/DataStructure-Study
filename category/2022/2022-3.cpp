/*
  查找不带权有向图G中从顶点v出发的最长路径
  8 11
  0 1 2 3 4 5 6 7
  0 1
  0 2
  0 3
  1 2
  2 3
  1 4
  4 2
  2 5
  3 5
  5 6
  6 7
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
  }
  return g;
}

int vis[N]={0},ans[N]={0},now[N]={0},n=0;

void dfs(Graph g,int u,int s){
  now[s]=u;
  if(g.list[u].first==nullptr){
    if(s>n){
      n=s;
      for(int i=0;i<=s;i++){
        ans[i]=now[i];
      }
    }
    return;
  }
  for(ArcNode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      vis[p->v]=1;
      dfs(g,p->v,s+1);
      vis[p->v]=0;
    }
  }
}

void GetMaxPath(Graph g,int u){
  vis[u]=1;
  dfs(g,u,0);
  for(int i=0;i<n;i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
}

int main(){
  Graph g=creatGraph();
  GetMaxPath(g,0);
  return 0;
}