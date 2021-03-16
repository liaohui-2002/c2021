#include<stdio.h>
#include<math.h>

void main()
{
	int a, b, c;
	int x = 0;
	for (int i = 100; i < 1000; i++)
	{
		a = i % 10;//个位
		b = i % 100 / 10;//十位
		c = i % 1000 / 100;//百位
		x = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (i == x)
		{
			printf("%d ", i);
		}
	}
}