/*
  输出二叉树所有节点平衡因子。并输出非叶子节点个数
  1 2 3 4 6 -1 -1 -1 -1 5 -1 -1 7 8 9 -1 -1 -1 10 -1 11 -1 -1
*/

#include<cstdio>
#include<cstdlib>
#include<cmath>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bitTree CreatBitTree(){
  int c;
  scanf("%d",&c);
  if(c==-1){
    return nullptr;
  }
  bitNode*t =new(bitNode);
  t->d=c;
  t->l=CreatBitTree();
  t->r=CreatBitTree();
  return t;
}

int cnt=0;

int getBanlance(bitTree t){
  if(t==nullptr){
    return 0;
  }
  if(t->l!=nullptr||t->r!=nullptr){
    cnt++;
  }
  int l=getBanlance(t->l);
  int r=getBanlance(t->r);
  printf("%d:%d\n",t->d,abs(l-r));
  int max=l>=r?l:r;
  return max+1;
}

int main(){
  bitTree t=CreatBitTree();
  getBanlance(t);
  printf("%d\n",cnt);
  return 0;
}