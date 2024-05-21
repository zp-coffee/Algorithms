#include "tree.h"

int main(void)
{
    TreeNode* test = CreateTestTree();
    int sum = 1;
    TreeNode* test1 = test;
    FindMaxNode(test, &sum);
    printf("%d\n", sum);
    printf("\n");
    return 0;
}

//*******普通二叉树***********************************************************

//创建一个作为调试的树
TreeNode* CreateTestTree(void)
{
    TreeNode* root = CreateRootTree();
    root->val = 1;
    AddLeftNode (root, 2, 1, 2);
    AddRightNode(root, 2, 2, 3);

    AddLeftNode (root, 3, 1, 4);
    AddRightNode(root, 3, 2, 5);
    AddLeftNode (root, 3, 3, 6);
    AddRightNode(root, 3, 4, 7);

    // AddLeftNode (root, 4, 1, 8);
    // AddRightNode(root, 4, 2, 9);
    // AddLeftNode (root, 4, 3, 10);
    // AddRightNode(root, 4, 4, 11);
    // AddLeftNode (root, 4, 5, 12);
    // AddRightNode(root, 4, 6, 13);
    // AddLeftNode (root, 4, 7, 14);
    // AddRightNode(root, 4, 8, 15);
    return root;
}

//创建一个作为调试的树
TreeNode* CreateTestTree2(void)
{
    TreeNode* root = CreateRootTree();
    root->val = 1;
    AddLeftNode (root, 2, 1, 2);
    AddRightNode(root, 2, 2, 3);

    // AddLeftNode (root, 3, 1, 4);
    // AddRightNode(root, 3, 2, 5);
    // AddLeftNode (root, 3, 3, 6);
    // AddRightNode(root, 3, 4, 7);

    // AddLeftNode (root, 4, 1, 8);
    // AddRightNode(root, 4, 2, 9);
    // AddLeftNode (root, 4, 3, 10);
    // AddRightNode(root, 4, 4, 11);
    // AddLeftNode (root, 4, 5, 12);
    // AddRightNode(root, 4, 6, 13);
    // AddLeftNode (root, 4, 7, 14);
    // AddRightNode(root, 4, 8, 15);
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
void AddLeftNode(TreeNode* p, int layer, int number, char target)
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
                number -= CalAccumulation(2, layer-i)/2;
            }
        }
    } //循环结束即找到了需要添加孩子的节点
    cur->lnext = Lnode;
}

//在树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddRightNode(TreeNode* p, int layer, int number, char target)
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
                number -= CalAccumulation(2, layer-i)/2;
            }
        }
    } //循环结束即找到了需要添加孩子的节点
    cur->rnext = Lnode;
}

//*******前序***********************************************************

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

//前序打印二叉树
void PrintfPreTree(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\n", root->val);
    PrintfPreTree(root->lnext);
    PrintfPreTree(root->rnext);
}

//树的迭代前序遍历
void preOrder1(TreeNode* root, int* ret, int* returnSize)
{
    SqStack* S = CreateSqStack();
    if (root == NULL)
    {
        return;
    }
    PushSqStack(S, root);
    while (!SqStackEmpty(S))
    {
        TreeNode* node = ReadSqStack(S);
        PopSqStack(S);
        ret[(*returnSize)++] = node->val;
        if (node->rnext) PushSqStack(S, node->rnext);
        if (node->lnext) PushSqStack(S, node->lnext);
    }
}

//*******中序***********************************************************

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

//树的迭代中序遍历
void inOrder1(TreeNode* root, int* ret, int* num_size)
{
    SqStack* S = CreateSqStack();
    TreeNode* cur = root;
    while(cur != NULL || !SqStackEmpty(S))
    {
        if (cur != NULL)
        {
            PushSqStack(S, cur);
            cur = cur->lnext;
        }
        else
        {
            cur = PopSqStack(S);
            ret[(*num_size)++] = cur->val;
            cur = cur->rnext;
        }
    }
}

//*******后序***********************************************************

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

//树的迭代后序遍历
void postOrder1(TreeNode* root, int* ret, int* returnSize)
{
    SqStack* S = CreateSqStack();
    int temp = 0;
    if (root == NULL)
    {
        return;
    }
    PushSqStack(S, root);
    while (!SqStackEmpty(S))
    {
        TreeNode* node = ReadSqStack(S);
        PopSqStack(S);
        ret[(*returnSize)++] = node->val;
        if (node->lnext) PushSqStack(S, node->lnext);
        if (node->rnext) PushSqStack(S, node->rnext);
    }//出栈顺序为根，右，左， 后序遍历为左，右，根，所以最后再倒置
    for (int i = 0, j = *returnSize-1; i <= j; i ++, j --)
    {
        temp = ret[i];
        ret[i] = ret[j];
        ret[j] = temp;
    }
}

//树的非递归遍历2
void postOrder2(TreeNode* root, int* ret, int* returnSize)
{
    SqStack* S = CreateSqStack();
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    while (cur != NULL || !SqStackEmpty(S))
    {
        if (cur != NULL)
        {
            PushSqStack(S, cur);
            cur = cur->lnext;
        }
        else
        {
            cur = ReadSqStack(S);
            if (cur->rnext && cur->rnext != pre)
            {
                cur = cur->rnext;
            }
            else
            {
                cur = PopSqStack(S);
                ret[(*returnSize) ++] = cur->val;
                pre = cur;
                cur = NULL;
            }
        }
    }
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

//********层序遍历***********************

//从上往下，从左往右的层序遍历
void LevelOrder(TreeNode* root, int* ret, int* returnSize)
{
    SqQueue* Q = CreateSqQueue();
    TreeNode* cur = root;
    int size = 0;
    PushSqQueue(Q, cur);
    while(!EmptySqQueue(Q))
    {
        size = Q->rear - Q->front;
        //depth ++;                                 求深度只需要在这里添加一行
        for (int i = 0; i < size; i ++)
        {
            cur = PopSqQueue(Q);
            ret[(*returnSize)++] = cur->val;            //遍历的处理逻辑
            if (cur->lnext) PushSqQueue(Q, cur->lnext);
            if (cur->rnext) PushSqQueue(Q, cur->rnext);
        }
    }
}

//******题目**************************************************************

//判断二叉树是否为完全二叉树
int CheckFullyTree(TreeNode* root)
{
    if (root == NULL)
    {
        return 1;
    }
    TreeNode* cur = root;
    SqQueue* Q = CreateSqQueue();
    PushSqQueue(Q, cur);
    while (!EmptySqQueue(Q))
    {
        cur = PopSqQueue(Q);
        if (cur)
        {
            PushSqQueue(Q, cur->lnext);
            PushSqQueue(Q, cur->rnext);
        }
        else
        {
            while(!EmptySqQueue(Q))
            {
                cur = PopSqQueue(Q);
                if (cur)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

//一颗二叉树上有多少个度为二的节点
int TwoNodeNums(TreeNode* root)
{
    SqQueue* Q = CreateSqQueue();
    TreeNode* cur = root;
    int size = 0;
    int num = 0;
    PushSqQueue(Q, cur);
    while(!EmptySqQueue(Q))
    {
        size = Q->rear - Q->front;
        //depth ++;                                 求深度只需要在这里添加一行
        for (int i = 0; i < size; i ++)
        {
            cur = PopSqQueue(Q);
            if (cur->lnext && cur->rnext) num ++;
            if (cur->lnext) PushSqQueue(Q, cur->lnext);
            if (cur->rnext) PushSqQueue(Q, cur->rnext);
        }
    }
    return num;
}

//一颗二叉树上有多少个度为二的节点,递归算法
int TwoNodeNumsRecur(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->lnext && root->rnext)
    {
        return TwoNodeNumsRecur(root->lnext) + TwoNodeNumsRecur(root->rnext) + 1;
    }
    else
    {
        return TwoNodeNumsRecur(root->lnext) + TwoNodeNumsRecur(root->rnext);
    }
}


//翻转二叉树，递归法，前序遍历
TreeNode* InvertTree(TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp = root->lnext;
    root->lnext = root->rnext;
    root->rnext = temp;
    InvertTree(root->lnext);
    InvertTree(root->rnext);
    return root;
}

//翻转二叉树，迭代法，前序遍历
TreeNode* InvertTree2(TreeNode* root)
{
    SqStack* S = CreateSqStack();
    if (root == NULL)
    {
        return NULL;
    }
    PushSqStack(S, root);
    while(!SqStackEmpty(S))
    {
        TreeNode* cur = PopSqStack(S);
        TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
        temp = cur->lnext;
        cur->lnext = cur->rnext;
        cur->rnext = temp;
        if (cur->rnext) PushSqStack(S, cur->rnext);
        if (cur->lnext) PushSqStack(S, cur->lnext);
    }
    return root;
}

int count = 1;
//前序遍历返回第几个节点的值
int FindTreeNode(TreeNode* root, int num)
{
    int temp;
    if (root == NULL) return -1;
    if (count == num) return root->val;
    count ++;
    temp = FindTreeNode(root->lnext, num);
    if (temp == -1) //说明不再左子树中
    {
        return FindTreeNode(root->rnext, num);
    }
    return temp;
}

//删除以root为根的子树
void DeleteTree(TreeNode* root)
{
    if (root->rnext) DeleteTree(root->rnext);
    if (root->lnext) DeleteTree(root->lnext);
    free(root);
}

//删除指定值的节点,前序遍历，不能只用free，得使该父节点指向null，释放空间得释放该节点的所有子节点的空间，free只释放一个节点的空间
TreeNode* DeleteNode(TreeNode* root, int target)
{
    if (root == NULL || root->val == target)
    {
        DeleteTree(root);
        return root;
    }
    if (root->lnext->val == target)
    {
        DeleteTree(root->lnext);
        root->lnext = NULL;
        return root;
    }
    if (root->rnext->val == target)
    {
        DeleteTree(root->rnext);
        root->rnext = NULL;
        return root;
    }
    if (root->lnext) DeleteNode(root->lnext, target);
    if (root->rnext) DeleteNode(root->rnext, target);
    return root;
}

//求树的最大深度,后序遍历
int MaxDepthTree(TreeNode* root)
{
    if (root == NULL)     //递归返回条件，递归到空节点为止
    {
        return 0;
    }
    int leftdepth = MaxDepthTree(root->lnext);
    int rightdepth = MaxDepthTree(root->rnext);
    int depth = 1 + max(leftdepth, rightdepth);   //最终的深度取决于前面两个函数递归了多少次
    return depth;
}

//求树的最小深度,指的是从深度最小的叶子节点开始到根节点的路径,使用后序遍历
int MinDepthTree(TreeNode* root)
{
    if (root == NULL) return 0;   //递归结束条件，递归到空节点为止
    int leftdepth = MinDepthTree(root->lnext);
    int rightdepth = MinDepthTree(root->rnext);
    if (root->rnext == NULL && root->lnext != NULL)  //右节点为空，但是左节点非空，不是最小深度，返回左节点的深度
    {
        return leftdepth + 1;
    } 
    if (root->rnext != NULL && root->lnext == NULL)  //左节点为空，但是右节点非空，不是最小深度，返回右节点的深度
    {
        return rightdepth + 1;
    }
    int depth = 1 + min(rightdepth, leftdepth);
    return depth;
}

// //求出树的所有路径,字符串
// void construct_paths(TreeNode* root, char** paths, int* returnSize, int* sta, int top) 
// {
//     if (root != NULL) {
//         if (root->lnext == NULL && root->rnext == NULL) {  // 当前节点是叶子节点
//             char* tmp = (char*)malloc(1001);
//             int len = 0;
//             for (int i = 0; i < top; i++) {
//                 len += sprintf(tmp + len, "%d->", sta[i]);
//             }
//             sprintf(tmp + len, "%d", root->val);
//             paths[(*returnSize)++] = tmp;  // 把路径加入到答案中
//         } else {
//             sta[top++] = root->val;  // 当前节点不是叶子节点，继续递归遍历
//             construct_paths(root->lnext, paths, returnSize, sta, top);
//             construct_paths(root->rnext, paths, returnSize, sta, top); //递归的同时完成了回溯
//         }
//     }
// }

//找到所有叶子节点的路径主函数
int** FindAllPaths(TreeNode* root, int* returnSize)
{
    int** result_path = (int**)malloc(sizeof(int*) * MaxSize);  //存放结果
    *returnSize = 0; //记录路径数
    int* cur;   //暂存一条路径
    construct_paths(root, result_path, returnSize, cur, 0);
    return result_path;
}

//构建所有叶子节点的路径
void construct_paths(TreeNode* root, int** paths, int* returnSize, int* cur, int top)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext == NULL && root->rnext == NULL)  //当前节点为叶子节点，说明一条路径已经遍历完了，要将路径存入结果中
    {
        int* temp = (int*)malloc(sizeof(int) * MaxSize);
        for (int i = 0; i < top; i ++)  //这里需要注意必须使用top，直接赋予指针cur的化会导致后面的路径也会加进来
        {
            temp[i] = cur[i];   //这里需要注意的是不能把paths当作二维数组来操作，因为二重指针和二维数组不是同一个东西，指针的长度和int的长度可能不同
        }
        temp[top] = root->val;
        paths[(*returnSize)++] = temp;
    }
    cur[top++] = root->val;   //路径放入暂存数组中
    construct_paths(root->lnext, paths, returnSize, cur, top); //一直向左遍历
    construct_paths(root->rnext, paths, returnSize, cur, top); //左子树的情况遍历完之后遍历右子树的同时，因为top传的不是指针，同时导致了回溯
}

// //找到值为x的所有祖先
// void FindAllAncestor(TreeNode* root, int target)
// {
//     if (root == NULL)
//     {
//         return ;
//     }
//     SqStack* S = CreateSqStack();
//     while(root != NULL || S->top >= 0)
//     {
//         while(root != NULL && root->val != target)
//         {
//             PushSqStack(S, root);
//         }
//     }
// }

//找最近的公共祖先,必须是同一棵树上的节点，不同树上的节点值相同不能用
TreeNode* FindLowestCommonAnestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == q || root == p || root == NULL)   //返回条件：找到了目标节点或者遍历到了根节点
    {
        return root;
    }
    TreeNode* left = FindLowestCommonAnestor(root->lnext, p, q);     //除了q和p会返回值之外，其他所有的都返回NULL
    TreeNode* right = FindLowestCommonAnestor(root->rnext, p, q);
    if (left != NULL && right != NULL)   //该节点的左右子树都有目标节点，有且只有一个最近的公共祖先满足这个条件
    {
        return root;
    }
    if (left == NULL && right != NULL)   //左子树没有，在右子树
    {
        return right;
    }
    else if (left != NULL && right == NULL) //右子树没有，在左子树
    {
        return left;
    }//left==null, right==null
    return NULL;            //左子树和右子树都没有
}


//求二叉树的最大宽度,采用层序遍历
int MaxWidth(TreeNode* root)
{
    SqQueue* Q = CreateSqQueue();
    PushSqQueue(Q, root);
    int sum = 0;
    while (!EmptySqQueue(Q))
    {
        int size = Q->rear - Q->front;
        sum = size > sum ? size : sum;
        for (int i = 0; i < size; i ++)
        {
            root = PopSqQueue(Q);
            if (root->lnext) PushSqQueue(Q, root->lnext);
            if (root->rnext) PushSqQueue(Q, root->rnext);
        }
    }
    return sum;
}

//由前序遍历求后序遍历,只有满二叉树才能实现，普通二叉树只有一种遍历不能求出另一种遍历
//前序遍历的结构：根 ｜ 左子树的根 左子树 右子树 ｜ 右子树的根 左子树 右子树
//后序遍历的结构：左子树的根 左子树 右子树 ｜ 右子树的根 左子树 右子树 ｜ 根
//思路：将结构不断视为 根｜左子树｜右子树，进行递归交换为 左子树 ｜ 右子树 ｜ 根
void PreToPost(int* pre, int* post, int start, int end, int* num)
{
    if (start > end)       //递归结束条件
    {
        return ;
    }
    int root = pre[start];
    if (start == end)      //递归结束条件
    {
        post[*num] = root;
        (*num) ++;
        return ;
    }
    int halfsize = (end - start) / 2;
    PreToPost(pre ,post, start+1, start+halfsize, num);  //遍历左子树
    PreToPost(pre, post, start+halfsize+1, end, num);    //遍历右子树
    post[*num] = root;  //加上根
    (*num) ++;
}

//在链表尾部加入一个节点
void ListAddTail(List* L, List* new)
{
    List* cur = L;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new;
}

//树的后序遍历,操作函数为将叶子添加到链表中
void postOrder3(TreeNode* root, List* list)
{
    if(root == NULL)
    {
        return;
    }
    postOrder3(root->lnext, list);
    postOrder3(root->rnext, list);
    if (root->lnext == NULL && root->rnext == NULL)
    {
        List* node = (List*)malloc(sizeof(List));
        node->val = root->val;
        node->next = NULL;
        ListAddTail(list, node);
    }
}

//将二叉树的所有叶子节点从左到右链接成一个单独的链表,采用后序遍历
List* AllLeafList(TreeNode* root)
{
    List* returnlist = (List*)malloc(sizeof(List));
    returnlist->next = NULL;
    postOrder3(root, returnlist);
    return returnlist;
}

//打印有头节点链表中的信息
void printf_headlist(List *L)
{
    int i = 1;
    List *p = L->next;
    while (p != NULL)
    {
        printf("%d:%d\n",i++, p->val);
        p = p->next;
    }
}

//将二叉树的所有叶子节点链接起来，使用叶子节点的右指针来指向下一个叶子节点,采用层序遍历
void AllLeafList2(TreeNode* root)
{
    SqQueue* Q = CreateSqQueue();
    PushSqQueue(Q, root);
    while (!EmptySqQueue(Q))
    {
        TreeNode* cur = PopSqQueue(Q);
        if (cur->lnext) PushSqQueue(Q, cur->lnext);
        if (cur->rnext) PushSqQueue(Q, cur->rnext);
        if (cur->lnext == NULL && cur->rnext == NULL)  //为叶子节点
        {
            cur->rnext = ReadSqQueue(Q);
        }
    }
}

//判断两个二叉树是否相似,采用同时对两个树进行前序遍历
int Similar1(TreeNode* root1, TreeNode* root2)
{
    int num = 1;
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    else if (root1 == NULL || root2 == NULL) //一个节点为空，另一个不为空
    {
        printf("no similar\n");
        return 0;
    }
    if (num) 
    {
        num = Similar1(root1->lnext, root2->lnext);
    }
    else
    {
        return 0;
    }
    if (num)
    {
        num = Similar1(root1->rnext, root2->rnext);
    }
    else
    {
        return 0;
    }
    return num;
}

//判断两个二叉树是否相似,采用同时对两个树进行前序遍历
int Similar(TreeNode* root1, TreeNode* root2)
{
    int left, right;
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    else
    {
        left = Similar(root1->lnext, root2->lnext);
        right = Similar(root1->rnext, root2->rnext);
        return left && right;
    }
}

//统计二叉树中度为1的节点,采用前序遍历
void CalOneNode(TreeNode* root, int* sum)
{
    if (root == NULL)
    {
        return ;
    }
    if ((root->lnext == NULL && root->rnext != NULL) || (root->lnext != NULL && root->rnext == NULL))
    {
        (*sum) ++;
    }
    if (root->rnext) CalOneNode(root->rnext, sum);
    if (root->lnext) CalOneNode(root->lnext, sum);
}

//统计二叉树中度为2的节点,采用前序遍历
void CalTwoNode(TreeNode* root, int* sum)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext != NULL && root->rnext != NULL)
    {
        (*sum) ++;
    }
    if (root->rnext) CalTwoNode(root->rnext, sum);
    if (root->lnext) CalTwoNode(root->lnext, sum);
}

//统计二叉树中度为0的节点,采用前序遍历
void CalZeroNode(TreeNode* root, int* sum)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext == NULL && root->rnext == NULL)
    {
        (*sum) ++;
    }
    if (root->rnext) CalZeroNode(root->rnext, sum);
    if (root->lnext) CalZeroNode(root->lnext, sum);
}

//从二叉树中删除所有叶节点
void DeleteZeroNode(TreeNode* root, TreeNode* pre, int num)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext == NULL && root->rnext == NULL)  //为叶子节点
    {
        if (num)  //为右节点
        {
            pre->rnext = NULL;
            free(root);
        }
        else      //为左节点
        {
            pre->lnext = NULL;
            free(root);
        }
    }
    if (root->rnext) DeleteZeroNode(root->rnext, root, 1);
    if (root->lnext) DeleteZeroNode(root->lnext, root, 0);
}

//计算指定节点p所在的层次，采用层序遍历
int FindNodeLevel(TreeNode* root, TreeNode* target, int* num)
{
    SqQueue* Q = CreateSqQueue();
    PushSqQueue(Q, root);
    while(!EmptySqQueue(Q))
    {
        int size = Q->rear - Q->front;
        for (int i = 0; i < size; i ++)
        {
            root = PopSqQueue(Q);
            if (root == target)
            {
                return (*num);
            }
            if (root->lnext) PushSqQueue(Q, root->lnext);
            if (root->rnext) PushSqQueue(Q, root->rnext);
        }
        (*num) ++;
    }
    return 0;
}

//找到二叉树中最大元素值,前序遍历
void FindMaxNode(TreeNode* root, int* num)
{
    if (root == NULL)
    {
        return ;
    }
    *num = (*num) > root->val ? (*num) : root->val;
    if (root->lnext) FindMaxNode(root->lnext, num);
    if (root->rnext) FindMaxNode(root->rnext, num);
}

//14年统考题，计算带权路径长度
void WPL2014(TreeNode* root, int* sum, int depth)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext == NULL && root->rnext == NULL)
    {
        *sum += (root->val) * depth;
    }
    if (root->lnext) WPL2014(root->lnext, sum, depth+1);
    if (root->rnext) WPL2014(root->rnext, sum, depth+1);
}

//17年统考题，中序遍历转换为表达式
void Char2017(TreeNode* root, char* num, int* size)
{
    if (root == NULL)
    {
        return ;
    }
    if (root->lnext)
    {
        num[(*size)++] = '(';
        Char2017(root->lnext, num, size);
    }
    if (root->lnext == NULL && root->rnext != NULL)
    {
        num[(*size)++] = '(';
        num[(*size)++] = root->val;
    }
    else
    {
        num[(*size)++] = root->val;
    }
    // num[(*size)++] = root->val;

    if (root->rnext) 
    {
        Char2017(root->rnext, num, size);
        num[(*size)++] = ')';
    }
}

//2017年统考题，观察可得到，除了根节点和叶节点外，遍历到其他节点时在左子树上加上左括号，在右子树上加上右括号
void Char2017Std(TreeNode* root, int depth)
{
    if (root == NULL)
    {
        return ;
    }
    else if (root->lnext == NULL && root->rnext == NULL)
    {
        printf("%c", root->val);
    }
    else
    {
        if (depth > 1)
        {
            printf("(");
        }
        Char2017Std(root->lnext, depth+1);
        printf("%c", root->val);
        Char2017Std(root->rnext, depth+1);
        if (depth > 1) 
        {
            printf(")");
        }
    }
}

//********栈**************************

//********顺序栈的基本操作**************

//创建一个栈
SqStack* CreateSqStack(void)
{
    SqStack* S = (SqStack* )malloc(sizeof(SqStack));
    S->top = -1;
    return S;
}


//初始化栈
void InitSqStack(SqStack* S)
{
    S->top = -1;
}

//判断栈是否为空
int SqStackEmpty(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty\n");
        return 1;
    }
    return 0;
}

//进栈
void PushSqStack(SqStack* S, variable_type x)
{
    if (S->top == MaxSize)
    {
        printf("the stack is full\n");
        return ;
    }
    S->data[++S->top] = x;
}

//出栈
variable_type PopSqStack(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty");
        return 0;
    }
    variable_type x = S->data[S->top];
    S->top --;
    return x;
}

//读栈顶元素
variable_type ReadSqStack(SqStack* S)
{
    if (S->top == -1)
    {
        printf("the stack is empty\n");
        return 0;
    }
    return S->data[S->top];
}

//********链式栈的基本操作**************

//创建一个节点
LinkStack* CreateLinkStack(variable_type num)
{
    LinkStack* cur = (LinkStack* )malloc(sizeof(LinkStack));
    cur->val = num;
    cur->next = NULL;
    return cur;
}

//判断栈是否为空
int LinkStackEmpty(LinkStack* l)
{
    if (l->next == NULL)
    {
        printf("the linkstack is empty\n");
        return 0;
    }
    return 1;
}

//入栈
void PushLinkStack(LinkStack* l, variable_type num)
{
    LinkStack* p = CreateLinkStack(num);
    p->next = l->next;
    l->next = p;
}

//出栈
variable_type PopLinkStack(LinkStack* l)
{
    LinkStack* cur = l->next;
    l->next = l->next->next;
    variable_type x = cur->val;
    free(cur);
    return x;
}

//读栈顶元素
variable_type ReadLinkStack(LinkStack* l)
{
    return l->next->val;
}

//*******队列***********************************************************

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
        return NULL;
    }
    variable_type temp = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return temp;
}

//读队头元素
variable_type ReadSqQueue(SqQueue* Q)
{
    return Q->data[Q->front];
}

//*******链式存储队列***********************************************************

//创建一个链式存储队列
LinkQueue* CreateLinkQueue(void)
{
    LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
    Q->front->next = NULL;
    Q->rear = Q->front;
    return Q;
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
    Q->rear->next->val = target;  //插入链尾
    Q->rear = Q->rear->next;
}

//出队
variable_type PopLinkQueue(LinkQueue* Q)
{
    if (Q->front == Q->rear)
    {
        printf("the queue is empty\n");
        return NULL;
    }
    LinkNode* temp = Q->front->next;       //有头节点
    Q->front->next = Q->front->next->next;
    variable_type val = temp->val;
    free(temp);
    return val;
}

//*******线索二叉树***********************************************************

//创建一个作为调试的线索树
ThreadTreeNode* CreateTestThreadTree(void)
{
    ThreadTreeNode* root = CreateRootThreadTree();
    root->val = 1;
    AddThreadLeftNode(root, 2, 1, 2);  //在第二层的第一个位置添加一个数值为2的节点
    AddThreadRightNode(root, 2, 2, 3);
    AddThreadLeftNode(root, 3, 1, 4);
    AddThreadRightNode(root, 3, 2, 5);
    return root;
}

//创建一个线索树的根节点
ThreadTreeNode* CreateRootThreadTree(void)
{
    ThreadTreeNode* root = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode));
    root->rnext = NULL;
    root->lnext = NULL;
    root->rtag = 0;
    root->ltag = 0;
    return root;
}

//在树的第layer层的第number个位置添加一个节点作为左孩子，如果双亲不存在就返回错误
void AddThreadLeftNode(ThreadTreeNode* p, int layer, int number, int target)
{
    ThreadTreeNode* Lnode = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode)); //先将节点创建好
    Lnode->rnext = NULL;
    Lnode->lnext = NULL;
    Lnode->ltag = 0;
    Lnode->rtag = 0;
    Lnode->val = target;

    ThreadTreeNode* cur = p;
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
void AddThreadRightNode(ThreadTreeNode* p, int layer, int number, int target)
{
    ThreadTreeNode* Lnode = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode)); //先将节点创建好
    Lnode->rnext = NULL;
    Lnode->lnext = NULL;
    Lnode->ltag = 0;
    Lnode->rtag = 0;
    Lnode->val = target;

    ThreadTreeNode* cur = p;
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

//*******前序***********************************************************

//前序遍历线索化树
void CreatePreOrderThreadTree(ThreadTreeNode* root)
{
    ThreadTreeNode* pre1 = NULL;
    if (root != NULL)
    {
        ThreadpreOrder(root, &pre1);
        pre1->rnext = NULL;
        pre1->rtag = 1;
    }
}

//前序遍历线索化树的递归写法
void ThreadpreOrder(ThreadTreeNode* p, ThreadTreeNode* *pre1)
{
    if (p != NULL)
    {
        if (p->lnext == NULL)
        {
            p->lnext = (*pre1);
            p->ltag = 1;
        }
        if ((*pre1) != NULL && (*pre1)->rnext == NULL)
        {
            (*pre1)->rnext = p;
            (*pre1)->rtag = 1;
        }
        (*pre1) = p;
        if (p->ltag == 0)
        {
            ThreadpreOrder(p->lnext, pre1);
        }
        ThreadpreOrder(p->rnext, pre1);
    }
}

//找前序线索树的后继节点
ThreadTreeNode* FindPreorderNextNode(ThreadTreeNode* p)
{
    ThreadTreeNode* cur = p;
    if (cur->rtag == 1)
    {
        return cur->rnext;
    }
    else
    {
        if (cur->ltag == 0)
        {
            return cur->lnext;
        }
        else
        {
            return cur->rnext;
        }
    }
    return cur;
}

//遍历前序线索树
void Preorder(ThreadTreeNode* root)
{
    for (ThreadTreeNode* cur = FirstPreorderNode(root); cur != NULL; cur = FindPreorderNextNode(cur))
    {
        visit(cur);
    }
}

//前序线索树的第一个节点就是根节点
ThreadTreeNode* FirstPreorderNode(ThreadTreeNode* root)
{
    return root;
}

//前序线索树的最后一个节点就是右子树的最下一层的节点，优先向右走
ThreadThreeNode* LastPreorderNode(ThreadThreeNode* root)
{
    ThreadThreeNode* cur = root;
    while (cur->ltag == 0 || cur->rtag == 0)
    {
        if (cur->rtag == 0)
        {
            cur = cur->rnext;
            continue;
        }
        else if (cur->ltag == 0)
        {
            cur = cur->lnext;
            continue;
        }
    }
    return cur;
}

//找前序线索树的前驱节点，因为前序的顺序为根，左，右，所以找前驱的话必须找双亲，不能直接用线索
//解决方法有：重头开始遍历，使用三叉链表
ThreadThreeNode* FindPreorderPreNode(ThreadThreeNode* p)
{
    ThreadThreeNode* cur = p;
    if (cur->prenext == NULL)   //为根节点
    {
        return NULL;
    }
    else
    {
        if (cur->prenext->lnext == cur)  //cur为其父节点的左孩子
        {
            return cur->prenext;
        }
        else                             //cur为其父节点的右孩子
        {
            cur = cur->prenext;          //找到其父节点的左孩子的最下一层的节点
            cur = cur->lnext;
            while (cur->rtag == 0 || cur->ltag == 0)
            {
                if (cur->rtag == 0)
                {
                    cur = cur->rnext;
                    continue;
                }
                else
                {
                    cur = cur->lnext;
                    continue;
                }
            }
            return cur;
        }
    }
    return cur;
}

//反向遍历前序线索树
void PreorderConverse(ThreadThreeNode* root)
{
    for (ThreadThreeNode* cur = LastPreorderNode(root); cur != NULL; cur = FindPreorderPreNode(cur))
    {
        printf("%d\n",cur->val);
    }
}

//*******前序***********************************************************

//*******中序***********************************************************

ThreadTreeNode* pre = NULL;
//中序遍历线索化树
void ThreadInOrder(ThreadTreeNode* root)
{
    //ThreadTreeNode* pre = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode));
    if (root != NULL)
    {
        ThreadInOrder(root->lnext);
        ThreadVisit(root);
        ThreadInOrder(root->rnext);
    }
}

//在访问该节点时修改左指针和右指针为前继节点和后继节点
void ThreadVisit(ThreadTreeNode* p)
{
    if (p->lnext == NULL)
    {
        p->lnext = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rnext == NULL)
    {
        pre->rnext = p;
        pre->rtag = 1;
    }
    pre = p;
}

//中序遍历线索化树的主函数,非递归，使用全局变量pre
void CreateInOrderThreadTree(ThreadTreeNode* root)
{
    pre = NULL;
    if (root != NULL)
    {
        ThreadInOrder(root);
        pre->rnext = NULL;
        pre->rtag = 1;
    }
}

//中序遍历线索化树的递归写法主函数
void CreateInOrderThreadTree1(ThreadTreeNode* root)
{
    ThreadTreeNode *pre1 = NULL;
    if (root != NULL)
    {
        ThreadInOrder1(root, &pre1);
        pre1->rnext = NULL;
        pre1->rtag = 1;
    }
}

//中序遍历线索化树的递归写法，C中没有引用，只有C++才有，所以必须使用指针来实现，也就是结构体指针的指针
void ThreadInOrder1(ThreadTreeNode* p, ThreadTreeNode* *pre1) 
{
    if (p != NULL)
    {
        ThreadInOrder1(p->lnext, pre1);
        if (p->lnext == NULL)
        {
            p->lnext = (*pre1);
            p->ltag = 1;
        }
        if (pre1 != NULL && (*pre1)->rnext == NULL)
        {
            (*pre1)->rnext = p;
            (*pre1)->rtag = 1;
        }
        *pre1 = p;
        ThreadInOrder1(p->rnext, pre1);
    }
}

//找中序线索树的后继
ThreadTreeNode* FindInorderNextNode(ThreadTreeNode* p)
{
    ThreadTreeNode* cur = p;
    if (cur->rtag == 1)
    {
        return cur->rnext;
    }
    else
    {
        cur = cur->rnext;
        while(cur->ltag == 0)  //如果有右孩子，找到右孩子中最左边的节点
        {
            cur = cur->lnext;
        }
        return cur;
    }
    return cur;
}

//找中序线索树的前驱
ThreadTreeNode* FindInorderPreNode(ThreadTreeNode* p)
{
    ThreadTreeNode* cur = p;
    if (cur->ltag == 1)
    {
        return cur->lnext;     //有线索直接返回
    }
    else
    {
        cur = cur->lnext;
        while(cur->rtag == 0)
        {
            cur = cur->rnext;
        }
        return cur;
    }
    return cur;
}

//找到中序线索树的第一个节点
ThreadTreeNode* FirstInordernode(ThreadTreeNode* p)
{
    while (p->ltag == 0)
    {
        p = p->lnext;
    }
    return p;
}

//找到中序线索树最后一个节点
ThreadTreeNode* LastInordernode(ThreadTreeNode* p)
{
    while (p->rtag == 0)
    {
        p = p->rnext;
    }
    return p;
}

//遍历中序线索树
void Inorder(ThreadTreeNode* root)
{
    for (ThreadTreeNode* p = FirstInordernode(root); p != NULL; p = FindInorderNextNode(p))
    {
        visit(p);
    }
}

//反向遍历中序线索树
void InorderConverse(ThreadTreeNode* root)
{
    for (ThreadTreeNode* p = LastInordernode(root); p != NULL; p = FindInorderPreNode(p))
    {
        visit(p);
    }
}

//*******中序***********************************************************

//*******后序***********************************************************

//后序遍历线索化树
void CreatePostOrderThreadTree(ThreadTreeNode* root)
{
    ThreadTreeNode* pre1 = NULL;
    if (root != NULL)
    {
        ThreadpostOrder(root, &pre1);
        pre1->rnext = NULL;
        pre1->rtag = 1;
    }
}

//后序遍历线索化树的递归写法
void ThreadpostOrder(ThreadTreeNode* p, ThreadTreeNode* *pre1)
{
    if (p != NULL)
    {
        ThreadpostOrder(p->lnext, pre1);
        ThreadpostOrder(p->rnext, pre1);
        if (p->lnext == NULL)
        {
            p->lnext = (*pre1);
            p->ltag = 1;
        }
        if ((*pre1) != NULL && (*pre1)->rnext == NULL)
        {
            (*pre1)->rnext = p;
            (*pre1)->rtag = 1;
        }
        (*pre1) = p;
    }
}

//找后序线索树的后继节点,后序遍历为左，右，根，所以找后继需要找其父节点
ThreadThreeNode* FindPostorderNextNode(ThreadThreeNode* p)
{
    ThreadThreeNode* cur = p;
    if (p->rtag == 1)                   //有线索
    {
        return cur->rnext;
    }
    else                                //无线索
    {
        if (cur->prenext->rnext == cur) //cur为右孩子，直接返回父节点
        {
            return cur->prenext;
        }
        else                            //cur为左孩子，则如果右兄弟为空，前驱为父节点，右兄弟非空，前驱为右兄弟的最下面的节点
        {
            cur = cur->prenext;
            if (cur->rtag == 1)         //右孩子为空，说明p为左孩子，直接返回
            {
                return cur;
            }
            else
            {
                cur = cur->rnext;
                while (cur->rtag == 0 || cur->ltag == 0) //找到右孩子左子树最下层的节点
                {
                    if (cur->ltag == 0)
                    {
                        cur = cur->lnext;
                        continue;
                    }
                    else
                    {
                        cur = cur->rnext;
                    }
                }
            }
        }
    }
    return cur;
}

//找后序线索树的前驱节点
ThreadTreeNode* FindPostorderPreNode(ThreadTreeNode* p)
{
    ThreadTreeNode* cur = p;
    if (cur->ltag == 1)
    {
        return cur->lnext;
    }
    else
    {
        if (cur->rtag == 0)
        {
            return cur->rnext;
        }
        else
        {
            return cur->lnext;
        }
    }
    return cur;
}

//*******后序***********************************************************

//*******三叉链表二叉树***********************************************************

//创建一个三叉链表线索树的根节点
ThreadThreeNode* CreateRootThreadThreeTree(void)
{
    ThreadThreeNode* root = (ThreadThreeNode *)malloc(sizeof(ThreadThreeNode));
    root->rnext = NULL;
    root->lnext = NULL;
    root->prenext = NULL;
    root->rtag = 0;
    root->ltag = 0;
    return root;
}

//创建一个作为调试的三叉链表线索树
ThreadThreeNode* CreateTestThreadThreeTree(void)
{
    ThreadThreeNode* root = CreateRootThreadThreeTree();
    root->val = 1;
    AddThreadThreeLeftNode(root, 2, 1, 2);  //在第二层的第一个位置添加一个数值为2的节点
    AddThreadThreeRightNode(root, 2, 2, 3);
    AddThreadThreeLeftNode(root, 3, 1, 4);
    AddThreadThreeRightNode(root, 3, 2, 5);
    return root;
}

//在树的第layer层的第number个位置添加一个节点作为左孩子，如果双亲不存在就返回错误
void AddThreadThreeLeftNode(ThreadThreeNode* p, int layer, int number, int target)
{
    ThreadThreeNode* Lnode = (ThreadThreeNode *)malloc(sizeof(ThreadThreeNode)); //先将节点创建好
    Lnode->rnext = NULL;
    Lnode->lnext = NULL;
    Lnode->prenext = NULL;
    Lnode->ltag = 0;
    Lnode->rtag = 0;
    Lnode->val = target;

    ThreadThreeNode* cur = p;
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
    Lnode->prenext = cur;
}

//在树的第几层的第几个节点添加右孩子,layer表示层数，number表示第几个节点，如果节点不存在就返回错误
void AddThreadThreeRightNode(ThreadThreeNode* p, int layer, int number, int target)
{
    ThreadThreeNode* Lnode = (ThreadThreeNode *)malloc(sizeof(ThreadThreeNode)); //先将节点创建好
    Lnode->rnext = NULL;
    Lnode->lnext = NULL;
    Lnode->ltag = 0;
    Lnode->rtag = 0;
    Lnode->val = target;

    ThreadThreeNode* cur = p;
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
    Lnode->prenext = cur;
}

//前序遍历线索化三叉链表树
void CreatePreOrderThreadThreeTree(ThreadThreeNode* root)
{
    ThreadThreeNode* pre1 = NULL;
    if (root != NULL)
    {
        ThreadThreepreOrder(root, &pre1);
        pre1->rnext = NULL;
        pre1->rtag = 1;
    }
}

//前序遍历线索化三叉链表树的递归写法
void ThreadThreepreOrder(ThreadThreeNode* p, ThreadThreeNode* *pre1)
{
    if (p != NULL)
    {
        if (p->lnext == NULL)
        {
            p->lnext = (*pre1);
            p->ltag = 1;
        }
        if ((*pre1) != NULL && (*pre1)->rnext == NULL)
        {
            (*pre1)->rnext = p;
            (*pre1)->rtag = 1;
        }
        (*pre1) = p;
        if (p->ltag == 0)
        {
            ThreadThreepreOrder(p->lnext, pre1);
        }
        ThreadThreepreOrder(p->rnext, pre1);
    }
}

//*******公共操作***********************************************************

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

//打印节点的值
void visit(ThreadTreeNode* p)
{
    printf("%d\n",p->val);
}

//求两个值之间的较大值
int max(int x, int y)
{
    return x>y ? x : y;
}

//求两个值之间的较小值
int min(int x, int y)
{
    return x>y ? y : x;
}
