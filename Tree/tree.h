#ifndef __TREE_H
#define __TREE_H

#include "stdio.h"
#include "stdlib.h"
// #include "stack_tree.h"

typedef struct tree
{
    int val;
    struct tree *lnext;
    struct tree *rnext;
    //SqStack* next;
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

//后序遍历线索化树
void CreatePostOrderThreadTree(ThreadTreeNode* root);

//后序遍历线索化树的递归写法
void ThreadpostOrder(ThreadTreeNode* p, ThreadTreeNode* *pre1);

//找后序线索树的后继节点,后序遍历为左，右，根，所以找后继需要找其父节点
ThreadThreeNode* FindPostorderNextNode(ThreadThreeNode* p);

//找后序线索树的前驱节点
ThreadTreeNode* FindPostorderPreNode(ThreadTreeNode* p);

//*******共同操作***********************************************************

//在访问该节点时修改左指针和右指针为前继节点和后继节点
void ThreadVisit(ThreadTreeNode* p);

//打印一个节点的值
void visit(ThreadTreeNode* p);

//计算一个值的几次方
int CalAccumulation(int target, int num);

#endif
