#include<stdio.h>
#include<stdlib.h>

void hanoi(int n, char a, char b,char c)
{
	if (n == 1)
	{
		printf("%c ->%c\n", a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);//把A上的n-1块盘借助c移动到b
		printf("%c ->%c\n", a, c);
		hanoi(n - 1, b, a, c);//把b上的n-1块盘借助a移动到c
	}
}
int main()
{
	hanoi(3, 'A', 'B', 'C');
	return 0;
}