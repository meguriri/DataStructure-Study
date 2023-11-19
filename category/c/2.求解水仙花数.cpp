/*
  求解1-20000内的水仙花数
  水仙花数：每位数字的n次方之和等于本身，n是这个数的位数
*/
#include"proto.h"

void getFlowerNum(){
  for(int i=1;i<=20000;i++){
    int a[5]={0,0,0,0,0},x=i,cnt=0;
    while(x){
      a[cnt++]=x%10;
      x/=10;
    }
    int n=cnt,sum=0;
    for(int j=0;j<cnt;j++){
      sum+=int(pow(a[j],n));
    }
    if(i==sum){
      printf("%d\n",i);
    }
  }
}

int main(){
  getFlowerNum();
  return 0;
}