/*
  正整数构成的链表，编写算法完成如下功能：
  1. 找链表最小值
  2. 若该节点为奇数，则与后继节点的值交换
  3. 若该节点为偶数，则删除后继节点
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

//!!!
int listFindMininum(list h){
  int ans=0x3f3f3f3f;
  node *p=h->next;
  while(p!=nullptr){
    if(p->d<ans){
      ans=p->d;
    }
    p=p->next;
  }
  return ans;
}

//!!!
void listOddOperate(list h){
  node *p=h->next;
  while(p->next!=nullptr){
    if(p->d%2){
      int t=p->d;
      p->d=p->next->d;
      p->next->d=t;
    }
    p=p->next;
  }
}

//!!!
void listEvenOperate(list h){
  node *p=h->next;
  while(p->next!=nullptr){
    if(p->d%2==0){
      node *t=p->next;
      p->next=p->next->next;
      delete(t);
    }
    p=p->next;
  }
}

int main(){
  int a[10]={3,5,8,4,1,7,2,9,6,10},n=10;
  list l=createList(a,n);
  printList(l);
  printf("%d\n",listFindMininum(l));
  listOddOperate(l);
  printList(l);
  listEvenOperate(l);
  printList(l);
  return 0;
}