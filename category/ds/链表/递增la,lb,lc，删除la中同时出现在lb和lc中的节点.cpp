#include"list.h"

void deleteBC(list l1,list l2,list l3){
  node *pre=l1,*p1=l1->next,*p2=l2->next,*p3=l3->next;
  while(p1!=nullptr){
    while(p2!=nullptr&&p3!=nullptr){
      if(p2->d==p3->d){
        break;
      }
      if(p2->d<p3->d){
        p2=p2->next;
      }else if(p2->d>p3->d){
        p3=p3->next;
      }
    }
    if(p2==nullptr||p3==nullptr){
      break;
    }
    if(p1->d<p2->d){
      pre=pre->next;
      p1=p1->next;
    }else if(p1->d>p2->d){
      p2=p2->next;
      p3=p3->next;
    }else if(p1->d==p2->d){
      pre->next=p1->next;
      delete(p1);
      p1=pre->next;
    }
  }
}

int main(){
  int a1[10]={1,2,2,3,4,4,5,7,8,9};
  int a2[6]={1,2,4,5,8,9};
  int a3[6]={1,3,5,6,9,10};
  list l1=creatList(a1,10),l2=creatList(a2,6),l3=creatList(a3,6);
  printList(l1);
  deleteBC(l1,l2,l3);
  printList(l1);
  return 0;
}