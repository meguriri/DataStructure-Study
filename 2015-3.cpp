/*
  求无向图中距离顶点V0的最短路径长度为k的所有节点
  12 17
  0 1 2 3 4 5 6 7 8 9 10 11
  0 1
  0 2
  0 3
  1 6
  1 4
  2 4
  2 5
  3 2
  3 7
  6 9
  6 8
  4 8
  5 8
  7 8
  8 10
  7 10
  7 11
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#define N 13
using namespace std;

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

typedef struct node{
  ArcHead h;
  int s;
}node;

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
    ArcNode *p1=new(ArcNode);
    p1->v=v;
    p1->next=g.list[u].first;
    g.list[u].first=p1;

    ArcNode *p2=new(ArcNode);
    p2->v=u;
    p2->next=g.list[v].first;
    g.list[v].first=p2;
  }
  return g;
}

int vis[13]={0};

void GetAllVex(Graph g,int u,int k){
  int ans[10],n=0,cnt=1;
  queue<node>q;
  q.push({g.list[u],0});
  vis[u]=1;
  while(!q.empty()){
    node nd=q.front();
    if(nd.s>k){
      break;
    }
    if(nd.s==k){
      ans[n++]=nd.h.u;
    }
    q.pop();
    for(ArcNode *p=nd.h.first;p!=nullptr;p=p->next){
      if(vis[p->v]==0){
        vis[p->v]=1;
        q.push({g.list[p->v],nd.s+1});
      }
    }
  }
  for(int i=0;i<n;i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
}

int main(){
  Graph g=creatGraph();
  GetAllVex(g,1,2);
  return 0;
}