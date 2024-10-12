#include "stack.h"

int main(void)
{
    DoubleStack* head = CreateDoubleStack(0);
    PushDoubleStack(head, 10);
    PushDoubleStack(head, 11);
    PushDoubleStack(head, 12);
    PushDoubleStack(head, 13);
    PushDoubleStack(head, 14);
    PushDoubleStack(head, 15);
    PushDoubleStack(head, 16);
    while (DoubleStackEmpty(head))
    {
        printf("%d\n", PopDoubleStack(head));
    }
    return 0;
}

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
int PushSqStack(SqStack* S, variable_type x)
{
    if (S->top == MaxSize)
    {
        printf("the stack is full\n");
        return 0;
    }
    S->data[++S->top] = x;      //先加一再赋值
    return 1;
}

//出栈
variable_type PopSqStack(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty");
        return 0;
    }
    variable_type x = S->data[S->top];  //先取值再减一
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

//入栈，有头节点，插入到头节点后面，前插法
void PushLinkStack(LinkStack* l, variable_type num)
{
    LinkStack* p = CreateLinkStack(num);
    p->next = l->next;
    l->next = p;
}

//出栈
variable_type PopLinkStack(LinkStack* l)
{
    LinkStack* cur = l->next;  //l为头节点
    l->next = l->next->next;
    variable_type x = cur->val;  //输出头节点后面的节点
    free(cur);
    return x;
}

//读栈顶元素
variable_type ReadLinkStack(LinkStack* l)
{
    return l->next->val;
}

//********双向链表栈的基本操作**************

//创建一个节点
DoubleStack* CreateDoubleStack(variable_type num)
{
    DoubleStack* cur = (DoubleStack*)malloc(sizeof(DoubleStack));
    cur->next = NULL;
    cur->pre  = NULL;
    cur->val  = num;
    return cur;
}

//判断是否为空
int DoubleStackEmpty(DoubleStack* l)
{
    if (l->next == NULL && l->pre == NULL)
    {
        printf("the doublestack is empty!\n");
        return 0;
    }
    return 1;
}

//入栈，有头节点，尾插法
void PushDoubleStack(DoubleStack* l, variable_type num)
{
    DoubleStack* p = CreateDoubleStack(num);
    while (l->next != NULL)
    {
        l = l->next;
    }
    l->next = p;  //插入到尾部
    p->pre = l;
}

//出栈，有头节点
variable_type PopDoubleStack(DoubleStack* l)
{
    variable_type x;
    while (l->next != NULL)
    {
        l = l->next;
    }
    x = l->val;
    l->pre->next = NULL;
    free(l);
    return x;
}