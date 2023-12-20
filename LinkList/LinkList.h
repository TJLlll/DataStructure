#ifndef __LINKLIST_H_
#define __LINKLIST_H_


#define ELEMENTTYPE int

/* 链表结点取别名 */
typedef struct LinkNode
{
    ELEMENTTYPE data;

    /* 指向下一个结点的指针 */
    struct LinkNode *next;       /* 指针的类型为什么是节点 */
}LinkNode;


/* 链表 */
typedef struct LinkList
{
    /* 链表头和链表尾 */
    LinkNode * head;
    LinkNode * tail;
    /* 链表的长度 */
    int len;
}LinkList;

/* 链表的初始化 */
int LinkListInit(LinkList ** PList);

/* 链表头插 */
int LinkListHeadTnsert(LinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int LinkListTaiInsert(LinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int LinkListHeadDel(LinkList * pList);

/* 链表尾部删 */
int LinkListTaiDel(LinkList * pList);

/* 链表指定位置删 */
int LinkListDelAppointPos(LinkList * pList, int pos);

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val);

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize);

/* 链表的销毁 */
int LinkListDestroy(LinkList * pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList);

#endif