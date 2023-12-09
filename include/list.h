#ifndef LIST_H
#define LIST_H
#include"proto.h"

typedef struct node{
  int d;
  node *next;
}node,*list;

list creatList(int [],int);
void printList(list);
list creastCirList(int [],int);
void printCirList(list);
#endif