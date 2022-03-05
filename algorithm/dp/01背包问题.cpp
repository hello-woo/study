#include<iostream>
#include<bits/stdc++.h>

/*
w:4, 3, 12,9
v:10, 7, 12,8
最多即小于等于15
问最大的价值为多少？

当为重量恰好满足装满背包时，dp[0] = 0,其他dp[1...v.size() - 1]都为负无穷大，如果为dp[v]为负无穷大，则没有
最优解
*/

using namespace std;

int getMaxValue(vector<int>&w,vector<int>&v,int maxWeight){
    int ans = 0;
    vector<vector<int>>dp(w.size(),vector<int>(maxWeight + 1,0));
    //外层遍历物品
    for(int i = 1 ;i < v.size();i++){
        //内层遍历重量
#if 0
        for(int j = 0;j <= maxWeight;j++){
            //如果背包容量不足以容纳下第[i]个物品
            if(j < w[i]){
                dp[i][j] = dp[i-1][j]; //最大价值即为i-1时候的
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-w[i]] + v[i]);
            }
        }
#endif
            for(int j = w[i] ; j <= maxWeight;j++){
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w[i]] + v[i]);
            }
    }
    return dp[v.size()- 1][maxWeight];
}


int onedp_get_max_value(vector<int>&w,vector<int>&v,int maxWeight){
    vector<int>dp(maxWeight + 1,0);
    for(int i = 0 ; i < w.size();i++){
        //内层遍历重量时,逆序刷表
        for(int j = maxWeight; j >= w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
        }
    }
    return dp[maxWeight];
}


int main(){
    vector<int> weight = {4, 3, 12,9};   //各个物品的重量
    vector<int> value = {10, 7, 12,8}; //对应的价值
    int bagWeight = 15;                //背包最大能放下多少重的物
    int res = getMaxValue(weight,value,bagWeight);
    int ans = onedp_get_max_value(weight,value,bagWeight);

    cout << res << endl; //19
    cout << ans << endl; //19

    return 0;
}