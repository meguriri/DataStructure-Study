/*
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1
*/
#include"bitTree.h"

int getXHigh(bitTree t,int x,int f){   
  if(t==nullptr){
    return 0;
  }
  if(t->d==x||f==1){
    int l=getXHigh(t->l,x,1),r=getXHigh(t->r,x,1);
    return (l>r?l:r)+1; 
  }
  int l=getXHigh(t->l,x,0),r=getXHigh(t->r,x,0);
  return (l>r?l:r);
}

int main(){
  bitTree t=creatBitTree();
  printf("%d\n",getXHigh(t,6,0));
  return 0;
}