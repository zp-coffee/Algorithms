#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct list
{
    int val;
    struct list *next;
}ListNode;  //ListNode相当于int一个数据类型，里面包含一个数据和一个指针

typedef struct doublelist
{
    int val;
    struct doublelist *next;
    struct doublelist *pre;
}DoubleList;

//初始化一个头节点
ListNode* InitHeadList(void);

//初始化一个双向链表的头节点
DoubleList* InitHeadDoubleList(void);

//创建一个新的节点
ListNode* CreatNode(int data);

//创建一个新的双向链表节点
DoubleList* CreateDoubleNode(int data);

//在链表尾部加入一个节点
void ListAddTail(ListNode* L, ListNode* new);

//在双向链表结尾插入一个节点
void DoubleListAddTail(DoubleList* L, DoubleList* new);

//创建一个用于调试的链表
ListNode* list1(void);

//创建一个用于调试的链表
ListNode* list2(void);

//创建一个用于测试的双向链表
DoubleList* list3(void);

//打印有头节点链表中的信息
void printf_headlist(ListNode *L);

//打印无头节点链表中的信息
void printf_noheadlist(ListNode *L);

//计算链表的长度
int GetLen(ListNode *L);

//找到链表中的第几个节点
ListNode* GetElem(ListNode *L, int num);

//获取链表中第几个节点的值
int GetIndexVal(ListNode* L, int index);

//在链表头部插入一个节点
void ListAddHead(ListNode* L, ListNode* new);

//在链表的第几个节点后插入一个节点
void ListAddInlist(ListNode* L, ListNode* new, int target);

//删除第几号节点
void DeleteInlist(ListNode* L, int target);

//删除链表中所有值等于val的节点
void DeleteValNode(ListNode* L, int target);

//计算无头节点的链表的长度
int GetNoHeadLen(ListNode* L);

//翻转一个列表
ListNode* ReverseList(ListNode* L);

//递归法翻转一个链表
ListNode* ReverseList1(ListNode* L);

//递归
ListNode* Reverse(ListNode* cur, ListNode* per);

//交换相邻节点,返回带头节点的链表
ListNode* SwapNodes(ListNode* L);

//删除倒数第几个节点
ListNode* DeleteNodeFromEnd(ListNode* L, int target);

//双指针法删除倒数第几个节点
ListNode* DeleteNodeFromEnd1(ListNode* L, int target);

//判断两个链表是否相交
ListNode* GetinterSectionNode(ListNode* L, ListNode* P);

//判断链表中是否有环,返回环的入口在第几个节点上
int ListCycle(ListNode* L);

//删除链表中含有最小值的节点
ListNode* DeleteMinNode(ListNode* L);

//删除链表中最小值的节点，通过另一套指针来保存
ListNode* DeleteMinNode1(ListNode* L);

//翻转一个链表，可以直接摘下头节点，再一次指向头节点
ListNode* ReverseList2(ListNode* L);

//链表为a1,b1,a2,b2,a3,b3......拆分为a1,a2,a3和b1,b2,b3
ListNode* SplitList(ListNode* L);

//链表为a1,b1,a2,b2,a3,b3......拆分为a1,a2,a3和bn,bn-1,bn-2
ListNode* SplitList1(ListNode* L);

//删除有序链表中重复的元素
void DeleteSameNode(ListNode* L);

//从两个带头节点的链表中取共同元素构成新链表C
ListNode* CreateListFromAandB(ListNode* A, ListNode* B);

//两个递增链表A，B，将它们的交集存放在A中
void Union(ListNode* A, ListNode* B);

//判断一个链表是不是另一个链表的子序列
void JudgeSonList(ListNode* A, ListNode* B);

//判断一个循环双链表是否对称
int JudgeSymmetryDoubleList(DoubleList* L);

//将两个循环单链表变成一个循环单链表
ListNode* MergeList(ListNode* A, ListNode* B);

//将一个单链表循环右移多少步
ListNode* MoveRightList(ListNode* L, int target);

//将一个单链表右移多少位，可以先将单链表连接成循环链表再找到新的链尾断开
ListNode* MoveRightList1(ListNode* L, int target);

//判断单链表中是否有环
ListNode* JudgeCircleList(ListNode* L);

//计算单链表的最大孪生值
int FindMaxSum(ListNode* L);

//查找最大孪生值，将后半部分链表倒置再分别从两个链表头开始计算孪生值
int FindMaxSum1(ListNode* L);

//查找倒数第k个节点
int FindCountDownNode(ListNode* L, int target);

//用双指针法输出倒数第k个节点的值
int FindCountDownNode1(ListNode* L, int target);

//只保留链表中唯一存在的绝对值,n为最大值
void DeleteSqrtNode(ListNode* L, int n);

//将倒数的节点一次插入前面
void InsertFromLast(ListNode* L);

//可以将后半段链表逆置，再从中间开始依次插入,时间复杂度为n
void InsertFromLast1(ListNode* L);
