#include<cstdio>

int judge(int (*a)[4],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]!=0&&j<i){
        return 0;
      }
    } 
  }
  return 1;
}

int main(){
  int a1[4][4]={
    {1,2,3,4},
    {0,0,6,7},
    {0,0,1,2},
    {0,0,0,4},
  };
  int a2[4][4]={
    {1,2,3,4},
    {0,0,6,7},
    {0,3,4,2},
    {0,0,0,1},
  };
  printf("%d\n",judge(a1,4));
  printf("%d\n",judge(a2,4));
  return 0;
}