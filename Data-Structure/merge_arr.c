//����ʵ�ֺϲ�����
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node {
  ElemType elm;
  struct node *next;
}SLNode;
void ListInit(SLNode **ppHead) {
  (*ppHead) = (SLNode*)(malloc(sizeof(SLNode)));
  (*ppHead)->next = NULL;
}



/* ���룺ָ��ͷ����һ��ָ��
   ���أ�������Ԫ�صĸ���
   ���ܣ�����������Ԫ�صĸ���
*/
int ListLen(SLNode *pHead) {
    SLNode *p = pHead;
    int i = 0;
    while (p->next != NULL){
        p = p->next;
        i++;
    }
    return i;

}

/* ���룺ָ��ͷ����һ��ָ�룬����λ�á���������
   ���أ���������0��ʾԪ�ز���ɹ�������1��ʾԪ�ز���ʧ��
   ���ܣ�Ϊ��������elem����һ���µĽڵ㣬Ȼ��Ѹýڵ���뵽iλ��
        ԭ��iλ�õĽڵ㽫��Ϊi+1λ�õĽڵ�
*/
int ListInsert(SLNode *pHead, int i, ElemType elm)
{
    SLNode *p = pHead,
    *q = (SLNode*)malloc(sizeof(SLNode));
    q->elm = elm;
    q->next = NULL;

    int k=0;
    while(p->next!=NULL && k<i-1)
    {
        p = p->next;
        k++;
    }
    if (k != i - 1) {
		printf("out of range!\n");
		return 1;
		}

    q->next = p->next;
    p->next = q;

    return 0;
}


/* ���룺ָ��ͷ����һ��ָ�룬ɾ��λ�á�ָ��ElemType��һ��ָ��
   ���أ���������0��ʾԪ��ɾ���ɹ�������1��ʾԪ��ɾ��ʧ��
   ���ܣ���λ��iλ�õĽڵ�ɾ����ͬʱ�Ѹýڵ��б����data����ͨ��pElemָ���ӷ��ʣ�
        ���ظ��������ĵ��÷������ͷŸýڵ�ռ�õĶ����ڴ棬ԭ��i+1λ�õĽڵ㽫��Ϊiλ�õĽڵ�
*/
int ListDelete(SLNode *p, int i, ElemType *pElm) {
    SLNode *q,*s;
    int k = 0;
    q = p->next;
    while ((k<i-1) && (q!=NULL)){
        p = q;
        q=q->next;
        k++;
    }
    if((q==NULL) || (k>i)){
        printf("out of range");
        return 1;
    }
    s = q;
    p->next = q->next;
    s->next = NULL;
    *pElm = s->elm;
    free(s);
    return 0;

}

/* ���룺ָ��ͷ����һ��ָ�룬ָ��ElemType��һ��ָ��
   ���أ���������0��ʾԪ�ػ�ȡ�ɹ�������1��ʾԪ�ػ�ȡʧ��
   ���ܣ���λ��iλ�õĽڵ��е�data����һ�ݸ�*pElem
*/
int ListGet(SLNode *pHead, int i, ElemType *pElm) {
   SLNode *p = pHead;
    int j = 0;
    while (p != NULL && j<i){
            p = p->next;
            j++;
    }
   *pElm = p->elm;
   return 0;
   if (p == NULL || j >= i){
    printf("out of reage!");
    return 1;
   }
}

/* ���룺ָ��ͷ���Ķ���ָ��
   ���أ��޷���ֵ
   ���ܣ���*ppHead��ָ�������е�Ԫ�أ������ɾ�����ͷţ�
        ����*ppHeadһ��ָ������Ϊ��ֵ
*/
void ListDestroy(SLNode **ppHead) {
    SLNode *pHead;
    pHead = *ppHead;
    while (pHead != NULL){
        *ppHead = pHead->next;
        free(pHead);
        pHead = *ppHead;

    }


    *ppHead = NULL;


}

/* ���룺ָ��ͷ����һ��ָ��
   ���أ��޷���ֵ
   ���ܣ���*ppHead��ָ�������е�Ԫ�أ�����ش�ӡ������̨������Ļ�������
*/
void ListPrint(SLNode *pHead) {
    pHead = pHead->next;
    if(pHead == NULL ){
        printf("list is empty!");
    }
    else{
        while(pHead != NULL){
            printf("%d  ",pHead->elm);
            pHead = pHead->next;
        }
        printf("\n");
    }
}

// main���������ϵ�����������в���
int main() {
  int i;
  ElemType a[10], b[10], x;
  SLNode *pHead;
  for (i = 0; i < 10; i++) {
    b[i] = 100 + i;
    a[i] = i + 1;
  }
  ListInit(&pHead);
  for (i = 0; i < 10; i++)
    ListInsert(pHead, i + 1, a[i]);
  puts("��a�����е�����Ԫ�ز��뵽����pHead��Ľ����");
  ListPrint(pHead);
  for (i = 0; i < 10; i++)
    ListInsert(pHead, i + 1, b[i]);
  puts("��b�����е�����Ԫ�ؼ������뵽����pHead��Ľ����");
  ListPrint(pHead);
  for (i = 0; i < 10; i++) {
    ListDelete(pHead, 1, &x);
    printf("ɾ���ˣ�%d\n", x);
  }
  puts("������ɾ��һ���ֺ󣬼�����ӡ�����");
  ListPrint(pHead);
  return 0;
}



