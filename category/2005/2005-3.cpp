/*
打印数据域为x的节点的祖先的数据域
  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

int f=0;

bitTree creatBitTree(){
  bitNode *t=new(node);
  int x;
  scanf("%d",&x);
  if(x=='!'){
    return nullptr;
  }
  t->d=x;
  t->l=creatBitTree();
  t->r=creatBitTree();
  return t;
}

void findAncestor(bitTree t,int k){
  if(t==nullptr){
    return;
  }
  if(t->d==k){
    f=1;
    return;
  }
  if(f==0){
    findAncestor(t->l,k);
  }
  if(f==0){
    findAncestor(t->r,k);
  }
  if(f==1){
    printf("%d ",t->d);
  }
}

int main(){
  bitTree t=creatBitTree();
  findAncestor(t,7);
  return 0;
}