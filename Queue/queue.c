#include "queue.h"

int main(void)
{
    LinkQueue* Q = CreateLinkQueue();
    EmptyLinkQueue(Q);
    PushLinkQueue(Q, 30);
    PushLinkQueue(Q, 2);
    PushLinkQueue(Q, 4);
    PushLinkQueue(Q, 1);
    int num[4];
    for (int i = 0; i < 4; i ++)
    {
        num[i] = PopLinkQueue(Q);
        printf("%d\n",num[i]);
    }
    return 0;
}

//*******顺序存储队列***********************************************************

//创建一个循环队列，避免假溢出
SqQueue* CreateSqQueue(void)
{
    SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

//判断队列是否为空
int EmptySqQueue(SqQueue* Q)
{
    if (Q->front == Q->rear)
    {
        printf("the queue is empty\n");
        return 1;
    }
    else
    return 0;
}

//入队
void PushSqQueue(SqQueue* Q, variable_type val)
{
    if ((Q->rear+1) % MaxSize == Q->front)  //队列满了，采取牺牲一个存储单元来实现判断队列满
    {
        printf("the queue is full\n");
        return;
    }
    Q->data[Q->rear] = val;
    Q->rear = (Q->rear + 1) % MaxSize;
}

//出队
variable_type PopSqQueue(SqQueue* Q)
{
    if (Q->rear == Q->front)
    {
        printf("the queue is empty\n");
        return 0;
    }
    variable_type temp = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return temp;
}

//*******链式存储队列***********************************************************

//创建一个链式存储队列
LinkQueue* CreateLinkQueue(void)
{
    LinkQueue* head = (LinkQueue*)malloc(sizeof(LinkQueue));
    head->front = head->rear = (LinkNode* )malloc(sizeof(LinkNode));
    head->front->next = NULL;
    return head;
}

//判断队列是否为空
int EmptyLinkQueue(LinkQueue* Q)
{
    if (Q->front == Q->rear)
    {
        printf("the linkqueue is empty\n");
        return 1;
    }
    return 0;
}

//入队
void PushLinkQueue(LinkQueue* Q, variable_type target)
{
    LinkNode* temp = (LinkNode*)malloc(sizeof(LinkNode)); 
    temp->val = target;
    temp->next = NULL;
    Q->rear->next = temp;  //插入链尾
    Q->rear = Q->rear->next;
}

//出队
variable_type PopLinkQueue(LinkQueue* Q)
{
    if (Q->front == Q->rear)
    {
        printf("the queue is empty\n");
        return 0;
    }
    LinkNode* temp = Q->front->next;       //有头节点
    Q->front->next = Q->front->next->next;
    variable_type val = temp->val;
    free(temp);
    return val;
}
