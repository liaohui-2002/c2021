#include<stdio.h>
int main()
{
    int i, j, t;
    for (i = 2; i <= 1000; i++)
    {
        int t = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t == 1)
        {
            printf("%d\n", i);
        }
    }
}

