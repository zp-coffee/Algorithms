#include "stdio.h"
#include "stdlib.h"

extern int last_numsize;

//找到给定值并返回坐标，如果没有则返回-1
int search_a_num(int *num, int num_size, int target);

//给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度
int delete_nums(int *num, int num_size, int target);

//打印数组
void printf_array(int* num, int num_size);

//有序数组的平方排序
int *sort_nums_square(int *num, int num_size);

//找到数组中满足和<=s的最小长度并返回,数组中元素为正数
int find_minlen(int *num, int s, int num_size);

//删除最小值的元素(唯一)并返回，删除的元素由最后一个元素填补
int delete_min(int *num, int num_size);

//将两个数据交换
void swap(int *i, int *j);

//逆置数组
void swap_array(int *num, int num_size);

//逆置数组，从a到b
void swap_array_from_a_to_b(int* num, int a, int b);

//删除数组中处于a到b到元素
int delete_num_for_a_to_b(int *num, int a, int b, int num_size);

//删除有序数组中相同元素
int delete_samenum(int *num, int num_size);

//将两个有序数组合并成一个有序数组
int* sort_twoarray(int *num1, int *num2, int num_size1, int num_size2);

//将数组内的两个线性表交换次序
int* swap_array_inside(int *num, int m, int n, int num_size);

//不使用额外空间
void swap_array_inside_nospace(int* num, int m, int n, int num_size);

//从三个相同长度的递增数组中找出相同的元素并返回
int find_same_num(int *num1, int *num2, int *num3, int num_size);

//在一个数组的第几个位置插入一个元素
int* insert_a_num(int *num, int target, int n, int num_size);

//使用三个指针同时移动
void find_same_num1(int *num1, int *num2, int *num3, int num_size);

//找最大值
int find_max(int a, int b, int c);

//在一个递增数组中寻找一个值，如果找到将其与后续元素交换，否则插入
int* find_a_num(int *num, int target, int num_size);

//begin和end都代表数组下标
void array_reverse(int *num, int begin, int end);

//实现数组内两个线性表的逆置
void swap_array_inside1(int *num, int p, int num_size);

//找中位数
int find_middle_num(int *num1, int *num2, int num_size);

//找主元素
int find_mainnum(int *num, int num_size);

//找主元素，时间为n，空间为1，思想为先找出可能为主元素的数，最后再进行统计
int find_mainnum1(int* num, int num_size);

//找到数组中未出现的最小正整数
int no_appearnum(int *num, int num_size);

//***************************排序算法*****************************

//冒泡排序
void bubblesort(int *num, int num_size);

//冒泡排序，简化
void bubblesort2(int *num, int num_size);

//冒泡排序，将最大的元素冒泡到最终位置
void bubblesort3(int *num, int num_size);

//选择排序
void selectsort(int *num, int num_size);

//插入排序
void insertsort(int *num, int num_size);

//插入排序的另一种写法
void insertsort2(int *num, int num_size);

//插入排序，使用折半查找，只能用于顺序存储的线性表
void insertsort3(int *num, int num_size);

//希尔排序，在插入排序的基础上将单位1改为d
void shellsort(int *num, int num_size);

//快速排序
void quicksort(int *num, int start, int end);

//归并有序序列
void Merge(int *num, int low, int mid, int high);

//归并排序
void MergeSort(int *num, int low, int high);

//将所有奇数放到所有偶数前面
void quickmove(int *num, int num_size);

//找到第k大的元素，基于快速排序，通过比较枢轴pivot与k来进行递归
int kth_elem(int *num, int left, int right, int k);

//将数组排为1，2，3，1，2，3，1，2，3的形式
void Flag_Arrange(int *num, int num_size);

//2016年真题
int num_2016(int *num, int left, int right, int num_size);

//先建立大根堆,当使用顺序存储存放二叉树时，num[0]不存放数据，从1开始，这样才能满足2n和2n+1为左孩子和右孩子
void buildmaxheap(int *num, int num_size);

//调整大根堆
void headadjust(int *num, int k, int num_size);

//堆排序
void Heapsort(int *num, int num_size);

//判断是否满足小根堆
int Judgeminheap(int *num, int num_size);

//计数排序
void countingsort(int *num, int *result, int num_size);

//计数排序
void countsort(int *num, int num2[], int num_size);

//找三个数组中的三元组的最小距离
int find_min_distance(int *num1, int *num2, int *num3, int num_size1, int num_size2, int num_size3);

//找三个数组中的三元组的最小距离，三指针法
int find_min_distance1(int *num1, int *num2, int *num3, int num_size1, int num_size2, int num_size3);

//计算三个数据的差的绝对值之和
int cal_absolute(int a, int b, int c);

//计算两个数的差的绝对值
int absolute(int x, int y);

//判断a是不是最小的值
int minimal_data(int a, int b , int c);

//找到第k大的元素
int findknum(int *num, int left, int right, int k);

void insert_test2(int* num, int num_size);
