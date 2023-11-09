/*  
  给定一个单链表存储的互异的数列，求出递增和递减序列的数目。
  eg. 7 2 6 9 8 3 5 2 1
  (7 2)(2 6 9)(9 8 3)(3 5)(5 2 1) 
*/
#include "list.h"

int cnt(list l){
  int ans=1;
  node *p=l->next;
  int f=0;
  if(p->d>p->next->d){
    f=0;
  }else{
    f=1;
  }
  printf("%d ",p->d);
  p=p->next;
  while(p!=nullptr){
    printf("%d ",p->d);
    if(f==0){
      if(p->next!=nullptr&&p->d<p->next->d){
        f=1;
        ans++;
        printf("\n%d ",p->d);
      }
    }else if(f==1){
      if(p->next!=nullptr&&p->d>p->next->d){
        f=0;
        ans++;
        printf("\n%d ",p->d);
      }
    }
    p=p->next;
  }
  printf("\n");
  return ans;
}

int main(){
  int a[9]={7,2,6,9,8,3,5,2,1};
  list l = creatList(a,9);
  printf("%d\n",cnt(l));
  return 0;
}