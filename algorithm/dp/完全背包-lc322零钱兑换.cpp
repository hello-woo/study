#include<bits/stdc++.h>

using namespace std;

/*leetcode 322
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

dp[i][j] 前 i 个物品，背包最大承重为 j 的情况下，最大价值
dp[i][j] = max(dp[i - 1][j] + dp[i][j - w[i]]  +v[i]);
*/


int two_dimensional_coin_change(vector<int>&nums,int amount){

}


int coinChange(vector<int>&nums,int amount){
    vector<int>dp(amount + 1,INT_MAX);
    dp[0] = 0;
    //外层遍历物品，内层遍历重量
    for(int i = 0 ;i < nums.size();i++){
        //完全背包，正序刷表
        for(int j = nums[i] ;j <= amount ;j++){
            dp[j] = min(dp[j],dp[j - nums[i]] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1:dp[amount];
}

int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;
    int res = coinChange(coins,amount);
    cout << res << endl;
    return 0;
}