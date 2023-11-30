/*
  给出二叉树的先序序列和中序序列的数组，以此建立该二叉树的二叉链表
*/

#include<cstdio>
#include<cstdlib>

typedef struct node{
  char d;
  node *l,*r;
}bitNode,*bitTree;

void preOrderTraversal(bitTree t){
  if(t==nullptr){
    return;
  }
  printf("%d ",t->d);
  preOrderTraversal(t->l);
  preOrderTraversal(t->r);
}

bitTree CreatTree(char *s1,int l1,int r1,char *s2,int l2,int r2){
  if(l1>r1){
    return nullptr;
  }
  bitNode *p=new(node);
  p->d=s1[l1];
  int k;
  for(int i=l2;i<=r2;i++){
    if(s2[i]==s1[l1]){
      k=i;
      break;
    }
  }
  p->l=CreatTree(s1,l1+1,l1+k-l2,s2,l2,k-1);
  p->r=CreatTree(s1,l1+k-l2+1,r1,s2,k+1,r2);
  return p; 
}

int main(){
  char s1[8]="1234567";
  char s2[8]="3241657";
  bitTree t=CreatTree(s1,0,6,s2,0,6);
  preOrderTraversal(t);
  return 0;
}