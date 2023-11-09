/*
  整数链表就地（应该是只交换值，不交换节点）冒泡排序
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

//交换节点
void bubbleSortList1(list h,int n){
  if(h->next==nullptr||h->next->next==nullptr){
    return;
  }
  node *p1=h,*p2=h->next,*p3=h->next->next;
  for(int i=0;i<n-1;i++){
    p1=h;
    p2=h->next;
    p3=h->next->next;
    for(int j=0;j<n-i-1;j++){
      if(p2->d>p3->d){
        p1->next=p3;
        p2->next=p3->next;
        p3->next=p2;
      }
      p1=p1->next;
      p2=p1->next;
      p3=p2->next;
    }
  }
}

//只交换值
void bubbleSortList2(list h,int n){
  node *p=h;
  for(int i=0;i<n-1;i++){
    p=h->next;
    for(int j=0;j<n-i-1;j++){
      if((p->d)>(p->next->d)){
        int temp=p->d;
        p->d=p->next->d;
        p->next->d=temp;
      }
      p=p->next;
    }
  }
}

int main(){
  int a[10]={4,3,6,7,1,5,2,9,8,0};
  list l=createList(a,10);
  printList(l);
  bubbleSortList2(l,10);
  printList(l);
  return 0;
}