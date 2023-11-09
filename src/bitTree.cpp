#include"bitTree.h"

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

void preOrderTraversal(bitTree t){
  if(t==nullptr){
    return;
  }
  printf("%d ",t->d);
  preOrderTraversal(t->l);
  preOrderTraversal(t->r);
}