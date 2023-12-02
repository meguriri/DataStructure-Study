/*
  eg1.
  10 8 14 13 25 
  2 6 11 15 30
*/
#include"proto.h"

typedef struct bstNode{
  int d;
  bstNode *l,*r;
}bstNode,*bstTree;

void insertBstTree(bstTree &t,int x){
  if(t==nullptr){
    t=new(bstNode);
    t->d=x;
    t->l=nullptr;
    t->r=nullptr;
    return;
  }
  if(x<t->d){
    insertBstTree(t->l,x);
  }else if(x>t->d){
    insertBstTree(t->r,x);
  }
}

bstTree creatBstTree(int n){
  bstTree t=nullptr;
  for(int i=0;i<n;i++){
    int num;
    scanf("%d",&num);
    insertBstTree(t,num);
  }
  return t;
}

void inOrderTraversal(bstTree t){
  if(t==nullptr){
    return;
  }
  inOrderTraversal(t->l);
  printf("%d ",t->d);
  inOrderTraversal(t->r);
}

int main(){
  bstTree t=creatBstTree(10);
  inOrderTraversal(t);
  printf("\n");
  return 0;
}