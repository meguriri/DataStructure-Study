/*
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1
*/
#include"bitTree.h"

int getHigh(bitTree t){
  if(t==nullptr){
    return 0;
  }
  int l=getHigh(t->l),r=getHigh(t->r);
  return (l>r?l:r)+1;
}

int main(){
  bitTree t=creatBitTree();
  printf("%d\n",getHigh(t));
  return 0;
}