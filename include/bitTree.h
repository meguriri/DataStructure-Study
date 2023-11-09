#ifndef BITTREE_H
#define BITTREE_H
#include"proto.h"

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bitTree creatBitTree();
void preOrderTraversal(bitTree);

#endif