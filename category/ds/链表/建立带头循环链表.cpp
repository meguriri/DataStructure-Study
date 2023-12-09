#include<cstdio>

typedef struct node{
  int d;
  node *next;
}node,*list;

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

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creastCirList(a,10);
  printCirList(l);
  return 0;
}