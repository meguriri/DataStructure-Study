#ifndef QUEUE_H
#define QUEUE_H
#include"proto.h"
#include"bitTree.h"

typedef bitNode* ElemType ;
typedef struct queue{
  ElemType d[N];
  int front,rear;
}queue;



void initQueue(queue &q);
int isQueueEmpty(queue q);
int enQueue(queue &q,ElemType x);
int deQueue(queue &q,ElemType &x);
int getFront(queue q,ElemType &x);

#endif
