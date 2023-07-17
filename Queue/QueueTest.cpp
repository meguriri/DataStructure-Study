//
// Created by haiyun on 2023/7/17.
//
#include "Queue.h"
using namespace std;

void QueueTest(){
    SqQueue q;
    InitQueue(q);

    cout<<QueueEmpty(q)<<endl;

    int x=5;
    cout<<EnQueue(q,5)<<endl;
    cout<<EnQueue(q,6)<<endl;
    cout<<EnQueue(q,7)<<endl;
    cout<<EnQueue(q,8)<<endl;
    cout <<QueueEmpty(q)<<endl;

    cout<<GetHead(q,x)<<" "<<x<<endl;
    cout<<DeQueue(q,x)<<" "<<x<<endl;
    cout<<GetHead(q,x)<<" "<<x<<endl;

    cout<<DeQueue(q,x)<<" "<<x<<endl;
    cout<<DeQueue(q,x)<<" "<<x<<endl;
    cout<<DeQueue(q,x)<<" "<<x<<endl;
    cout<<GetHead(q,x)<<" "<<x<<endl;
}