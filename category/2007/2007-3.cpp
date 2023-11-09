/*
  有向图有n个点，e条边，给出邻接表节点结构，编写算法建立G邻接表，并根据G的邻接表生成G的逆邻接表
  7 7
  1 2 3 4 5 6 7
  1 2
  2 4
  4 5
  5 7
  1 3
  6 3
  6 5
*/

#include<cstdio>
#include<cstdlib>
#define N 10

typedef struct ArcNode{
  int d;
  ArcNode *next;
}ArcNode;

typedef struct ArcHead{
  int d;
  ArcNode *first;
}ArcHead,ArcList[N];

typedef struct Graph{
  int vexNum;
  int arcNum;
  ArcList list;
}Graph;

Graph CreatGraph(){
  Graph g;
  int u,v;
  scanf("%d%d",&g.vexNum,&g.arcNum);
  for(int i=0;i<g.vexNum;i++){
    scanf("%d",&g.list[i].d);
    g.list[i].first=nullptr;
  }
  for(int i=0;i<g.arcNum;i++){
    scanf("%d%d",&u,&v);
    for(int j=0;j<g.vexNum;j++){
      if(g.list[j].d==u){
        ArcNode *p=new(ArcNode);
        p->d=v;
        p->next=g.list[j].first;
        g.list[j].first=p;
        break;
      }
    }
  }
  return g;
}

void printGraph(Graph g){
  for(int i=0;i<g.vexNum;i++){
    printf("%d: ",g.list[i].d);
    ArcNode *p=g.list[i].first;
    while(p!=nullptr){
      printf("%d ",p->d);
      p=p->next;
    }
    printf("\n");
  }
}

Graph contraryGraph(Graph g){
  Graph cg;
  cg.vexNum=g.vexNum;
  cg.arcNum=g.arcNum;
  for(int i=0;i<cg.vexNum;i++){
    cg.list[i].d=g.list[i].d;
    cg.list[i].first=nullptr;
  }
  for(int i=0;i<g.vexNum;i++){
    ArcNode *p=g.list[i].first;
    while(p!=nullptr){
      for(int j=0;j<cg.vexNum;j++){
        if(cg.list[j].d==p->d){
          ArcNode *t=new(ArcNode);
          t->d=g.list[i].d;
          t->next=cg.list[j].first;
          cg.list[j].first=t;
          break;
        }
      }
      p=p->next;
    }
  }
  return cg;
}

int main(){
  Graph g=CreatGraph();
  Graph cg=contraryGraph(g);
  printGraph(g);
  printGraph(cg);
  return 0;
}