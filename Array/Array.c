#include "Array.h"
#include "test.h"

int nums[3] = {-1,0,9};
int nums1[10] = {0,1,2,4,4,5,6,7,8,9};
int nums2[3] = {2,4,6}; 
int nums3[10] = {0,0,4,2,8,5,3,1,3,6};
int last_numsize = 10;

int main(void)
{
    quicksort(nums3, 0, 10);
    printf_array(nums3, 10);
    return 0;
}

//找到给定值并返回坐标，如果没有则返回-1, 二分法,只能用于有序数组
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
//双指针法
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

//有序数组的平方排序,双指针法
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

//找到数组中满足>=s的最小长度并返回,数组中元素为正数，滑动窗口，时间复杂度为O(n)，里面的while只执行有限次
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
    return_num = return_num == INT32_MAX ? 0 : return_num;  //最后检查是不是找不到和比target大的序列
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
    for (i = 0; i <= j; i ++,j--)
    {
        swap(&num[i],&num[j]);
    }
}

//逆置数组，从a开始长度为b的序列
void swap_array_from_a_to_b(int* num, int a, int b)
{
    int mid = (a+b)/2;
    for (int i = 0; i <= mid-a; i ++)
    {
        int temp = num[a+i];
        num[a+i] = num[b-i];
        num[b-i] = temp;
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

//将数组内的两个线性表交换次序,a1,a2,...,an,b1,b2,...,bm，换为b1,b2,....bm,a1,a2....an
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

//不使用额外空间
void swap_array_inside_nospace(int* num, int m, int n, int num_size)
{
    swap_array(num, num_size);
    swap_array_from_a_to_b(num, 0, n-1);
    swap_array_from_a_to_b(num, n, n+m-1);
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
            if(middle == num_size - 1) //找到的元素是最后一个元素，不存在交换
            {
                return num;
            }
            swap(&num[middle],&num[middle+1]);
            return num;
        }
    }
    int *return_num = insert_a_num(num, target, left+1, num_size); //执行到这里说明查找失败，将元素插入
    return return_num;
}

//在一个数组的a[n]插入一个元素
int* insert_a_num(int *num, int target, int n, int num_size)
{
    int *return_num = (int *)malloc(sizeof(int) * (num_size + 1));
    int i  = 0;
    for (i = 0; i < n; i ++)
    {
        return_num[i] = num[i];
    }
    return_num[n] = target;
    for(i = n+1; i < num_size+1; i ++)
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

//找两个有序序列的中位数,时间复杂度和空间复杂度都为n
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
    int maynum = num[0];   //先假设0号为主元素
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

//***********************排序算法***********************

//插入排序，从第一个元素开始，使前面的序列保持有序，再一个一个从后面加入元素，使保持有序，稳定的，每一趟并不能得到一个最终位置
void insertsort(int *num, int num_size)
{
    for (int i = 1; i < num_size; i ++)
    {
        for (int j = i; j > 0; j --)   //将后面无序的元素插入到前面有序的序列中,这种写法时间复杂度至少为n2
        {
            if (num[j-1] > num[j])
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

//插入排序的另一种写法，上述采用不断交换的方法，一次交换需要移动三次，而这里采用往后移的方法，交换一个位置只需要一次
void insertsort2(int *num, int num_size)
{
    int temp = 0;    //哨兵
    int i, j;
    for (i = 1; i < num_size; i ++)
    {
        if (num[i-1] > num[i])   //先比较再循环，在最好情况下能达到O(n)
        {
            temp = num[i];
            for (j = i-1; num[j] > temp && j >= 0; j --)
            {
                num[j+1] = num[j];        //往后移
            }
            num[j+1] = temp;
        }
    }
}

//插入排序，使用折半查找，只能用于顺序存储的线性表，直接对半查找，减少了比较元素的次数，但是移动元素的次数不变，时间复杂度仍为n2
void insertsort3(int *num, int num_size)
{
    int i, j, low, high, mid, temp;
    for (i = 1; i < num_size; i ++)
    {
        temp = num[i];
        low = 0;
        high = i - 1;
        while (low <= high)  //先找到插入位置，折半查找后的结果high+1始终为元素应该插入的位置，当不需要插入时为原位置
        {
            mid = (low + high) / 2; 
            if (temp > num[mid]) //在右边
            {
                low = mid + 1;
            }
            else if (temp <= num[mid])  //在左边,要加等于号
            {
                high = mid - 1;
            }
        }
        for (j = i - 1; j >= high + 1; j --) //把需要插入的位置high+1到i-1的元素统一后移
        {
            num[j+1] = num[j];  //最坏情况下，1+2+3+...+n-1 = n(n-1)/2，时间复杂度为n2
        }
        num[high+1]  = temp;  //插入
    }
}

//希尔排序，在插入排序的基础上将单位1改为d，不稳定
void shellsort(int *num, int num_size)  
{
    int i, d, j, temp;
    for (d = num_size/2; d >= 1; d/=2)  //以插入排序的方法进行排序，只是将序列缩小，每一趟之后将进行比较的序列扩大，稳定
    {
        for (i = d; i < num_size; i ++)
        {
            if (num[i] < num[i-d])   //不再与前一个元素比较，而是与前d个元素比较
            {
                temp = num[i];
                for (j = i-d; j >= 0 && num[j] > temp; j-=d) //将数据后移
                {
                    num[j+d] = num[j];
                }
                num[j+d] = temp;
            }
        }
    }
}


//冒泡排序，还能简化，基于交换
void bubblesort(int *num, int num_size)
{
    int count = 0;
    for (int i = 0; i < num_size; i ++)  //表示趟数，每一趟都遍历整个序列，与初始状态无关
    {
        for (int j = 0 ; j < num_size-1; j ++)   //每次都将最大的元素移到最终的位置 
        {
            if (num[j] > num[j+1])
            {
                swap(&num[j], &num[j+1]);    //每次从第一个开始，不断地将小元素与大元素交换位置
            }
            count ++;
        }
    }
    printf("%d\n", count);
}

//冒泡排序，简化，比较的次数少了将近一半，将最小的元素冒泡到最终位置，稳定算法
void bubblesort2(int *num, int num_size)
{
    for (int i = 0; i < num_size; i ++)   //表示趟数
    {
        int flag = 0;                     //判断后序的序列是否已经有序，及时终止，此时与初始状态有关
        for (int j = num_size - 1; j > i; j --) //每次将最小的元素放到前面，后续不再进行比较
        {
            if (num[j] < num[j-1])
            {
                swap(&num[j], &num[j-1]);   //以不断交换相邻元素来使每次最大的元素或最小的元素到达最终位置
                flag = 1;
            }
        }
        if (flag == 0)  //经过一轮的比较没有需要进行交换的元素，说明已经有序，不需要再进行循环
        {
            break;
        }
    }
}

//冒泡排序，将最大的元素冒泡到最终位置
void bubblesort3(int *num, int num_size)
{
    int count = 0;
    for (int i = num_size - 1; i >= 0; i --)
    {
        int flag = 0;
        for (int j = 0; j < i; j ++)
        {
            if (num[j] > num[j+1])
            {
                swap(&num[j], &num[j+1]);
                flag = 1;
            }
            count ++;
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("%d\n", count);
}

//快速排序，每次选择一个元素作为基准，使大于该基准的元素排在右边，小于该基准的元素排在左边，当left=right时，把基准的值赋给重合点
void quicksort(int *num, int start, int end) //后续再递归地对前面排好的序列和后面排好的序列进行快排，(3,3,2)，不稳定
{
    if (start >= end)
    {
        return ;
    }
    int left = start;
    int right = end-1;
    int point = num[left];   //一开始从左边取一个元素，所以从右边开始比较
    while (left < right)     //最左边的值初始为point，所以从右边开始比较
    {
        while (right > left && num[right] >= point) //确保目前right所在的值比point小，也就是应该放左边
        {                                           //这里必须加=，因为当num[left] = num[right]时会一直循环
            right --;
        }
        if (right > left)
        {
            num[left] = num[right];
        }
        while (right > left && num[left] <= point) //确保目前left所在的值比point大，也就是应该在右边
        {
            left ++;
        }
        if (right > left)
        {
            num[right] = num[left];
        }
        num[left] = point;
    }
    quicksort(num, start, left-1);
    quicksort(num, left+1, end);
}


//简单选择排序(2,2,1),是不稳定的
void selectsort(int *num, int num_size)
{
    int min = 0;
    for (int i = 0; i < num_size; i ++)      //表示趟数，每次将最小的元素移到最前面
    {
        min = i;
        for (int j = i+1; j < num_size; j ++)  //每一轮循环找到最小的元素插到前面
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }
        swap(&num[i], &num[min]);
    }
}

//堆排序,不稳定
//先建立大根堆,当使用顺序存储存放二叉树时，num[0]不存放数据，从1开始，这样才能满足2n和2n+1为左孩子和右孩子
void buildmaxheap(int *num, int num_size)  //这里的num_size指的是数组的长度不包括num[0]
{
    for (int i = num_size/2; i >=1; i --)  //将堆视为一个二叉树，num_size/2的位置为树中最后一个根节点
    {  
        headadjust(num, i, num_size);
    }
}

//调整大根堆
void headadjust(int *num, int k, int num_size)  //k为根节点的编号
{
    num[0] = num[k];  //暂存这个值
    for (int i = 2*k; i <= num_size; i *= 2)
    {
        if (i < num_size && num[i] < num[i+1])  //找到左右孩子中更大的那个孩子，i<num_size是为了保证有右孩子
        {
            i ++;
        }
        if (num[0] > num[i])
        {
            break;
        }
        else
        {
            num[k] = num[i];
            k = i;            //交换位置之后可能会破坏下面的次序，将k赋值为i再进行判断，此时的i为调整的子树
        }
    }
    num[k] = num[0];
}

//先建立大根堆，再依次输出
void Heapsort(int *num, int num_size)
{
    buildmaxheap(num, num_size);
    for (int i = num_size; i > 1; i --)
    {
        swap(&num[1], &num[i]);   //把根节点(最大的元素)依次放到最后的节点中，之后大根堆次序打乱，重新排序
        headadjust(num, 1, i-1);  //每一次输出之后需要调整的长度就变短
    }
}

//判断是否满足小根堆
int Judgeminheap(int *num, int num_size)
{
    if (num_size%2 == 0)  //偶数个，有单分支
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
    else  //奇数个元素
    {
        for (int i = num_size/2; i >= 1; i --)
        {
            if (num[i] > num[2*i] || num[i] > num[2*i+1])
            {
                return 0;
            }
        }
    }
    return 1;
}

//归并有序序列
void Merge(int *num, int low, int mid, int high)
{
    int i, k, j;
    for (i = 0; i <= high; i ++)
    {
        nums1[i] = num[i];      //先将数据都复制到另一个数组中
    }
    for (i = low, k = low, j = mid+1; i <= mid && j <= high; k ++) //每次取较小值存放在原数组中
    {
        if (nums1[i] <= nums1[j])
        {
            num[k] = nums1[i++];
        }
        else 
        {
            num[k] = nums1[j++];
        }
    }
    while (i <= mid)            //将未比较完的剩余部分复制到原数组中
    {
        num[k++] = nums1[i++];
    }
    while (j <= high)
    {
        num[k++] = nums1[j++];
    }
}

//归并排序，从前往后依次比较，是稳定的
void MergeSort(int *num, int low, int high)
{
    if (low < high)                   //递归结束条件
    {
        int mid = (low + high) / 2;
        MergeSort(num, low, mid);     //递归将前面的序列分组排序
        MergeSort(num, mid+1, high);  //递归将后面的序列分组排序
        Merge(num, low, mid, high);   //排序进行的操作
    }
}

//计数排序，需要三个数组，一个原始数组，一个计数数组，一个最终排序数组，稳定的，时间复杂度为O(n+k)，k=n时，为O(n),空间为O(n+k)
void countingsort(int *num, int *result, int num_size)
{
    int *countnum = (int *)malloc(sizeof(int) * (num_size+1));
    for (int i = 0; i < num_size; i ++)   //初始化计数数组
    {
        countnum[i] = 0;
    }
    for (int i = 0; i < num_size; i ++)   //对原始数组进行计数
    {
        countnum[num[i]] ++;
    }
    for (int i = 1; i < num_size; i ++)   //对计数数组进行统计
    {
        countnum[i] += countnum[i-1];
    }
    for (int i = 0; i < num_size; i ++)
    {
        result[countnum[num[i]] - 1] = num[i];  //计数数组中存储的是小于等于i的数量，需要减1，循环的是num[i]
        countnum[num[i]] --;  //如果有重复的数，减1，方便下次循环到该相同元素时将其放在前一个位置
    }
    free(countnum);
}

//将所有奇数放到所有偶数前面
void quickmove(int *num, int num_size)
{
    int left = 0;
    int right = num_size - 1;
    while (left < right)
    {
        while (left < right && num[left]%2 != 0) //是奇数就往后移
        {
            left ++;
        }
        swap(&num[left], &num[right]);

        while (left < right && num[right]%2 == 0) //是偶数就往前移
        {
            right --;
        }
        swap(&num[left], &num[right]);
    }
}

//找到第k大的元素，基于快速排序，通过比较枢轴pivot与k来进行递归
//当num[m] = pivot，m = k时，即piovt就是要找的目标值
//m<k时，所要寻找的元素在num[m+1...n]中
//m>k时，所要寻找的元素在num[0...m-1]中
int kth_elem(int *num, int left, int right, int k)
{
    int left_temp = left;
    int right_temp = right;
    int piovt = num[left];
    //以下部分实现快排
    while (left < right)
    {
        while (left < right && num[right] >= piovt) //这里必须加=，因为当num[left] = num[right]时会一直循环
        {
            right --;
        }
        if (left != right)
        {
            num[left] = num[right];
        }
        
        while (left < right && num[left] <= piovt)
        {
            left ++;
        }
        if (left != right)
        {
            num[right] = num[left];
        }
    }
    num[left] = piovt;
    //以下部分实现寻找第k大的元素
    if (left == k)
    {
        return num[left];
    }
    else if (left < k)  //在右边区域
    {
        return kth_elem(num, left+1, right_temp, k);
    }
    else if (left > k)  //在左边区域
    {
        return kth_elem(num, left_temp, left-1, k);
    }
    return num[left];
}


//找到第k大的元素
int findknum(int *num, int left, int right, int k)
{
    int piovt = num[left];
    int left_temp = left;
    int right_temp = right;
    while (left < right)
    {
        while (left < right && num[right] > piovt)
        {
            right --;
        }
        swap(&num[right], &num[left]);
        while (left < right && num[left] < piovt)
        {
            left ++;
        }
        swap(&num[right], &num[left]);
    }
    num[left] = piovt;
    if (k == left)
    {
        return piovt;
    }
    else if (k < left)
    {
        return findknum(num, left_temp, left-1, k);
    }
    else 
    {
        return findknum(num, left+1, right_temp, k);
    }
    return piovt;
}

typedef enum{RED, WHITE, BLUE} color;

//将数组排为1，1，1，2，2，2，3，3，3的形式
void Flag_Arrange(int *num, int num_size)
{
    int i = 0, j = 0, k = num_size-1;
    while (j <= k)      //使i以前的颜色都是红色，k以后的颜色都是蓝色，j为工作指针
    {
        switch (num[j])
        {
            case RED:
                swap(&num[i], &num[j]);
                i ++;
                j ++;
                break;
            
            case WHITE:
                j ++;
                break;

            case BLUE:
                swap(&num[j], &num[k]);
                k --;
                break;   //这里不能添加j++，防止交换之后还是蓝色
            
            default:
                break;
        }
    }
}

//2016年真题
int num_2016(int *num, int left, int right, int num_size)
{
    int left_temp = left;
    int right_temp = right;
    int piovt = num[left];
    int sum1 = 0, sum2 = 0;
    while (left < right)
    {
        while (num[right] > piovt)
        {
            right --;
        }
        swap(&num[right], &num[left]);

        while (num[left] < piovt)
        {
            left ++;
        }
        swap(&num[left], &num[right]);
    }
    num[left] = piovt;
    if (left == (num_size/2-1))
    {
        for (int i = 0; i <= left; i ++)
        {
            sum1 += num[i];
        }
        for (int i = left + 1; i < num_size; i ++)
        {
            sum2 += num[i];
        }
        return sum2 - sum1;
    }
    else if (left > (num_size/2-1))  //分割点在左边
    {
        return num_2016(num, left_temp, left-1, num_size);
    }
    else if (left < (num_size/2-1))  //分割点在右边
    {
        return num_2016(num, left+1, right_temp, num_size);
    }
    return 0;
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

//打印数组
void printf_array(int* num, int num_size)
{
    printf("printf_array:\n");
    for (int i = 0; i < num_size; i ++)
    {
        printf("%d\n", num[i]);
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
