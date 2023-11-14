#include"bstTree.h"

void insertBstNode(bstTree &t,float x){
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

bstTree creatBstTree(float a[],float n){
  bstTree t=nullptr;
  for(int i=0;i<n;i++){
    insertBstNode(t,a[i]);
  }
  return t;
}

void inOrderTraversal(bstTree t){
  if(t==nullptr){
    return;
  }
  inOrderTraversal(t->l);
  printf("%.2lf ",t->d);
  inOrderTraversal(t->r);
}