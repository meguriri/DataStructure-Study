#include<cstdio>

typedef struct node{
  int d;
  node *next;
}node,*list;

list CreatList(int a[],int n){
  list l=new(node);
  l->next=nullptr;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->d=a[i];
    p->next=l->next;
    l->next=p;
  }
  return l;
}

void PrintList(list l){
  node *p=l->next;
  while(p!=nullptr){
    printf("%d ",p->d);
    p=p->next;
  }
  printf("\n");
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=CreatList(a,10);
  PrintList(l);
  return 0;
}