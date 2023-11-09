/*
  线性表，负数移动到正数前面
*/

#include<cstdio>
#include<cstdlib>

void move(int a[],int n){
  int l=0,r=n-1;
  while(l<r){
    while(l<r&&a[r]>=0){
      r--;
    }
    while(l<r&&a[l]<0){
      l++;
    }
    if(l<r){
      int t=a[l];
      a[l]=a[r];
      a[r]=t;
    }
  }
}

int main(){
  int a[10]={-4,-2,3,4,5,-6,-7,8,-2,10};
  move(a,10);
  for(int i=0;i<10;i++)
    printf("%d ",a[i]);
  return 0;
}