//
// Created by meguriri on 2023/7/16.
//

#include "Queue.h"

void InitQueue(SqQueue &q){
    q.front=q.rear=0;
}

bool QueueEmpty(SqQueue q){
    return q.front==q.rear;
}

bool EnQueue(SqQueue & q,ElemType x){
    if((q.rear+1)%MaxSize==q.front)
        return false;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue &q,ElemType &x){
    if(q.rear==q.front)
        return false;
    x=q.data[q.front];
    q.front=(q.front+1)%MaxSize;
    return true;
}

bool GetHead(SqQueue q,ElemType &x){
    if(q.rear==q.front)
        return false;
    x=q.data[q.front];
    return true;
}
