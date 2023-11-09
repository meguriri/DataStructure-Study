/*
  将循环链表中节点x的直接前驱删掉
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *next;
};

void DelPriorNode(node *p){
  node *t=p->next,*pre=p;
  while(t->next!=p){
    pre = t;
    t=t->next;
  }
  pre->next=p;
  delete(t);
}

int main(){

  return 0;
} 