#include"list.h"

list creatMergeList(list l1,list l2){
  list l3=new(node),t=l3;
  l3->next=nullptr;
  node *p1=l1->next,*p2=l2->next;
  while(p1!=nullptr&&p2!=nullptr){
    if(t!=l3&&(t->d==p1->d)){
      p1=p1->next;
      continue;
    }else if(t!=l3&&(t->d==p2->d)){
      p2=p2->next;
      continue;
    }
    if(p1->d==p2->d){
      t->next=p1;
      t=p1;
      p1=p1->next;
      p2=p2->next;
    }else if(p1->d<p2->d){
      t->next=p1;
      t=p1;
      p1=p1->next;
    }else if(p1->d>p2->d){
      t->next=p2;
      t=p2;
      p2=p2->next;
    }
  }
  while(p1!=nullptr){
    if(t->d<p1->d){
      t->next=p1;
      t=p1;
    }
    p1=p1->next;
  }
  while(p2!=nullptr){
    if(t->d<p2->d){
      t->next=p2;
      t=p2;
    }
    p2=p2->next;
  }
  t->next=nullptr;
  return l3;
}

int main(){
  int a1[8]={1,2,3,3,4,6,8,8};
  int a2[8]={1,2,4,5,6,7,8,8};
  list l1=creatList(a1,8),l2=creatList(a2,8);
  list l3=creatMergeList(l1,l2);
  printList(l3);
  return 0;
}