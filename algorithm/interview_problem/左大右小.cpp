/**
 * @file 左大右小.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
求数组中比左边元素都大同时比右边元素都小的元素，返回这些元素的索引
要求时间复杂度 o(N)

输入：[2, 3, 1, 8, 9, 20, 12]
输出：3, 4
解释：数组中 8, 9 满足题目要求，他们的索引分别是 3、4
 */

#include<bits/stdc++.h>

using namespace std;

const int N = 5007;
int nums[N];
int n;

vector<int>getIndex(){
    vector<int>left(n + 1,INT_MIN);
    left[1] = nums[1];
    for(int i = 2 ;i <= n ;i++){
        left[i] = max(left[i - 1],nums[i - 1]);
    }

    vector<int>right(n + 1,INT_MAX);
    right[n] = nums[n] + 1;
    for(int i = n - 1; i >= 0;i--){
        right[i] = min(right[i + 1],nums[i + 1]);
    }

    vector<int>ans;
    for(int i = 1; i <= n;i++){
        if(nums[i] > left[i] && nums[i] < right[i]){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n ;i++){
        cin>> nums[i];
    }
    vector<int>res = getIndex();
    for(int i = 0 ;i < res.size();i++){
        cout << res[i] - 1 << "," ;
    }
    return 0;
}