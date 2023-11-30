/*
  每层遇到空之后都是空
  eg1.
  1 2 4 -1 -1 5 -1 -1 3 -1 -1

  eg2.
  1 2 3 -1 -1 -1 4 -1 5 -1 -1

  eg3.
  1 2 3 -1 -1 4 -1 -1 -1

  eg4.
  1 2 4 6 -1 -1 -1 5 -1 -1 3 -1 -1
*/
#include"queue.h"

int checkComplete(bitTree t){
  queue q;
  initQueue(q);
  bitNode *p=nullptr;
  enQueue(q,t);
  while(!isQueueEmpty(q)){
    deQueue(q,p);
    if(p==nullptr){
      break;
    }else{
      enQueue(q,p->l);
      enQueue(q,p->r);
    }
  }
  while(!isQueueEmpty(q)){
    deQueue(q,p);
    if(p!=nullptr){
      return 0;
    }
  }
  return 1;
}

int main(){
  bitTree t=creatBitTree();
  printf("%d\n",checkComplete(t));
  return 0;
}