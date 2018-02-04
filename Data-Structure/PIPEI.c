/************************************************
 Created by David Song in 2016-4-26

 Note:
   1. Sequencial implementation of stack
*************************************************/
//��������Ƿ�ƥ�䣬����ջ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef char ElemType;
typedef struct stack {
  ElemType a[MAX];
  int top;
} Stack;

// ��ʼ��
void InitStack(Stack **p) {
    *p = (Stack *)malloc(sizeof(Stack));
    (*p)->top = -1;
}

//��ջ��
int StackEmpty(Stack *p) {
    return (p->top == -1);

}

//��ջ��
int StackFull(Stack *p) {
    return (p->top == MAX-1);

}

//ѹջ
void Push(Stack *p, ElemType x) {
    if(!StackFull(p))
        p->a[++p->top] = x;

}

//��ջ
void Pop(Stack *p, ElemType *q) {
    if(!StackEmpty(p))
        *q = p->a[p->top--];

}

//ȡվ��Ԫ��
void StackTop(Stack *p, ElemType *q){

    if(!StackEmpty(p))
        *q = p->a[p->top];
}
//���ջ
void StackClear(Stack *p) {
    p->top = -1;

}

//�ж��Ƿ�ƥ��
int Match(char a, char b) {
    if ((a=='(' && b==')')||
        (a=='[' && b==']')||
        (a=='{' && b=='}'))
            return 1;
    else
        return 0;

}


int main() {
  char str[100] = "()[]{}";
  //char str[100] = "{[()][(()())]}";
  //char str[100] = "([)]{}";
  //char str[100] = "{[)(]{}}";
  int i,len;
  Stack *p;
  ElemType tmp,tmp2;
  InitStack(&p);
  len = strlen(str);

  for(i=0;i<len;i++){
    if(str[i] == '(' || str[i] == '[' || str[i]=='{')
        Push(p,str[i]);
    if(str[i] == ')' || str[i] == ']' || str[i]=='}'){
        if(StackEmpty(p)){
            break;
        }
        StackTop(p,&tmp);
        if (Match(tmp,str[i]))
            Pop(p,&tmp2);
        else
            break;

    }

  }
  if(StackEmpty(p) && i==len)
    {
        printf("   MATCH!\n");
    }
  else
    {
        printf("   NOT MATCH!\n");
    }

  return 0;
}
