#include "list.h"


//统一规定头节点为0号节点
int main(void)
{
    ListNode* mylist1 = list1();
    return 0;
}

//创建一个用于调试的链表
ListNode* list1(void)
{
    ListNode* header = InitHeadList(); //先建立一个头节点，再在头节点尾部添加节点
    ListAddTail(header, CreatNode(-100));
    ListAddTail(header, CreatNode(11));
    ListAddTail(header, CreatNode(-11));
    ListAddTail(header, CreatNode(11));
    ListAddTail(header, CreatNode(14));

    ListAddTail(header, CreatNode(100));
    ListAddTail(header, CreatNode(23));
    ListAddTail(header, CreatNode(25));
    ListAddTail(header, CreatNode(6));
    ListAddTail(header, CreatNode(5));
    // ListNode* cur = header;   //加入变为循环的单链表
    // while (cur->next != NULL)
    // {
    //     cur = cur->next;
    // }
    // cur->next = header;
    return header;
}

//创建一个用于调试的链表
ListNode* list2(void)
{
    ListNode* header = InitHeadList(); //先建立一个头节点，再在头节点尾部添加节点
    ListAddTail(header, CreatNode(23));
    ListAddTail(header, CreatNode(25));
    ListAddTail(header, CreatNode(6));
    // ListAddTail(header, CreatNode(14));
    // ListNode* cur = header;
    // while (cur->next != NULL)
    // {
    //     cur = cur->next;
    // }
    // cur->next = header;
    // ListNode* num = header->next;
    // while(header->next != NULL)
    // {
    //     header = header->next;
    // }
    // header->next = num->next->next->next->next;
    return header;
}

//创建一个用于测试的双向链表
DoubleList* list3(void)
{
    DoubleList* header = InitHeadDoubleList();
    DoubleListAddTail(header, CreateDoubleNode(11));
    DoubleListAddTail(header, CreateDoubleNode(12));
    DoubleListAddTail(header, CreateDoubleNode(13));
    DoubleListAddTail(header, CreateDoubleNode(12));
    DoubleListAddTail(header, CreateDoubleNode(11));
    // DoubleList* cur = header;  //加入变为循环的双向链表
    // while (cur->next != NULL)
    // {
    //     cur = cur->next;
    // }
    // cur->next = header;
    // header->pre = cur;
    return header;
}

//初始化一个头节点
ListNode* InitHeadList(void)
{
    ListNode* head = (ListNode *)malloc(sizeof(ListNode));  //为头节点分配空间，并将头节点指向null
    head->next = NULL;
    return head;
}

//初始化一个双向链表的头节点
DoubleList* InitHeadDoubleList(void)
{
    DoubleList* head = (DoubleList *)malloc(sizeof(DoubleList));
    head->next = NULL;
    head->pre = NULL;
    return head;
}

//创建一个新的节点
ListNode* CreatNode(int data)
{
    ListNode* cur = (ListNode*)malloc(sizeof(ListNode));   //每创建一个节点都需要建立空间
    cur -> val = data;
    cur -> next = NULL;
    return cur;
}

//创建一个新的双向链表节点
DoubleList* CreateDoubleNode(int data)
{
    DoubleList* cur = (DoubleList*)malloc(sizeof(DoubleList));
    cur->next = NULL;
    cur->pre = NULL;
    cur->val = data;
    return cur;
}

//在链表尾部加入一个节点
void ListAddTail(ListNode* L, ListNode* new)
{
    ListNode* cur = L;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new;
}

//在双向链表结尾插入一个节点
void DoubleListAddTail(DoubleList* L, DoubleList* new)
{
    DoubleList* cur = L;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new;
    new->pre = cur;
}

//在链表头部插入一个节点
void ListAddHead(ListNode* L, ListNode* new)
{
    new->next = L->next;
    L->next = new;
}

//计算有头节点的链表的长度
int GetLen(ListNode *L)
{
    int len = 0;
    ListNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len ++;
    }
    return len;
}

//计算无头节点的链表的长度
int GetNoHeadLen(ListNode* L)
{
    return GetLen(L) + 1;
}

//打印有头节点链表中的信息
void printf_headlist(ListNode *L)
{
    int i = 1;
    ListNode *p = L->next;
    while (p != NULL)
    {
        printf("%d:%d\n",i++, p->val);
        p = p->next;
    }
}

//打印没有头节点的链表中的信息
void printf_noheadlist(ListNode *L)
{
    int i = 1;
    ListNode *p = L;
    while (p != NULL)
    {
        printf("%d:%d\n",i++, p->val);
        p = p->next;
    }
}

//找到链表中的第几个节点
ListNode* GetElem(ListNode *L, int num)
{
    ListNode *p = L;
    int j = 0;
    while (L != NULL && j < num)
    {
        p = p->next;
        j ++;
    }
    return p;
}

//获取链表中第几个节点的值
int GetIndexVal(ListNode* L, int index)
{
    if (index < 0 || index > GetLen(L))
    {
        return -1;
    }
    ListNode* cur = L;
    for (int i = 0; i < index; i ++)
    {
        if (cur->next != NULL)
        {
            cur = cur->next;
        }
    }
    return cur->val;
}

//插入一个节点作为链表的几号节点
void ListAddInlist(ListNode* L, ListNode* new, int target)
{
    ListNode* cur = L;
    if (target > GetLen(L))
    {
        target = GetLen(L)+1;
    }
    if (target <= 0)
    {
        target = 1;
    }
    for(int i = 1; i < target; i ++)
    {
        cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
}

//删除第几号节点
void DeleteInlist(ListNode* L, int target)
{
    ListNode* per = L;
    ListNode* cur = L;
    cur = cur->next;
    if (target < 1 || target > GetLen(L))
    {
        printf("error!\n");
        return ;
    }
    for (int i = 1; i < target; i ++)
    {
        cur = cur->next;
        per = per->next;
    }
    ListNode* temp = cur;
    per->next = cur->next;
    free(temp);
}

//删除链表中所有值等于val的节点
void DeleteValNode(ListNode* L, int target)
{
    ListNode* cur = L;
    while(cur->next != NULL)
    {   
        if (cur->next->val == target)
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        }
        else
        {
            cur = cur->next;
        }
    }
}

//翻转一个链表，双指针法
ListNode* ReverseList(ListNode* L)
{
    ListNode* cur = L->next;
    ListNode* per = NULL;
    ListNode* temp;
    while(cur->next != NULL)
    {
        temp = cur->next;
        cur->next = per;
        per = cur;
        cur = temp;
    }
    cur->next = per;
    L->next = cur;
    return L;
}

//翻转一个链表，可以直接摘下头节点，再一次指向头节点,相当于用头节点替代了pre
ListNode* ReverseList2(ListNode* L)
{
    ListNode* cur = L->next;
    ListNode* temp;
    L->next = NULL;
    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = L->next;
        L->next = cur;
        cur = temp;
    }
    return L;
}

//递归法翻转一个链表
ListNode* ReverseList1(ListNode* L)
{
    ListNode* head = L->next;
    L->next = Reverse(head, NULL);
    return L;
}

//递归
ListNode* Reverse(ListNode* cur, ListNode* per)
{
    if (cur == NULL)
    {
        return per;
    }
    ListNode* temp = cur->next;
    cur->next = per;
    per = cur;
    return Reverse(temp, per); //不断传入剩余翻转的链表和新链表
}

//交换相邻节点,返回带头节点的链表
ListNode* SwapNodes(ListNode* L)
{
    ListNode* cur = L;
    while(cur->next != NULL && cur->next->next != NULL)
    {
        ListNode* temp1 = cur->next;
        ListNode* temp2 = cur->next->next->next;
        cur->next = cur->next->next;
        cur->next->next = temp1;
        cur->next->next->next = temp2;
        cur = cur->next->next;
    }
    return L;
}

//删除倒数第几个节点
ListNode* DeleteNodeFromEnd(ListNode* L, int target)
{
    ListNode* cur = L;
    int num = GetLen(L) - target;
    for (int i = 0; i < num; i ++)
    {
        cur = cur->next;
    }
    ListNode* temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
    return L;
}

//双指针法删除倒数第几个节点
ListNode* DeleteNodeFromEnd1(ListNode* L, int target)
{
    ListNode* slow = L;
    ListNode* fast = L;
    for (int i = 0; i < target; i ++)
    {
        fast = fast->next;
    }
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    //free(fast);   //这里不能使用free因为此时fast指向最后一个节点，释放会将最后一个节点清除，而最后一个节点也链接在slow中
    return L; 
}

//判断两个链表是否相交
ListNode* GetinterSectionNode(ListNode* L, ListNode* P)
{
    int len1 = GetLen(L);
    int len2 = GetLen(P);
    ListNode* fast;
    ListNode* slow;
    if (len1 > len2)
    {
        fast = L;
        slow = P;
    }
    else
    {
        fast = P;
        slow = L;
    }
    for (int i = 0; i < len1-len2; i ++)
    {
        fast = fast->next;
    }
    while (fast != slow && fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    if (fast == NULL)
    {
        printf("no intersection\n");
        return NULL;
    }
    return fast;
}

//判断链表中是否有环,返回环的入口在第几个节点上
int ListCycle(ListNode* L)
{
    ListNode* slow = L->next;
    ListNode* fast = L->next;
    int num = 1;
    while(fast != NULL && fast->next != NULL)  //判断链表中是否有环，没有环的话肯定有一个节点是指向null的
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            ListNode* index1 = L->next;
            ListNode* index2 = fast;
            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
                num ++;
            }
            return num;
        }
    }
    printf("no cycle\n");
    return -1;
}

//删除链表中含有最小值的节点,通过计数来找到最小节点
ListNode* DeleteMinNode(ListNode* L)
{
    int num = 1;
    ListNode* cur = L;
    int min = INT32_MAX;
    int minnode = 0;
    while(cur->next != NULL)
    {
        if (cur->next->val < min)
        {
            min = cur->next->val;
            minnode = num;
        }
        num++;
        cur = cur->next;
    }
    cur = L;
    for (int i = 1; i < minnode; i ++)
    {
        cur = cur->next;
    }
    ListNode* temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
    return L;
}

//删除链表中最小值的节点，通过另一套指针来保存
ListNode* DeleteMinNode1(ListNode* L)
{
    ListNode* pre = L;
    ListNode* cur = L->next;
    ListNode* min = cur;
    ListNode* minpre = pre;
    int minnum = INT32_MAX;
    while (cur != NULL)
    {
        if (cur->val < minnum)
        {
            min = cur;
            minpre = pre;
            minnum = cur->val;
        }
        cur = cur->next;
        pre = pre->next;
    }
    minpre->next = min->next;
    free(min);
    return L;
}

//链表为a1,b1,a2,b2,a3,b3......拆分为a1,a2,a3和b1,b2,b3
ListNode* SplitList(ListNode* L)
{
    ListNode* temp = InitHeadList(); //创建一个新链表来保存另一个分出来的链表
    temp->next = L->next;
    ListNode* p = temp->next;  //新链表用p来操作，p在cur的后面
    ListNode* cur = L;  //原始链表用cur来操作
    while(cur->next != NULL && p->next != NULL) //这里用p->next->next判断会出界，因为只有p->next为null，p->next->next不知道指向哪里
    {
        cur->next = cur->next->next;
        p->next = p->next->next;
        cur = cur->next;
        p = p->next;
    }
    if (cur->next != NULL)
    {
        cur->next = NULL;
        
    }
    return temp;
}

//链表为a1,b1,a2,b2,a3,b3......拆分为a1,a2,a3和bn,bn-1,bn-2
ListNode* SplitList1(ListNode* L)
{
    ListNode* temp = InitHeadList();
    ListNode* cur = L->next;
    ListNode* temp2 = L->next;
    int num = 1;
    while (temp2 != NULL)
    {
        temp2 = temp2->next;
        if (num%2)
        {
            L->next = cur;
            L = L->next;
            cur = temp2;
        }
        else
        {
            cur->next = temp->next;
            temp->next = cur;
            cur = temp2;
        }
        num++;
    }
    L->next = NULL;
    return temp;
}

//删除有序链表中重复的元素
void DeleteSameNode(ListNode* L)
{
    ListNode* cur = L->next;
    while(cur->next != NULL)
    {
        if (cur->val == cur->next->val)
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        }
        else
        {
            cur = cur->next;
        }
    }
}

//从两个带头节点的有序链表中取共同元素构成新链表C
ListNode* CreateListFromAandB(ListNode* A, ListNode* B)
{
    ListNode* q = A->next;
    ListNode* p = B->next;
    ListNode* temp = InitHeadList();
    ListNode* cur = temp;
    while(p != NULL && q != NULL)
    {
        if (p->val == q->val)
        {
            cur->next = CreatNode(p->val);
            cur = cur->next;
            p = p->next;
            q = q->next;
        }
        else if (p->val < q->val)
        {
            p = p->next;
        }
        else
        {
            q = q->next;
        }
    }
    return temp;
}

//两个递增链表A，B，将它们的交集存放在A中
void Union(ListNode* A, ListNode* B)
{
    ListNode* temp = A;
    ListNode* q = A->next;
    ListNode* p = B->next;
    ListNode* u;
    while (q != NULL && p != NULL)
    {
        if (q->val == p->val)
        {
            temp->next = q;
            temp = temp->next;
            while (q!=NULL && p!=NULL && temp->val == q->val && temp->val == p->val)
            {
                q = q->next;
                u = p;
                p = p->next;
                free(u);
            }
        }
        else if (q->val < p->val)
        {
            u = q;
            q = q->next;
            free(u);
        }
        else
        {
            u = p;
            p = p->next;
            free(u);
        }
    }
    temp->next = NULL; 
    while(p)
    {
        u = p;
        p = p->next;
        free(u);
    }
    while(q)
    {
        u = q;
        q = q->next;
        free(u);
    }
}

//判断一个链表是不是另一个链表的子序列
void JudgeSonList(ListNode* A, ListNode* B)
{
    ListNode* cur = A->next;
    ListNode* pre = A->next; //保存上次开始比较的节点
    ListNode* temp = B->next;
    while(cur != NULL)
    {
        if (cur->val != temp->val)
        {
            cur = cur->next;
            pre = cur;
        }
        else
        {
            while(temp != NULL && temp->val == cur->val)
            {
                temp = temp->next;
                cur = cur->next;
            }
            if (temp == NULL)
            {
                printf("yes\n");
                return ;
            }
            temp = B->next;
            cur = pre->next->next;
            pre = pre->next;
        }
    }
    printf("no\n");
}

//判断一个循环双链表是否对称
int JudgeSymmetryDoubleList(DoubleList* L)
{
    DoubleList* q = L->pre;
    DoubleList* p = L->next;
    while (q != p && p->next != q)
    {
        if (p->val == q->val)
        {
            p = p->next;
            q = q->pre;
        }
        else
        {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 1;
}

//将两个循环单链表变成一个循环单链表
ListNode* MergeList(ListNode* A, ListNode* B)
{
    ListNode* cur = A->next;
    while (cur->next != A)
    {
        cur = cur->next;
    }
    cur->next = B->next;
    while (cur->next != B)
    {
        cur = cur->next;
    }
    cur->next = A;
    return A;
}

//将一个不含头节点的单链表循环右移多少步
ListNode* MoveRightList(ListNode* L, int target)
{
    int num = GetLen(L);
    ListNode* cur = L->next;
    num = num - target % num;
    if (num == GetLen(L))
    {
        return cur;
    }
    while(num--)
    {
        cur = cur->next;
    }
    ListNode* pre = cur;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = L->next;
    while (cur->next != pre)
    {
        cur = cur->next;
    }
    cur->next = NULL;
    return pre;
}

//将一个单链表右移多少位，可以先将单链表连接成循环链表再找到新的链尾断开
ListNode* MoveRightList1(ListNode* L, int target)
{
    int num = GetLen(L);
    ListNode* cur = L->next;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = L->next;
    for(int i = 0; i < num-target; i ++)
    {
        cur = cur->next;
    }
    L = cur->next;
    cur->next = NULL;
    return L;
}

//判断单链表中是否有环
ListNode* JudgeCircleList(ListNode* L)
{
    ListNode* slow = L;
    ListNode* fast = L;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast->next == NULL || fast->next->next == NULL)
    {
        return 0;
    }
    ListNode* index1 = L;
    ListNode* index2 = slow;
    while (index1 != index2)
    {
        index1 = index1->next;
        index2 = index2->next;
    }
    return index1;
}

//计算单链表的最大孪生值
int FindMaxSum(ListNode* L)
{
    int num = GetLen(L);
    int sum[num/2];
    ListNode* cur = L->next;
    int max = 0;
    for (int i = 0; i < num/2; i ++)
    {
        sum[i] = 0;
    }
    for (int i = 1, j = 0; i <= num; i ++)
    {
        if (i <= num/2)
        {
            sum[j] += cur->val;
            j ++;
        }
        else
        {
            j --;
            sum[j] += cur->val;
        }
        cur = cur->next;
    }
    for (int i = 0; i < num/2; i ++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
        }
    }
    return max;
}

//查找最大孪生值，将后半部分链表倒置再分别从两个链表头开始计算孪生值
int FindMaxSum1(ListNode* L)
{
    ListNode* slow = L->next;
    ListNode* fast = L->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = InitHeadList();
    ListNode* p = slow->next;
    ListNode* tmp;
    while (p != NULL)
    {
        tmp = p->next;
        p->next = temp->next;
        temp->next = p;
        p = tmp;
    }
    int max = 0;
    slow = L->next;
    fast = temp->next;
    while (fast != NULL)
    {
        if (slow->val + fast->val > max)
        {
            max = slow->val + fast->val;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return max;
}

//查找倒数第k个节点，getlen需要一遍扫描，一共两遍扫描
int FindCountDownNode(ListNode* L, int target)
{
    int num = GetLen(L);
    ListNode* cur = L;
    if (target > num)
    {
        return 0;
    }
    for (int i = 0; i <= num - target; i ++)
    {
        cur = cur->next;
    }
    printf("%d\n",cur->val);
    return 1;
}

//用双指针法输出倒数第k个节点的值,只用到了一遍扫描
int FindCountDownNode1(ListNode* L, int target)
{
    ListNode* slow = L->next;
    ListNode* fast = L->next;
    while (fast != NULL)
    {
        if (target > 0)
        {
            fast = fast->next;
            target --;
        }
        else
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    if (target > 0)
    {
        return 0;
    }
    else
    {
        printf("%d\n", slow->val);
    }
    return 1;
}

//只保留链表中唯一存在的绝对值,n为最大值
void DeleteSqrtNode(ListNode* L, int n)
{
    ListNode* cur = L;
    int* num = (int *)malloc(sizeof(int) * (n+1));
    int val;
    for (int i = 0; i < n; i ++)
    {
        num[i] = 0;
    }
    while (cur->next != NULL)
    {
        val = cur->next->val > 0 ? cur->next->val : -(cur->next->val);
        if (num[val] == 1)
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        }
        else
        {
            num[val] = 1;
            cur = cur->next;
        }
    }
}

//将倒数的节点一次插入前面
void InsertFromLast(ListNode* L)
{
    ListNode* slow = L->next;
    ListNode* fast = L->next;
    while (slow->next != NULL)
    {
        if (slow->next->next == NULL)
        {
            return ;
        }
        while (fast->next->next != NULL)
        {
            fast = fast->next;
        }
        fast->next->next = slow->next;
        slow->next = fast->next;
        fast->next = NULL;
        slow = slow->next->next;
        fast = slow;
    }
}

//可以将后半段链表逆置，再从中间开始依次插入,时间复杂度为n
void InsertFromLast1(ListNode* L)
{
    ListNode* slow = L->next;
    ListNode* fast = L->next;
    ListNode* temp;
    while (fast->next != NULL)  //找到中间节点
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
    }
    fast = slow->next;
    slow->next = NULL;
    while (fast != NULL)  //逆置后半段链表
    {
        temp = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        fast = temp;
    }
    fast = slow->next;  //从后半段链表开始
    slow = L->next;     //从头开始
    //slow->next = NULL;
    while (fast != NULL)
    {
        temp = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        slow = fast->next;
        fast = temp;
    }
    if (slow->next != NULL)
    {
        slow = slow->next;
    }
    slow->next = NULL;
}
