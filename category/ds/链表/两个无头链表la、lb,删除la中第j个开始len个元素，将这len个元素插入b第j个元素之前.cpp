#include"list.h"

void merge(list l1,list l2,int s,int len){
  node *prel=l1,*prer=nullptr,
  *pl=l1->next,*pt=nullptr,*p2=l2->next,*ppre2=l2;
  int cnt=0;
  while(pl!=nullptr){
    cnt++;
    if(cnt==s){
      break;
    }
    prel=prel->next;
    pl=pl->next;
  }
  cnt=0;
  prer=prel;
  pt=pl;
  while(pt!=nullptr){
    cnt++;
    if(cnt==len){
      prer=prer->next;
      pt=pt->next;
      break;
    }
    prer=prer->next;
    pt=pt->next;
  }
  cnt=0;
  while(p2!=nullptr){
    cnt++;
    if(cnt==s){
      prer->next=ppre2->next;
      ppre2->next=pl;
      break;
    }
    ppre2=ppre2->next;
    p2=p2->next;
  }
  prel->next=pt;
}
 
int main(){
  int a1[10]={0,1,2,3,4,5,6,7,8,9};
  int a2[10]={10,11,12,13,14};
  list l1=creatList(a1,10);
  list l2=creatList(a2,5);
  printList(l1);
  printList(l2);
  merge(l1,l2,2,1);
  printList(l1);
  printList(l2);
  return 0;
}