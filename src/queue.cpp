#include"queue.h"

void initQueue(queue &q){
  q.front=0;
  q.rear=0;
}

int isQueueEmpty(queue q){
  if(q.front==q.rear){
    return 1;
  }
  return 0;
}

int enQueue(queue &q,ElemType x){
  if((q.rear+1)%N==q.front){
    return 0;
  }
  q.d[q.rear]=x;
  q.rear=(q.rear+1)%N;
  return 1;
}

int deQueue(queue &q,ElemType &x){
  if(q.front==q.rear){
    return 0;
  }
  x=q.d[q.front];
  q.front=(q.front+1)%N;
  return 1;
}

int getFront(queue q,ElemType &x){
  if(isQueueEmpty(q)){
    return 0;
  }
  x=q.d[q.front];
  return 1;
}
