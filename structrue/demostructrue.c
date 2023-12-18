#include <stdio.h>
#include <string.h>

#define BUFEER_SIZE 16
#define DEFAULT_SIZE 10
/* 结构体 */
/* 1.什么叫结构体：将不同类型的属性封装成一个类型 */
/* 2.怎么定义结构体？ */
typedef struct stuInfo
{
    int age;
    int height;
    int weight;
    char sex;
    char name[BUFEER_SIZE];
    char* address;

#if 0
    char clothes;
    char shoes;
    char phones;
#endif
}stuInfo;
/* 取别名 typedef. */

#if 0
int printStruct(stuInfo stu)
{
    /* 栈空间小的很，不允许超过8M。 */
    stu.age = 100;
    printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\n",
                stu.age, stu.height, stu.sex, stu.height, stu.name);
    return 0;
}
#endif

#if 0
/* 传入参数: 不要改变值 */
int printStruct(stuInfo* stu)
{
    int ret = 0;
    int len = sizeof(stu);
    printf("len:%d\n", len);
    /* 栈空间小的很，不允许超过8M。 */
    stu->age = 100;
    printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\n",
                stu->age,(*stu).height, stu.sex, stu.height, stu.name);
    return 0;
}
#endif
int printStructBuffer(stuInfo *stu, int stuSize)
{
    for(int idx = 0; idx < stuSize; idx++)
    {
        printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\n",
                stu[idx].age, stu[idx].height, stu[idx].sex, (*(stu+idx)).weight, stu[idx].name);
    }
}

int main()
{

#if 1
    stuInfo buffer[DEFAULT_SIZE];

    buffer[0].age = 10;
    buffer[0].height = 180;
    buffer[0].sex = 'm';
    buffer[0].weight = 50;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].height = 160;
    buffer[1].sex = 'f';
    buffer[1].weight = 40;
    strncpy(buffer[1].name, "wangwu", sizeof(buffer[1].name) - 1);
#endif

#if 1

    /* 3.怎么使用结构体 */
    struct stuInfo stu;
    memset(&stu, 0, sizeof(stu));

    stu.address =NULL;
    /* 4.结构体的大小 */
    int len = sizeof(stu);
    printf("len:%d\n", len);

    stu.age = 10;
    stu.weight = 50;
    stu.sex = 'm';
    stu.height = 180;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);/* 为什么不能直接给 */

    printStruct(stu);

    /* 回顾指针 */
    int a = 5; 
    int *p = &a;

    /* 结构体指针 */
    stuInfo * info = &stu;

    /* 结构体指针 读数据 或者写数据。 都是-> */
    info->age = 30;
    printf("info->age:%d\n", info->age);
    printf("stu.age:%d\n", stu.age);
    printStructBuffer(buffer, 0);
#endif

#if 0
    printf("stu.age:%d\t, stu.height:%d\t, stu.sex:%c\t, stu.weight:%d\t, stu.name:%s\n",
                stu.age, stu.height, stu.sex, stu.height, stu.name);
    
#endif
    /* */
    stu.address = (char *)malloc(sizeof(char) * BUFEER_SIZE);
    strcpy(stu.address,"china");
    return 0;
}