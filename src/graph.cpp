#include"graph.h"

Graph CreatDGraph(){
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

Graph CreatUDGraph(){
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

void printGraph(Graph g){
  for(int i=0;i<g.vexNum;i++){
    printf("%d: ",g.list[i].u);
    ArcNode *p=g.list[i].first;
    while(p!=nullptr){
      printf("%d ",p->v);
      p=p->next;
    }
    printf("\n");
  }
}