/*
  求二叉树，第i层和第i+1叶子节点个数之和
  1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

void count(bitTree t,int s,int i,int *x){
  if(t==nullptr)
    return;
  if(s==i||s==i+1){
    if(t->l==nullptr&&t->r==nullptr){
      *x++;
    }
  }
  count(t->l,s+1,i,x);
  count(t->r,s+1,i,x);
}

int main(){

  return 0;
}