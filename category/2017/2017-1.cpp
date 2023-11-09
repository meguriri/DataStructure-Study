/*
  递增的单链表 编写算法删除线性表中相同的多余元素（使操作后的线性表的元素值各不相同）
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *next;
}node,*list;

list createList(int a[],int n){
  node *head =new(node),*tail=head;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->d=a[i];
    p->next=nullptr;
    tail->next=p;
    tail=p;
  }
  return head;
}

void printList(list h){
  node *p=h->next;
  while(p!=nullptr){
    printf("%d ",p->d);
    p=p->next;
  }
  printf("\n");
}

void operate(list l){
  node *p=l->next;
  while(p!=nullptr){
    if(p->next!=nullptr&&p->d==p->next->d){
      node *t=p->next;
      p->next=p->next->next; 
      delete(t);
    }else{//注意！！！删完仍要继续判断后面是否一样，不一样才往后移
      p=p->next;
    }
  }
}

int main(){
  int a[10]={1,1,2,3,3,4,5,6,6,6};
  list l=createList(a,10);
  printList(l);
  operate(l);
  printList(l);
  return 0;
}