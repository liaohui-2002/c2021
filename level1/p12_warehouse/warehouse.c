#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define For(x,a,b) for(x=a;x<=b;x++)
int i, i1, i2;
struct cargo {//��ĿҪ�������������Ϣ
	char name[100];
	long int number;
};
int main(void)
{
start:
	FILE* fp;
	struct cargo cargoes[888];//��һ�����Ļ��������ռ䣬˳���¾�Qualcomm Snapdragon 888
	int choice, count, newnumber, flag;
	char next, container;
	char newname[100];
	count = 0;
	printf("����һ�����������ļ򵥳�����ѡ������Ҫִ�еĲ�����\n");
	printf("0.�˳�    1.��ʾ����б�    2.���    3.����\n");
	scanf("%d", &choice);
	scanf("%c", &container);//���������ͦ��ֵģ���ȫ���Ǹ���������Ϊ���������Ժ�Ļس���ֱ�ӱ���Ϊ�ǻ���������������ˣ�����Ҫ�Ҹ�������������س�
	if (choice == 0) {
		printf("��л����ʹ�á�\n");
		exit(0);
	}
	if ((fp = fopen("cargo.txt", "r+")) == NULL) {
		printf("�򿪿���ļ����������ԡ�\n");
		printf("%s\n", strerror(errno));
		return 0;
	
	}
	while (1) {//�������л������Ϣ 
		if ((fscanf(fp, "%s  %d", &cargoes[count].name, &cargoes[count].number)) == EOF) break;
		count++;
	}
	if (fclose(fp)) {
		printf("�رտ���ļ����ִ��󡣳��򼴽��˳���\n");//�ر��ļ���Ϊ����һ�������w�ķ�ʽ�򿪡� 
		exit(0);
	}
	if (choice == 1) {
		printf("����б�\n");
		printf("��������          ����\n");//10���ո�����ÿ�һ��ɡ� 
		for (i = 0; i < count; i++) {
			printf("%s", cargoes[i].name);
			For(i1, 1, (18 - strlen(cargoes[i].name))) printf(" ");//�Ʊ�ʹ����������ͷ���롣
			printf("%d\n", cargoes[i].number);
		}
		printf("�����ǲֿ�����ʣ�����л��������������������\n");
	}
	else if (choice == 2) {
	tryagain1:
		printf("����������Ҫ������Ʒ��\n");
		i2 = 0;
		while ((newname[i2] = getchar()) != '\n') i2++;//��������һЩ�����ǿ��Զ�ȡ�ո� 
		newname[i2] = '\0';
		printf("���������Ʒ�����������\n");
		scanf("%d", &newnumber);
		scanf("%c", &container);//���������ͦ��ֵģ���ȫ���Ǹ���������Ϊ���������Ժ�Ļس���ֱ�ӱ���Ϊ��next��������ˣ�����Ҫ�Ҹ�������������س�
		flag = 0;
		for (i = 0; i < count; i++) {
			if (strcmp(newname, cargoes[i].name) == 0) {//Ѱ��֮ǰ��û�����ֻ��� 
				flag = 1;
				break;
			}
		}
		if (newnumber <= 0) {
			printf("���ʧ�ܣ����������������Ϊ�������\n");
			Sleep(2000);
			goto tryagain1;
		}
		if (flag == 1) {
			cargoes[i].number += newnumber;//�����ֻ�������ֻ������������ 
			if ((fp = fopen("cargo.txt", "w")) == NULL) {//���´��ļ� 
				printf("�򿪿���ļ����������ԡ�\n");
				exit(0);
			}
			if (fclose(fp)) {
				printf("�رտ���ļ����ִ��󡣳��򼴽��˳���\n");//��w��ʽ���Ѵ��ڵ��ļ�Ȼ���ٹرգ���������ļ���ȫ������ 
				exit(0);
			}
			if ((fp = fopen("cargo.txt", "r+")) == NULL) {
				printf("�򿪿���ļ����������ԡ�\n");
				exit(0);
			}
			for (i1 = 0; i1 < count; i1++) {//ȫ������д�� 
				fprintf(fp, "%s  %d\n", cargoes[i1].name, cargoes[i1].number);
			}
		}
		else {
			if ((fp = fopen("cargo.txt", "r+")) == NULL) {//���´��ļ� 
				printf("�򿪿���ļ����������ԡ�\n");
				exit(0);
			}
			fseek(fp, 0, SEEK_END);
			fprintf(fp, "%s  %d\n", newname, newnumber);//û�����ֻ���ͼ������ֻ�� 
		}
	}
	else if (choice == 3) {
	tryagain2:
		printf("����������Ҫ�������Ʒ��\n");
		i2 = 0;
		while ((newname[i2] = getchar()) != '\n') i2++;//��������һЩ�����ǿ��Զ�ȡ�ո� 
		newname[i2] = '\0';
		printf("���������Ʒ�ĳ���������\n");
		scanf("%d", &newnumber);
		scanf("%c", &container);//���������ͦ��ֵģ���ȫ���Ǹ���������Ϊ���������Ժ�Ļس���ֱ�ӱ���Ϊ��next��������ˣ�����Ҫ�Ҹ�������������س�
		flag = 0;
		for (i = 0; i < count; i++) {//֮ǰһ�������ֻ���ҵ������� 
			if (strcmp(newname, cargoes[i].name) == 0) {
				flag = 1;
				break;
			}
		}
		if (newnumber <= 0) {
			printf("����ʧ�ܣ�������������Ϊ�������\n");
			Sleep(2000);
			goto tryagain2;
		}
		if ((cargoes[i].number - newnumber) < 0 && flag != 0) {
			printf("����ʧ�ܣ�����и��ֻ����������㣡��������ĳ������������ԡ�\n");//�ô���� 
			Sleep(2000);
			goto tryagain2;
		}
		if (flag == 0) {
			printf("����ʧ�ܣ������û�����ֻ����������Ļ������Ʋ����ԡ�\n");//�������� 
			Sleep(2000);
			goto tryagain2;
		}
		else {
			cargoes[i].number -= newnumber;//�����ֻ�������ֻ����ȥ������� 
			if ((fp = fopen("cargo.txt", "w")) == NULL) {
				printf("�򿪿���ļ����������ԡ�\n");
				exit(0);
			}
			if (fclose(fp)) {
				printf("�رտ���ļ����ִ��󡣳��򼴽��˳���\n");//��w��ʽ���Ѵ��ڵ��ļ�Ȼ���ٹرգ���������ļ���ȫ������ 
				exit(0);
			}
			if ((fp = fopen("cargo.txt", "r+")) == NULL) {//���´��ļ� 
				printf("�򿪿���ļ����������ԡ�\n");
				exit(0);
			}
			for (i1 = 0; i1 < count; i1++) {//�����������д�� 
				if (cargoes[i1].number != 0) {
					fprintf(fp, "%s  %d\n", cargoes[i1].name, cargoes[i1].number);
				}
			}
		}
	}
	else {
		printf("����ѡ����������ԡ�\n");
		Sleep(2000);
		goto start;
	}
	if (choice != 1)//�����ļ���ʱ��û�ж��δ��ļ�������Ҫ�ٴιر� 
		if (fclose(fp)) {
			printf("�رտ���ļ����ִ��󡣳��򼴽��˳���\n");
			exit(0);
		}
	printf("�����ִ�и��������\n������Y���ǣ���N����\n");
	scanf("%c", &next);
	if (next == 'Y') {
		printf("���Ժ�...\n");
		Sleep(2000);
		system("CLS");
		goto start;
	}
	else if (next == 'N') {
		printf("�����˳�\n");
	}
	system("pause");
	return 0;
}