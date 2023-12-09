#include"list.h"

void deleteP(node *p){
  node *t=p->next;
  while(t->next->next!=p){
    t=t->next;
  }
  node *cur=t->next;
  t->next=p;
  delete(cur);
} 

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creastCirList(a,10);
  printCirList(l);
  deleteP(l->next->next->next->next->next);
  printCirList(l);
  return 0;
}