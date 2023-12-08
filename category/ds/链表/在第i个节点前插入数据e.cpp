#include"list.h"

void InsertE(list l,int x,int e){
  node *p=l;
  for(int i=1;i<x;i++){
    p=p->next;
  }
  node *t=new(node);
  if(p!=nullptr){
    t->d=e;
    t->next=p->next;
    p->next=t;
  } 
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creatList(a,10);
  printList(l);
  InsertE(l,10,10);
  printList(l);
  return 0;
}