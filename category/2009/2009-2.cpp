/*
  二叉树左右孩子互换位置
  1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
*/

#include"bitTree.h"
// #include<cstdio>
// #include<cstdlib>

// typedef struct node{
//   int d;
//   node *l,*r;
// }bitNode,*bitTree;

// bitTree creatBitTree(){
//   bitNode *t=new(node);
//   int x;
//   scanf("%d",&x);
//   if(x==-1){
//     return nullptr;
//   }
//   t->d=x;
//   t->l=creatBitTree();
//   t->r=creatBitTree();
//   return t;
// }

// void preOrderTraversal(bitTree t){
//   if(t==nullptr){
//     return;
//   }
//   printf("%d ",t->d);
//   preOrderTraversal(t->l);
//   preOrderTraversal(t->r);
// }

void swapChildren(bitTree &t){
  if(t==nullptr){
    return;
  }
  node *p=t->l;
  t->l=t->r;
  t->r=p;
  swapChildren(t->l);
  swapChildren(t->r);
}

int main(){
  bitTree t=creatBitTree();
  preOrderTraversal(t);
  swapChildren(t);
  printf("\n");
  preOrderTraversal(t);
  return 0;
}