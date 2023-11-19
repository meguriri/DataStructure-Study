/*
  LA，LB两个递减单链表，构造一个递增有序循环链表LC
  其节点同时出现LA，LB中，且LC中的值不重复
*/

#include"list.h"

list creatCircList(list la,list lb){
  list lc=new(node);
  lc->next=lc;
  node *pa=la->next,*pb=lb->next;
  while(pa!=nullptr&&pb!=nullptr){
    if(pa->d>pb->d){
      if(lc->next==lc||lc->next->d>pa->d){
        node *p=new(node);
        p->d=pa->d;
        p->next=lc->next;
        lc->next=p;
      }
      pa=pa->next;
    }else if(pa->d<pb->d){
      if(lc->next==lc||lc->next->d>pb->d){
        node *p=new(node);
        p->d=pb->d;
        p->next=lc->next;
        lc->next=p;
      }
      pb=pb->next;
    }else if(pa->d==pb->d){
      if(lc->next==lc||lc->next->d>pb->d){
        node *p=new(node);
        p->d=pb->d;
        p->next=lc->next;
        lc->next=p;
      }
      pa=pa->next;
      pa=pb->next;
    }
  }
  while(pa!=nullptr){
    if(lc->next==lc||lc->next->d>pa->d){
        node *p=new(node);
        p->d=pa->d;
        p->next=lc->next;
        lc->next=p;
      }
      pa=pa->next;
  }
  while(pb!=nullptr){
    if(lc->next==lc||lc->next->d>pb->d){
        node *p=new(node);
        p->d=pb->d;
        p->next=lc->next;
        lc->next=p;
      }
      pb=pb->next;
  }
  return lc;
}

void printClcList(list lc){
  node *p=lc->next;
  while(p!=lc){
    printf("%d ",p->d);
    p=p->next;
  }
  printf("\n");
}

int main(){
  int a[6]={8,6,6,4,3,3};
  int b[6]={8,7,6,5,2,1};
  list la=creatList(a,6);
  list lb=creatList(b,6);
  list lc=creatCircList(la,lb);
  printClcList(lc);
  return 0;
}