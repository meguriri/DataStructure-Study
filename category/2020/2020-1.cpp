/*
  单链表，在不改变链表的前提下，查找链表倒数第m位的节点并输出节点的data值，
  成功返回true，否则返回false
  eg1. 1 2 3 4 5 6 7
      3
  eg2. 1 2 3 4 5 6 7
      8
*/

#include"list.h"

bool getListM(list l,int m){
  node *pre,*p=l->next;
  int cnt=0;
  while(p!=nullptr){
    cnt++;
    if(cnt==m+1){
      pre=l->next;
    }
    if(cnt>=m+1){
      pre=pre->next;
    }
    p=p->next;
  }
  if(pre==nullptr)
    return false;
  printf("%d\n",pre->d);
  return true;
}

int main(){
  int a[7]={1,2,3,4,5,6,7};
  list l=creatList(a,7);
  printf("%d\n",getListM(l,3));
  return 0;
}