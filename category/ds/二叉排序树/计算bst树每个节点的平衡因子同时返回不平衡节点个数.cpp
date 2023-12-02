/*
  eg1.
  10 8 14 13 25 
  2 6 11 15 30 16 17 5
*/
#include"proto.h"

typedef struct bstNode{
  int d;
  int bf;
  bstNode *l,*r;
}bstNode,*bstTree;

void insertBstNode(bstTree &t,int x){
  if(t==nullptr){
    t=new(bstNode);
    t->d=x; 
    t->l=nullptr;
    t->r=nullptr;
  }else if(t->d>x){
    insertBstNode(t->l,x);
  }else if(t->d<x){
    insertBstNode(t->r,x);
  }
}

bstTree CreatBstTree(int n){
  bstTree t=nullptr;
  for(int i=0;i<n;i++){
    int num;
    scanf("%d",&num);
    insertBstNode(t,num);
  }
  return t;
}

void inOrderTraversal(bstTree t){
  if(t==nullptr){
    return;
  }
  inOrderTraversal(t->l);
  printf("%d: %d\n",t->d,t->bf);
  inOrderTraversal(t->r);
}

int getDepth(bstTree t){
  if(t==nullptr){
    return 0;
  }
  int l=getDepth(t->l);
  int r=getDepth(t->r);
  return (l>r?l:r)+1;
}

int getBalance(bstTree t){
  if(t==nullptr){
    return 0;
  }
  int l=getDepth(t->l);
  int r=getDepth(t->r);
  int cnt=0;
  t->bf=l-r;
  if(abs(l-r)>=2){
    cnt=1;
  }
  return cnt+getBalance(t->l)+getBalance(t->r);
}

int main(){
  bstTree t=CreatBstTree(13);
  printf("%d\n",getBalance(t));
  inOrderTraversal(t);
  return 0;
}