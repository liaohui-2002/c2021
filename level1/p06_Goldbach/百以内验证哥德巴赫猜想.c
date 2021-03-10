
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
    for (i = 4; i <= 100; i += 2) //分别拆分每个正偶数的
    {
        count = 0;
        j = i;
        k1 = j - 1; //从j-1开始拆分j,依次递减k1，然后分别确定k1和j-k1=k2是否是素数,都是素数则输出
        while (k1 >= (j / 2))//k1递减到j/2终止
        {
            ret1 = isPrime(k1);//判断k1是否是素数
            if (ret1)//k1是素数
            {
                k2 = j - k1;//获取k2
                ret2 = isPrime(k2);//判断k2是否是素数
                if (ret2)//k2是素数
                {
                    printf("%d = %d + %d,", j, k2, k1);//k1,k2皆为素数，进行输出
                    count++;//计算正偶数可以被拆分为几组素数相加
                }
            }
            k1--;//k1依次递减1
        }
        printf("%d可以拆分为%d组！\n", i, count);
        //putchar('\n');//处理完一个正偶数，输出换行符

    }
    return 0;
}

/*判断是否是素数*/
int isPrime(int n)
{
    int i = 0;
    if (n <= 1)//小于1的数不是素数
    {
        return 0;
    }
    if (2 == n)//2是最小的素数
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
