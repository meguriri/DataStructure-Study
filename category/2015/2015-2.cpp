/*
  求二叉树的最大密度(各层节点数值的最大值)
  1 2 4 8 -1 -1 -1 5 -1 -1 3 6 -1 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bitTree creatBitTree(){
  bitNode *t=new(node);
  int x;
  scanf("%d",&x);
  if(x==-1){
    return nullptr;
  }
  t->d=x;
  t->l=creatBitTree();
  t->r=creatBitTree();
  return t;
}

int a[10]={0},n=0;

void getFloor(bitNode *t,int s){
  if(t==nullptr){
    return;
  }
  if(n<s){
    n=s;
  }
  a[s]++;
  getFloor(t->l,s+1);
  getFloor(t->r,s+1);
}

int count(bitTree t){
  getFloor(t,1);
  int mmax=-1;
  for(int i=1;i<=n;i++){
    if(a[i]>mmax){
      mmax=a[i];
    }
  }
  return mmax;
}

int main(){
  bitTree t=creatBitTree();
  printf("%d",count(t));
  return 0;
}