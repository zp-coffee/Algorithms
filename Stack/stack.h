#include "stdio.h"
#include "stdlib.h"

#define MaxSize 50

typedef struct stack
{
    int data[MaxSize];
    int top;
}SqStack;   //栈的顺序存储


typedef struct linkstack
{
    int val;
    struct linkstack* next;
}LinkStack;  //栈的链式存储

//********顺序栈的基本操作******************

//初始化栈
void InitSqStack(SqStack* S);

//判断栈是否为空
int SqStackEmpty(SqStack* S);

//进栈
int PushSqStack(SqStack* S, int x);

//出栈
int PopSqStack(SqStack* S);

//读栈顶元素
int ReadSqStack(SqStack* S);

//********链式栈的基本操作**************

//创建一个节点
LinkStack* CreateLinkStack(int num);

//入栈
void PushLinkStack(LinkStack* l, int num);

//出栈
int PopLinkStack(LinkStack* l);

//读栈顶元素
int ReadLinkStack(LinkStack* l);

//判断栈是否为空
int LinkStackEmpty(LinkStack* l);
