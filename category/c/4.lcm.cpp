/*
  输入n，m，输出m，n的最小公倍数
*/
#include"proto.h"

int gcd(int a,int b){ 
  return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
  int g=gcd(a,b);
  return a*b/g;
}

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  printf("%d\n",lcm(n,m));
  return 0;
}