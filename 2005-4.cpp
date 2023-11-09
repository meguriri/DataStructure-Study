/*
  邻接表存储的有向图，判断是否存在vi到vj的路径
  6 6
  1 2 3 4 5 6
  1 2
  2 5
  5 6
  6 2
  3 1
  3 4
*/

#include<cstdio>
#include<cstdlib>
#define N 10
typedef int vertexType;


typedef struct ArcNode{
  vertexType val;
  struct ArcNode *next;
}ArcNode;

typedef struct VNode{
  vertexType data;
  ArcNode *first;
}VNode,AdjList[N];

typedef struct ALGraph{
    AdjList List;
    int vexNum;
    int arcNum;
};

void creatGraph(ALGraph &g){
  scanf("%d%d", &g.vexNum,&g.arcNum);
  //初始化点
  for(int i=0;i<g.vexNum;i++){
    scanf("%d",&g.List[i].data);
    g.List[i].first=nullptr;
  }
  //输入边，建立邻接表
  for(int i=0;i<g.arcNum;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    ArcNode *p=new(ArcNode);
    p->val=v;
    int temp=0;
    for(int i=0;i<g.vexNum;i++){
      if(g.List[i].data==u){
        temp=i;
        break;
      }
    }
    p->next=g.List[temp].first;
    g.List[temp].first=p;
  }
}

void printGraph(ALGraph g){
  for(int i=0;i<g.vexNum;i++){
    printf("%d: ",g.List[i].data);
    ArcNode *p=g.List[i].first;
    while(p!=nullptr){
      printf("%d ",p->val);
      p=p->next;
    }
    printf("\n");
  }
}

int visit[N];

bool dfs(ALGraph g,vertexType u,vertexType v){
  visit[u]=1;
  if(u==v){
    return true;
  }
  int temp=0;
  for(int i=0;i<g.vexNum;i++){
    if(g.List[i].data==u){
      temp=i;
      break;
    }
  }
  for(ArcNode *p=g.List[temp].first;p!=nullptr;p=p->next){
    bool ret=false;
    vertexType w=p->val;
    if(visit[w]==0){
      ret=dfs(g,w,v);
    }
    if(ret){
      return ret;
    }
  }
  return false;
}

bool isExistedPath(ALGraph g,vertexType u,vertexType v){
  return dfs(g,u,v);
}

int main(){
  ALGraph g;
  creatGraph(g);
  printf("%d",isExistedPath(g,2,1));
  return 0;
}