#include <stdio.h>
#include<stdlib.h>

#define ROW 10
#define LINE 10

void ShowMap(arr);
void Game();
void Move(char arr[][LINE], int* row, int* line);

int main()
{
	Game();
	system("pause");
	return 0;
}


void ShowMap(char arr[][LINE])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			if (arr[i][j] == 0)
			{
				printf("��");
			}
			else if (arr[i][j] == 1)
			{
				printf("  ");
			}
			else if (arr[i][j] == 2)
			{
				printf("��");
			}
		}
		printf("\n");
	}
}

void Game() 
{
	char arr[10][10] = {  //0λǽ�ڡ���1λ�հ�,2Ϊ�ˡ�
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 1, 1, 0, 0, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 1, 1, 1, 1, 0, 1, 0 },
		{ 1, 1, 0, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 1, 1, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }
	};//��ʼ����ͼ
	ShowMap(arr);
	int row = 2, line = 2;

	while (1)
	{
		Move(arr, &row, &line);
		system("cls");
		ShowMap(arr);

		if (row == 3&& line == 10||line>10)
		{
			printf("���ػ���������\n");
			break;
		}
	}

}
void Move(char arr[][LINE], int* row, int* line)//�ƶ�С�˶�
{
	while (1)
	{
		int newrow = *row;
		int newline = *line;
		int quit = 0;
		printf("��ͨ��w,s,a,d�������������� �����enter�������ƶ�\n");

		int move = 0;
		int c = 0;
		while (!quit)
		{
			move = getchar();//�ӱ�׼�����ȡ�ַ�
			while ((c = getchar()) != '\n');//�Ե�������ַ��Լ��ո�
			switch (move)
			{
			case 'w':
				newrow--;//�����ƶ�
				quit = 1;
				break;
			case 's':
				newrow++;//�����ƶ�
				quit = 1;
				break;
			case 'a':
				newline--;//�����ƶ�
				quit = 1;
				break;
			case 'd':
				newline++;//�����ƶ�
				quit = 1;
				break;
			default:
				printf("�����������������\n");
				break;
			}
		}

		if (arr[newrow][newline] == 0)//��ǰ������һ��λ����ǽ��=
		{
			printf("��ֹǰ��\n");
		}

		else//ǰ��Ϊ�հף����ӣ�����Ŀ���
		{
			if (arr[newrow][newline] == 1)//Ϊ�հ�
			{
				arr[newrow][newline] = 2;//��С���ƶ��������
				arr[*row][*line] = 1;//С�˵ĵط���Ϊ�հ�
				*row = newrow;
				*line = newline;
				break;
			}

		}
	}

}
