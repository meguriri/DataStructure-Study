/*
  eg1.
  10 8 14 13 25 
  2 6 11 15 30 16 17 5
*/
#include"bstTree.h"

int getXFloor(bstTree t,int x,int s){
  if(t==nullptr){
    return 0;
  }
  if(t->d==x){
    return s;
  }
  if(x<t->d){
    return getXFloor(t->l,x,s+1);
  }else if(x>t->d){
    return getXFloor(t->r,x,s+1);
  }
}
 
int main(){
  bstTree t=creatBstTree(10);
  printf("%d\n",getXFloor(t,12,1));
  return 0;
}