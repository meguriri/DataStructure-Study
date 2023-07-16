//
// Created by meguriri on 2023/7/16.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "../Basic/Basic.h"

#define MaxSize 10

//顺序栈的定义
typedef struct {
    ElemType data[MaxSize];//栈元素
    int top;//栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack&);
//判断栈是否为空
bool StackEmpty(SqStack);
//入栈
bool Push(SqStack&,ElemType);
//出栈
bool Pop(SqStack&,ElemType&);
//获取栈顶元素值
bool GetTop(SqStack,ElemType&);

//栈功能测试
void StackTest();

#endif //DATASTRUCTURE_STACK_H
