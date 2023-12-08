#include"list.h"

void deleteList(list l){
  node *p=l->next;
  while(p!=nullptr){
    if(p->next!=nullptr&&p->d==p->next->d){
      node *t=p->next;
      p->next=p->next->next;
      delete(t);
    }else{
      p=p->next;
    }
  }
}

int main(){
  int a[10]={1,1,2,2,3,4,4,4,5,5};
  list l=creatList(a,10);
  printList(l);
  deleteList(l);
  printList(l);
  return 0;
}