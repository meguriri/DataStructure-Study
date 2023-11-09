/*
  一棵树用孩子兄弟链表存储，编写算法计算该树的度
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int data;
  node *firstChi;
  node *nextSib;
}cstNode,*cstTree;

cstTree getCstTree(){
  cstTree t;
  t=new(cstNode);
  t->data=1;
  t->firstChi=new(cstNode);
  t->nextSib=nullptr;
  t->firstChi->data=2;
  t->firstChi->nextSib=new(cstNode);
  t->firstChi->nextSib->data=3;
  t->firstChi->nextSib->nextSib=nullptr;
  t->firstChi->nextSib->firstChi=new(cstNode);
  t->firstChi->nextSib->firstChi->data=7;
  t->firstChi->nextSib->firstChi->firstChi=nullptr;
  t->firstChi->nextSib->firstChi->nextSib=nullptr;
  t->firstChi->firstChi=new(cstNode);
  t->firstChi->firstChi->data=4;
  t->firstChi->firstChi->firstChi=nullptr;
  t->firstChi->firstChi->nextSib=new(cstNode);
  t->firstChi->firstChi->nextSib->data=5;
  t->firstChi->firstChi->nextSib->firstChi=nullptr;
  t->firstChi->firstChi->nextSib->nextSib=new(cstNode);
  t->firstChi->firstChi->nextSib->nextSib->data=6;
  t->firstChi->firstChi->nextSib->nextSib->firstChi=nullptr;
  t->firstChi->firstChi->nextSib->nextSib->nextSib=nullptr;
  return t;
}

int getDegree(cstTree t){
  if(t==nullptr){
    return 0;
  }
  int mmax=0;
  int cnt=0;
  for(cstNode *p=t->firstChi;p!=nullptr;p=p->nextSib){
    cnt++;
    int now=getDegree(p);
    if(mmax<now){
      mmax=now;
    }
  }
  return cnt>mmax?cnt:mmax;
}

int main(){
  cstTree t=getCstTree();
  int ans=getDegree(t);
  printf("%d\n",ans);
  return 0;
}