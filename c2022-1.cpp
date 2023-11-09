/*
  编写算法stuff(char *s1,char *s2,int start,int end)
  将s1从start到end的部分替换为字符串s2
  编写函数从键盘输入两个字符串，两个整数，调用stuff函数，输替换后的字符串
  eg. yangsheng psqy 2 6 
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>

void stuff(char *s1,char *s2,int start,int end){
  int l2=strlen(s2),cnt=0;
  for(int i=start;i<=end;i++){
    if(cnt<l2){
      s1[i]=s2[cnt++];
    }else{
      break;
    }
  }
}

void solve(){
  char s1[100],s2[100];
  int l,r;
  scanf("%s%s",s1,s2);
  scanf("%d%d",&l,&r);
  stuff(s1,s2,l,r);
  printf("%s\n",s1);
}

int main(){
  solve();
  return 0;
}