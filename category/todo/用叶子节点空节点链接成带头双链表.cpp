/*
1 2 4 -1 -1 5 -1 -1 3 6 8 -1 -1
9 -1 -1 7 -1 -1
*/
#include"bitTree.h"

bitNode *head=new(bitNode),*tail=head;
void CreatLeafList(bitTree t){
  if(t==nullptr){
    return;
  }
  if(t->l==nullptr&&t->r==nullptr){
    tail->r=t;
    t->l=tail;
    tail=t;
    return;
  }
  CreatLeafList(t->l);
  CreatLeafList(t->r);
}

void CreatList(bitTree t){
  head->l=nullptr;
  head->r=nullptr;
  CreatLeafList(t);
  bitNode *p=tail;
  tail=new(node);
  tail->r=nullptr;
  p->r=tail;
  tail->l=p;
}

int main(){
  bitTree t=creatBitTree();
  CreatList(t);
  bitNode *p=head->r;
  while(p->r!=nullptr){
    printf("%d ",p->d);
    p=p->r;
  }
  printf("\n");
  p=tail->l;
  while(p->l!=nullptr){
    printf("%d ",p->d);
    p=p->l;
  }
  printf("\n");
  return 0;
}