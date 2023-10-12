/*
  算数表达式转化成二叉树，并根据该二叉树算出表达式的值
  eg: ((a+b)+c*(d+e)+f)*(g+h)
  *++*+1..2..3..+4..5..6..+7..8..
*/

#include<cstdio>
#include<cstdlib>
int k=0;
typedef struct node{
  char c;
  node *l,*r;
}bitNode,*bitTree;

bitTree CreatBitTree(){
  char c;
  scanf("%c",&c);
  if(c=='.'){
    return nullptr;
  }
  bitNode*t =new(bitNode);
  t->c=c;
  t->l=CreatBitTree();
  t->r=CreatBitTree();
  return t;
}

void preOrderTraversal(bitTree t){
  if(t==nullptr)
    return;
  printf("%c ",t->c);
  preOrderTraversal(t->l);
  preOrderTraversal(t->r);
}

//!!!
int CalculateBitTree(bitTree t){
  if(t->l==nullptr&&t->r==nullptr){
    return (int)(t->c-'0');
  }
  int v1=CalculateBitTree(t->l),v2=CalculateBitTree(t->r);
  if(t->c=='+'){
    return v1+v2;
  }else if(t->c=='-'){
    return v1-v2;
  }else if(t->c=='*'){
    return v1*v2;
  }else if(t->c=='/'){
    return v1/v2;
  }
}

int main(){
  bitTree t=CreatBitTree();
  preOrderTraversal(t);
  printf("\n");
  printf("%d\n",CalculateBitTree(t));
  return 0;
}