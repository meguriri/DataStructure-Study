//
// Created by meguriri on 2023/7/16.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include "../Basic/Basic.h"

#define MaxSize 10

//顺序队列定义
typedef struct {
    ElemType data[MaxSize];//队列元素
    int front,rear;//队头，队尾指针
}SqQueue;

//初始化队列
void InitQueue(SqQueue&);
//判断队列是否为空
bool QueueEmpty(SqQueue);
//入队
bool EnQueue(SqQueue&,ElemType);
//出队
bool DeQueue(SqQueue&,ElemType&);
//获取队首元素
bool GetHead(SqQueue,ElemType&);

//队列功能测试
void QueueTest();

#endif //DATASTRUCTURE_QUEUE_H
