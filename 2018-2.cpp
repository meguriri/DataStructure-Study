/*
  二叉树采用二叉链表存储，判断两棵树是否相似
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

int judge(bitTree t1,bitTree t2){
  if(t1==nullptr&&t2==nullptr){
    return 1;
  }
  if((t1==nullptr&&t2!=nullptr)||(t1!=nullptr&&t2==nullptr)){
    return 0;
  }
  return judge(t1->l,t2->l)&&judge(t1->r,t2->r);
}

int main(){

  return 0;
}