#include"list.h"

void leftMoveK(list l,int k){
  int cnt=0;
  node *p=l->next,*t=l->next;
  while(t->next!=l){
    t=t->next;
  }
  while(p!=l){
    cnt++;
    if(cnt==k){
      break;
    }
    p=p->next;
  }
  t->next=l->next;
  l->next=p->next;
  p->next=l;
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creastCirList(a,10);
  printCirList(l);
  leftMoveK(l,4);
  printCirList(l);
  return 0;
}