//
// Created by haiyun on 2023/7/17.
//


#include "List.h"
using namespace std;

void ListTest(){
    LinkList L1,L2;
    ListHeadInsert(L1);
    ListTailInsert(L2);
    cout<<ListLength(L1)<<endl;

    cout<<GetElem(L1,4)->data<<endl;
    cout<<GetElem(L2,4)->data<<endl;

    cout<<LocateElem(L2,3)->data<<endl;

    LNode *s =(LNode*) malloc(sizeof (LNode));
    s->next=NULL;
    s->data=8;
    ListInsert(L1,3,s);
    for(int i=1;i<= ListLength(L1);i++){
        cout<<GetElem(L1,i)->data<<" ";
    }
    cout<<endl;

    ListDelete(L2,4);
    for(int i=1;i<= ListLength(L2);i++){
        cout<<GetElem(L2,i)->data<<" ";
    }
    cout<<endl;
}