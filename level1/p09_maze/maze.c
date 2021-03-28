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
				printf("■");
			}
			else if (arr[i][j] == 1)
			{
				printf("  ");
			}
			else if (arr[i][j] == 2)
			{
				printf("♀");
			}
		}
		printf("\n");
	}
}

void Game() 
{
	char arr[10][10] = {  //0位墙壁■，1位空白,2为人♀
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
	};//初始化地图
	ShowMap(arr);
	int row = 2, line = 2;

	while (1)
	{
		Move(arr, &row, &line);
		system("cls");
		ShowMap(arr);

		if (row == 3&& line == 10||line>10)
		{
			printf("你重获自由啦！\n");
			break;
		}
	}

}
void Move(char arr[][LINE], int* row, int* line)//移动小人儿
{
	while (1)
	{
		int newrow = *row;
		int newline = *line;
		int quit = 0;
		printf("请通过w,s,a,d，控制上下左右 输入后按enter键进行移动\n");

		int move = 0;
		int c = 0;
		while (!quit)
		{
			move = getchar();//从标准输入读取字符
			while ((c = getchar()) != '\n');//吃掉多余的字符以及空格
			switch (move)
			{
			case 'w':
				newrow--;//向上移动
				quit = 1;
				break;
			case 's':
				newrow++;//向下移动
				quit = 1;
				break;
			case 'a':
				newline--;//向左移动
				quit = 1;
				break;
			case 'd':
				newline++;//向右移动
				quit = 1;
				break;
			default:
				printf("输入有误，请从新输入\n");
				break;
			}
		}

		if (arr[newrow][newline] == 0)//当前往的下一个位置是墙壁=
		{
			printf("禁止前行\n");
		}

		else//前面为空白，箱子，或者目标点
		{
			if (arr[newrow][newline] == 1)//为空白
			{
				arr[newrow][newline] = 2;//将小人移动到坐标点
				arr[*row][*line] = 1;//小人的地方变为空白
				*row = newrow;
				*line = newline;
				break;
			}

		}
	}

}
