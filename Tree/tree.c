#include "tree.h"

int main(void)
{
    TreeNode* test1 = CreateTestTree();
    int count = 0;
    int* num = Traversal(test1, &count, 1);
    for(int i = 0; i < count; i ++)
    {
        printf("%d\n", num[i]);
    }
    return 0;
}

//创建一个作为调试的树
TreeNode* CreateTestTree(void)
{
    TreeNode* root = CreateRootTree();
    root->val = 1;
    AddLeftNode(root, 2, 1, 2);
    AddRightNode(root, 2, 2, 3);
    AddLeftNode(root, 3, 1, 4);
    AddRightNode(root, 3, 2, 5);
    return root;
}


//创建一个树的根节点
TreeNode* CreateRootTree(void)
{
    TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
    root->rnext = NULL;
    root->lnext = NULL;
    return root;
}

//在树的第layer层的第number个位置添加一个节点作为左孩子，如果双亲不存在就返回错误
void AddLeftNode(TreeNode* p, int layer, int number, int target)
{
    TreeNode* Lnode = (TreeNode *)malloc(sizeof(TreeNode)); //先将节点创建好
    Lnode->rnext = NULL;
    Lnode->lnext = NULL;
    Lnode->val = target;

    TreeNode* cur = p;
    for (int i = 1; i < layer-1; i ++)
    {
        if (number <= CalAccumulation(2, layer-i)/2) //在当前节点的左子树当中
        {
            if (cur->lnext == NULL)
            {
                printf("error\n");
            }
            else
            {
                cur = cur->lnext;
            }
        }
        else                      //在当前节点的右子树中
        {
            if (cur->rnext == NULL)
            {
                printf("error\n");
            }
            else
            {
                cur = cur->rnext;
            }
        }
    } //循环结束即找到了需要添加孩子的节点
    cur->lnext = Lnode;
}

//在树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddRightNode(TreeNode* p, int layer, int number, int target)
{
    TreeNode* Lnode = (TreeNode *)malloc(sizeof(TreeNode)); //先将节点创建好
    Lnode->rnext = NULL;
    Lnode->lnext = NULL;
    Lnode->val = target;

    TreeNode* cur = p;
    for (int i = 1; i < layer-1; i ++)
    {
        if (number <= CalAccumulation(2, layer-i)/2) //在当前节点的左子树当中
        {
            if (cur->lnext == NULL)
            {
                printf("error\n");
            }
            else
            {
                cur = cur->lnext;
            }
        }
        else                      //在当前节点的右子树中
        {
            if (cur->rnext == NULL)
            {
                printf("error\n");
            }
            else
            {
                cur = cur->rnext;
            }
        }
    } //循环结束即找到了需要添加孩子的节点
    cur->rnext = Lnode;
}

//计算一个值的几次方
int CalAccumulation(int target, int num)
{
    int sum = 1;
    for (int i = 0; i < num; i ++)
    {
        sum *= target;
    }
    return sum;
}

//树的前序遍历
void preOrder(TreeNode* root, int* ret, int* returnSize)
{
    if(root == NULL)
    {
        return;
    }
    ret[(*returnSize)++] = root->val;
    preOrder(root->lnext, ret, returnSize);
    preOrder(root->rnext, ret, returnSize);
}

//树的中序遍历
void inOrder(TreeNode* root, int* ret, int* returnSize)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->lnext, ret, returnSize);
    ret[(*returnSize)++] = root->val;
    inOrder(root->rnext, ret, returnSize);
}

//树的后序遍历
void postOrder(TreeNode* root, int* ret, int* returnSize)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root->lnext, ret, returnSize);
    postOrder(root->rnext, ret, returnSize);
    ret[(*returnSize)++] = root->val;
}

//树的遍历，结果存于数组ret中并返回,way:1->前序，2->中序，3->后序
int* Traversal(TreeNode* root, int* returnSize, int way) 
{
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    if (way == 1)
    {
        preOrder(root, ret, returnSize);
    }
    else if (way == 2)
    {
        inOrder(root, ret, returnSize);
    }
    else
    {
        postOrder(root, ret, returnSize);
    } 
    return ret;
}

