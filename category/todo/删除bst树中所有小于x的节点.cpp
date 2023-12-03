/*
  eg1.
  10 8 14 13 25 
  2 6 11 15 30 16 17 5
*/
#include"bstTree.h"

void FreeNode(bstTree t){
  if(t==nullptr){
    return;
  }
  FreeNode(t->l);
  FreeNode(t->r);
  t->l=nullptr;
  t->r=nullptr;
  delete(t);
}

void deleteXNode(bstTree &t,int x){
  if(t==nullptr){
    return;
  }
  if(t->d==x){
    FreeNode(t->l);
    t->l=nullptr;
  }else if(t->d>x){
    deleteXNode(t->l,x);
  }else{
    FreeNode(t->l);
    t->l=nullptr;
    bstNode *pre=t;
    t=t->r;
    delete(pre);
    deleteXNode(t,x);
  }
}

int main(){
  bstTree t=creatBstTree(13);
  inOrderTraversal(t);
  printf("\n");
  deleteXNode(t,12);
  inOrderTraversal(t);
  printf("\n");
  return 0;
}