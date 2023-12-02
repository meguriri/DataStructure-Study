/*
  eg1.
  10 8 14 13 25 
  2 6 11 15 30 12
*/
#include"bstTree.h"

int getSuccessor(bstTree t){
  bstNode *p=t;
  
}

void deleteOperation(bstTree &t){
  if(t->l==nullptr&&t->r==nullptr){
    t=nullptr;
  }else if(t->l!=nullptr&&t->r==nullptr){
    t=t->l;
  }else if(t->l==nullptr&&t->r!=nullptr){
    t=t->r;
  }else{
    bstNode *p=t->r,*pre;
    while(p->l!=nullptr){
      pre=p;
      p=p->l;
    }
    t->d=p->d;
    deleteOperation(pre->l);
  }
}

void deleteXNode(bstTree &t,int x){
  if(t==nullptr){
    return;
  }
  if(t->d==x){
    deleteOperation(t);
  }else if(x<t->d){
    deleteXNode(t->l,x);
  }else if(x>t->d){
    deleteXNode(t->r,x);
  }
}

int main(){
  bstTree t=creatBstTree(11);
  inOrderTraversal(t);
  printf("\n");
  deleteXNode(t,10);
  inOrderTraversal(t);
  printf("\n");
  return 0;
}