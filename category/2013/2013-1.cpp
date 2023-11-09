/*
  la指向单链表的首节点，编写算法：从la中删除第i个元素起共len个元素
  0 1 2 3 4 5 6 7 8 9 
  1 2 3 4 5
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

void deleteLen(list l,int i,int len){
  node *pre=l,*p=l->next;
  for(int j=1;j<i&&p!=nullptr;j++){
    p=p->next;
    pre=pre->next;
  }
  for(int j=1;j<=len&&p!=nullptr;j++){
    pre->next=p->next;
    delete(p);
    p=pre->next;

  }
}

int main(){
  int a[10]={1,2,3,4,5};
  list l=createList(a,5);
  printList(l);
  deleteLen(l,6,4);
  printList(l);
  return 0;
}