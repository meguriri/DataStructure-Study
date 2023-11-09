/*
  假设A表示出栈，D表示入栈。一个仅由A、D组成的字符串表示一组出栈入栈序列，
  判断一个序列是否为合法的出入栈序列。
  eg.
  合法：DADDDADAADAA
  非法：ADDADAAD
*/

#include<cstdio>
#include<cstdlib>



int checkStack(char *s,int len){
  int top=0;
  for(int i=0;i<len;i++){
    if(s[i]=='D'){
      top++;
    }else if(s[i]=='A'){
      if(top==0){
        return 0;
      }else{
        top--;
      }
    }
  }
  if(top!=0)
    return 0;
  return 1;
}

int main(){
  printf("%d\n",checkStack("DADDDADAADAA",12));
  printf("%d\n",checkStack("ADDADAAD",8));
  printf("%d\n",checkStack("DADDDADAADAA",11));
  return 0;
}