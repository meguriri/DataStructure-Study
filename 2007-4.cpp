/*
  两个二叉排序树，合并成一个，要求辅助空间最小（使用原空间，不开辟新空间）
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

void insertNode(bitTree &t,bitNode *p){
  if(t==nullptr){
    p->l=nullptr;
    p->r=nullptr;
    t=p;
  }
  if(p->d<t->d){
    insertNode(t->l,p);
  }else if(p->d<t->d){
    insertNode(t->r,p);
  }
}

void MergeBST(bitTree &t1, bitTree &t2){
  if(t2==nullptr){
    return;
  }
  //后序遍历防止断链
  MergeBST(t1,t2->l);
  MergeBST(t1,t2->r);
  insertNode(t1,t2);
}

int main(){

  return 0;
}