/*todo
  给出中序线索二叉树，编写在不使用栈和递归的情况下的先序和中序遍历线索二叉树的算法 
*/

#include<cstdio>
#include<cstdlib>
#include"bstTree.h"

typedef struct BiThrNode{
  int data;
  BiThrNode *lchild,*rchild;
  int lTag,rTag;
}BiThrNode,*BiThrTree;

BiThrTree creatTree(){
  int d;
  scanf("%d",&d);
  if(d==-1){
    return nullptr;
  }
  BiThrNode *p=new(BiThrNode);
  p->data=d;
  p->lTag=0;
  p->rTag=0;
  p->lchild=creatTree();
  p->rchild=creatTree();
  return p;
}

BiThrNode *pre=nullptr;

void InOrderCreat(BiThrTree t){
  if(t==nullptr){
    return;
  }
  InOrderCreat(t->lchild);

  if(t->lchild==nullptr){
    t->lchild=pre;
    t->lTag=1;
  }
  if(pre!=nullptr&&pre->rchild==nullptr){
    pre->rchild=t;
    pre->rTag=1;
  }
  pre=t;
  InOrderCreat(t->rchild);
}

BiThrNode * getSuccessor(BiThrNode *p){
  if(p==nullptr){
    return nullptr;
  }
  while(p->lTag==0&&p->lchild!=nullptr){
    p=p->lchild;
  }
  return p;
}

void InOrderTraversal(BiThrTree t){
  if(t==nullptr){
    return;
  }
  BiThrNode *p=getSuccessor(t);
  while(p!=nullptr){
    printf("%d ",p->data);
    if(p->rTag==1){
      p=p->rchild;
    }else{
      p=getSuccessor(p->rchild);
    }
  }
}

int main(){
  BiThrTree t=creatTree();
  InOrderCreat(t);
  InOrderTraversal(t);
  return 0;
}