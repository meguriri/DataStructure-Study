/*
假设二叉树中止为x的节点不少于1个，采用二叉链表存储。编写算法，打印值为x的节点的所有祖先
eg. 1 2 7 -1 -1 -1 4 5 -1 7 -1 -1 6 -1 7 -1 -1
*/
#include"bitTree.h"

int ans[100]={0};
int n=0;
void getAncestors(bitTree t,int x){
  if(t==nullptr){
    return;
  }
  if(t->d==x){
    for(int i=n-1;i>=0;i--){
      printf("%d ",ans[i]);
    }
    printf("\n");
    return;
  }
  ans[n++]=t->d;
  getAncestors(t->l,x);
  getAncestors(t->r,x);
  n--;
}

int main(){
  bitTree t=creatBitTree();
  getAncestors(t,7);
  return 0;
}
