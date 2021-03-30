
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//ps:��������Щ����ע����  ����ǰѧ��д��  �������Ҳ�ǻ���֮ǰд��һ���޸�

//����ڵ�
typedef struct LinkNode
{
    int value;//��������򴢴�int ������
    struct LinkNode* next;
}LinkNode;

//����ṹ��
typedef struct LINKLIST
{
    LinkNode* head;
    int size;
    //����Ҫ��������ʱ�����ڴ�
}LinkList;


//��ʼ������
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;

    //ͷ�ڵ��ʼ����
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->value = NULL;
    list->head->next = NULL;
    return list;

}

//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, int data)
{
    if (list == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    //posԽ��
    if (pos< 0 || pos>list->size)
    {
        pos = list->size;
    }
    //�����µĽڵ�
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->value = data;
    newnode->next = NULL;

    //�ҽڵ����  Ūһ������ָ�� ָ��ͷ�ڵ㣻
    LinkNode* pcur = list->head;
    for (int i = 0; i < pos; i++)
    {
        pcur = pcur->next;
    }

    //�½ڵ�������
    newnode->next = pcur->next;
    pcur->next = newnode;
    list->size++;
}
//ɾ��ָ��λ�õĽ��
void RemoveByPos_LinkList(LinkList* list, int pos)
{
    if (list == NULL)
    {
        return;
    }
    if (pos < 0 || pos >= list->size)
    {
        return;
    }
    LinkNode* pcur = list->head;
    //���Ҵ�ɾ���ڵ��ǰһ���ڵ㣻
    for (int i = 0; i < pos-1; i++)
    {
        pcur = pcur->next;
    }

    /*pcur->next = pcur->next->next;*/
    //    //�����ɾ���ڵ�
    LinkNode* del = pcur->next;

    pcur->next = del->next;
    //�ͷ�
    free(del);

    list->size--;
}
//�������ĳ���
int Size_LinkList(LinkList* list)
{
    return list->size;
}
//����
int Find_LinkList(LinkList* list, int data)
{
    if (list == NULL)
    {
        return -1;
    }
    if (data == NULL)
    {
        return -1;
    }
    LinkNode* pcur = list->head->next;
    int i = 0;
    while (pcur != NULL)
    {
        if (pcur->value == data)
        {
            break;
        }
        i++;
        pcur = pcur->next;
    }
    return i+1;
}
//���ص�һ���ڵ�����
int  Front_LinkList(LinkList* list)
{
    return list->head->next->value;
}

//��ӡ������ڵ��ֵ
void Print_LinkList(LinkNode* head)
{
    if (head->next == NULL)
    {
        printf("��\n");
    }
    LinkNode* pcur = head->next;
    while (pcur != NULL)
    {
        printf("%d ",pcur->value);
        pcur = pcur->next;
    }

}

//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
    if (list == NULL)
    {
        return;
    }
    //����ָ�����
    LinkNode* pcur = list->head;
    while (pcur != NULL)
    {
        //�Ȼ�����һ���ڵ�
        LinkNode* pnext = pcur->next;
        free(pcur);
        pcur = pnext;
    }
    //�ͷ������ڴ�
    list->size = 0;
    free(list);
}

LinkNode* Reverse(LinkNode* head)//�����������нڵ㷴�� 
{
    LinkNode* pre, *cur, * tmp;//tmp��¼��ǰ������һ�����
    pre = NULL;
    tmp = NULL;
    cur = head->next;
    if (cur == NULL)
    {
        printf("����������Ҫ����\n");
        return head;
    }
    if (head->next->next == NULL)
    {
        printf("����ֻ��һ��Ԫ�أ�����Ҫ����\n");
        return head;
    }
   
    while (cur != NULL)
    {
       //��¼��ǰ���ĺ�һ���
        tmp = cur->next;
        //��pre��ֵ�onext
        cur->next = pre;
        // pre cur ����
        pre = cur;
        cur = tmp;
    }
    return pre;

}



int main()
{

    LinkList* list = Init_LinkList();
    Insert_LinkList(list, 1, 5);
    Insert_LinkList(list, 2, 6);
    Insert_LinkList(list, 3, 7);
    Insert_LinkList(list, 4, 8);
    Insert_LinkList(list, 5, 9);
    Insert_LinkList(list, 6, 10);
    
    Print_LinkList(list->head);
    printf("����ǰ��\n");
    printf("ֵΪ5������λ���� ");
    printf("%d\n",Find_LinkList(list, 5));

    /*RemoveByPos_LinkList(list, 1);
    Print_LinkList(list->head);*/


    LinkList* list2 = Init_LinkList();
    list2->head->next = Reverse(list->head);
    printf("�����:\n");
    Print_LinkList(list2->head);
    printf("\n");

    printf("ֵΪ5������λ���� ");
    printf("%d\n", Find_LinkList(list2, 5));

    FreeSpace_LinkList(list);
    //printf("hello world!\n");
    return 0;
}

