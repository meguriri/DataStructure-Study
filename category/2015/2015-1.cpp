/*
  判断单链表的各节点是否有序
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

int judge(list l){
  node *p=l->next;
  if(p->next==nullptr){
    return 1;
  }
  int f=0;
  while(p!=nullptr){
    if(p->next!=nullptr&&p->d!=p->next->d){
      if(p->d<p->next->d){//递增
        f=1;
      }else if(p->d>p->next->d){//递减
        f=0;
      }
      break;
    }else{
      p=p->next;
    }
  } 
  if(f==1){//递增
    while(p!=nullptr){
      if(p->next!=nullptr&&p->d>p->next->d){
        return 0;
      }
      p=p->next;
    }
  }else if(f==0){//递减
    while(p!=nullptr){
      if(p->next!=nullptr&&p->d<p->next->d){
        return 0;
      }
      p=p->next;
    }
  }
  return 1;
}

int main(){
  int a[5]={1,2,1,6,4};
  list l=createList(a,5);
  printf("%d\n",judge(l));
  return 0;
}