/*
  已知二叉排序树中每一个结点值为整型，采用二叉链表编写算法，删除二叉排序树中所有节点值x
  小于1的节点
*/
#include"bstTree.h"

void del(bstTree &t){
  if(t==nullptr){
    return;
  }
  del(t->l);
  del(t->r);
  t->l=nullptr;
  t->r=nullptr;
  delete(t);
  t=nullptr;
}

void delOne(bstTree &t){
  if(t==nullptr){
    return;
  }
  if(t->d==1){
    del(t->l);
    t->l=nullptr;
  }else if(t->d<1){
    del(t->l);
    t->l=nullptr;
    bstNode *p=t;
    t=t->r;
    delOne(t);
    delete(p);
  }else{
    delOne(t->l);
  }
}

int main(){
  float a[10]={0.3,0.1,0.8,0.5,0.9,0.4,0.85,1,0.6,0.7};
  bstTree t=creatBstTree(a,10);
  inOrderTraversal(t);
  printf("\n");
  delOne(t);
  inOrderTraversal(t);
  printf("\n");
  return 0;
}