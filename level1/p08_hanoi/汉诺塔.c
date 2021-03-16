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
		hanoi(n - 1, a, c, b);//��A�ϵ�n-1���̽���c�ƶ���b
		printf("%c ->%c\n", a, c);
		hanoi(n - 1, b, a, c);//��b�ϵ�n-1���̽���a�ƶ���c
	}
}
int main()
{
	hanoi(3, 'A', 'B', 'C');
	return 0;
}