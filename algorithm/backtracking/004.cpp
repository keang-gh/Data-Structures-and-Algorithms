/************************************************************
*描述：2N整数选择问题；给定2n个整数，从里面挑选出n个整数，让选择的整数
      和，和剩下的整数和的差最小
*时间：2024.9.11
*************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[]{12, 6, 7, 11, 16, 3, 8, 4};
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;                  // 记录子集中被选择的元素
vector<int> bestx;              // 记录最优解
int sum = 0;                    // 记录子集中所选数字的和
int unsum = 0;                  // 记录未选择数字的和
unsigned int min1 = 0xFFFFFFFF; // 记录最小差值
int testsum = 0;                // 测试，用于记录遍历的子集的个数
int unelesum = length;          // 记录未处理数字的个数

void func(int i)
{
    if (i == length)
    {
        testsum++;
        // 得到子集数的一个解，对应一个叶子节点
        if (x.size() != length / 2)
        {
            return;
        }

        int res = abs(sum - unsum);
        if (res < min1)
        {
            min1 = res;
            bestx = x;
        }
    }
    else
    {
        unelesum--;                // 表示处理了一个节点，表示剩余的未处理元素的个数
        if (x.size() < length / 2) // 剪左树枝，选择数字的前提：还没有选够n个整数
        {
            sum += arr[i];
            unsum -= arr[i];
            x.push_back(arr[i]);
            func(i + 1); // 遍历i的左孩子，表示选择i号元素
            sum -= arr[i];
            unsum += arr[i];
            x.pop_back();
        }

        // 这里右树枝剪枝：已选择的个数 +  未来能选的个数 >= n个元素,才进行
        if (x.size() + unelesum >= length / 2)
        {
            func(i + 1); // 遍历i的右孩子，表示不选择i号元素
        }

        // 当前i节点已经处理完了，回溯到父节点了
        unelesum++;
    }
}

int main()
{
    for (int ele : arr)
    {
        unsum += ele;
    }
    func(0);
    for (int ele : bestx)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "min:" << min1 << endl;
    cout << "testsum:" << testsum << endl;

    return 0;
}