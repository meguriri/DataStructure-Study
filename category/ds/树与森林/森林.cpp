#include<cstdio>
#include<cstdlib>

typedef struct CSTNode{
  int data;
  CSTNode *firstChild,*nextSibling;
}CSTNode,*CSTree;

//有争议！！！！

//先序遍历森林
void preOrderTraversal(CSTree t){
  if(t==nullptr){
    return;
  }
  printf("%d ",t->data);
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    preOrderTraversal(p);
  }
  //先序遍历下一棵树
  preOrderTraversal(t->nextSibling);
}

//中序遍历森林
void postOrderTraversal(CSTree t){
  if(t==nullptr){
    return;
  }
  for(CSTNode *p=t->firstChild;p!=nullptr;p=p->nextSibling){
    postOrderTraversal(p);
  }
  printf("%d ",t->data);
  //中序遍历下一棵树
  postOrderTraversal(t->nextSibling);
}

int main(){

  return 0;
}