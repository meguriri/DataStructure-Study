/*
  二叉链表的二叉树中，查找值为x的节点，并求出该节点在树中的层数
  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bitTree CreatBitTree(){
  int d;
  scanf("%d",&d);
  if(d==-1){
    return nullptr;
  }
  bitNode*t =new(bitNode);
  t->d=d;
  t->l=CreatBitTree();
  t->r=CreatBitTree();
  return t;
}

bool findX(bitTree t,int x,int s){
  if(t==nullptr){
    return false;
  }
  if(t->d==x){
    printf("%d is on %d floor\n",x,s);
    return true;
  }
  return findX(t->l,x,s+1)||findX(t->r,x,s+1);
}

int main(){
  bitTree t=CreatBitTree();
  if(findX(t,8,1)){
    printf("find !!\n");
  }else{
    printf("not find !!\n");
  }
  return 0;
}