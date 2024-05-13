#include "tree.h"

int main(void)
{
    TreeNode* test = CreateTestTree();
    int num_size = 0;
    int num[MaxSize];
    postOrder1(test, num, &num_size);
    for (int i = 0; i < num_size; i ++)
    {
        printf("%d\n", num[i]);
    }
    return 0;
}

//*******普通二叉树***********************************************************

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
    }
    for (int i = 0, j = *returnSize-1; i <= j; i ++, j --)
    {
        temp = ret[i];
        ret[i] = ret[j];
        ret[j] = temp;
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

//*******栈***********************************************************

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

