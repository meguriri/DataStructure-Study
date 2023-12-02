#include"bstTree.h"

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

bstTree creatBstTree(int n){
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
  printf("%d ",t->d);
  inOrderTraversal(t->r);
}