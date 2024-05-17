#ifndef __TREE_H
#define __TREE_H

#include "stdio.h"
#include "stdlib.h"

#define variable_type TreeNode*
#define MaxSize 50

//************************树************************
typedef struct tree
{
    int val;
    struct tree *lnext;
    struct tree *rnext;
}TreeNode;

typedef struct threadtree
{
    int val;
    struct threadtree* lnext;
    struct threadtree* rnext;
    int ltag;
    int rtag;
}ThreadTreeNode;

typedef struct threenodetree
{
    int val;
    struct threenodetree* rnext;
    struct threenodetree* lnext;
    struct threenodetree* prenext;
    int ltag;
    int rtag;
}ThreadThreeNode;

//************************栈************************

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
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;

//************************函数************************

//创建一个作为调试的树
TreeNode* CreateTestTree(void);

//创建一个作为调试的线索树
ThreadTreeNode* CreateTestThreadTree(void);

//创建一个作为调试的三叉链表线索树
ThreadThreeNode* CreateTestThreadThreeTree(void);

//创建一个树的根节点
TreeNode* CreateRootTree(void);

//为树的第几层的第几个节点添加左孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddLeftNode(TreeNode* p, int layer, int number, int target);

//为树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddRightNode(TreeNode* p, int layer, int number, int target);

//创建一个线索树的根节点
ThreadTreeNode* CreateRootThreadTree(void);

//在树的第layer层的第number个位置添加一个节点作为左孩子，如果双亲不存在就返回错误
void AddThreadLeftNode(ThreadTreeNode* p, int layer, int number, int target);

//在树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddThreadRightNode(ThreadTreeNode* p, int layer, int number, int target);

//创建一个三叉链表线索树的根节点
ThreadThreeNode* CreateRootThreadThreeTree(void);

//在三叉链表树的第layer层的第number个位置添加一个节点作为左孩子，如果双亲不存在就返回错误
void AddThreadThreeLeftNode(ThreadThreeNode* p, int layer, int number, int target);

//在树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddThreadThreeRightNode(ThreadThreeNode* p, int layer, int number, int target);

//树的结构
//            1
//      1           2
//   1     2     3     4
//  1 2   3 4   5 6   7 8

//树的遍历，结果存于数组ret中并返回,way:1->前序，2->中序，3->后序
int* Traversal(TreeNode* root, int* returnSize, int way);

//*******前序***********************************************************

//树的前序遍历
void preOrder(TreeNode* root, int* ret, int* returnSize);

//树的迭代前序遍历
void preOrder1(TreeNode* root, int* ret, int* returnSize);

//前序打印二叉树
void PrintfPreTree(TreeNode* root);

//前序遍历线索化树
void CreatePreOrderThreadTree(ThreadTreeNode* root);

//前序遍历线索化树的递归写法
void ThreadpreOrder(ThreadTreeNode* p, ThreadTreeNode* *pre1);

//找前序线索树的后继节点
ThreadTreeNode* FindPreorderNextNode(ThreadTreeNode* p);

//找前序线索树的前驱节点，因为前序的顺序为根，左，右，所以找前驱的话必须找双亲，不能直接用线索
//解决方法有：重头开始遍历，使用三叉链表
ThreadThreeNode* FindPreorderPreNode(ThreadThreeNode* p);

//遍历前序线索树
void Preorder(ThreadTreeNode* root);

//前序遍历线索化三叉链表树
void CreatePreOrderThreadThreeTree(ThreadThreeNode* root);

//前序遍历线索化三叉链表树的递归写法
void ThreadThreepreOrder(ThreadThreeNode* p, ThreadThreeNode* *pre1);

//前序线索树的第一个节点就是根节点
ThreadTreeNode* FirstPreorderNode(ThreadTreeNode* root);

//前序线索树的最后一个节点就是右子树的最下一层的节点，优先向右走
ThreadThreeNode* LastPreorderNode(ThreadThreeNode* root);

//反向遍历前序线索树
void PreorderConverse(ThreadThreeNode* root);

//*******中序***********************************************************

//树的中序遍历
void inOrder(TreeNode* root, int* ret, int* returnSize);

//树的迭代中序遍历
void inOrder1(TreeNode* root, int* ret, int* num_size);

//中序遍历线索化树
void ThreadInOrder(ThreadTreeNode* root);

//中序遍历线索化树的主函数
void CreateInOrderThreadTree(ThreadTreeNode* root);

//中序遍历线索化树的递归写法
void ThreadInOrder1(ThreadTreeNode* p, ThreadTreeNode* *pre1);

//中序遍历线索化树的递归写法主函数
void CreateInOrderThreadTree1(ThreadTreeNode* root);

//找中序线索树的后继
ThreadTreeNode* FindInorderNextNode(ThreadTreeNode* p);

//找中序线索树的前驱
ThreadTreeNode* FindInorderPreNode(ThreadTreeNode* p);

//找到中序线索树的第一个节点
ThreadTreeNode* FirstInordernode(ThreadTreeNode* p);

//找到中序线索树的最后一个节点
ThreadTreeNode* LastInordernode(ThreadTreeNode* p);

//反向遍历中序线索树
void InorderConverse(ThreadTreeNode* root);

//遍历中序线索树
void Inorder(ThreadTreeNode* root);

//*******后序**************************************************************

//树的后序遍历
void postOrder(TreeNode* root, int* ret, int* returnSize);

//树的迭代后序遍历
void postOrder1(TreeNode* root, int* ret, int* returnSize);

//树的非递归遍历2
void postOrder2(TreeNode* root, int* ret, int* returnSize);

//后序遍历线索化树
void CreatePostOrderThreadTree(ThreadTreeNode* root);

//后序遍历线索化树的递归写法
void ThreadpostOrder(ThreadTreeNode* p, ThreadTreeNode* *pre1);

//找后序线索树的后继节点,后序遍历为左，右，根，所以找后继需要找其父节点
ThreadThreeNode* FindPostorderNextNode(ThreadThreeNode* p);

//找后序线索树的前驱节点
ThreadTreeNode* FindPostorderPreNode(ThreadTreeNode* p);

//******层序**************************************************************

//从上往下，从左往右的层序遍历
void LevelOrder(TreeNode* root, int* ret, int* returnSize);


//******题目**************************************************************

//判断二叉树是否为完全二叉树
int CheckFullyTree(TreeNode* root);

//一颗二叉树上有多少个度为二的节点
int TwoNodeNums(TreeNode* root);

//一颗二叉树上有多少个度为二的节点,递归算法
int TwoNodeNumsRecur(TreeNode* root);

//翻转二叉树，递归法
TreeNode* InvertTree(TreeNode* root);

//翻转二叉树，迭代法，前序遍历
TreeNode* InvertTree2(TreeNode* root);

//前序遍历返回第几个节点的值
int FindTreeNode(TreeNode* root, int num);

//删除以root为根的子树
void DeleteTree(TreeNode* root);

//删除指定值的节点
TreeNode* DeleteNode(TreeNode* root, int target);

//求树的深度
int DepthTree(TreeNode* root);

//找最近的公共祖先
TreeNode* FindLowestCommonAnestor(TreeNode* root, TreeNode* p, TreeNode* q);

//*******共同操作***********************************************************

//在访问该节点时修改左指针和右指针为前继节点和后继节点
void ThreadVisit(ThreadTreeNode* p);

//打印一个节点的值
void visit(ThreadTreeNode* p);

//计算一个值的几次方
int CalAccumulation(int target, int num);

//求两个值之间的较大值
int max(int x, int y);

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

#endif
