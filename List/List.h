//
// Created by haiyun on 2023/7/17.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include "../Basic/Basic.h"

//单链表
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//头插法建立链表
LinkList ListHeadInsert(LinkList &L);
//尾插法建立链表
LinkList ListTailInsert(LinkList &L);
//获取第i个结点
LNode* GetElem(LinkList L,int i);
//获取值为e的结点
LNode* LocateElem(LinkList L,ElemType e);
//在位置i上插入结点s
void ListInsert(LinkList &L,int i,LNode *s);
//删除位置i的结点
void ListDelete(LinkList &L,int i);
//获取表长
int ListLength(LinkList L);

//单链表功能测试
void ListTest();

#endif //DATASTRUCTURE_LIST_H
