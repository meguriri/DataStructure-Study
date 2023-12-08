#include<cstdio>

typedef struct node{
  int d;
  node *next;
}node,*list;

list CreatList(int a[],int n){
  list l=new(node),t=l;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->next=nullptr;
    p->d=a[i];
    t->next=p;
    t=p;
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