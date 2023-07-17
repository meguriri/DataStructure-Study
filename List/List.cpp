//
// Created by haiyun on 2023/7/17.
//

#include "List.h"

//头插法建立链表
LinkList ListHeadInsert(LinkList &L){
    LNode *p;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i=1;i<=6;i++){
        p=(LNode*)malloc(sizeof(LNode));
        p->data=i;
        p->next=L->next;
        L->next=p;
    }
    return L;
}
//尾插法建立链表
LinkList ListTailInsert(LinkList &L){
    LNode *p,*t;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    t=L;
    for(int i=1;i<=6;i++){
        p=(LNode*)malloc(sizeof(LNode));
        p->data=i;
        p->next=NULL;
        t->next=p;
        t=p;
    }
    return L;
}
//获取第i个结点
LNode* GetElem(LinkList L,int i){
    if(i<1)
        return NULL;
    LNode *p=L->next;
    for(int j=1;j<i&&p!=NULL;j++){
        p=p->next;
    }
    return p;
}
//获取值为e的结点
LNode* LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}
//在位置i上插入结点s
void ListInsert(LinkList &L,int i,LNode *s){
    LNode *p=L->next;
    for(int j=1;j<i-1&&p!=NULL;j++){
        p=p->next;
    }
    s->next=p->next;
    p->next=s;
}
//删除位置i的结点
void ListDelete(LinkList &L,int i){
    LNode *p=L->next;
    for(int j=1;j<i-1&&p!=NULL;j++){
        p=p->next;
    }
    LNode *q=p->next;
    p->next=q->next;
    free(q);
}

//获取表长
int ListLength(LinkList L){
    int length=0;
    LNode *p=L->next;
    while(p!=NULL){
        p=p->next;
        length++;
    }
    return length;
}