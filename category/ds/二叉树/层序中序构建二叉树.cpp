#include"bitTree.h"

bitTree CreatBitTree(char floor[],int fl,int fr,char in[],int il,int ir){
  if(il>ir){
    return nullptr;
  }
  bitNode *p=new(bitNode);
  p->d=floor[fl];
  int k;
  for(int i=il;i<=ir;i++){
    if(floor[fl]==in[i]){
      k=i;
      break;
    }
  } 
  //find left 
  char leftArray[N];int leftN=0;
  for(int i=fl+1;i<=fr;i++){
    for(int j=il;j<=k-1;j++){
      if(floor[i]==in[j]){
        leftArray[leftN++]=floor[i];
      }
    }
  }
  //find right
  char rightArray[N];int rightN=0;
  for(int i=fl+1;i<=fr;i++){
    for(int j=k+1;j<=ir;j++){
      if(floor[i]==in[j]){
        rightArray[rightN++]=floor[i];
      }
    }
  }
  p->l=CreatBitTree(leftArray,0,leftN-1,in,il,k-1);
  p->r=CreatBitTree(rightArray,0,rightN-1,in,k+1,ir);
  return p;
}

int main(){
  char floor[]="ABCDEFGH",in[]="BDAEHGCF";
  bitTree t=CreatBitTree(floor,0,8,in,0,8);
  preOrderTraversal(t);
  return 0;
}