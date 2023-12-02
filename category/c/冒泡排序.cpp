#include<cstdio>

void bubbleSort(int a[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=1;j<n-i;j++){
      if(a[j-1]>a[j]){
        int t=a[j];
        a[j]=a[j-1];
        a[j-1]=t;
      }
    }
  }
}

int main(){
  int a[10]={6,2,8,5,3,0,9,4,1,7};
  bubbleSort(a,10);
  for(int i=0;i<10;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}