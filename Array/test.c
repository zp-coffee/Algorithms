#include "test.h"

//找到给定值并返回坐标，如果没有则返回-1
int search_test(int *num, int num_size, int target)
{
    int left = 0;
    int right = num_size - 1;
    int middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (num[middle] > target)
        {
            right = middle - 1;
        }
        else if (num[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
}

//给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度
int delete_test(int *num, int num_size, int target)
{
    int slow = 0;
    int fast = 0;
    for (int i = 0; i < num_size; i ++)
    {
        if (num[fast] != target)
        {
            num[slow] = num[fast];
            slow ++;
        }
        fast ++;
    }
    last_numsize = slow;
    return last_numsize;
}

//有序数组的平方排序
int *sort_test(int *num, int num_size)
{
    int left = 0;
    int right = num_size - 1;
    int index;
    int left_num = 0;
    int right_num = num_size - 1;
    int* return_num = (int*)malloc(sizeof(int)*num_size);
    for (index = num_size-1; index >= 0; index --)
    {
        left_num = num[left]*num[left];
        right_num = num[right]*num[right];
        if (left_num >= right_num)
        {
            return_num[index] = left_num;
            left ++;
        }
        else if (left_num < right_num)
        {
            return_num[index] = right_num;
            right --;
        }
    }
    return return_num;
}

//找到数组中满足>=target的最小长度序列并返回,数组中元素为正数，滑动窗口，时间复杂度为O(n)，里面的while只执行有限次
int find_test(int *num, int target, int num_size)
{
    int min_num = 0;
    int min = 0;
    int return_num = num_size+1;
    int j = 0;
    for (int i = 0; i < num_size; i ++)
    {
        min_num += num[i]; 
        while (min_num >= target)
        {
            min = i - j + 1;
            return_num = (return_num > min) ? min : return_num;
            min_num -= num[j++];
        }
    }
    return_num = (return_num == num_size+1) ? 0 : return_num;
    return return_num;
}

void swap_test(int *num, int num_size)
{
    int temp;
    for (int i = 0, j = num_size-1; i < j; i ++, j--)
    {
        temp = num[j];
        num[j] = num[i];
        num[i] = temp;
    }
}

int delete_atobtest(int *num, int a, int b, int num_size)
{
    int slow = 0;
    int fast = 0;
    for (fast = 0; fast < num_size-1; fast ++)
    {
        if (num[fast] < a || num[fast] > b)
        {
            num[slow++] = num[fast];
        }
    }
    last_numsize = slow;
}

int delete_sametest(int *num, int num_size)
{
    int slow = 0;
    int fast = 1;
    for (fast = 1; fast <= num_size-1; fast++)
    {
        if (num[fast] != num[slow])
        {
            slow ++;
            num[slow] = num[fast];
        }
    }
    last_numsize = slow+1;
}

//将两个有序数组合并成一个有序数组
int* sort_twotest(int *num1, int *num2, int num_size1, int num_size2)
{
    int* return_num = (int*)malloc(sizeof(int)*(num_size1+num_size2));
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (p1 < num_size1 && p2 < num_size2)
    {
        if (num1[p1] <= num2[p2])
        {
            return_num[i++] = num1[p1++];
        }
        else
        {
            return_num[i++] = num2[p2++];
        }
    }
    while (p1 < num_size1)
    {
        return_num[i++] = num1[p1++];
    }
    while (p2 < num_size2)
    {
        return_num[i++] = num2[p2++];
    }
    return return_num;
}

int* searchfind(int* num, int target, int num_size)
{
    int left = 0;
    int right = num_size - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (num[mid] > target)
        {
            right = mid - 1;
        }
        else if (num[mid] < target)
        {
            left = mid + 1;
        }
        else 
        {
            if (num[mid] == target && mid != num_size-1)
            {
                swap(&num[mid], &num[mid+1]);
                return num;
            }
            else if (mid == num_size-1)
            {
                return num;
            }
        }
    }
    int *return_num = insert_a_num(num, target, right+1, num_size);
    return return_num;
}

void find_same_form_three_num(int* num1, int* num2, int* num3, int num_size1, int num_size2, int num_size3)
{
    int a = 0; 
    int b = 0;
    int c = 0;
    while (a < num_size1 && b < num_size2 && c < num_size3)
    {
        if (num1[a] == num2[b] && num2[b] == num3[c])
        {
            printf("%d ", num1[a]);
            a++;b++;c++;
        }
        else
        {
            int max = find_max(num1[a], num2[b], num3[c]);
            if (num1[a] < max) a ++;
            if (num2[b] < max) b ++;
            if (num3[c] < max) c ++;
        }
    }
}


void insert_test(int* num, int num_size)
{
    int i,j;
    int left, right, mid;
    for(i = 1; i < num_size; i ++)
    {
        if (num[i] < num[i-1])
        {
            int temp = num[i];
            left = 0;
            right = i - 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (temp < num[mid])
                {
                    right = mid - 1;
                }
                else if (temp >= num[mid])
                {
                    left = mid + 1;
                }
            }
            for (j = i-1; j >= right+1; j --)
            {
                num[j+1] = num[j];
            }
            num[right+1] = temp;
        }
    }
}

void bubble_test(int* num, int num_size)
{
    for (int i = 0; i < num_size; i++)
    {
        int flag = 0;
        for (int j = 0; j < num_size - 1 - i; j ++)
        {
            if (num[j] > num[j+1])
            {
                swap(&num[j], &num[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void quick_test(int* num, int start, int end)
{
    if (start >= end)
    {
        return ;
    }
    int left, right, temp;
    left = start;
    right = end - 1;
    temp = num[left];
    while (left < right)
    {
        while (left < right && num[right] >= temp)
        {
            right --;
        }
        if (left < right)
        {
            num[left] = num[right];
        }
        while (left < right && num[left] <= temp)
        {
            left ++;
        }
        if (left < right)
        {
            num[right] = num[left];
        }
    }
    num[left] = temp;
    quick_test(num, start, left);
    quick_test(num, left+1, end);
}

void select_test(int* num, int num_size)
{
    int min = -9;
    int temp = 0;
    for (int i = 0; i < num_size; i ++)
    {
        min = num[i];
        temp = i;
        for (int j = i; j < num_size; j ++)
        {
            if (num[j] < min)
            {
                min = num[j];
                temp = j;
            }
        }
        swap(&num[i], &num[temp]);
    }
}

void heapsort_test(int* num, int num_size)
{
    buildheap_test(num, num_size);
    for (int i = num_size; i > 1; i --)
    {
        swap(&num[1], &num[i]);
        changeheap_test(num, 1, i-1);
    }
}


void buildheap_test(int* num, int num_size)
{
    for (int i = num_size/2; i >= 1;i --)
    {
        changeheap_test(num, i, num_size);
    }
}


void changeheap_test(int* num, int k, int num_size)  //调整堆
{
    num[0] = num[k];  //保存根节点
    for (int i = 2*k; i <= num_size; i *= 2) //只要还在树的范围内就一直调整，这里i*=2，而不是i++
    {
        if (i < num_size && num[i] < num[i+1]) //右孩子更大
        {
            i ++;
        }
        if (num[i] < num[0])  //孩子小于根节点,这里是num[0]而不是num[k]，需要一直与最初的根节点进行比较
        {
            break;
        }
        else
        {
            num[k] = num[i];  //孩子大于根节点，覆盖根节点
            k = i;            //继续向下比较直到超出树的范围
        }
    }
    num[k] = num[0];
}


int judgesmallheap(int* num, int num_size)
{
    if (num_size % 2)
    {
        if (num[num_size/2] > num[num_size])
        {
            return 0;
        }
        for (int i = num_size/2 - 1; i >= 1; i --)
        {
            if (num[i] > num[2*i] || num[i] > num[2*i+1])
            {
                return 0;
            }
        }
    }
    else 
    {
        for (int i = num_size/2; i >= 1; i --)
        {
            if (num[i] > num[2*i] || num[i] > num[2*i+1])
            {
                return 0;
            }
        }
    }
}

int* merge_sort(int* num, int low, int mid, int high)
{
    int i, j, k;
    int* num_test = (int*)malloc(sizeof(int) * (high-low));
    for (int i = 0; i < high; i ++)
    {
        num_test[i] = 0;
    }
    for (i = low, k = low, j = mid+1; i <= mid && j < high; k ++)
    {
        if (num[i] < num[j])
        {
            num_test[k] = num[i++];
        }
        else
        {
            num_test[k] = num[j++];
        }
    }
    while (i <= mid)
    {
        num_test[k++] = num[i++];
    }
    while (j < high)
    {
        num_test[k++] = num[j++];
    }
}

void merge_test(int* num, int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;
        merge_test(num, low, mid);
        merge_test(num, mid+1, high);
        merge_sort(num, low, mid, high);
    }
}


void countsort_test(int* num, int* result, int num_size)
{
    int* countnum = (int*)malloc(sizeof(int) * (num_size+1));
    for (int i = 0; i <= num_size; i ++)
    {
        countnum[i] = 0;
    }
    for (int i = 0; i < num_size; i ++)
    {
        countnum[num[i]] ++;
    }
    for (int i = 1; i <= num_size; i ++)
    {
        countnum[i] += countnum[i-1];
    }
    for (int i = num_size-1; i >= 0; i --)
    {
        result[countnum[num[i]]-1] = num[i];
        countnum[num[i]] --;
    }
}