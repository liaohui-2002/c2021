#include<stdio.h>
#include<math.h>

void main()
{
	int a, b, c;
	int x = 0;
	for (int i = 100; i < 1000; i++)
	{
		a = i % 10;//��λ
		b = i % 100 / 10;//ʮλ
		c = i % 1000 / 100;//��λ
		x = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (i == x)
		{
			printf("%d ", i);
		}
	}
}