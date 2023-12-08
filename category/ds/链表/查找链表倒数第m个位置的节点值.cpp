#include"list.h"

int getMNode(list l,int m){
  node *p=l->next,*pre=nullptr;
  int ans=0,cnt=0;
  while(p!=nullptr){
    if(cnt==m){
      pre=l->next;
    }
    cnt++;
    if(pre!=nullptr){
      pre=pre->next;
    }
    p=p->next;
  }
  if(pre==nullptr){
    if(cnt==m){
      ans=l->next->d;
    }
  }else{
    ans=pre->d;
  }
  return ans;
}

int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  list l=creatList(a,10);
  printf("%d\n",getMNode(l,5));
  printf("%d\n",getMNode(l,10));
  printf("%d\n",getMNode(l,1));
  return 0;
}