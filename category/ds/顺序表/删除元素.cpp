/*
  在无序顺序表中，删除s和t之间的所有元素
*/
#include<cstdio>
#include<cstdlib>
#define MAX_SIZE 100

typedef int ElemType;
typedef struct SqList{
  ElemType list[MAX_SIZE];
  int length;
}SqList;

void deleteElem(int s,int t,SqList &l){
  int nl=0;
  for(int i=0;i<l.length;i++){
    if(l.list[i]<s||l.list[i]>t){
      l.list[nl++]=l.list[i];
    }
  }
  l.length=nl;
}

int main(){
  SqList l={
    {2,3,4,5,6,7},
    6
  };
  deleteElem(3,5,l);
  for(int i=0;i<l.length;i++){
    printf("%d ",l.list[i]);
  }
  printf("\n");
  return 0;
}