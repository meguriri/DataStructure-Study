/*
  单链表，在不改变链表的前提下，查找链表倒数第m位的节点并输出节点的data值，
  成功返回true，否则返回false
  eg1. 1 2 3 4 5 6 7
      3
  eg2. 1 2 3 4 5 6 7
      8
  eg3. 1 2 3 4 5 6 7
      7
*/
#include"list.h"

int getListM(list head,int m){
  node *p=head->next,*pre=nullptr;
  int cnt=0;
  while(p!=nullptr){
    if(cnt==m){
      pre=head->next;
    }
    if(pre!=nullptr){
      pre=pre->next;
    }
    p=p->next;
    cnt++;
  }
  if(pre!=nullptr){
    printf("%d\n",pre->d);
    return 1;
  }else if(cnt==m){
    printf("%d\n",head->next->d);
    return 1;
  }
  return 0;
}

int main(){
  int a[7]={1,2,3,4,5,6,7};
  list l=creatList(a,7);
  printf("%d\n",getListM(l,8));
  return 0;
}