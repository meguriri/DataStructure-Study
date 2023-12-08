/*
L=(l1,l2,l3,l4....ln-1,ln) -> L=(l1,ln,l2,ln-1,l3,ln-2....)
*/
#include"list.h"

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creatList(a,10);
  return 0;
}