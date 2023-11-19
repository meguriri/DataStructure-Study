/*
  邻接矩阵存储的有向图G吗，编写算法判断G中是否存在一条
  简单有向回路，若存在输出回路的顶点序列
  8 10
  0 1 2 3 4 5 6 7
  0 1
  1 4
  1 2
  2 3
  2 0
  4 5
  5 6
  6 7
  6 2
  7 3
*/
#include"proto.h"

int vis[N],ans[N],n;
void dfs(int g[][8],int v,int s,int n){
  if(vis[v]==1){
    int st=0;
    for(int i=0;i<s;i++){
      if(ans[i]==v){
        st=i;
        break;
      }
    }
    for(int i=st;i<s;i++){
      printf("%d ",ans[i]);
    }
    printf("\n");
    vis[v]=2;
    return;
  }
  ans[s]=v;
  vis[v]=1;
  for(int i=0;i<n;i++){
    if(g[v][i]==1){
      dfs(g,i,s+1,n);
    }
  }
  vis[v]=2;
}

void findLoop(int g[][8],int n){
  for(int i=0;i<n;i++){
    if(vis[i]==0){
      dfs(g,i,0,n); 
    }
  }
}

int main(){
  int g[8][8]={
    {0,1,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,0},
    {1,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,0,0,0,0},
  };
  findLoop(g,8);
  return 0;
}