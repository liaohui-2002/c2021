#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEY 5  // 偏移量 

/**
*根据传入的字符串
* 参数1 要加密的字符串
*  返回加密后的参数
*/

char* encrypt(char[]);//加密
char* encryptr(char[]); //解密 

int main()
{
	char name[100];
	printf("请输入需要加密的字符：\n");
	scanf_s("%s", name);
	encrypt(name);
	printf("\n加密后的字符为：%s", name);
	printf("\n");
	printf("请输入需要解密的字符：");
	scanf_s("%s", name);
	encryptr(name);
	printf("\n解密后的字符为：%s", name);
	return 0;
}


char* encrypt(char str[])  //字符串加密 
{
	int i;
	int count = strlen(str);  //字符串长度
	for (i = 0; i < count; i++)    //为什么for循环里不直接用strlen（str）量，因为for循环会每循环一次 就测量一次 所以不推荐使用
	{
		str[i] = str[i] + i + KEY; //str数组中的第i个值加上i的值加上偏移量
	}
	return str;   //返回加密后的的字符串 
}

char* encryptr(char str[]) //解密
{
	int i;
	int count = strlen(str);  //字符串长度 
	for (i = 0; i < count; i++)
	{
		str[i] = str[i] - i - KEY; //str数组中的第i个值减去i的值减去偏移量
	}
	return str;  //返回解密后的字符串 
}
