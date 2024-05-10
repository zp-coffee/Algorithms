#include "stack.h"

int main(void)
{
    LinkStack* head = CreateLinkStack(0);
    LinkStackEmpty(head);
    PushLinkStack(head, 20);
    printf("%d\n",ReadLinkStack(head));
    return 0;
}

//********顺序栈的基本操作**************

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
int PushSqStack(SqStack* S, int x)
{
    if (S->top == MaxSize)
    {
        printf("the stack is full\n");
        return 0;
    }
    S->data[++S->top] = x;
    return 1;
}

//出栈
int PopSqStack(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty");
        return 0;
    }
    int x = S->data[S->top];
    S->top --;
    return x;
}

//读栈顶元素
int ReadSqStack(SqStack* S)
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
LinkStack* CreateLinkStack(int num)
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
void PushLinkStack(LinkStack* l, int num)
{
    LinkStack* p = CreateLinkStack(num);
    p->next = l->next;
    l->next = p;
}

//出栈
int PopLinkStack(LinkStack* l)
{
    LinkStack* cur = l->next;
    l->next = l->next->next;
    int x = cur->val;
    free(cur);
    return x;
}

//读栈顶元素
int ReadLinkStack(LinkStack* l)
{
    return l->next->val;
}