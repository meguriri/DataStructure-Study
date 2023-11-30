#include"bitTree.h"
/*
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1
*/


int getDegreeOne(bitTree t){
  if(t==nullptr){
    return 0;
  }
  if(t->l==nullptr&&t->r!=nullptr){
    return getDegreeOne(t->r)+1;
  }
  if(t->l!=nullptr&&t->r==nullptr){
    return getDegreeOne(t->l)+1;
  }
  return getDegreeOne(t->l)+getDegreeOne(t->r);
}

int main(){
  bitTree t=creatBitTree();
  printf("%d ",getDegreeOne(t));
  return 0;
}