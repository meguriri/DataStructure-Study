#include"list.h"

int cntXList(list l,int x){
  int last=-1,cnt=0;
  node *p=l->next;
  while(p!=nullptr&&p->d<x){
    if(last==-1||p->d!=last){
      last=p->d;
      cnt++;
    }
    p=p->next;
  }
  return cnt;
}

int main(){
  int a[10]={1,1,2,2,3,4,4,4,5,5};
  list l=creatList(a,10);
  printf("%d\n",cntXList(l,5));
  return 0;
}