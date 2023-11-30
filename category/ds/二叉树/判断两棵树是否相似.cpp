/*
eg1.
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1

1 6 -1 2 -1 -1 8 5 -1 7 9 -1 -1 -1 10 -1 -1

eg2.
1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1

1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 9 -1 -1 6 -1 -1

*/
#include"bitTree.h"

int isSimilar(bitTree t1,bitTree t2){
  if(t1==nullptr&&t2==nullptr){
    return 1;
  }
  if((t1==nullptr&&t2!=nullptr)||(t1!=nullptr&&t2==nullptr)){
    return 0;
  }
  return isSimilar(t1->l,t2->l)&&isSimilar(t1->r,t2->r);

}

int main(){
  bitTree t1=creatBitTree();
  bitTree t2=creatBitTree();
  printf("%d\n",isSimilar(t1,t2));
  return 0;
}