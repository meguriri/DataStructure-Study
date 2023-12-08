#include"list.h"

void deleteRange(list l,int min,int max){
  node *pre=l,*p=l->next;
  while(p!=nullptr){
    if(p->d>min){
      break;
    }
    pre=pre->next;
    p=p->next;
  }
  while(p!=nullptr&&p->d<max){
    pre->next=p->next;
    delete(p);
    p=pre->next;
  }
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creatList(a,10);
  printList(l);
  deleteRange(l,0,9);
  printList(l);
  return 0;
}