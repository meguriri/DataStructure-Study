/*
  二叉排序树的删除
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bool insertBstTree(bitTree &t,int k){
  if(t==nullptr){
    t=new(node);
    t->d=k;
    t->l=nullptr;
    t->r=nullptr;
    return true;
  }
  if(k<t->d){
    return insertBstTree(t->l,k);
  }
  if(k>t->d){
    return insertBstTree(t->r,k);
  }
  if(k==t->d){
    return false;
  }
}

void createBstTree(bitTree &t,int a[],int n){
  for(int i=0;i<n;i++){
    if(!insertBstTree(t,a[i])){
      printf("create error!\n");
      break;
    }
  }
} 

bitNode* findRearNode(bitNode *t){
  bitNode *p=t;
  while(p->l!=nullptr){
    p=p->l;
  }
  return p;
}

void deleteBstNode(bitTree &t,int k){
  if(k==t->d){
    //待删的是叶子节点
    if(t->l==nullptr&&t->r==nullptr){
      t=nullptr;
    }
    //只有左子树
    else if(t->l!=nullptr&&t->r==nullptr){
      t=t->l;
    }
    //只有右子树
    else if(t->l==nullptr&&t->r!=nullptr){
      t=t->r;
    }
    else{
      bitNode *r=findRearNode(t->r);
      deleteBstNode(t,r->d);
      t->d=r->d;
    }
  }
  else if(k<t->d){
    deleteBstNode(t->l,k);
  }
  else if(k>t->d){
    deleteBstNode(t->r,k);
  }
}

void preOrderTraversal(bitTree t){
  if(t==nullptr)
    return;
  printf("%d ",t->d);
  preOrderTraversal(t->l);
  preOrderTraversal(t->r);
}

int main(){
  int a[10]={5,8,1,3,10,12,11,25,16,9};
  bitTree t;
  createBstTree(t,a,10);
  preOrderTraversal(t);
  printf("\n");
  deleteBstNode(t,5);
  printf("\n");
  preOrderTraversal(t);
  return 0;
}