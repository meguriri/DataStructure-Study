/*
  查找二叉树T中第k层中度为1的节点的数量
  1 2 4 7 -1 -1 8 -1 -1 5 9 -1 -1 -1 3 6 -1 10 -1 -1 -1
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

int getDegree(bitTree t,int k,int s){
  if(t==nullptr){
    return 0;
  }
  if(s==k){
    if((t->l==nullptr&&t->r!=nullptr)||(t->l!=nullptr&&t->r==nullptr)){
      return 1;
    }
    return 0;
  }
  return getDegree(t->l,k,s+1)+getDegree(t->r,k,s+1);
}

void solve(bitTree t,int k){
  printf("%d\n",getDegree(t,k,1));
}

int main(){
  bitTree t=creatBitTree();
  solve(t,3);
  return 0;
}