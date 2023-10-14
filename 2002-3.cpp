/*
  不带头字符链表。构造三个带头循环链表，一个存英文字母，一个存数字，一个存其他字符
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>

typedef struct node{
  char c;
  node *next;
}node,*list;

node* creatList(char *s,int n){
  node *h=nullptr,*t=h;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->c=s[i];
    p->next=nullptr;
    if(h==nullptr){
      h=p;
    }else{
      t->next=p;
    }
    t=p;
  }
  return h;
}

void printList(list h){
  node *p=h;
  while(p!=nullptr){
    printf("%c ",p->c);
    p=p->next;
  }
  printf("\n");
}

void creatLoopList(list h,list &wh,list &nh,list &oh){
  node *p=h;
  while(p!=nullptr){
    node *now=new(node);
    now->c=p->c;
    now->next=nullptr;
    if((p->c>='A'&&p->c<='Z')||(p->c>='a'&&p->c<='z')){
      now->next=wh->next;
      wh->next=now;
    }else if(p->c>='0'&&p->c<='9'){
      now->next=nh->next;
      nh->next=now;
    }else{
      now->next=oh->next;
      oh->next=now;
    }
    p=p->next;
  }
}

void printLoopList(list h){
  node *p=h->next;
  while(p!=h){
    printf("%c ",p->c);
    p=p->next;
  }
  printf("\n");
}

int main(){
  char *s="ab@C12d3eFg56#1)";
  list l=creatList(s,strlen(s));

  list wordList=new(node),numList=new(node),otherList=new(node);
  wordList->next=wordList;
  numList->next=numList;
  otherList->next=otherList;

  creatLoopList(l,wordList,numList,otherList);
  printLoopList(wordList);
  printLoopList(numList);
  printLoopList(otherList);
  return 0;
}