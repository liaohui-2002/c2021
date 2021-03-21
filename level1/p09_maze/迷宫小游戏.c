#include <stdio.h>
#define ROW 6
#define COL 6
// 封装打印地图的函数

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
    // 表示人的位置
    int x = 1;
    int y = 1;
    while (1) {
        // 打印
        printMap(map);
        // 胜利的代码
        if (isSuccess(x, y)) break;
        // 提示用户的输入
        printf("请输入 w(上) s(下) a(左) d(右)\n");
        // 输入数据, 判断正确
        input = inputChar();
        // 更新地图`
        switch (input) 
        {
        case 'W':
        case 'w':
            // 判断下一个位置是否可以走, 如果可以走就交换地图中的数据
            // 如果不能走就不变
            // 即 判断 (x - 1, y) 是不是空格, 如果是空格就可以走
            if (map[x - 1][y] == ' ') {
                // 交换
                int temp = map[x - 1][y];
                map[x - 1][y] = map[x][y];
                map[x][y] = temp;
                // 交换后更新 x y
                x--;
            }
            break;
        case 's':
            if (map[x + 1][y] == ' ') {
                // 交换
                int temp = map[x + 1][y];
                map[x + 1][y] = map[x][y];
                map[x][y] = temp;
                // 交换后更新 x y
                x++;
            }
            break;
        case 'a':
            if (map[x][y - 1] == ' ') {
                // 交换
                int temp = map[x][y - 1];
                map[x][y - 1] = map[x][y];
                map[x][y] = temp;
                // 交换后更新 x y
                y--;
            }
            break;
        case 'd':
            if (map[x][y + 1] == ' ') 
            {
                // 交换
                int temp = map[x][y + 1];
                map[x][y + 1] = map[x][y];
                map[x][y] = temp;
                // 交换后更新 x y
                y++;
            }
            break;
        }
        // 清屏
        system("clear");
    }
    printf("恭喜你重获自由...\n");
    return 0;

}