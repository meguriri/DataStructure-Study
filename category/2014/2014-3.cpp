/*
  邻接表存储的无向图，输出从u到v的简单路径
  7 10
  0 1 2 3 4 5 6
  0 1
  0 3
  1 2
  3 2
  3 4
  2 4
  4 5
  5 2
  2 6
  5 6
*/

#include<cstdio>
#include<cstdlib>
#define N 10

typedef struct ANode{
  int v;
  ANode *next;
}ANode;

typedef struct AHead{
  int u;
  ANode *first;
}Ahead,AList[N];

typedef struct Graph{
  int vexNum;
  int arcNum;
  AList list;
}Graph;

int vis[10];
int ans[10];
int cnt;
int f;

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
    ANode *p=new(ANode);
    p->v=v;
    p->next=g.list[u].first;
    g.list[u].first=p;
  }
  return g;
}

void getPath(Graph g,int u,int v,int len,int s){
  ans[s]=u;
  if(u==v){
    if(s==len){
      f=1;
      for(int i=0;i<=s;i++){
        printf("%d ",ans[i]);
      }
      printf("\n");
    }
    return;
  }
  for(ANode *p=g.list[u].first;p!=nullptr;p=p->next){
    if(vis[p->v]==0){
      vis[p->v]=1;
      getPath(g,p->v,v,len,s+1);
      vis[p->v]=0;
    }
  }
}

int main(){
  Graph g=creatGraph();
  getPath(g,0,6,5,0);
  return 0;
}