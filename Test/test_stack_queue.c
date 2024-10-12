#include "test_stack_queue.h"

int main(void)
{
    LinkQueue* head = (LinkQueue*)malloc(sizeof(LinkQueue));
    InitLinkQueue(head);
    int x;
    PushLinkQueue(head, 10);
    PushLinkQueue(head, 11);
    PushLinkQueue(head, 12);
    PushLinkQueue(head, 13);
    PushLinkQueue(head, 14);
    PushLinkQueue(head, 15);
    PushLinkQueue(head, 16);
    while (!IsLinkQueueEmpty(head))
    {
        PopLinkQueue(head, &x);
        printf("%d\n", x);
    }
    return 0;
}

//创建栈
Sqstack* CreateSqStack(void)
{
    Sqstack* cur = (Sqstack*)malloc(sizeof(Sqstack));
    cur->top = -1;
    return cur;
}

//入栈
bool PushSqstack(Sqstack* s, int num)
{
    if (s->top == MAX_SIZE-1)
    {
        printf("the stack is full!\n");
        return false;
    }
    s->stack[++s->top] = num;
    return true;
}

//出栈
bool PopSqstack(Sqstack* s, int* x)
{
    if (s->top == -1)
    {
        printf("the stack is empty!\n");
        return false;
    }
    *x = s->stack[s->top --];
    return true;
}

//判空
bool IsSqstackEmpty(Sqstack* s)
{
    if (s->top == -1)
    {
        return true;
    }
    return false;
}

//判满
bool IsSqstackFull(Sqstack* s)
{
    if (s->top == MAX_SIZE-1)
    {
        return true;
    }
    return false;
}

//创建新节点
Linkstacknode* CreateLinkNode(int num)
{
    Linkstacknode* cur = (Linkstacknode*)malloc(sizeof(Linkstacknode));
    cur->next = NULL;
    cur->val = num;
    return cur;
}

//初始化
void InitLinkstack(Linkstack* l)
{
    l->top = NULL;
}

//判断是否为空
bool IsLinkstackEmpty(Linkstack* l)
{
    if (l->top == NULL)
    {
        return true;
    }
    return false;
}

//入栈
bool PushLinkstack(Linkstack* l, int num)
{
    Linkstacknode* cur = CreateLinkNode(num);
    if (l->top == NULL)
    {
        l->top = cur;
        return true;
    }
    cur->next = l->top;
    l->top = cur;
    return true;
}

//出栈
bool PopLinkstack(Linkstack* l, int* x)
{
    if (l->top == NULL)
    {
        printf("the linkstack is empty!\n");
        return false;
    }
    if (l->top->next == NULL)
    {
        *x = l->top->val;
        l->top = NULL;
        return true;
    }
    Linkstacknode* cur = l->top;
    l->top = l->top->next;
    *x = cur->val;
    cur->next = NULL;
    free(cur);
    return true;
}


//创建新节点
DoubleLinkNode* CreateDoubleNode(int num)
{
    DoubleLinkNode* cur = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));
    cur->next = NULL;
    cur->pre = NULL;
    cur->val = num;
    return cur;
}

//初始化
void InitDoubleStack(Doublestack* s)
{
    s->top = NULL;
    s->bottom = NULL;
}

//判断是否为空
bool IsDoubleLinkStackIsEmpty(Doublestack* s)
{
    if (s->top == NULL)
    {
        return true;
    }
    return false;
}

//入栈
bool PushDoubleStack(Doublestack* s, int num)
{
    DoubleLinkNode* cur = CreateDoubleNode(num);
    if (IsDoubleLinkStackIsEmpty(s))
    {
        s->top = s->bottom = cur;
    }
    else
    {
        cur->pre = s->top;
        s->top->next = cur;
        s->top = cur;
    }
    return true;
}

//出栈
bool PopDoubleStack(Doublestack* s, int* x)
{
    if (IsDoubleLinkStackIsEmpty(s))
    {
        printf("the doublestack is empty!\n");
        return false;
    }
    DoubleLinkNode* cur = s->top;
    if (s->top == s->bottom)
    {
        s->top = s->bottom = NULL;
    }
    else
    {
        s->top = s->top->pre;
        s->top->next = NULL;
    }
    *x = cur->val;
    free(cur);
    return true;
}

//创建一个新队列
SqQueue* CreateSqQueue(void)
{
    SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
    InitSqQueue(Q);
    return Q;
}

//初始化
void InitSqQueue(SqQueue* Q)
{
    Q->bottom = Q->top = 0;
}

//判满,采取牺牲一个单元的方式
bool IsQueueFull(SqQueue* Q)
{
    if ((Q->top+1) % MAX_SIZE == Q->bottom)
    {
        printf("the queue is full!\n");
        return true;
    }
    return false;
}

//判空
bool IsQueueEmpty(SqQueue* Q)
{
    if (Q->top == Q->bottom)
    {
        printf("the queue is empty!\n");
        return true;
    }
    return false;
}

//入队
bool PushQueue(SqQueue* Q, int num)
{
    if (IsQueueFull(Q))
    {
        return false;
    }
    Q->queue[Q->top] = num;
    Q->top = (Q->top+1) % MAX_SIZE;
    return true;
}

//出队
bool PopQueue(SqQueue* Q, int* x)
{
    if (IsQueueEmpty(Q))
    {
        return false;
    }
    *x = Q->queue[Q->bottom];
    Q->bottom = (Q->bottom+1) % MAX_SIZE;
    return true;
}

//创建一个节点
LinkQueueNode* CreateLinkQueueNode(int num)
{
    LinkQueueNode* Q = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    Q->val = num;
    Q->next = NULL;
    return Q;
}

#if head_queue

//初始化,有头节点
void InitLinkQueue(LinkQueue* Q)
{
    Q->rear = Q->front = CreateLinkQueueNode(-1); //头节点
    Q->front->next = NULL;
}

//判空
bool IsLinkQueueEmpty(LinkQueue* Q)
{
    if (Q->rear == Q->front)
    {
        printf("the linkqueue is empty!\n");
        return true;
    }
    return false;
}

//入队
bool PushLinkQueue(LinkQueue* Q, int num)
{
    LinkQueueNode* cur = CreateLinkQueueNode(num);
    Q->rear->next = cur;
    Q->rear = cur;
    return true;
}

//出队
bool PopLinkQueue(LinkQueue* Q, int* x)
{
    if (IsLinkQueueEmpty(Q))
    {
        return false;
    }
    LinkQueueNode* cur = Q->front->next;
    Q->front->next = cur->next;
    if (cur == Q->rear)  //队列中除了头节点只有一个节点
    {
        Q->rear = Q->front;
    }
    *x = cur->val;
    free(cur);
    return true;
}

#else

//初始化，无头节点
void InitLinkQueue(LinkQueue* Q)
{
    Q->front = Q->rear = NULL;
}

//判空
bool IsLinkQueueEmpty(LinkQueue* Q)
{
    if (Q->front == NULL)
    {
        printf("the linkqueue is empty!\n");
        return true;
    }
    return false;
}

//入队
bool PushLinkQueue(LinkQueue* Q, int num)
{
    LinkQueueNode* cur = CreateLinkQueueNode(num);
    if (Q->front == NULL)
    {
        Q->front = Q->rear = cur;
        return true;
    }
    Q->rear->next = cur;
    Q->rear = cur;
    return true;
}

//出队
bool PopLinkQueue(LinkQueue* Q, int* x)
{
    if (IsLinkQueueEmpty(Q))
    {
        return false;
    }
    LinkQueueNode* cur = Q->front;
    *x = cur->val;
    Q->front = Q->front->next;
    if (Q->front == NULL)
    {
        Q->rear = Q->front;
    }
    free(cur);
    return true;
}

#endif
