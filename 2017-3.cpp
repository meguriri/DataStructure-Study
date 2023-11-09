/*
  根据有向图的邻接表构造相应的逆邻接表
  10 11
  9 8 7 6 5 4 3 2 1 0
  0 1
  0 2
  0 3
  1 4
  1 5
  4 5
  2 6
  2 7
  3 8
  3 9
  8 2
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
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

int getPos(Graph g,int u){
  for(int i=0;i<g.vexNum;i++){
    if(g.list[i].u==u){
      return i;
    }
  }
  return -1;
}

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
    //
    int k=getPos(g,u);
    //
    p->next=g.list[k].first;
    g.list[k].first=p;
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

Graph getReverse(Graph s){
  Graph g;
  g.vexNum=s.vexNum;
  g.arcNum=s.arcNum;
  for(int i=0;i<s.vexNum;i++){
    g.list[i].u=s.list[i].u;
    g.list[i].first=nullptr;
  }
  for(int i=0;i<s.vexNum;i++){
    int u=s.list[i].u;
    for(ArcNode *p=s.list[i].first;p!=nullptr;p=p->next){
      int v=p->v;
      ArcNode *t=new(ArcNode);
      t->v=u;
      //
      int k=getPos(g,v);
      //
      t->next=g.list[k].first;
      g.list[k].first=t;
    }
  }
  return g;
}

int main(){
  Graph g1=creatGraph();
  printGraph(g1);
  Graph g2=getReverse(g1);
  printGraph(g2);
  return 0;
}