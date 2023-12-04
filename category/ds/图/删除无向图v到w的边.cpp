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

void deleteOp(Graph &g,int u,int v){
  ArcNode *pre=nullptr,*p=g.list[u].first;
  while(p!=nullptr){
    if(p->v==v){
      if(p==g.list[u].first){
        g.list[u].first=p->next;
      }else{
        pre->next=p->next;
      }
      delete(p);
      break;
    }
    pre=p;
    p=p->next;
  }
}

void deleteVToW(Graph &g,int u,int v){
  deleteOp(g,u,v);
  deleteOp(g,v,u);
}

int main(){
  Graph g=CreatUDGraph();
  printGraph(g);
  deleteVToW(g,0,2);
  printGraph(g);
  return 0;
}