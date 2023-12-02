/*

*/
#include"bstTree.h"

typedef struct avlNode{
  int d;
  avlNode *l,*r;
  int degree;
}avlNode,*avlTree;

int getAvlTree(avlTree t){
  if(t==nullptr){
    return 0;
  }
  if(t->degree>0){
    return getAvlTree(t->l)+1;
  }
  return getAvlTree(t->r)+1;
}

int main(){
  
  return 0;
}