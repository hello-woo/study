/*
leetcode 494
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
left - right = target;
left + right = sum;
即为找出 2*left = (target + sum);
在nums中找出left = (target + sum) / 2的组合总数
01 背包的组合问题
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        int total = sum + target ;
        //如果和为奇数，则不可能找到满足题意得组合数
        if(total & 1) return 0;
        int tar = total / 2;
        //题目里面nums[i]>0,如果abs(target) 比最最大值都大，说明没有符合题意得组合数
        if(abs(target) > sum) return 0;
        vector<int>dp(tar + 1,0);
        //以下为01背包一维动态规划得求组合总数得解题思路，逆向刷表
        dp[0] = 1;
        for(int i = 0; i < nums.size();i++){
            for(int j = tar ;j >= nums[i] ;j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[tar];
    }
};


int main(){
    Solution s1;
    vector<int>nums={1,1,1,1,1};
    int target = 3;
    int res = s1.findTargetSumWays(nums,target);
    cout << res << endl; // 5
}