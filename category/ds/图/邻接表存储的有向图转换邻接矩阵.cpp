/*
  6 10
  0 1 2 3 4 5
  0 1
  0 2
  1 3
  2 4
  3 4
  2 5
  4 5 
  1 5
  4 1
  5 0
*/
#include"graph.h"
#define INF 0x3f3f3f3f
typedef struct MGraph{
  int vexList[N];
  int vexNum,arcNum;
  int Martix[N][N];
}MGraph;

MGraph creatMGraph(Graph g){
  MGraph m;
  m.vexNum=g.vexNum;
  m.arcNum=g.arcNum;
  for(int i=0;i<g.vexNum;i++){
    for(int j=0;j<g.vexNum;j++){
      m.Martix[i][j]=INF;
    }
  }
  for(int i=0;i<g.vexNum;i++){
    int u=g.list[i].u;
    m.vexList[i]=u;
    for(ArcNode *p=g.list[i].first;p!=nullptr;p=p->next){
      m.Martix[u][p->v]=p->w;
    }
  }
  return m;
}

int main(){
  Graph g=CreatDGraph();
  MGraph m=creatMGraph(g);
  for(int i=0;i<m.vexNum;i++){
    for(int j=0;j<m.vexNum;j++){
      printf("%d ",m.Martix[i][j]);
    }
    printf("\n");
  }
  return 0;
}