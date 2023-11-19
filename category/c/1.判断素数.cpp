/*
  判断素数
*/
#include"proto.h"

int isPrime(int num){
  if(num==1){
    return 0;
  }
  for(int i=2;i<=sqrt(num);i++){
    if(num%i==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int num;
  scanf("%d",&num);
  printf("%d\n",isPrime(num));
  return 0;
}
