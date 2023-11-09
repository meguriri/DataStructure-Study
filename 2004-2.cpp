/*
  某手机按价格从低到高存入链表中，节点包括数量、价格、指针
  现到n个不同的手机，编写将新的手机插入到原链表中的算法
*/

#include<cstdio>
#include<cstdlib>

struct phone{
  int cnt;
  float price;
};

typedef struct node{
  phone p;
  node *next;
}node,*list;

list createList(phone a[],int n){
  node *head =new(node),*tail=head;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->p.cnt=a[i].cnt;
    p->p.price=a[i].price;
    p->next=nullptr;
    tail->next=p;
    tail=p;
  }
  return head;
}

void printList(list h){
  node *p=h->next;
  while(p!=nullptr){
    printf("%.1lf ",p->p.price);
    p=p->next;
  }
  printf("\n");
}

void insertNode(list l,phone ph){
  node *pre=l,*p=l->next;
  while(p!=nullptr){
    if(ph.price>p->p.price){
      node *t=new(node);
      t->p.price=ph.price;
      t->p.cnt=ph.cnt;
      t->next=p;
      pre->next=t;
      break;
    }
    p=p->next;
    pre=pre->next;
  }
  if(p==nullptr){
    node *t=new(node);
    t->p.price=ph.price;
    t->p.cnt=ph.cnt;
    t->next=p;
    pre->next=t;
  }
}

int main(){
  phone pl[5]={{5,100},{4,90},{3,80},{2,70},{1,60}};
  list l=createList(pl,5);
  phone newPl[5]={{10,45},{9,120},{8,20},{7,85},{6,95}};
  for(int i=0;i<5;i++){
    insertNode(l,newPl[i]);
  }
  printList(l);
  return 0;
}