/*
  循环队列，设置头指针front和队列节点个数count，写出判空，入队，出队的函数
*/

#include<cstdio>
#include<cstdlib>
#define M 5

struct queue{
  int a[M];
  int front;
  int count;
};

bool isEmpty(queue q){
  return q.count==0;
}

bool push(queue &q,int k){
  if(q.count==M){
    return false;
  }
  q.a[(q.front+q.count)%M]=k;
  q.count++;
  return true;
}

bool pop(queue &q,int &x){
  if(q.count==0){
    return false;
  }
  x=q.a[q.front];
  q.front=(q.front+1)%M;
  q.count--;
  return true;
}

void print(queue q){
  for(int i=0;i<M;i++){
    printf("%d ",q.a[i]);
  }
  printf("\n");
}
int main(){
  queue q;
  q.count=0;
  q.front=0;
  printf("%d\n",isEmpty(q));
  for(int i=1;i<=5;i++){
    push(q,i);
  }
  print(q);
  printf("%d\n",isEmpty(q));
  for(int i=1;i<=4;i++){
    int x=0;
    pop(q,x);
    printf("%d ",x);
  }
  printf("\n");
  print(q);
  for(int i=6;i<=8;i++){
    push(q,i);
  }
  print(q);
  return 0;
}