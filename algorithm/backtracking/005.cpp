/************************************************************
 *描述：挑选数字---有一组整数，挑选出一组数字，让他们的和等于指定的值，打印
 *时间：2024.9.11
 *************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int arr[]{4, 8, 12, 16, 7, 9, 3};
int length = sizeof(arr) / sizeof(arr[0]);
int tgt = 18;
vector<int> x;    // 记录选择的数字
int sum = 0;      // 记录所选数字的和
int unelesum = 0; // 记录未处理的数字的和    不要混淆未处理和未选择

void func(int i)
{
    if (i == length)
    {
        if (sum != tgt)
        {
            return;
        }
        for (int ele : x)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    else
    {
        unelesum -= arr[i];
        if (sum + arr[i] <= tgt) // 剪左树枝   已选择的树枝的和 + 即将要选择的数字
        {
            sum += arr[i];
            x.push_back(arr[i]);
            func(i + 1);
            sum -= arr[i];
            x.pop_back();
        }

        if (sum + unelesum >= tgt)  // 剪右树枝  已选择的数字的和 + 剩余可以被选的数字的和（i+1,...,n）
        {
            func(i + 1);
        }

        unelesum += arr[i];
    }
}

int main()
{
    for (auto ele : arr)
    {
        unelesum += ele;
    }
    func(0);
    return 0;
}