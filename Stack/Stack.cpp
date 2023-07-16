//
// Created by meguriri on 2023/7/16.
//

#include "Stack.h"

void InitStack(SqStack &s){
    s.top=0;
}

bool StackEmpty(SqStack s){
    return s.top==0;
}

bool Push(SqStack &s,ElemType x){
    if(s.top==MaxSize)
        return false;
    s.data[s.top++]=x;
    return true;
}

bool Pop(SqStack &s,ElemType &x){
    if(s.top==0)
        return false;
    x=s.data[--s.top];
    return true;
}

bool GetTop(SqStack s,ElemType &x){
    if(s.top==0)
        return false;
    x=s.data[s.top-1];
    return true;
}
