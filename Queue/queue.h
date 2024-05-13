#include "stdio.h"
#include "stdlib.h"

#define variable_type int
#define MaxSize 50

//************************队列************************
typedef struct {
    variable_type data[MaxSize];
    int front, rear;
}SqQueue;

typedef struct LinkNode{
    variable_type val;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* front;  //front 和 rear只是作为操作的指针，真正存放的值在val与next中
    LinkNode* rear;
}LinkQueue;

//********顺序队列的基本操作******************

//创建一个顺序队列
SqQueue* CreateSqQueue(void);

//判断队列是否为空
int EmptySqQueue(SqQueue* Q);

//入队
void PushSqQueue(SqQueue* Q, variable_type val);

//出队
variable_type PopSqQueue(SqQueue* Q);

//********链式队列的基本操作******************

//创建一个链式存储队列
LinkQueue* CreateLinkQueue(void);

//判断队列是否为空
int EmptyLinkQueue(LinkQueue* Q);

//入队
void PushLinkQueue(LinkQueue* Q, variable_type target);

//出队
variable_type PopLinkQueue(LinkQueue* Q);
