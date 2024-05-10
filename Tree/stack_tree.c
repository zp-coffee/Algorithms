#include "stack_tree.h"

//SqStack* global_stack;

//********顺序栈的基本操作**************

//创建一个栈
SqStack* CreateSqStack(void)
{
    SqStack* S = (SqStack* )malloc(sizeof(SqStack));
    S->top = -1;
    return S;
}


//初始化栈
void InitSqStack(SqStack* S)
{
    S->top = -1;
}

//判断栈是否为空
int SqStackEmpty(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty\n");
        return 1;
    }
    return 0;
}

//进栈
void PushSqStack(SqStack* S, variable_type x)
{
    if (S->top == MaxSize)
    {
        printf("the stack is full\n");
        return ;
    }
    S->data[++S->top] = x;
}

//出栈
variable_type PopSqStack(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty");
        return 0;
    }
    variable_type x = S->data[S->top];
    S->top --;
    return x;
}

//读栈顶元素
variable_type ReadSqStack(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty\n");
        return 0;
    }
    return S->data[S->top];
}

//********链式栈的基本操作**************

//创建一个节点
LinkStack* CreateLinkStack(variable_type num)
{
    LinkStack* cur = (LinkStack* )malloc(sizeof(LinkStack));
    cur->val = num;
    cur->next = NULL;
    return cur;
}

//判断栈是否为空
int LinkStackEmpty(LinkStack* l)
{
    if (l->next == NULL)
    {
        printf("the linkstack is empty\n");
        return 0;
    }
    return 1;
}

//入栈
void PushLinkStack(LinkStack* l, variable_type num)
{
    LinkStack* p = CreateLinkStack(num);
    p->next = l->next;
    l->next = p;
}

//出栈
variable_type PopLinkStack(LinkStack* l)
{
    LinkStack* cur = l->next;
    l->next = l->next->next;
    variable_type x = cur->val;
    free(cur);
    return x;
}

//读栈顶元素
variable_type ReadLinkStack(LinkStack* l)
{
    return l->next->val;
}