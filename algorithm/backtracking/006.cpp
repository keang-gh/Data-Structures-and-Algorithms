/************************************************************
 *描述：挑选数字---有一组整数，挑选出一组数字，让他们的和等于指定的值，打印(穷举法)
 *时间：2024.9.11
 *************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int arr[]{4, 8, 12, 16, 7, 9, 3};
const int length = sizeof(arr) / sizeof(arr[0]);
int tgt = 18;
vector<int> vec; //存放选择的数字

void func(int i,int tgt)
{
    if(tgt==0)
    {
        for(int ele:vec)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    else
    {
        for (int k = i; k < length;++k)
        {
            if(tgt>=arr[k])   // 剩余的元素小于tgt
            {
                vec.push_back(arr[k]);
                //func(k + 1, tgt - arr[k]);    // 不可以重复选择元素
                func(k, tgt - arr[k]);   // 可以选择重复元素
                vec.pop_back();
            }
        }
    }
}

int main()
{
    func(0, tgt);

    return 0;
}