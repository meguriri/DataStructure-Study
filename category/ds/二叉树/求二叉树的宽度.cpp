/*
  eg1.
  1 2 -1 4 -1 -1 3 5 -1 7 8 -1 -1 -1 6 -1 -1

  eg2.
  1 2 4 -1 -1 5 -1 -1 3 6 8 -1 -1
  9 -1 -1 7 -1 -1
*/
#include"bitTree.h"
#include<queue>
using namespace std;

typedef struct fl{
  bitNode *p;
  int f;
}fl;

int getWidth(bitTree t){
  int ans=0,now=1,cnt=0;
  queue<fl>q;
  q.push(fl{t,1});
  while(!q.empty()){
    fl f=q.front();
    q.pop();
    if(f.f==now){
      cnt++;
    }else{
      if(ans<cnt){
        ans=cnt;
      }
      now=f.f;
      cnt=1;
    }
    if(f.p->l!=nullptr){
      q.push(fl{f.p->l,f.f+1});
    }
    if(f.p->r!=nullptr){
      q.push(fl{f.p->r,f.f+1});
    }
  }
  return ans;
}

int main(){
  bitTree t=creatBitTree();
  printf("%d\n",getWidth(t));
  return 0;
}