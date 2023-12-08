#include"list.h"

int getMax(node *p){
  if(p==nullptr){
    return -10000;
  }
  int n=getMax(p->next);
  return p->d>n?p->d:n;
}

int getCnt(node *p){
  if(p==nullptr){
    return 0;
  }
  return getCnt(p->next)+1;
}

int getSum(node *p){
  if(p==nullptr){
    return 0;
  }
  return p->d+getSum(p->next);
}

int main(){ 
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creatList(a,10);
  int max=getMax(l->next),cnt=getCnt(l->next),p=getSum(l->next);
  printf("%d %d %.3f\n",max,cnt,((float)p/(1.0*cnt)));
  return 0;
}