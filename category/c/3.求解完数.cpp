/*
  求解2-20000的完数，
  完数：真因数的和等于本身数字的数
*/
#include"proto.h"

int isWan(int num){
  int sum=0;
  for(int i=1;i<num;i++){
    if(num%i==0){
      sum+=i;
    }
  }
  if(sum==num){
    return 1;
  }
  return 0;
}

int main(){
  for(int i=2;i<=20000;i++){
    if(isWan(i)){
      printf("%d\n",i);
    }
  }
  return 0;
}