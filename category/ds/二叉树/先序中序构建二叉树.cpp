#include"bitTree.h"

bitTree CreatBitTree(char pre[],int pl,int pr,char in[],int il,int ir){
  if(pl>pr){
    return nullptr;
  }
  char root=pre[pl];
  int k=-1;
  for(int i=il;i<=ir;i++){
    if(in[i]==root){
      k=i;
      break;
    }
  }
  bitNode *p=new(bitNode);
  p->d=root;
  p->l=CreatBitTree(pre,pl+1,pl+(k-il),in,il,k-1);
  p->r=CreatBitTree(pre,pl+(k-il)+1,pr,in,k+1,ir);
  return p;
}

int main(){
  char pre[9]="ABDCEGHF",in[9]="BDAEHGCF";
  bitTree t=CreatBitTree(pre,0,8,in,0,8);
  preOrderTraversal(t);
  return 0;
}