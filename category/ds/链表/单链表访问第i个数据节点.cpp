#include"list.h"

int getINode(list l,int n){
  node *p=l->next;
  for(int i=1;i<n;i++){
    p=p->next;
  }
  if(p!=nullptr){
    return p->d;
  }
  return 0;
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creatList(a,10);
  printf("%d\n",getINode(l,5));
  return 0;
}