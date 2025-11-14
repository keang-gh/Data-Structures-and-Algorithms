// 二分搜索中的分治思想
// 注意：二分搜索要先排序

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

// 分治算法思想-二分搜索
bool binarySearch(vector<int> &vec,int q,int p,int target){
    if(q>p){
        return false;
    }

    int mid = (q + p) / 2;
    if(vec[mid]==target){
        return true;
    }
    else if(vec[mid]>target){
        return binarySearch(vec, q, mid - 1, target);
    }
    else{
        return binarySearch(vec, mid + 1, p, target);
    }
}

int main()
{
    vector<int> vec;
    for (int i = 0; i < 19;i++){
        vec.push_back(rand() % 100 + 1);
    }
    sort(vec.begin(), vec.end());
    vec.push_back(103);

    cout << binarySearch(vec, 0, vec.size() - 1, 103) << endl;

    return 0;
}