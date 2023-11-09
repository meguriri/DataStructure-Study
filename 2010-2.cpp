/*
  编写后续遍历算术二叉树，计算表达式值的算法
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  char c;
  node *l,*r;
}bitNode,*bitTree;

int calc(bitTree t){
  if(t->l==nullptr&&t->r==nullptr){
    return (int)(t->c-'0');
  }
  int l=calc(t->l),r=calc(t->r),ans=0;
  if(t->c=='+'){
    ans=l+r;
  }else if(t->c=='-'){
    ans=l-r;
  }else if(t->c=='*'){
    ans=l*r;
  }else if(t->c=='/'){
    ans=l/r;
  }
  return ans;
}

int main(){

  return 0;
}