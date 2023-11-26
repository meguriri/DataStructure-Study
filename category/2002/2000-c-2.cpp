#include<cstdio>
#include<cstdlib>
#include<cstring>
/*
frabsoc from asbcw oo ot at on inn in 12 a1 b
*/


int main(){
  char s[1000];
  fgets(s,1000,stdin);
  int n=strlen(s),cnt=0,flag=0,nl=0;

  char check[5][10]={"from","in","at","an","on"};
  char ans[1000]="",now[100]="";
  
  for(int i=0;i<=n;i++){
    if(s[i]==' '||s[i]=='\0'){
      now[nl]='\0';
      for(int j=0;j<5;j++){
        if(strcmp(now,check[j])==0){
          flag=1;
          break;
        }
      }
      if(flag==0){
        strcat(ans,now);
        strcat(ans," ");
      }
      flag=0;
      nl=0;
      continue;
    }
    now[nl++]=s[i];
  }

  printf("%s\n",ans);

  return 0;
}