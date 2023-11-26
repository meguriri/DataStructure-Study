/*
  已知线索二叉树T，编写算法对它进行先序遍历
  eg1.
  1 2 3 -1 -1
  4 -1 -1 5 6
  -1 8 9 -1 -1
  -1 10 -1 11 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct BiThrNode{
  int data;
  struct BiThrNode *lchild,*rchild;
  int lTag,rTag;//0为孩子，1为线索
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
void PreOrderCreat(BiThrNode *t){
  if(t==nullptr){
    return;
  }
  if(t->lchild==nullptr){
    t->lchild=pre;
    t->lTag=1;
  }
  if(pre!=nullptr&&pre->rchild==nullptr){
    pre->rchild=t;
    pre->rTag=1;
  }
  pre=t;
  if(t->lTag==0){
    PreOrderCreat(t->lchild);
  }
  if(t->rTag==0){
    PreOrderCreat(t->rchild);
  }
}

void PreOrderTraversal(BiThrTree t){
  BiThrNode *p=t;
  while(p!=nullptr){
    printf("%d ",p->data);
    if(p->lTag==0&&p->lchild!=nullptr){
      p=p->lchild;
    }else{
      p=p->rchild;
    }
  }
  printf("\n");
}

int main(){
  BiThrTree t=creatTree();
  PreOrderCreat(t);
  PreOrderTraversal(t);
  return 0;
}