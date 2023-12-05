#include<cstdio>
#include<cstring>
#define N 16

typedef struct score{
  char sport[100];
  int athlete[4];
  char college[50];
  int place;
  float result;
}score;

void total(struct score record[N]){
  score ans[N];
  int n=0;
  for(int i=0;i<N;i++){
    if(record[i].place<=6){
      ans[n++]=record[i];
    }
  }
  int f=0;
  for(int i=0;i<n-1;i++){
    f=0;
    for(int j=0;j<n-i-1;j++){
      if(strcmp(ans[j].sport,ans[j+1].sport)>0){
        score t=ans[j];
        ans[j]=ans[j+1];
        ans[j+1]=t;
        f++;
      }
    }
    if(f==0){
      break;
    }
  }
  for(int i=0;i<n;i++){
    printf("%s %s %d %f\n",ans[i].sport,ans[i].college,ans[i].place,ans[i].result);
  }
}

int main(){
  score record[N]={
    {"basketball",{1,2,3,4},"A",1,3},
    {"football",{1,2,3,4},"A",3,5},
    {"tennis",{1,2,3,4},"A",1,1},
    {"basketball",{1,2,3,4},"F",3,5},
    {"football",{1,2,3,4},"B",2,3},
    {"football",{1,2,3,4},"D",1,2},
    {"basketball",{1,2,3,4},"B",2,4},
    {"football",{1,2,3,4},"C",4,6},
    {"basketball",{1,2,3,4},"R",4,6},
    {"football",{1,2,3,4},"A",6,8},
    {"football",{1,2,3,4},"C",5,7},
    {"basketball",{1,2,3,4},"A",6,8},
    {"basketball",{1,2,3,4},"A",5,7},
    {"football",{1,2,3,4},"B",7,5},
    {"swim",{1,2,3,4},"B",2,5},
    {"basketball",{1,2,3,4},"C",7,9},
  };
  total(record);
  return 0;
}