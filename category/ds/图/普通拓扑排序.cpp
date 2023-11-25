/*
  eg.
  8 10
  0 1 2 3 4 5 6 7
  0 2
  1 2
  2 3
  2 4
  2 5
  3 4
  5 4
  4 6
  4 7
  6 7
*/
#include"graph.h"

int stack[N],degree[N],n,top;

void getDegree(Graph g){
  for(int i=0;i<g.vexNum;i++){
    for(ArcNode *p=g.list[i].first;p!=nullptr;p=p->next){
      degree[p->v]++;
    }
  }
}

int getTopologicSort(Graph g){
  int cnt=0;
  getDegree(g);
  for(int i=0;i<g.vexNum;i++){
    if(degree[i]==0){
      stack[top++]=i;
    }
  }
  while(top!=0){
    int x=stack[--top];
    printf("%d ",x);
    for(ArcNode *p=g.list[x].first;p!=nullptr;p=p->next){
      degree[p->v]--;
      if(degree[p->v]==0){
        stack[top++]=p->v;
      }
    }
    cnt++;
  }
  printf("\n");
  if(cnt==g.vexNum){
    return 1;
  }
  return 0;
}

int main(){
  Graph g=CreatDGraph();
  printf("%d\n",getTopologicSort(g));
  return 0;
}