/************************************************************
*描述：整数选择问题；给定一组整数，从里面挑选出一组整数，让选择的整数
      和，和剩下的整数和的差最小
*时间：2024.9.11
*************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int arr[] = {12, 6, 7, 11, 16, 3, 9};
const int length = sizeof(arr) / sizeof(arr[0]);
unsigned int min1 = 0xFFFFFFFF; // 记录最小的差值
int sum = 0;                    // 记录所选子集数字的总和
int unsum = 0;                  // 记录未选择数字的和
int bestx[length]{0};           // 记录最优解

// 子集树辅助数组，记录节点走向左孩子还是右孩子，代表i节点被选&未被选
int x[length]{0};

// 生成子集树
void func(int i)
{
    if (i == length) // 访问到了子集树的一个叶子节点了
    {
        // sum
        int res = abs(sum - unsum);
        if (res < min1)
        {
            min1 = res;
            // 需要记录一下差值最小的子集
            {
                for (int j = 0; j < length; ++j)
                {
                    bestx[j] = x[j];
                }
            }
        }
    }
    else
    {
        unsum -= arr[i];
        sum += arr[i];
        x[i] = 1;
        func(i + 1); // 选择i节点
        unsum += arr[i];
        sum -= arr[i];
        
        x[i] = 0;
        func(i + 1); // 不选择i节点
    }
}

int main()
{
    for (int ele : arr)
    {
        unsum += ele;
    }

    func(0);

    for (int i = 0; i < length; ++i)
    {
        if (bestx[i] == 1)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "min:" << min1 << endl;
    return 0;
}