/*
  实现Locate函数，设带头的双向链表L，每个节点有4个数据成员，
  指向前驱节点的指针prior，指向后继节点的指针next，存放数据的成员data
  和访问频度freq，所有节点freq的初始值都为0，每当在链表上进行每一次Locate(L,x)
  操作时，令元素x的节点访问频度加1，同时调整链表中节点的顺序，
  使链表中所有节点按访问频度递减的顺序排列
  1 2 3 4 5 6 7 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int data;
  int freq;
  node *prior;
  node *next;
}node,*list;


list creatList(){
  list l=new(node);
  l->next=nullptr;
  l->prior=nullptr;
  node *t=l;
  int x;
  while(1){
    scanf("%d",&x);
    if(x==-1){
      break;
    }
    node *p=new(node);
    p->data=x;
    p->freq=0;
    p->next=nullptr;
    p->prior=t;
    t->next=p;
    t=p;
  }
  return l;
}

void orderPrint(list l){
  node *p=l->next;
  while(p!=nullptr){
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}

void Locate(list l,int x){
  node *p=l->next;
  while(p!=nullptr){
    if(p->data==x){
      p->freq++;

      //方法1
      // node *r=p;
      // p->prior->next=p->next;
      // p->next->prior=p->prior;
      // p=l->next;
      // while(r->freq<p->freq){
      //   p=p->next;
      // }
      // r->prior=p->prior;
      // p->prior->next=r;
      // r->next=p;
      // p->prior=r;

      //方法2
      node *r=p;
      p=p->prior;
      while(p!=l&&p->freq<r->freq){
        p=p->prior;
      }
      //更新之前的位置前后的指针
      r->prior->next=r->next;
      r->next->prior=r->prior;
      //插入新的位置
      r->next=p->next;
      p->next->prior=r;
      r->prior=p;
      p->next=r;
      
      break;
    }else{
      p=p->next;
    }
  }
}

int main(){
  list l=creatList();
  orderPrint(l);
  Locate(l,3);
  orderPrint(l);
  Locate(l,5);
  orderPrint(l);
  Locate(l,3);
  orderPrint(l);
  Locate(l,6);
  orderPrint(l);
  Locate(l,6);
  orderPrint(l);
  Locate(l,6);
  orderPrint(l);
  Locate(l,1);
  orderPrint(l);
  return 0;
}