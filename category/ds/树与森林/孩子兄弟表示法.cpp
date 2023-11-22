#include<cstdio>
#include<cstdlib>
#include<cmath>

typedef struct CSTNode{
  int data;
  CSTNode *firstChild,*nextSibling;
}CSTNode,*CSTree;

CSTree getCSTree(){
  CSTree t;
  t=new(CSTNode);
  t->data=1;
  t->firstChild=new(CSTNode);
  t->nextSibling=nullptr;
  t->firstChild->data=2;
  t->firstChild->nextSibling=new(CSTNode);
  t->firstChild->nextSibling->data=3;
  t->firstChild->nextSibling->nextSibling=nullptr;
  t->firstChild->nextSibling->firstChild=new(CSTNode);
  t->firstChild->nextSibling->firstChild->data=7;
  t->firstChild->nextSibling->firstChild->firstChild=nullptr;
  t->firstChild->nextSibling->firstChild->nextSibling=nullptr;
  t->firstChild->firstChild=new(CSTNode);
  t->firstChild->firstChild->data=4;
  t->firstChild->firstChild->firstChild=nullptr;
  t->firstChild->firstChild->nextSibling=new(CSTNode);
  t->firstChild->firstChild->nextSibling->data=5;
  t->firstChild->firstChild->nextSibling->firstChild=nullptr;
  t->firstChild->firstChild->nextSibling->nextSibling=new(CSTNode);
  t->firstChild->firstChild->nextSibling->nextSibling->data=6;
  t->firstChild->firstChild->nextSibling->nextSibling->firstChild=nullptr;
  t->firstChild->firstChild->nextSibling->nextSibling->nextSibling=nullptr;
  return t;
}

//先根遍历
void preOrderTraversal(CSTree t){
  if(t==nullptr){
    return;
  }
  printf("%d ",t->data);
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    preOrderTraversal(p);
  }
}

//后根遍历
void postOrderTraversal(CSTree t){
  if(t==nullptr){
    return;
  }
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    postOrderTraversal(p);
  }
  printf("%d ",t->data);
}

//计算树的叶子节点个数
int leafsNum = 0;
void getLeafsNum(CSTree t){
  if(t->firstChild==nullptr){
    leafsNum++;
    return;
  }
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    getLeafsNum(p);
  }
}

//计算树的度
int getDegree(CSTree t){
  if(t==nullptr){
    return 0;
  }
  int max=-1,cnt=0;
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    int d=getDegree(p);
    cnt++;
    max=max>d?max:d;
  }
  return max>cnt?max:cnt;
}

//计算树的深度
int getHigh(CSTree t){
  if(t==nullptr){
    return 0;
  }
  int h=0;
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    int now=getHigh(p);
    h=h>now?h:now;
  }
  return h+1;
}

int main(){
  CSTree t=getCSTree();
  preOrderTraversal(t);
  printf("\n");
  postOrderTraversal(t);
  printf("\n");
  getLeafsNum(t);
  printf("%d\n",leafsNum);
  printf("%d\n",getDegree(t));
  printf("%d\n",getHigh(t));
  return 0;
}