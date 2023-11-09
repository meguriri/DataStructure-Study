/*
  求二叉排序树的各节点的平衡因子
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

void preOrderTraversal(bitTree t){
  if(t==nullptr)
    return;
  printf("%d ",t->d);
  preOrderTraversal(t->l);
  preOrderTraversal(t->r);
}

//获取深度
int getHigh(bitTree t){
  if(t==nullptr){
    return 0;
  }
  int l=1+getHigh(t->l);
  int r=1+getHigh(t->r);

  //这个输出其实就是平衡因子，因为节点的深度是左右子树最大深度+1，平衡因子是左子树深度-右子树深度，求的l和r其实就是左右子树深度
  printf("%d: %d\n",t->d,l-r);
  
  return l>=r?l:r;
}


//标准版
void countBalance(bitTree t){
  if(t==nullptr){
    return;
  }
  int l=getHigh(t->l),r=getHigh(t->r);
  printf("%d: %d\n",t->d,l-r);
  countBalance(t->l);
  countBalance(t->r);
}

int main(){
  int a[10]={5,8,1,3,10,12,11,25,16,9};
  bitTree t;
  createBstTree(t,a,10);
  preOrderTraversal(t);
  printf("\n");
  
  //countBalance(t);
  getHigh(t);
  return 0;
}