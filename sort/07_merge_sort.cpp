/*******************************************************
 描述：归并排序
 时间复杂度：平均/最好/最坏：都是O(nlogn)
 空间复杂度：O(n)+O(logn) 取大的O(n)   后者是递归栈空间
 排序稳定性：稳定
 思路：递归
 作者：周康
 时间：2024.5.17
*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>  // 补充time头文件，避免time(nullptr)报错
using namespace std;

// 归并过程函数
void merge(int arr[], int l, int m, int r)
{
    int *p = new int[r - l + 1];  // 临时数组，存储合并结果
    int idx = 0;                  // 临时数组的索引
    int i = l, j = m + 1;         // i指向左半段起始，j指向右半段起始

    // 1. 比较左右两段元素，按顺序放入临时数组
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            p[idx++] = arr[i++];  // 左半段元素更小，放入临时数组
        }
        else
        {
            p[idx++] = arr[j++];  // 右半段元素更小，放入临时数组
        }
    }

    // 2. 处理左半段剩余元素（主循环结束后执行，而非内部）
    while (i <= m)
    {
        p[idx++] = arr[i++];  // 从原数组arr取剩余元素，修正p[i++]为arr[i++]
    }

    // 3. 处理右半段剩余元素（主循环结束后执行，而非内部）
    while (j <= r)
    {
        p[idx++] = arr[j++];  // 从原数组arr取剩余元素，修正p[j++]为arr[j++]
    }

    // 4. 将临时数组的结果拷贝回原数组[l, r]区间
    for (i = l, j = 0; i <= r; i++, j++)
    {
        arr[i] = p[j];
    }

    delete[] p;  // 释放临时数组内存
}

// 归并排序递归接口
void mergeSort(int arr[], int begin, int end)
{
    // 递归结束条件：子数组长度为1或0时无需排序
    if (begin >= end)
    {
        return;
    }

    int mid = (begin + end) / 2;          // 中间位置，拆分左右两段
    mergeSort(arr, begin, mid);           // 递归排序左半段[begin, mid]
    mergeSort(arr, mid + 1, end);         // 递归排序右半段[mid+1, end]
    merge(arr, begin, mid, end);          // 合并左右两段有序数组
}

// 归并排序对外接口（接收数组长度）
void mergeSort(int arr[], int size)
{
    if (size <= 1) return;  // 空数组或单元素数组无需排序
    mergeSort(arr, 0, size - 1);
}

int main()
{
    int arr[10];
    srand(time(nullptr));  // 初始化随机数种子

    // 生成10个1-100的随机数
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    // 打印排序前的数组
    cout << "排序前: ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    // 执行归并排序
    mergeSort(arr, 10);

    // 打印排序后的数组
    cout << "排序后: ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}