#include<cstdio>
#include<cstring>

typedef struct node{
  char d;
  node *next;
}node,*list;

list CreatList(char a[],int n){
  list l=new(node),t=l;
  for(int i=0;i<n;i++){
    node *p=new(node);
    p->next=nullptr;
    p->d=a[i];
    t->next=p;
    t=p;
  }
  return l;
}

void PrintList(list l){
  node *p=l->next;
  while(p!=nullptr){
    printf("%c ",p->d);
    p=p->next;
  }
  printf("\n");
}

int symmetry(list l,int n){
  int f=1,top=0;
  char stack[10];
  node *p=l->next;
  for(int i=1;i<=n/2;i++){
    stack[top++]=p->d;
    p=p->next;
  }
  if(n%2!=0){
    p=p->next;
  }
  for(int i=1;i<=n/2;i++){
    char c=stack[--top];
    if(p->d!=c){
      f=0;
      break;
    }
    p=p->next;
  }
  return f;
}

int main(){
  char a1[10]="abcbadee";
  char a2[10]="abccbade";
  char a3[10]="efcbaeft";
  list l1=CreatList(a1,8);
  list l2=CreatList(a2,8);
  list l3=CreatList(a3,8);
  printf("%d\n",symmetry(l1,5));
  printf("%d\n",symmetry(l1,8));
  printf("%d\n",symmetry(l2,6));
  printf("%d\n",symmetry(l2,5));
  printf("%d\n",symmetry(l3,1));
  printf("%d\n",symmetry(l3,8));
  return 0;
}