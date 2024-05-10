#ifndef __STACK_TREE_H
#define __STACK_TREE_H

#include "tree.h"
#include "stdio.h"
#include "stdlib.h"

#define variable_type TreeNode*
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

//********顺序栈的基本操作******************

//初始化栈
void InitSqStack(SqStack* S);

//创建一个栈
SqStack* CreateSqStack(void);

//判断栈是否为空
int SqStackEmpty(SqStack* S);

//进栈
void PushSqStack(SqStack* S, variable_type x);

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


#endif
