/*
  输入数据 以0为结尾，将数据按递增顺序用单链表存放，并打印单链表
  4 1 2 6 7 5 3 9 8 10 0
*/

#include<cstdio>
#include<cstdlib>

struct node{
  int d;
  node *next;
};

node* creat(){
  int a[100]={0},n=0,x=1;
  while(1){
    scanf("%d",&x);
    if(x==0){
      break;
    }
    a[n++]=x;
  }
  node *h=new(node);
  h->next=nullptr;
  for(int i=0;i<n;i++){
    node *p=h->next,*pre=h;
    node *pp=new(node);
    pp->d=a[i];
    while(p!=nullptr&&pp->d>p->d){
      pre=pre->next;
      p=p->next;
    }
    pp->next=pre->next;
    pre->next=pp;
  }
  return h;
}

void print(node *h){
  node *p=h->next;
  while(p!=nullptr){
    printf("%d ",p->d);
    p=p->next;
  }
  printf("\n");
}

int main(){
  int a[10]={};
  node *h=creat();
  print(h);
  return 0;
}