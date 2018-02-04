/*����Ӧ��
  �ԡ�:���ָ��ַ��������������֣�
    L����߱��ұ߳�
    R���ұ߱���߳�
    S��������ȫ��ͬ
    N����ʽ����ȷ
    D���������
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef char ElemType;
typedef struct seqQue {
  ElemType a[MAX];
  int front;
  int rear;
} Que;

//��ʼ������
void InitQue(Que **p) {
  *p = malloc(sizeof(Que));
  (*p)->front = 0;
  (*p)->rear  = 0;
}
//�жӿ�
int QueEmpty(Que *p) {
  return p->front == p->rear;
}

//�ж���
int QueFull(Que *p) {
  return (p->rear + 1) % MAX == p->front;
}

//���
void EnQue(Que *p, ElemType x) {
  if (QueFull(p)){
     puts("error: enqueue to a full queue!");
  }
  else {
    p->rear = (p->rear + 1) % MAX;
    p->a[p->rear] = x;
  }
}

//����
void DeQue(Que *p, ElemType *q) {
  if (QueEmpty(p)){
       puts("error: depart from an empty queue!");
  }

  else {
    p->front = (p->front + 1) % MAX;
    *q = p->a[p->front];
  }
}

//��ӡ
void PrintQue(Que *p) {
  if (QueEmpty(p)){
    return;
  }
  puts("the queue has: ");
  int i = (p->front + 1) % MAX;
  while (i != p->rear) {
    printf("%5d", p->a[i]);
    i = (i + 1) % MAX;
  }
  printf("%5d\n", p->a[i]);
}

//���
void QueClear(Que *p) {
  p->front = p->rear = 0;
}

//����
void QueDestory(Que **p) {
  free(*p);
  *p = NULL;
}

void compar(char *s){
    Que *p;
    InitQue(&p);
    int i=0;
    while(s[i] != '\0'){
        if(s[i] != ':'){
             EnQue(p, s[i]);
             i++;
        }
        else
            break;

    }
    if(s[i] == '\0'){
        printf("N");
        return;
    }
    i+=1;
    int flag = 1;
    while(s[i]!='\0' && !QueEmpty(p)){
        ElemType tmp;
        DeQue(p, &tmp);
        if(tmp!=s[i]){
            flag = 0;
        }
        i++;
    }

        if(!QueEmpty(p) && s[i] == '\0'){
            printf("L");
            return;
        }
        else if(QueEmpty(p) && s[i]!='\0'){
            printf("R");
            return;
            }
        else{
            if(flag==1){
                printf("S");
                return;
                }
            else{
                printf("D");
            return;
            }
        }

 }


int main() {
  //ElemType a[MAX] = "aaaaaaa";
  //ElemType a[MAX] = "aaaa:aaa";
  //ElemType a[MAX] = "aaaa:aaabb";
  //ElemType a[MAX] = "aaaa:aaaa";
  ElemType a[MAX] = "aaaa:aabb";

  compar(a);
  return 0;
}
