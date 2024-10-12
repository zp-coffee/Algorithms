#include "stdio.h"
#include "stdlib.h"

#define variable_type int
#define MaxSize 50

typedef struct stack
{
    variable_type data[MaxSize];
    int top;
}SqStack;   //栈的顺序存储

typedef struct linkstack
{
    variable_type val;
    struct linkstack* next;
}LinkStack;  //栈的链式存储

typedef struct doublestack
{
    variable_type val;
    struct doublestack* next;
    struct doublestack* pre;
}DoubleStack;  //栈的双向链表实现


//********顺序栈的基本操作******************

//初始化栈
void InitSqStack(SqStack* S);

//创建一个栈
SqStack* CreateSqStack(void);

//判断栈是否为空
int SqStackEmpty(SqStack* S);

//进栈
variable_type PushSqStack(SqStack* S, variable_type x);

//出栈
variable_type PopSqStack(SqStack* S);

//读栈顶元素
variable_type ReadSqStack(SqStack* S);

//********链式栈的基本操作**************

//创建一个节点
LinkStack* CreateLinkStack(variable_type num);

//入栈
void PushLinkStack(LinkStack* l, variable_type num);

//出栈
variable_type PopLinkStack(LinkStack* l);

//读栈顶元素
variable_type ReadLinkStack(LinkStack* l);

//判断栈是否为空
int LinkStackEmpty(LinkStack* l);

//********双向链表栈的基本操作**************

//创建一个节点
DoubleStack* CreateDoubleStack(variable_type num);

//判断是否为空
int DoubleStackEmpty(DoubleStack* l);

//入栈，有头节点，尾插法
void PushDoubleStack(DoubleStack* l, variable_type num);

//出栈，有头节点
variable_type PopDoubleStack(DoubleStack* l);
