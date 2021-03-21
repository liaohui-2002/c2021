#include <stdio.h>
#define ROW 6
#define COL 6
// ��װ��ӡ��ͼ�ĺ���

void printMap(char map[][COL]) 
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) 
        {
            printf("%c", map[i][j]);
        }
        printf("\n");

    }

}



int isSuccess(int x, int y) {

    return x == 0 || x == ROW - 1 || y == 0 || y == COL - 1;
}

char inputChar() 
{
    char input;
    while (1) {
        printf("> ");
        input = getchar();
        while (getchar() != '\n');
        if (input == 'w' || input == 's' || input == 'a' || input == 'd') {
            break;
        }
    }
    return input;
}

int main01(int argc, const char* argv[]) 
{
    char map[ROW][COL] = {
        {'#','#','#','#','#','#'},
        {'#','O','#','#',' ',' '},
        {'#',' ','#','#',' ','#'},
        {'#',' ',' ','#',' ','#'},
        {'#','#',' ',' ',' ','#'},
        {'#','#','#','#','#','#'}
    };
    char input;
    // ��ʾ�˵�λ��
    int x = 1;
    int y = 1;
    while (1) {
        // ��ӡ
        printMap(map);
        // ʤ���Ĵ���
        if (isSuccess(x, y)) break;
        // ��ʾ�û�������
        printf("������ w(��) s(��) a(��) d(��)\n");
        // ��������, �ж���ȷ
        input = inputChar();
        // ���µ�ͼ`
        switch (input) 
        {
        case 'W':
        case 'w':
            // �ж���һ��λ���Ƿ������, ��������߾ͽ�����ͼ�е�����
            // ��������߾Ͳ���
            // �� �ж� (x - 1, y) �ǲ��ǿո�, ����ǿո�Ϳ�����
            if (map[x - 1][y] == ' ') {
                // ����
                int temp = map[x - 1][y];
                map[x - 1][y] = map[x][y];
                map[x][y] = temp;
                // ��������� x y
                x--;
            }
            break;
        case 's':
            if (map[x + 1][y] == ' ') {
                // ����
                int temp = map[x + 1][y];
                map[x + 1][y] = map[x][y];
                map[x][y] = temp;
                // ��������� x y
                x++;
            }
            break;
        case 'a':
            if (map[x][y - 1] == ' ') {
                // ����
                int temp = map[x][y - 1];
                map[x][y - 1] = map[x][y];
                map[x][y] = temp;
                // ��������� x y
                y--;
            }
            break;
        case 'd':
            if (map[x][y + 1] == ' ') 
            {
                // ����
                int temp = map[x][y + 1];
                map[x][y + 1] = map[x][y];
                map[x][y] = temp;
                // ��������� x y
                y++;
            }
            break;
        }
        // ����
        system("clear");
    }
    printf("��ϲ���ػ�����...\n");
    return 0;

}