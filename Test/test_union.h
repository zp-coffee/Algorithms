#include "stdio.h"
#include "stdlib.h"

#define Max_Size 10

typedef struct arcnode
{
    int adjvex;
    struct arcnode* nextnode;
    int info;
    /* data */
}ArcNode;

typedef struct vexnode
{
    int data;
    ArcNode* firstArcnode;
}VexNode;

typedef struct graph
{
    int vexnum, arcnum;
    VexNode nodes[Max_Size];
}Graph;
