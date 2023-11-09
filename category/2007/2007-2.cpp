/*
  标注平衡因子的平衡二叉树，求树的高度
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  int bf;
  node *l,*r;
}bitNode,*bitTree;

int getHigh(bitTree t){
  int high=0;
  bitNode *p=t; 
  while(p!=nullptr){
    high++;
    if(p->bf<0){
      p=p->r;
    }else{
      p=p->l;
    }
  }
  return high;
}

int main(){

  return 0;
}