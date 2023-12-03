/*
  eg1.
  10 8 14 13 25 
  2 6 11 15 30 16 17 5
*/
#include"bstTree.h"

void findLessX(bstTree t,int x){
  if(t==nullptr){
    return;
  }
  findLessX(t->l,x);
  if(t->d<x){
    printf("%d ",t->d);
    findLessX(t->r,x);
  }
}

int main(){
  bstTree t=creatBstTree(13);
  findLessX(t,13);
  return 0;
}