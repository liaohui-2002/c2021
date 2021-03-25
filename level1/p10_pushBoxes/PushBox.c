#include <stdio.h>
#include <windows.h>

#define ROW 10
#define LINE 10


//�����ӱ��Ƶ������ʱ��  ��ʵ��Ϸ������  ����emmm Ҫ�жϵĻ�������鷳������

void Game();
//��ӡ��ͼ
void ShowMap(char arr[][LINE]);
//�ƶ�С��
void Move(char arr[][LINE], int* row, int* line);
//�ж����
void  Judge(char arr[][LINE], int* boxs);


int main()
{
	Game();
	system("pause");
	return 0;
}

void Game()
{
	char arr[10][10] = {  //0λǽ�ڡ���1λ�հף�2Ϊ���ӡ�3ΪĿ�ĵ�裬4Ϊ�ˡ�
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 1, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 3, 1, 0 },
		{ 0, 1, 1, 1, 2, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 1, 2, 1, 0, 1, 2, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 3, 0 },
		{ 0, 3, 1, 2, 1, 4, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};//��ʼ����ͼ
	ShowMap(arr);
	int row = 8, line = 5;//С�˳�ʼ��������
	int boxs = 4;//��δ����Ŀ���ĺ�����
	while (boxs)
	{
		Move(arr, &row, &line);//�ƶ�С��
		system("cls");
		ShowMap(arr);
		Judge(arr, &boxs);//ʣ��Ŀ�����
		if (boxs == 0)
			printf("��ϲ�㣬ͨ�سɹ�\n");
	}

}

void ShowMap(char arr[][LINE])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			if (arr[i][j] == 0)
				printf("��");//��ӡǽ��
			else if (arr[i][j] == 1)//��ӡ�հ�
				printf("  ");
			else if (arr[i][j] == 2)//��ӡ����
				printf("��");
			else if (arr[i][j] == 3)//��ӡĿ�ĵ�
				printf("��");
			else if (arr[i][j] == 4)//�� 
				printf("��");
		}
		printf("\n");
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

		if (arr[newrow][newline] == 0 || arr[newrow][newline] == 3)//��ǰ������һ��λ����ǽ�ڻ���Ŀ���ʱ
		{
			printf("��ֹǰ��\n");
		}

		else//ǰ��Ϊ�հף����ӣ�����Ŀ���
		{
			if (arr[newrow][newline] == 1)//Ϊ�հ�
			{
				arr[newrow][newline] = 4;//��С���ƶ��������
				arr[*row][*line] = 1;//С�˵ĵط���Ϊ�հ�
				*row = newrow;
				*line = newline;
				break;
			}
			else if (arr[newrow][newline] == 2)//��һ��Ŀ���Ϊ����
			{
				int nextrow = newrow;
				int nextline = newline;
				if (move == 'w')//��
					nextrow = newrow - 1;
				else if (move == 's')//��
					nextrow = newrow + 1;
				else if (move == 'a')//��
					nextline = newline - 1;
				else//��
					nextline = newline + 1;
				if (arr[nextrow][nextline] == 0 || arr[nextrow][nextline] == 2)//����ǰ����ǽ�ڻ�������
					printf("�ƶ�����,����ǰ�����ϰ�\n");
				else//����ǰ�治��ǽ��
				{
					arr[nextrow][nextline] = 2;//����ǰŲ
					arr[newrow][newline] = 4;//����λ�ñ�Ϊ��
					arr[*row][*line] = 1;//С�˵ĵط���Ϊ�հ�
					*row = newrow;
					*line = newline;
					break;
				}

			}

		}
	}

}

void  Judge(char arr[][LINE], int* boxs)
{
	int temp = 0;//
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			if (arr[i][j] == 3)//ʣ��Ŀ�����
				temp++;
		}
	}
	*boxs = temp;
}