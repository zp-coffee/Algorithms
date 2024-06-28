#include "test.h"

//迭代中序遍历，重练：6.28，先读再加入右节点，符合左中右
// void inorder_test1(TreeNode* root, int* ret, int* returnsize);

//迭代后序遍历2,重练：6.28，先不读，先看有没有右节点，先加入右节点，再读，符合左右中，后序遍历中还要使用前置节点来判断
// void postorder_test2(TreeNode* root, int* ret, int* returnsize);

//删除值为target的节点
TreeNode* DeleteNode_test(TreeNode* root, int target)
{
    if (root == NULL || root->val == target)
    {
        DeleteTree(root);
        root = NULL;
        return root;
    }
    SqQueue* Q = CreateSqQueue();
    TreeNode* cur = root;
    PushSqQueue(Q, root);
    while (!EmptySqQueue(Q))
    {
        root = PopSqQueue(Q);
        if (root->lnext)
        {
            if (root->lnext->val == target)
            {
                DeleteTree(root->lnext);
                root->lnext = NULL;
            }
            else
            {
                PushSqQueue(Q, root->lnext);
            }
        }
        if (root->rnext)
        {
            if (root->rnext->val == target)
            {
                DeleteTree(root->rnext);
                root->rnext = NULL;
            }
            else
            {
                PushSqQueue(Q, root->rnext);
            }
        }
    }
    return cur;
}

// //求树的最大深度,后序遍历
// int MaxDepthTree_test(TreeNode* root);

// //求树的最小深度,指的是从深度最小的叶子节点开始到根节点的路径,使用后序遍历
// int MinDepthTree_test(TreeNode* root);


