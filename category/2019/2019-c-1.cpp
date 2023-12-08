#include<cstdio>

void solve(int n){
  for(int i=0;i<=n;i++){
    int n1=i,n2=i*i,f=0;
    while(n1&&n2){
      if(n1%10!=n2%10){
        f++;
        break;
      }
      n1/=10;
      n2/=10;
    }
    if(f==0){
      printf("%d\n",i);
    }
  }
}

int main(){
  solve(10000);
  return 0;
}