/*
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1
*/
#include"bitTree.h"

bitNode* getXNode(bitTree t,int x){
  if(t==nullptr){
    return nullptr;
  }
  if(t->d==x){
    return t;
  }
  bitNode *l=getXNode(t->l,x);
  if(l!=nullptr){
    return l;
  }
  return getXNode(t->r,x);
}

int main(){
  bitTree t=creatBitTree();
  bitNode *p=getXNode(t,8);
  if(p!=nullptr){
    printf("%d\n",p->d);
  }else{
    printf("nullptr\n");
  }
  return 0;
}