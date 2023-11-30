/*
- + 9 -1 -1 * 2 -1 -1 / 4 -1 -1
2 -1 -1 * 3 -1 -1 / 8 -1 -1 4 -1 -1

+ 2 -1 -1 3 -1 -1

*/
#include"bitTree.h"

int calculate(bitTree t){
  if(t->l==nullptr&&t->r==nullptr){
    return t->d-'0';
  }
  int l=calculate(t->l);
  int r=calculate(t->r);
  if(t->d=='+'){
    return l+r;
  }else if(t->d=='-'){
    return l-r;
  }else if(t->d=='*'){
    return l*r;
  }else if(t->d=='/'){
    return l/r;
  }
}

int main(){
  bitTree t=creatBitTree();
  printf("%d\n",calculate(t));
  return 0;
}