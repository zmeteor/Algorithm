#include <stdio.h>
#include <stdlib.h>


int removeTimes = 0;
void hanoiorignal(int nm, char czs, char temp, char czd)
{
    if (nm == 0)
    {
        return;
    }
    else if (nm == 1)
    {
        removeTimes++;
    }
    else
    {
        hanoiorignal(nm -1, czs, czd, temp);
        printf("move the %d from %c to %c\n",nm,czs,czd);
        removeTimes++;
        hanoiorignal(nm -2,temp, czd, czs);
    }
}

void hanoitwocolor(int ndisk)
{
    char szs = 'A';
    char szt = 'B';
    char szd = 'C';
    int i = ndisk;
    for ( i = ndisk ; i > 0; i-= 2)
    {
        hanoiorignal(ndisk, szs, szt, szd);
    }
    printf("�ܹ��ƶ�����Ϊ��%d\n",removeTimes);
    removeTimes = 0;

}

int main()
{
    int ndisk = 0;
    printf("�������ϵ��̵���Ŀ��������2�ı���������0����\n");
    scanf("%d",&ndisk);
    while (ndisk)
    {
        hanoitwocolor(ndisk);
        printf("�������ϵ��̵���Ŀ��������2�ı���������0����\n");
        scanf("%d",&ndisk);
    }
    return 0;
}
