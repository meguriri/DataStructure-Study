#include"list.h"

void deleteS(list l1,list l2){
  node *pre=l1,*p1=l1->next,*p2=l2->next;
  while(p1!=nullptr&&p2!=nullptr){
    if(p1->d<p2->d){
      pre=pre->next;
      p1=p1->next;
    }else if(p1->d>p2->d){
      p2=p2->next;
    }else if(p1->d==p2->d){
      pre->next=p1->next;
      delete(p1);
      p1=pre->next;
    }
  }
}

int main(){
  int a1[10]={1,2,2,3,4,4,5,7,8,9};
  int a2[4]={1,2,5,9};
  list l1=creatList(a1,10),l2=creatList(a2,4);
  printList(l1);
  deleteS(l1,l2);
  printList(l1);
  return 0;
}