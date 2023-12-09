#include"list.h"

void reverseList(list l){
  node *p=l->next;
  l->next=l;
  while(p!=l){
    node *t=p;
    p=p->next;
    t->next=l->next;
    l->next=t;
  }
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creastCirList(a,10);
  printCirList(l);
  reverseList(l);
  printCirList(l);
  return 0;
}