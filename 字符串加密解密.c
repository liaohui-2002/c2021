#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEY 5  // ƫ���� 

/**
*���ݴ�����ַ���
* ����1 Ҫ���ܵ��ַ���
*  ���ؼ��ܺ�Ĳ���
*/

char* encrypt(char[]);//����
char* encryptr(char[]); //���� 

int main()
{
	char name[100];
	printf("��������Ҫ���ܵ��ַ���\n");
	scanf_s("%s", name);
	encrypt(name);
	printf("\n���ܺ���ַ�Ϊ��%s", name);
	printf("\n");
	printf("��������Ҫ���ܵ��ַ���");
	scanf_s("%s", name);
	encryptr(name);
	printf("\n���ܺ���ַ�Ϊ��%s", name);
	return 0;
}


char* encrypt(char str[])  //�ַ������� 
{
	int i;
	int count = strlen(str);  //�ַ�������
	for (i = 0; i < count; i++)    //Ϊʲôforѭ���ﲻֱ����strlen��str��������Ϊforѭ����ÿѭ��һ�� �Ͳ���һ�� ���Բ��Ƽ�ʹ��
	{
		str[i] = str[i] + i + KEY; //str�����еĵ�i��ֵ����i��ֵ����ƫ����
	}
	return str;   //���ؼ��ܺ�ĵ��ַ��� 
}

char* encryptr(char str[]) //����
{
	int i;
	int count = strlen(str);  //�ַ������� 
	for (i = 0; i < count; i++)
	{
		str[i] = str[i] - i - KEY; //str�����еĵ�i��ֵ��ȥi��ֵ��ȥƫ����
	}
	return str;  //���ؽ��ܺ���ַ��� 
}
