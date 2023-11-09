/*
  二叉链表存储的二叉树，从右向左删除叶子节点，并将节点值放到一个数组中
  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bitTree creatBitTree(){
  bitNode *t=new(node);
  int x;
  scanf("%d",&x);
  if(x==-1){
    return nullptr;
  }
  t->d=x;
  t->l=creatBitTree();
  t->r=creatBitTree();
  return t;
}

void preOrderTraversal(bitTree t){
  if(t==nullptr){
    return;
  }
  printf("%d ",t->d);
  preOrderTraversal(t->l);
  preOrderTraversal(t->r);
}


void deleteLeaf(bitTree &t,int a[],int &cnt){
  if(t->l==nullptr&&t->r==nullptr){
    a[cnt++]=t->d;
    delete(t);
    t=nullptr;
    return;
  }
  deleteLeaf(t->r,a,cnt);
  deleteLeaf(t->l,a,cnt);
}

int main(){
  bitTree t=creatBitTree();
  preOrderTraversal(t);
  printf("\n");

  int leaf[10],cnt=0;
  deleteLeaf(t,leaf,cnt);

  preOrderTraversal(t);
  printf("\n");

  for(int i=0;i<cnt;i++){
    printf("%d ",leaf[i]);
  }
  printf("\n");

  return 0;
}