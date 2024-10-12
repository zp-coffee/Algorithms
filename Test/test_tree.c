#include "test_tree.h"

int tree_test[MaxSize];

int main(void)
{
    FatherTree* tree = (FatherTree*)malloc(sizeof(FatherTree));
    InitFatherTree(tree);
    
    InsertNode(tree, 1, -1);  // 根节点
    InsertNode(tree, 2, 0);   // A的孩子
    InsertNode(tree, 3, 0);   // A的孩子
    // InsertNode(&tree, 4, 1);   // B的孩子
    // InsertNode(&tree, 5, 1);   // B的孩子
    // InsertNode(&tree, 6, 2);   // C的孩子
    // InsertNode(&tree, 7, 2);   // C的孩子

    printf("%d\n", Find_Fathernode(tree, 2));
    return 0;
}

#if beginfromzero

//初始化
void Init_tree(int* num)
{
    for (int i = 0; i < MaxSize; i ++)
    {
        *num++ = i;
    }
}

//找父节点
int Find_Father(int i)
{   
    if (i == 1)
    {
        printf("this is root!\n");
        return -1;
    }
    return i/2;
}

//找左孩子
int Find_LeftChild(int i)
{
    if (i > MaxSize/2)
    {
        //printf("no leftchild!\n");
        return -1;
    }
    return 2*i;
}

//找右孩子
int Find_RightChild(int i)
{
    if (i >= MaxSize/2)
    {
        //printf("no rightchild!\n");
        return -1;
    }
    return 2*i + 1;
}

//前序遍历
void PreOrder(int* tree, int num)
{
    if (num >= MaxSize || num < 0)
    {
        return ;
    }
    printf("%d\n", tree[num]);
    PreOrder(tree, Find_LeftChild(num));
    PreOrder(tree, Find_RightChild(num));
}

//中序遍历
void InOrder(int* tree, int num)
{
    if (num >= MaxSize || num < 0)
    {
        return ;
    }
    InOrder(tree, Find_LeftChild(num));
    printf("%d\n", tree[num]);
    InOrder(tree, Find_RightChild(num));
};

//后序遍历
void PostOrder(int* tree, int num)
{
    if (num >= MaxSize || num < 0)
    {
        return ;
    }
    PostOrder(tree, Find_LeftChild(num));
    PostOrder(tree, Find_RightChild(num));
    printf("%d\n", tree[num]);
};

#else

//初始化
void Init_tree(int* num)
{
    for (int i = 0; i < MaxSize; i ++)
    {
        *num++ = i;
    }
}

//找父节点
int Find_Father(int i)
{   
    if (i == 0)
    {
        printf("this is root!\n");
        return -1;
    }
    return (i-1)/2;
}

//找左孩子
int Find_LeftChild(int i)
{
    if (i >= MaxSize/2)
    {
        //printf("no leftchild!\n");
        return -1;
    }
    return 2*i+1;
}

//找右孩子
int Find_RightChild(int i)
{
    if (i >= MaxSize/2-1)
    {
        //printf("no rightchild!\n");
        return -1;
    }
    return 2*i + 2;
}

//前序遍历
void PreOrder(int* tree, int num)
{
    if (num >= MaxSize || num < 0)
    {
        return ;
    }
    printf("%d\n", tree[num]);
    PreOrder(tree, Find_LeftChild(num));
    PreOrder(tree, Find_RightChild(num));
}

//中序遍历
void InOrder(int* tree, int num)
{
    if (num >= MaxSize || num < 0)
    {
        return ;
    }
    InOrder(tree, Find_LeftChild(num));
    printf("%d\n", tree[num]);
    InOrder(tree, Find_RightChild(num));
}

//后序遍历
void PostOrder(int* tree, int num)
{
    if (num >= MaxSize || num < 0)
    {
        return ;
    }
    PostOrder(tree, Find_LeftChild(num));
    PostOrder(tree, Find_RightChild(num));
    printf("%d\n", tree[num]);
}

#endif


//双亲表示法
//初始化
void InitFatherTree(FatherTree* tree)
{
    tree->size = 0;
}

//插入节点
void InsertNode(FatherTree* tree, int data, int father_index)
{
    if (tree->size < MaxSize)
    {
        tree->nodes[tree->size].data = data;
        tree->nodes[tree->size].parent = father_index;
        tree->size ++;
    }
    else 
    {
        printf("this tree is full!\n");
    }
}

//查找父节点
int Find_Fathernode(FatherTree* tree, int i)
{
    if (i >= 0 && i < tree->size)
    {
        return tree->nodes[i].parent;
    }
    return -1;
}
