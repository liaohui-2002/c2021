#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void LetterRunning()
{
	char ch;
	int m = 120;
	scanf_s("%c", &ch);
	while (1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < i; j++)
			{
				printf(" ");
			}
			printf("%c", ch);
			//Sleep(50);
			system("cls");
		}
		for (int i = m - 2; i > 0; i--)
		{
			for (int j = i; j > 0; j--)
			{
				printf(" ");
			}
			printf("%c", ch);
			//Sleep(5000);
			system("cls");
		}
	}
}