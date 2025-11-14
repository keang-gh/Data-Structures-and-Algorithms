//快速排序中的分治思想

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;

// 快排划分函数，用于调整基准数
int partition(vector<int> &vec,int i,int j){
    int val = vec[i];  // 作为基准数
    int left = i, right = j;
    while(left<right){
        while(left<right && vec[right]>=val){  //从右往左找第一个比val小的
            right--;
        }
        if(left<right){
            vec[left++] = vec[right];
        }
        while(left<right && vec[left]<val){  //从左往右找第一个比val大的
            left++;
        }
        if(left<right){
            vec[right--] = vec[left];
        }
    }
    vec[left] = val;  // right & left都行，放置基准数
    return left;      // 返回基准数的下标
}
void quickSort(vector<int> &vec,int i,int j){
    if(i>=j){
        return;
    }
    int pos = partition(vec, i, j);
    quickSort(vec, i, pos - 1);
    quickSort(vec, pos + 1, j);
}

int main(){
    vector<int> vec;
    for (int i = 0; i < 11;i++){
        vec.push_back(rand() % 100);
    }

    for(int ele:vec){
        cout << ele << " ";
    }
    cout << endl;

    quickSort(vec, 0, vec.size() - 1);
    for(int ele:vec){
        cout << ele << " ";
    }
    cout << endl;
}