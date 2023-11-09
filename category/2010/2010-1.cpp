/*
  带头链表，至少含有三个节点，每个节点存一个整型值，编写算法判断链表每个节点是否等于其后续两个节点值的和。
  满足返回1，并输出最大值；否则返回0，并输出最小值。
*/

#include<cstdio>
#include<cstdlib>

struct node{
  int d;
  node *next;
};

int judge(node *h){
  int f=1,mmin=0x3f3f3f3f,mmax=-10000000;
  node *p=h->next;
  while(p!=nullptr){
    if(p->d>mmax){
      mmax=p->d;
    }
    if(p->d<mmin){
      mmin=p->d;
    }
    if(p->next!=nullptr||p->next->next!=nullptr){
      if(p->d!=(p->next->d+p->next->next->d)){
        f=0;
      }
    }
    p=p->next;
  }
  if(f==1){
    printf("%d\n",mmax);
  }else if(f==0){
    printf("%d\n",mmin);
  }
  return f;
}

int main(){

  return 0;
}