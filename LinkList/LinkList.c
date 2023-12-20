#include "LinkList.h"
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 链表的初始化 */
int LinkListInit(LinkList ** PList)
{
    int ret = 0;
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list, 0, sizeof(LinkList) * 1);
    
    /* 给链表头节点初始化 */
    list->head = (LinkList *)malloc(sizeof(LinkNode) * 1);
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(LinkList) * 1);
    list->head->data = 0;
    list->head->next = NULL;
    /* 初始化的时候，头指针等于尾指针 */
    list->tail = list->head;

    /* 链表的长度为0 */
    list->len = 0;

    /* *二级指针 */
    *PList = list;

    return ret;
}

/* 链表头插 */
int LinkListHeadTnsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int LinkListTaiInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 封装结点 */
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkList) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(newNode, 0, sizeof(LinkNode) * 1);

    /* 赋值 */
    newNode->data = val;
#if 1
    /* 从虚拟头节点开始遍历 */
    LinkNode * travelNode = pList->head;
#else
    LinkNode * travalNode = pList->head->next;
#endif

    int flag = 0;
    /* 这种情况下需要改尾指针 */
    if (pos == pList->len)
    {
        /* 修改节点指向尾指针 */
        travelNode = pList->tail;
        flag = 1;
    }
    else
    {
            while (pos--)
        {
            travelNode = travelNode->next;
        }
    }

    newNode->next = travelNode->next;
    travelNode->next = newNode;
    
    if(flag)
    {
        /* 尾指针更新位置 */
        pList->tail = newNode;
    }

    /* 节点数增加 */
    (pList->len)++;
    return ret ;
}

/* 链表头删 */
int LinkListHeadDel(LinkList * pList)
{
    return LinkListDelAppointPos(pList, 1);
}

/* 链表尾部删 */
int LinkListTaiDel(LinkList * pList)
{
    return LinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删 */
int LinkListDelAppointPos(LinkList * pList, int pos)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    /* pos <= 0 */
    if(pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

#if 1
    LinkNode * travelNode = pList->head;
#else
    LinkList * travelNode = pList->head->next;
#endif

    while (--pos)
    {
        /* 向后移动位置 */
        travelNode = travelNode->next;
    }

    LinkNode * needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;

    /* 释放内存 */
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    /* 链表长度减一 */
    (pList->len)--;
    return ret;

}

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList * pList, ELEMENTTYPE val)
{

}

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pList->len;
    }
    return ret;
}

/* 链表的销毁 */
int LinkListDestroy(LinkList * pList)
{

}

/* 链表遍历接口 */
int LinkListForeach(LinkList * pList)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    /* travelNode指向虚拟头节点 */
    LinkNode * travelNode = pList->head;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    /* travelNode指向链表第一个元素 */
    LinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        printf("travelNode->data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
#endif
    return ret;
}