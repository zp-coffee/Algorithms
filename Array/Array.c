#include"Array.h"

int nums[3] = {-1,0,9};
int nums1[4] = {-25,-10,10,11};
int nums2[5] = {2,9,17,30,41};
int nums3[8] = {4,2,8,5,3,1,0,9};
int last_numsize = 10;

int main(void)
{
    int min = find_min_distance1(nums, nums1, nums2, 3, 4, 5);
    printf("%d\n", min);
    return 0;
}

//找到给定值并返回坐标，如果没有则返回-1
int search_a_num(int *num, int num_size, int target)
{
    int left = 0;
    int right = num_size - 1;
    int middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (num[middle] < target)
        {
            left = middle + 1;
        }
        else if (num[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}
//给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度
int delete_nums(int *num, int num_size, int target)
{
    int slow = 0;
    int fast = 0;
    for (fast = 0; fast < num_size; fast ++)
    {
        if (num[fast] != target)
        {
            num[slow] = num[fast];
            slow ++;
        }
    }
    last_numsize = slow;
    return slow;
}

//打印数组
void printf_array(int* num, int num_size)
{
    printf("printf_array:\n");
    for (int i = 0; i < num_size; i ++)
    {
        printf("%d\n", num[i]);
    }
}

//有序数组的平方排序
int *sort_nums_square(int *num, int num_size)
{
    int *return_array = (int *)malloc(sizeof(int) * num_size);
    int right = num_size - 1;
    int left = 0;
    int index = 0;
    int left_num = 0;
    int right_num = 0;
    for (index = num_size - 1; index >= 0; index --)
    {
        left_num = num[left] * num[left];
        right_num = num[right] * num[right];
        if (right_num >= left_num)
        {
            return_array[index] = right_num;
            right --;
        }
        else
        {
            return_array[index] = left_num;
            left ++;
        }
    }
    return return_array;
}

//找到数组中满足和<=s的最小长度并返回,数组中元素为正数
int find_minlen(int *num, int s, int num_size)
{
    int return_num = INT32_MAX;
    int i = 0;
    int sum = 0;
    int length = 0;
    for(int j = 0; j < num_size; j ++)
    {
        sum += num[j];
        while(sum >= s)
        {
            length = j - i + 1;
            return_num = return_num > length ? length : return_num;
            sum -= num[i++];
        }
    }
    return_num = return_num == INT32_MAX ? 0 : return_num;
    return return_num;
}

//删除最小值的元素(唯一)并返回，删除的元素由最后一个元素填补
int delete_min(int *num, int num_size)
{
    int return_num = INT32_MAX;
    if (num_size == 0)
    {
        printf("the array is empty!\n");
        return 0;
    }
    int j = 0;
    for (int i = 0; i < num_size; i ++)
    {
        if (num[i] < return_num)
        {
            return_num = num[i];
            j = i;
        }
    }
    num[j] = num[num_size - 1];

    return return_num;
}

//将两个数据交换
void swap(int *i, int *j)
{
    int k = 0;
    k = *i;
    *i = *j;
    *j = k;
}

//逆置数组
void swap_array(int *num, int num_size)
{
    int i = 0;
    int j = num_size - 1;
    for (i = 0; i <= num_size/2; i ++,j--)
    {
        swap(&num[i],&num[j]);
    }
}

//删除数组中处于a到b到元素
int delete_num_for_a_to_b(int *num, int a, int b, int num_size)
{
    if (a > b || num_size == 0)
    {
        printf("error!\n");
        return 0;
    }
    int slow = 0;
    int fast = 0;
    int return_numsize = num_size;
    for (fast = 0; fast < num_size; fast ++)
    {
        if (num[fast] >= a && num[fast] <= b)
        {
            return_numsize --;
        }
        else
        {
            num[slow++] = num[fast];
        }
    }
    last_numsize = return_numsize;
    return return_numsize;
}

//删除有序数组中相同元素
int delete_samenum(int *num, int num_size)
{
    int slow = 0;
    int fast = 1;
    if (num_size == 1)
    {
        return 0;
    }
    for (fast = 1; fast < num_size; fast ++)
    {
        if (num[slow] != num[fast])
        {
            num[++slow] = num[fast];
        }
        last_numsize = slow + 1;
    }
    return slow;
}

//将两个有序数组合并成一个有序数组
int* sort_twoarray(int *num1, int *num2, int num_size1, int num_size2)
{
    int *return_num = (int *)malloc(sizeof(int) * (num_size1 + num_size2));
    int slow = 0;
    int fast = 0;
    int k = 0;
    for (slow = 0, fast = 0; slow < num_size1 && fast < num_size2;)
    {
        if (num1[slow] <= num2[fast])
        {
            return_num[k++] = num1[slow];
            slow ++;
        }
        else
        {
            return_num[k++] = num2[fast];
            fast ++;
        }
    }
    if (slow == num_size1)
    {
        for( ; fast < num_size2; fast ++)
        {
            return_num[k++] = num2[fast];
        }
    }
    if (fast == num_size2)
    {
        for( ; slow < num_size1; slow ++)
        {
            return_num[k++] = num1[slow];
        }
    }
    return return_num;
}

//将数组内的两个线性表交换次序
int* swap_array_inside(int *num, int m, int n, int num_size)
{
    int *return_num = (int *)malloc(sizeof(int) * num_size);
    int i = 0; 
    for (i = 0; i < n; i ++)
    {
        return_num[i] = num[m+i];
    }
    for (i = 0; i < m; i ++)
    {
        return_num[n+i] = num[i];
    }
    return return_num;
}

//在一个递增数组中寻找一个值，如果找到将其与后续元素交换，否则插入
int* find_a_num(int *num, int target, int num_size)
{
    int left = 0;
    int right = num_size - 1;
    int middle = (left + right) / 2;
    while(left <= right)
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
            if(middle == num_size - 1)
            {
                return num;
            }
            swap(&num[middle],&num[middle+1]);
            return num;
        }
    }
    int *return_num = insert_a_num(num, target, left+1, num_size);
    return return_num;
}

//在一个数组的第几个位置插入一个元素
int* insert_a_num(int *num, int target, int n, int num_size)
{
    int *return_num = (int *)malloc(sizeof(int) * (num_size + 1));
    int i  = 0;
    for (i = 0; i < n-1; i ++)
    {
        return_num[i] = num[i];
    }
    return_num[n-1] = target;
    for(i = n; i <= num_size; i ++)
    {
        return_num[i]  = num[i-1];
    }
    return return_num;
}

//从三个相同长度的递增数组中找出相同的元素并返回
int find_same_num(int *num1, int *num2, int *num3, int num_size)
{
    int i = 0; 
    int k = 0;
    for (i = 0; i < num_size; i ++)
    {
        k = search_a_num(num2, num_size, num1[i]);
        if (k != -1)
        {
            k = search_a_num(num3, num_size, num1[i]);
            if (k != -1)
            {
                printf("%d\n", num1[i]);
            }
        }
    }
    return -1;
}

//使用三个指针同时移动
void find_same_num1(int *num1, int *num2, int *num3, int num_size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < num_size && j < num_size && k < num_size)
    {
        if (num1[i] == num2[j] && num2[j] == num3[k])
        {
            printf("%d\n", num1[i]);
            i ++; j ++; k ++;
        }
        else
        {
            int max = find_max(num1[i], num2[j], num3[k]);
            if (num1[i] < max) i ++;
            if (num2[j] < max) j ++;
            if (num3[k] < max) k ++;
        }
    }
}

//找最大值
int find_max(int a, int b, int c)
{
    int temp = a;
    if (a < b)
    {
        temp = b;
    }
    if (temp < c)
    {
        temp = c;
    }
    return temp;
}

//begin和end都代表数组下标
void array_reverse(int *num, int begin, int end)
{
    for (int i = 0; i < (end-begin+1)/2; i ++)
    {
        swap(&num[begin+i], &num[end-i]);
    }
}

//实现数组内两个线性表的逆置
void swap_array_inside1(int *num, int p, int num_size)
{
    array_reverse(num, 0, num_size-1);
    array_reverse(num, 0, p-1);
    array_reverse(num, p, num_size-1);
}

//找中位数,时间复杂度和空间复杂度都为n
int find_middle_num(int *num1, int *num2, int num_size)
{
    int *new_num = sort_twoarray(num1, num2, num_size, num_size);
    return new_num[(num_size*2-1)/2];
}

//找主元素,时间和空间都为n
int find_mainnum(int *num, int num_size)
{
    int *num1 = (int *)malloc(sizeof(int) * num_size);
    for (int i = 0; i < num_size; i ++)
    {
        num1[i] = -1;
    }
    for (int i = 0; i < num_size; i ++)
    {
        num1[num[i]] ++;
    }
    for (int i = 0; i < num_size; i ++)
    {
        if (num1[i]+1 > num_size/2)
        {
            return i;
        }
    }
    return -1;
}

//找主元素，时间为n，空间为1，思想为先找出可能为主元素的数，最后再进行统计
int find_mainnum1(int* num, int num_size)
{
    int maynum = num[0];
    int count = 0;
    for (int i = 1; i < num_size; i ++)
    {
        if (num[i] == maynum)
        {
            count ++;
        }
        else
        {
            if (count > 0)
            {
                count --;
            }
            else
            {
                maynum = num[i];
            }
        }
    }
    if (count > 0)
    {
        count = 0;
        for (int i = 0; i < num_size; i ++)
        {
            if (num[i] == maynum)
            {
                count ++;
            }
        }
        if (count > num_size/2)
        {
            return maynum;
        }   
    }
    return -1;
}

//找到数组中未出现的最小正整数
int no_appearnum(int *num, int num_size)
{
    int *temp_num = (int *)malloc(sizeof(int) * (num_size+1));
    for (int i = 0; i < num_size+1; i ++)
    {
        temp_num[i] = 0;
    }
    for (int i = 0; i < num_size; i ++)
    {
        if (num[i] > 0)
        {
            temp_num[num[i]] ++;
        }
    }
    for (int i = 1; i < num_size+1; i ++)
    {
        if (temp_num[i] == 0)
        {
            return i;
        }
    }
    return num_size+1;
}

//冒泡排序
void bubblesort(int *num, int num_size)
{
    for (int i = 0; i < num_size; i ++)
    {
        for (int j = 0 ; j < num_size-1; j ++)
        {
            if (num[j] > num[j+1])
            {
                swap(&num[j], &num[j+1]);
            }
        }
    }
}

//选择排序
void selectsort(int *num, int num_size)
{
    int min = 0;
    for (int i = 0; i < num_size; i ++)
    {
        min = i;
        for (int j = i+1; j < num_size; j ++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }
        swap(&num[i], &num[min]);
    }
}

//插入排序
void insertsort(int *num, int num_size)
{
    for (int i = 1; i < num_size; i ++)
    {
        for (int j = i; j > 0; j --)
        {
            if (num[j] < num[j-1])
            {
                swap(&num[j], &num[j-1]);
            }
            else
            {
                continue;
            }
        }
    }
}

//快速排序
void quicksort(int *num, int start, int end)
{
    if (start >= end)
    {
        return ;
    }
    int left = start;
    int right = end;
    int point = num[left];
    while (left < right)  //最左边的值初始为point，所以从右边开始比较
    {
        while (right > left && num[right] > point) //确保目前right所在的值比point小，也就是应该放左边
        {
            right --;
        }
        if (right > left)
        {
            num[left] = num[right];
        }
        while (right > left && num[left] < point) //确保目前left所在的值比point大，也就是应该在右边
        {
            left ++;
        }
        if (right > left)
        {
            num[right] = num[left];
        }
        if (left >= right) //最后left和right重合，也就是point所应该在的位置
        {
            num[left] = point;
        }
    }
    quicksort(num, start, left-1);
    quicksort(num, left+1, end);
}

//快速排序自己的实现方法
void quicksort1(int *num, int start, int end)
{
    if (start >= end)
    {
        return ;
    }
    int left = start;
    int right = end;
    int point = num[left];
    while (left < right)
    {
        while (left < right && num[right] > point)
        {
            right --;
        }
        if (left < right)
        {
            swap(&num[left], &num[right]);
            left ++;
        }
        while (left < right && num[left] < point)
        {
            left ++;
        }
        if (left < right)
        {
            swap(&num[left], &num[right]);
            right --;
        }
    }
    quicksort1(num, start, left-1);
    quicksort1(num, left+1, end);
}

//找三个数组中的三元组的最小距离
int find_min_distance(int *num1, int *num2, int *num3, int num_size1, int num_size2, int num_size3)
{
    int min = INT32_MAX;
    int temp = 0;
    for (int i = 0; i < num_size1; i ++)
    {
        for (int j = 0; j < num_size2; j ++)
        {
            for (int k = 0; k < num_size3; k ++)
            {
                temp = cal_absolute(num1[i], num2[j], num3[k]);
                if (temp < min)
                {
                    min = temp;
                }
            }
        }
    }
    return min;
}

//计算三个数据的差的绝对值之和
int cal_absolute(int a, int b, int c)
{
    int sum = 0;
    sum = absolute(a,b) + absolute(b,c) + absolute(c,a);
    return sum;
}

//计算两个数的差的绝对值
int absolute(int x, int y)
{
    return (x-y)>0 ? x-y : y-x;
}

//找三个数组中的三元组的最小距离,时间复杂度为n,三指针法
int find_min_distance1(int *num1, int *num2, int *num3, int num_size1, int num_size2, int num_size3)
{
    int min = INT32_MAX;
    int temp = 0;
    int i = 0, j = 0, k = 0;
    while (i < num_size1 && j < num_size2 && k < num_size3 && min > 0)
    {
        temp = cal_absolute(num1[i], num2[j], num3[k]);
        if (temp < min)
        {
            min = temp;
        }
        if (minimal_data(num1[i], num2[j], num3[k])) i ++;
        else if (minimal_data(num2[j], num3[k], num1[i])) j ++;
        else k ++;
    }
    return min;
}

//判断a是不是最小的值
int minimal_data(int a, int b , int c)
{
    if (a <= b && a <= c)
    {
        return 1;
    }
    return 0;
}
