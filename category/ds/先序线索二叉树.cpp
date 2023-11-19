/*
  右孩子不存在，将右指针指向先序序列的直接后继
  如果左孩子不存在，将左指针指向先序序列的直接前驱
  eg1.
  1 2 3 -1 -1
  4 -1 -1 5 6
  -1 8 9 -1 -1
  -1 10 -1 11 -1 -1

  eg2 
  1 -1 2 -1 3 -1 -1
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

//构建先序线索二叉树
BiThrNode *pre =nullptr;
void preOrder(BiThrNode *p){
  if(p==nullptr){
    return;
  }
  if(p->lchild==nullptr){
    p->lTag=1;
    p->lchild=pre;
  }
  if(pre!=nullptr&&pre->rchild==nullptr){
    pre->rTag=1;
    pre->rchild=p;
  }
  pre=p;
  if(p->lTag==0){
     preOrder(p->lchild);
  }
  if(p->rTag==0){
     preOrder(p->rchild);
  }
}

void creatBiThrTree(BiThrTree T){
  preOrder(T);
}

void preOrderTravers(BiThrTree t){
  BiThrNode *p=t;
  while(p!=nullptr){
    printf("%d ",p->data);
    if(p->lTag==0&&p->lchild!=nullptr){
      p=p->lchild;
    }else{
      p=p->rchild; 
    } 
  }
}

int main(){
  BiThrTree t=creatTree();
  creatBiThrTree(t);
  preOrderTravers(t);
  return 0;
}