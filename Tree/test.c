#include "test.h"

//迭代中序遍历，重练：6.28，先读再加入右节点，符合左中右
// void inorder_test1(TreeNode* root, int* ret, int* returnsize);

//迭代后序遍历2,重练：6.28，先不读，先看有没有右节点，先加入右节点，再读，符合左右中，后序遍历中还要使用前置节点来判断
// void postorder_test2(TreeNode* root, int* ret, int* returnsize);

//删除值为target的节点
// TreeNode* DeleteNode_test(TreeNode* root, int target);

void char_2017(TreeNode* root, int* num, int* returnsize)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext)
    {
        char_2017(root->lnext, num, returnsize);
    }
    else
    {
        num[(*returnsize) ++] = 0;
    }

    num[(*returnsize) ++] = root->val;
    
    if (root->rnext)
    {
        char_2017(root->rnext, num, returnsize);
    }
    else
    {
        num[(*returnsize) ++] = 0;
    }
}

