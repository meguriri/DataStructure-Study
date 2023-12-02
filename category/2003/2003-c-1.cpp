/*
  2000.1.1日是周六，求任意年份的1月1日是星期几
*/
#include<cstdio>

void getWeek(int y){
  int ans=0,cnt=0;
  if(y<2000){
    for(int i=y;i<2000;i++){
      if((i%4==0&&i%100!=0)||(i%400==0)){
        cnt+=366;
      }else{
        cnt+=365;
      }
    }
    ans=6-cnt%7;
  }else if(y>2000){
    for(int i=2000;i<y;i++){
      if((i%4==0&&i%100!=0)||(i%400==0)){
        cnt+=366;
      }else{
        cnt+=365;
      }
    }
    ans=(6+cnt)%7;
  }else{
    ans=6;
  }

  if(ans==1){
    printf("%d.1.1 is monday\n",y);
  }else if(ans==2){
    printf("%d.1.1 is tuesday\n",y);
  }else if(ans==3){
    printf("%d.1.1 is wednesday\n",y);
  }else if(ans==4){
    printf("%d.1.1 is thursday\n",y);
  }else if(ans==5){
    printf("%d.1.1 is friday\n",y);
  }else if(ans==6){
    printf("%d.1.1 is saturday\n",y);
  }else if(ans==0){
    printf("%d.1.1 is sunday\n",y);
  }
}

int main(){
  getWeek(1996);
  getWeek(2000);
  getWeek(2023);
  return 0;
}