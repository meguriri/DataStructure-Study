/*
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
#include"graph.h"

Graph CreatContrary(Graph g){
  Graph cg;
  cg.vexNum=g.vexNum;
  cg.arcNum=g.arcNum;
  for(int i=0;i<g.vexNum;i++){
    cg.list[i].u=g.list[i].u;
    cg.list[i].first=nullptr;
  }
  for(int i=0;i<g.vexNum;i++){
    for(ArcNode *p=g.list[i].first;p!=nullptr;p=p->next){
      ArcNode *t=new(ArcNode);
      t->v=g.list[i].u;
      t->next=cg.list[p->v].first;
      cg.list[p->v].first=t;
    }
  }
  return cg;
}

int main(){
  Graph g=CreatDGraph();
  Graph cg=CreatContrary(g);
  printGraph(cg);
  return 0;
}