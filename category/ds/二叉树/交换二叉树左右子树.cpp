/*
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1
*/
#include"bitTree.h"

void exchageChild(bitTree t){
  if(t==nullptr){
    return;
  }
  bitNode *p=t->l;
  t->l=t->r;
  t->r=p;
  exchageChild(t->r);
  exchageChild(t->l);
}

int main(){
  bitTree t=creatBitTree();
  exchageChild(t);
  preOrderTraversal(t);
  return 0;
}