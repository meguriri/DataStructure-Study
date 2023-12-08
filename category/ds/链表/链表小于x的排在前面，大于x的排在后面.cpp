#include"list.h"

void move(list l,int x){
  node *pre=l,*p=l->next;
  while(p!=nullptr){
    if(p->d<x&&pre!=l){//!!!!!!
      pre->next=p->next;
      p->next=l->next;
      l->next=p;
      p=pre->next;
    }else{
      pre=p;
      p=pre->next;
    }
  }
}

int main(){
  int a[10]={30,50,10,6,21,7,3,2,33,21};
  list l=creatList(a,10);
  printList(l);
  move(l,20);
  printList(l);
  return 0;
}