/*
将bst树分割成两棵bst树t1,t2,让t1的节点都小于x,t2的节点都大于x
  eg1.
  10 8 14 13 25 
  2 6 11 15 30 16 17 5
*/
#include"bstTree.h"


void insert(bstTree &t,bstNode *p){
  if(t==nullptr){
    t=p;
  }else if(p->d<t->d){
    insert(t->l,p);
  }else if(p->d>t->d){
    insert(t->r,p);
  }
}

void creatTwoBstTree(bstTree &t,int x,bstTree &t1,bstTree &t2){
  if(t==nullptr){
    return;
  }
  if(t->d<x){ 
    creatTwoBstTree(t->r,x,t1,t2);
    t->r=nullptr;
    insert(t1,t);
  }else if(t->d==x){
    insert(t1,t->l);
    insert(t2,t->r);
    delete(t);
    t=nullptr;
  }else if(t->d>x){
    creatTwoBstTree(t->l,x,t1,t2);
    t->l=nullptr;
    insert(t2,t);
  }
}

int main(){
  bstTree t1=nullptr,t2=nullptr;
  bstTree t=creatBstTree(13);
  creatTwoBstTree(t,14,t1,t2);
  inOrderTraversal(t1);
  printf("\n");
  inOrderTraversal(t2);
  printf("\n");
  return 0;
}