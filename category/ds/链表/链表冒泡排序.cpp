#include"list.h"

void bubbleSort(list l){
  node *p,*pre;
  int f=1;
  while(f!=0){
    pre=l->next;
    p=pre->next;
    f=0;
    while(p!=nullptr){
      if(p->d<pre->d){
        int t=p->d;
        p->d=pre->d;
        pre->d=t;
        f++;
      }
      p=p->next;
      pre=pre->next;
    }
  }
}

int main(){
  int a[10]={6,2,8,5,3,0,9,4,1,7};
  list l=creatList(a,10);
  printList(l);
  bubbleSort(l);
  printList(l);
  return 0;
}