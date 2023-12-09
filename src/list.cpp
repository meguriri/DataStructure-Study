#include"list.h"

list creatList(int a[],int n){
  list l=new(node),t=l;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->d=a[i];
    p->next=nullptr;
    t->next=p;
    t=p;
  }
  return l;
}

void printList(list l){
  node *p=l->next;
  while(p!=nullptr){
    printf("%d ",p->d);
    p=p->next;
  }
  printf("\n");
}

list creastCirList(int a[],int n){
  list l=new(node);
  l->next=l;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->d=a[i];
    p->next=l->next;
    l->next=p;
  }
  return l;
}

void printCirList(list l){
  node *p=l->next;
  while(p!=l){
    printf("%d ",p->d);
    p=p->next;
  }
  printf("\n");
}