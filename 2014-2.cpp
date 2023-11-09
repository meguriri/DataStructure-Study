/*
  求以x为根的子树的深度
  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  int d;
  node *l,*r;
}bitNode,*bitTree;

bitTree CreatBitTree(){
  int d;
  scanf("%d",&d);
  if(d==-1){
    return nullptr;
  }
  bitNode*t =new(bitNode);
  t->d=d;
  t->l=CreatBitTree();
  t->r=CreatBitTree();
  return t;
}


int getXHigh(bitTree t,int x,bool f){
  if(t==nullptr){
    return 0;
  }
  int l,r;
  if(t->d==x||f==true){
    l=getXHigh(t->l,x,true)+1;
    r=getXHigh(t->r,x,true)+1;
  }else{
    l=getXHigh(t->l,x,false);
    r=getXHigh(t->r,x,false);
  }
  return l>=r?l:r;
}

int main(){
  bitTree t=CreatBitTree();
  printf("%d\n",getXHigh(t,3,false));
  return 0;
}