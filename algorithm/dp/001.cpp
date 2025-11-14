/*******************************************************************
 问题：硬币选择问题
 描述: 有1、3、5分面额的硬币，给定一个面值11，问组成给定面值所需要要的最少的硬币数量是多少？
 思路：11：1+(10)   3+(8)   5+(6)
      10:1+(9)     3+(7)   5+(5)
      8:1+(7)      3+(5)   5+(3)
      6:1+(5)      3+(3)   5+(1)
 作者：周康
 时间：2024.07
********************************************************************/
#include<iostream>
#include<cstdlib>
using namespace std;

// 先用分治算法实现
int func1(int n){
    if(n==1 || n==3 || n==5){
        return 1;
    }
    else if(n==2 || n==4){
        return 2;
    }
    else{
        int n1 = func1(n-1) + 1;  // 选择了1分硬币
        int n2 = func1(n-3) + 1;  // 选择了3分硬币
        int n3 = func1(n-5) + 1;  // 选择了5分硬币
        return min(min(n1,n2),n3);
    }
}

// 再用动态规划实现（递归）
const int MAX_N = 1000;  // 假设n不超过1000
int dp[MAX_N + 1] = {0};
static int test_count = 0; // 测试：相对于分治算法重复求解的计数
int func2(int n)
{
    if(dp[n]>0){ // dp[n]这个问题已经被求解过了
        test_count++;   // 测试：相对于分治重复求解计数+1
        return dp[n];
    }
    if(n==1 || n==3 || n==5){
        dp[n] = 1;
        return 1;
    }
    else if(n==2 || n==4){
        dp[n] = 2;
        return 2;
    }
    else{
        int n1 = func2(n - 1) + 1;
        int n2 = func2(n - 3) + 1;
        int n3 = func2(n - 5) + 1;
        dp[n] = min(min(n1, n2), n3);
        return dp[n];
    }
}

// 动态规划的非递归实现
/*
问题的状态：dp[i]：组成面值i所需要的最少硬币数量
状态转移方程：
dp[0]=0
dp[1]=1+dp[1-1]=1
dp[2]=1+dp[2-1]=1+dp[1]=1+1=2
dp[3]=
    1+dp[3-1]=1+dp[2]=1+2=3
    1+dp[3]=1+dp[0]=1
...
从上面的理论推导得到下面的状态转移方程
dp[i]=min(1+dp[i-vj])   // i表示面值，vj表示第j个硬币的面额，i>=vj
*/

int main(){
    // int val = 100;
    // int num = func2(val);
    // cout << "num：" << num << endl;
    // cout << "test_count:" << test_count << endl;
    int v[] = {1, 3, 5};
    int length = sizeof(v) / sizeof(v[0]);
    int c = 18;
    int *dp = new int[c + 1]{0};  // dp[c]  dp[0]=0
    for (int i = 0; i <= c;++i){
        dp[i] = i; //表示初始全部由1分硬币组成
        for (int j = 0; j < length;++j){
            if(i>=v[j] && (1+dp[i-v[j]])<dp[i]){
                dp[i] = 1 + dp[i - v[j]];
            }
        }
    }
    cout << dp[c] << endl;
    delete[] dp;

    return 0;
}