/*
  eg.
  6 7
  0 1 2 3 4 5
  0 1
  0 2
  1 3
  2 4
  3 4
  2 5
  4 5 
*/
#include<cstdio>
#include<cstdlib>
#define N 100

typedef struct ArcNode{
  int v;
  ArcNode *next;
}ArcNode;

typedef struct ArcHead{
  int u;
  ArcNode *first;
}ArcHead,AList[N];

typedef struct Graph{
  int vexNum;
  int arcNum;
  AList list;
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
    ArcNode *p=new(ArcNode),*q=new(ArcNode);
    p->v=v;
    p->next=g.list[u].first;
    g.list[u].first=p;
    q->v=u;
    q->next=g.list[v].first;
    g.list[v].first=q;
  }
  return g;
}

void printGraph(Graph g){
  for(int i=0;i<g.vexNum;i++){
    printf("%d: ",g.list[i].u);
    for(ArcNode *p=g.list[i].first;p!=nullptr;p=p->next){
      printf("%d ",p->v);
    }
    printf("\n");
  }
}

int main(){
  Graph g=creatGraph();
  printGraph(g);
  return 0;
}
