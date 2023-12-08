#include"list.h"

void bubbleSort(list l){
  int f=0;
  while(1){
    f=0;
    for(node *p=l->next;p->next!=nullptr;p=p->next){
      if(p->d>p->next->d){
        int t=p->d;
        p->d=p->next->d;
        p->next->d=t;
        f++;
      }
    }
    if(f==0){
      break;
    }
  }
}

int main(){
  int a[10]={9,2,1,4,3,5,8,7,6,0};
  list l=creatList(a,10);
  printList(l);
  bubbleSort(l);
  printList(l);
  return 0;
}