
#include <stdio.h>

int isPrime(int n);

int main()
{
    int i = 0;
    int j = 0;
    int k1 = 0;
    int k2 = 0;
    int even[50];
    int ret1 = 0;
    int ret2 = 0;
    int count = 0;
    for (i = 4; i <= 100; i += 2) //�ֱ���ÿ����ż����
    {
        count = 0;
        j = i;
        k1 = j - 1; //��j-1��ʼ���j,���εݼ�k1��Ȼ��ֱ�ȷ��k1��j-k1=k2�Ƿ�������,�������������
        while (k1 >= (j / 2))//k1�ݼ���j/2��ֹ
        {
            ret1 = isPrime(k1);//�ж�k1�Ƿ�������
            if (ret1)//k1������
            {
                k2 = j - k1;//��ȡk2
                ret2 = isPrime(k2);//�ж�k2�Ƿ�������
                if (ret2)//k2������
                {
                    printf("%d = %d + %d,", j, k2, k1);//k1,k2��Ϊ�������������
                    count++;//������ż�����Ա����Ϊ�����������
                }
            }
            k1--;//k1���εݼ�1
        }
        printf("%d���Բ��Ϊ%d�飡\n", i, count);
        //putchar('\n');//������һ����ż����������з�

    }
    return 0;
}

/*�ж��Ƿ�������*/
int isPrime(int n)
{
    int i = 0;
    if (n <= 1)//С��1������������
    {
        return 0;
    }
    if (2 == n)//2����С������
    {
        return 1;
    }
    for (i = 2; i < n; i++)
    {
        if (0 == n % i)
        {
            return 0;
        }
    }
    return 1;
}
