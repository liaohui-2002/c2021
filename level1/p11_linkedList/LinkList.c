
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//ps:方法内有些代码注释了  是以前学着写的  这个链表也是基于之前写的一个修改

//链表节点
typedef struct LinkNode
{
    int value;//结点数据域储存int 型数据
    struct LinkNode* next;
}LinkNode;

//链表结构体
typedef struct LINKLIST
{
    LinkNode* head;
    int size;
    //不需要容量；即时开辟内存
}LinkList;


//初始化链表
LinkList* Init_LinkList()
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;

    //头节点初始化；
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->value = NULL;
    list->head->next = NULL;
    return list;

}

//指定位置插入
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
    //pos越界
    if (pos< 0 || pos>list->size)
    {
        pos = list->size;
    }
    //创建新的节点
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->value = data;
    newnode->next = NULL;

    //找节点插入  弄一个辅助指针 指向头节点；
    LinkNode* pcur = list->head;
    for (int i = 0; i < pos; i++)
    {
        pcur = pcur->next;
    }

    //新节点入链表
    newnode->next = pcur->next;
    pcur->next = newnode;
    list->size++;
}
//删除指定位置的结点
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
    //查找待删除节点的前一个节点；
    for (int i = 0; i < pos-1; i++)
    {
        pcur = pcur->next;
    }

    /*pcur->next = pcur->next->next;*/
    //    //缓存待删除节点
    LinkNode* del = pcur->next;

    pcur->next = del->next;
    //释放
    free(del);

    list->size--;
}
//获得链表的长度
int Size_LinkList(LinkList* list)
{
    return list->size;
}
//查找
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
//返回第一个节点数据
int  Front_LinkList(LinkList* list)
{
    return list->head->next->value;
}

//打印链表各节点的值
void Print_LinkList(LinkNode* head)
{
    if (head->next == NULL)
    {
        printf("空\n");
    }
    LinkNode* pcur = head->next;
    while (pcur != NULL)
    {
        printf("%d ",pcur->value);
        pcur = pcur->next;
    }

}

//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
    if (list == NULL)
    {
        return;
    }
    //辅助指针变量
    LinkNode* pcur = list->head;
    while (pcur != NULL)
    {
        //先缓存下一个节点
        LinkNode* pnext = pcur->next;
        free(pcur);
        pcur = pnext;
    }
    //释放链表内存
    list->size = 0;
    free(list);
}

LinkNode* Reverse(LinkNode* head)//将该链表所有节点反序 
{
    LinkNode* pre, *cur, * tmp;//tmp记录当前结点的下一个结点
    pre = NULL;
    tmp = NULL;
    cur = head->next;
    if (cur == NULL)
    {
        printf("空链表，不需要逆序\n");
        return head;
    }
    if (head->next->next == NULL)
    {
        printf("链表只有一个元素，不需要逆序\n");
        return head;
    }
   
    while (cur != NULL)
    {
       //记录当前结点的后一结点
        tmp = cur->next;
        //把pre赋值給next
        cur->next = pre;
        // pre cur 后移
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
    printf("反序前：\n");
    printf("值为5的数据位置是 ");
    printf("%d\n",Find_LinkList(list, 5));

    /*RemoveByPos_LinkList(list, 1);
    Print_LinkList(list->head);*/


    LinkList* list2 = Init_LinkList();
    list2->head->next = Reverse(list->head);
    printf("反序后:\n");
    Print_LinkList(list2->head);
    printf("\n");

    printf("值为5的数据位置是 ");
    printf("%d\n", Find_LinkList(list2, 5));

    FreeSpace_LinkList(list);
    //printf("hello world!\n");
    return 0;
}

