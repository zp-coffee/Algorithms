#include "test_union.h"

int UFSets[Max_Size];

void Initial(int S[])
{
    for (int i = 0; i < Max_Size; i ++)
    {
        S[i] = -1;
    }
}

//查找包含元素x的树的根
int Find(int S[], int x) 
{
    Graph* G;
    G->nodes[1].firstArcnode->nextnode->adjvex = 10;
    while (S[x] >= 0)  //当S[x]=-1的时候，说明这时x为根
    {
        x = S[x];  //S[x]代表父节点，x代表孩子节点
    }
    return x;
}

//求两个不相交子集合的并集
void Union(int S[], int root1, int root2)
{
    if (root1 == root2)
    {
        return ;
    }
    S[root2] = root1;  //root2这棵树接到root1树下作为孩子
}

//优化的并操作，将小树并到大树下，能减少树的高度，减少find的时间复杂度
void Union_pro(int S[], int root1, int root2)
{
    if (root1 == root2) return;
    if (S[root2] > S[root1])
    {
        S[root1] += S[root2];  //root2节点数更少，小树接到大树
        S[root2] = S[root1];
    }
    else
    {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}

//查找的优化，查找到根的同时，将路径进行压缩
void Find_pro(int S[], int x)
{
    int root = x;
    while(S[root] >= 0)  //循环找到根
    {
        root = S[root];
    } //最后root等于根
    while (x != root)  //压缩路径
    {
        int t = S[x];  //暂存x的父节点
        S[x] = root;   //将x的父节点直接设置为根
        x = t;         //循环处理x的父节点，直到根为止
    }
    return root;
}