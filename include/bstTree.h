#ifndef BSTTREE_H
#define BSTTREE_H
#include"proto.h"

typedef struct node{
  int d;
  node *l,*r;
}bstNode,*bstTree;

bstTree creatBstTree(int n);
void insertBstNode(bstTree&,int);
void inOrderTraversal(bstTree);

#endif