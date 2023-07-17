//
// Created by meguriri on 2023/7/16.
//
#include "Stack.h"
using namespace std;

void StackTest(){
    SqStack s;
    InitStack(s);

    cout <<StackEmpty(s)<<endl;

    int x=5;
    cout<<Push(s,5)<<endl;
    cout<<Push(s,6)<<endl;
    cout<<Push(s,7)<<endl;
    cout<<Push(s,8)<<endl;
    cout <<StackEmpty(s)<<endl;

    cout<<GetTop(s,x)<<" "<<x<<endl;
    cout<<Pop(s,x)<<" "<<x<<endl;
    cout<<GetTop(s,x)<<" "<<x<<endl;

    cout<<Pop(s,x)<<" "<<x<<endl;
    cout<<Pop(s,x)<<" "<<x<<endl;
    cout<<Pop(s,x)<<" "<<x<<endl;
    cout<<GetTop(s,x)<<" "<<x<<endl;
    cout<<GetTop(s,x)<<" "<<x<<endl;
}