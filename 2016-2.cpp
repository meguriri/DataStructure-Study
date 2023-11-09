/*
  已知二叉树采用二叉链表存储结构，设计算法求二叉树中指定节点所在的层数
  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

int f=0;

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

void getFloor(bitTree t,int x,int s){
  if(t==nullptr||f!=0){
    return;
  }
  if(t->d==x){
    f=s;
    return;
  }
  if(f==0)
    getFloor(t->l,x,s+1);
  if(f==0)
    getFloor(t->r,x,s+1);
}

int main(){
  bitTree t=creatBitTree();
  getFloor(t,2,1);
  printf("%d",f);
  return 0;
}