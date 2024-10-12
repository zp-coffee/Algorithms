#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAX_SIZE 9

#define head_queue 1

typedef struct sqstack
{
    int stack[MAX_SIZE];
    int top;
}Sqstack;

typedef struct linkstacknode
{
    int val;
    struct linkstacknode* next;
}Linkstacknode;

typedef struct linkstack
{
    Linkstacknode* top;
}Linkstack;

typedef struct doublelinknode
{
    struct doublelinknode* next;
    struct doublelinknode* pre;
    int val;
}DoubleLinkNode;

typedef struct doublestack
{
    DoubleLinkNode* top;
    DoubleLinkNode* bottom;
}Doublestack;  //就是有两个节点的双向链表


typedef struct sqqueue
{
    int queue[MAX_SIZE];
    int top;
    int bottom;
}SqQueue;

typedef struct linkqueuenode
{
    int val;
    struct linkqueuenode* next;
}LinkQueueNode;

typedef struct linkqueue
{
    LinkQueueNode* front;
    LinkQueueNode* rear;
}LinkQueue;


//创建栈
Sqstack* CreateSqStack(void);

//出栈
bool PopSqstack(Sqstack* s, int* x);

//入栈
bool PushSqstack(Sqstack* s, int num);

//判空
bool IsSqstackEmpty(Sqstack* s);

//判满
bool IsSqstackFull(Sqstack* s);

//创建新节点
Linkstacknode* CreateLinkNode(int num);

//初始化
void InitLinkstack(Linkstack* l);

//判断是否为空
bool IsLinkstackEmpty(Linkstack* l);

//入栈
bool PushLinkstack(Linkstack* l, int num);

//出栈
bool PopLinkstack(Linkstack* l, int* x);

//创建新节点
DoubleLinkNode* CreateDoubleNode(int num);

//判断是否为空
bool IsDoubleLinkStackIsEmpty(Doublestack* s);

//入栈
bool PushDoubleStack(Doublestack* s, int num);

//出栈
bool PopDoubleStack(Doublestack* s, int* x);

//初始化
void InitDoubleStack(Doublestack* s);

//初始化
void InitSqQueue(SqQueue* Q);

//判满
bool IsQueueFull(SqQueue* Q);

//判空
bool IsQueueEmpty(SqQueue* Q);

//入队
bool PushQueue(SqQueue* Q, int num);

//创建一个节点
LinkQueueNode* CreateLinkQueueNode(int num);

//初始化
void InitLinkQueue(LinkQueue* Q);

//判空
bool IsLinkQueueEmpty(LinkQueue* Q);

//入队
bool PushLinkQueue(LinkQueue* Q, int num);

//出队
bool PopLinkQueue(LinkQueue* Q, int* x);


