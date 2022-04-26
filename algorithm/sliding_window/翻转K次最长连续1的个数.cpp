/* 给定一个二进制数组 nums 和一个整数 k，
如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
 */

#include<bits/stdc++.h>

using namespace std;

int getLengthOfOnes(vector<int>&nums,int k){
    int l = 0, r = 0;
    int zeros = 0;
    int ans = 0;

    while(r < nums.size()){
        if(nums[r] == 0){
            zeros++;
        }

        //当0的数量大于K，说明要缩紧左边界
        while(zeros > k){
            if(nums[l] == 0){
                zeros--;
            }
            l++;
        }
        r++;

        ans = max(ans,r - l);
    }
    return ans;
}


int main(){
    vector<int>nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout << getLengthOfOnes(nums,k);
    return 0;
}