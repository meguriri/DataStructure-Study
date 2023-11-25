#include"bitTree.h"

int getLeafNum(bitTree t){
  if(t==nullptr){
    return 0;
  }
  if(t->l==nullptr&&t->r==nullptr){
    return 1;
  }
  return getLeafNum(t->l)+getLeafNum(t->r);
}

int main(){
  return 0;
}