#include "stdio.h"
#include "stdlib.h"

typedef struct tree
{
    int val;
    struct tree *lnext;
    struct tree *rnext;
}TreeNode;


//创建一个作为调试的树
TreeNode* CreateTestTree(void);

//计算一个值的几次方
int CalAccumulation(int target, int num);

//为树的第几层的第几个节点添加左孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddLeftNode(TreeNode* p, int layer, int number, int target);

//为树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddRightNode(TreeNode* p, int layer, int number, int target);

//创建一个树的根节点
TreeNode* CreateRootTree(void);

//树的结构
//            1
//      1           2
//   1     2     3     4
//  1 2   3 4   5 6   7 8

//树的遍历，结果存于数组ret中并返回,way:1->前序，2->中序，3->后序
int* Traversal(TreeNode* root, int* returnSize, int way);

//树的前序遍历
void preOrder(TreeNode* root, int* ret, int* returnSize);

//树的中序遍历
void inOrder(TreeNode* root, int* ret, int* returnSize);

//树的后序遍历
void postOrder(TreeNode* root, int* ret, int* returnSize);

