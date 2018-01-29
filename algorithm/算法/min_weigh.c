//  ��С��������������⡣

#include<stdio.h>

#define max 30

int w[max][max];
int c[max][max];
int bestx[max];
int x[max];
int cw=0,cc=0;
int bestw=10000;
int cost;
int n;
int m;

void Backtrack(int t);

int main()
{
    int i,j;
    printf("�����벿����,��Ӧ����,�޶��۸�\n");
    scanf("%d%d%d",&n,&m,&cost);

    printf("��������������ڲ�ͬ��Ӧ�̵�������\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&w[i][j]);

        }

    }
    printf("��������������ڲ�ͬ��Ӧ�̵ļ۸�\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&c[i][j]);
        }

    }

    Backtrack(1);

    printf("\n��С����Ϊ��%d\n",bestw);
    printf("ÿ�������Ĺ�Ӧ�̣�\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",bestx[i]);

    }

    return 0;
}

void Backtrack(int t)
{
    int j;
    if( t > n)
    {
        bestw=cw;
        for(j=1;j<=n;j++)
        {

            bestx[j]=x[j];
        }
    }
    else
    {
        for(j=1;j<=m;j++)
        {
            if(cc+c[t][j]<=cost && cw+w[t][j]<bestw)
            {
                x[t]=j;
                cc+=c[t][j];
                cw+=w[t][j];
                Backtrack(t+1);
                cc-=c[t][j];
                cw-=w[t][j];
            }
        }
    }
}
