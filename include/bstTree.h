#ifndef BSTTREE_H
#define BSTTREE_H
#include"proto.h"

typedef struct node{
  float d;
  node *l,*r;
}bstNode,*bstTree;

bstTree creatBstTree(float [],float);
void insertBstNode(bstTree&,float);
void inOrderTraversal(bstTree);

#endif