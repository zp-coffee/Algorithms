#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MaxSize 10

#define beginfromzero 0

//双亲表示法
typedef struct fathernode
{
    int data;
    int parent;
}FatherNode;

typedef struct fathertree
{
    int size;
    FatherNode nodes[MaxSize];
}FatherTree;

//孩子链表表示法
typedef struct childnode
{
    int childindex;         //指向的孩子的数组索引，不是节点的数据
    struct childnode* next;
}ChildNode;  //链表中的孩子节点

typedef struct childtreenode
{
    int data;
    ChildNode* firstnode;
}ChildTreeNode;  //父节点

typedef struct childtree
{
    ChildTreeNode nodes[MaxSize];
    int size;
}ChildTree;  //父节点的集合

//图的邻接表，与孩子表示法的实现是一样的
typedef struct arcnode    //弧节点
{
    int adjvex;           //这条边(弧)所指向的节点数组索引，而不是顶点的数据
    struct arcnode* next; //指向下一条弧
    //int info;             //这条边的权值
}ArcNode;

typedef struct vnode //顶点节点
{
    int data;           //顶点的信息
    ArcNode* firstnode; //这个顶点所连接的第一条弧
}VNode;

typedef struct algraph
{
    VNode nodes[MaxSize];
    int vexnum, arcnum;    //顶点的数量和边的数量
}ALGraph;

//孩子兄弟表示法
typedef struct node
{
    int data;
    struct node* child;
    struct node* sibling;
}TreeNode;


//初始化
void Init_tree(int* num);

//找父节点
int Find_Father(int i);

//找左孩子
int Find_LeftChild(int i);

//找右孩子
int Find_RightChild(int i);

//前序遍历
void PreOrder(int* tree, int num);

//中序遍历
void InOrder(int* tree, int num);

//中序遍历
void PostOrder(int* tree, int num);

//插入节点
void InsertNode(FatherTree* tree, int data, int father_index);

//查找父节点
int Find_Fathernode(FatherTree* tree, int i);

//初始化
void InitFatherTree(FatherTree* tree);
