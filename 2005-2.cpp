/*
  哈希表删除关键字为K的算法，设哈希函数为H，解决冲突使用链地址法
*/

typedef struct node{
  int d;
  node *next;
};

typedef struct LinkHashTable{
  node* hashtable[10];
};

int H(int k){
  return k%7;
}

bool delKeyInLinkTable(LinkHashTable* l,int k){
  int pos=H(k);
  node *p1=l->hashtable[pos],*p2;
  if(p1==nullptr){
    return false;
  }
  p2=p1->next;
  while(p2!=nullptr){
    if(p2->d==k){
      p1->next=p2->next;
      delete(p1);
      return true;
    }
    p2=p2->next;
  }
  return false;
}