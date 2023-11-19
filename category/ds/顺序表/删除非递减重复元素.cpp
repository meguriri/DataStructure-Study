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

void deleteElem(SqList &l){
  int nl=0;
  for(int i=0;i<l.length;i++){
    int e=l.list[i];
    if(nl==0||l.list[i-1]!=e){
      l.list[nl++]=e;
    }
  }
  l.length=nl;
}

int main(){
  SqList l={
    {1,2,3,3,4,4,5,5,5,6,7,8,8},
    13,
  };
  deleteElem(l);
  for(int i=0;i<l.length;i++){
    printf("%d ",l.list[i]);
  }
  printf("\n");
  return 0;
}