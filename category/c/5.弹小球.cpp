/*
  小球从10m处落下，每次弹回原来高度的一半，求
  静止前一共走了多少距离
*/
#include"proto.h"

int main(){
  double a=10,sum=10;
  a/=2;
  while(a>0){
    sum+=(a*2);
    a/=2;
  } 
  printf("%f\n",sum);
  return 0;
}