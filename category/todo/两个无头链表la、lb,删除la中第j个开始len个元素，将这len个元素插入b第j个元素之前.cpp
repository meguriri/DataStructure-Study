#include"list.h"

void merge(list l1,list l2,int s,int len){
  node *pre1=l1,*pre2=nullptr,
  *p1=l1->next,*p2=nullptr,*pp=l2->next,*ppre=l2;
  int cnt=0;
  while(p1!=nullptr){
    cnt++;
    if(cnt==s){
      break;
    }
    pre1=pre1->next;
    p1=p1->next;
  }
  cnt=0;
  pre2=pre1;
  p2=p1;
  while(p2!=nullptr){
    cnt++;
    if(cnt==s){
      pre2=pre2->next;
      p2=p2->next;
      break;
    }
    pre2=pre2->next;
    p2=p2->next;
  }
  cnt=0;
  while(pp!=nullptr){
    cnt++;
    if(cnt==s){
      pre2->next=ppre->next;
      ppre->next=p1;
      break;
    }
    ppre=ppre->next;
    pp=pp->next;
  }
  pre1->next=p2;
}
 
int main(){
  int a1[10]={0,1,2,3,4,5,6,7,8,9};
  int a2[10]={10,11,12,13,14};
  list l1=creatList(a1,10);
  list l2=creatList(a1,5);
  printList(l1);
  printList(l2);
  merge(l1,l2,4,5);
  printList(l1);
  printList(l2);
  return 0;
}