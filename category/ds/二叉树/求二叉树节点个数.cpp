#include"bstTree.h"

int getNodeNum(bstTree t){
  if(t==nullptr){
    return 0;
  }
  return getNodeNum(t->l)+getNodeNum(t->r)+1;
}

int main(){
  return 0;
}