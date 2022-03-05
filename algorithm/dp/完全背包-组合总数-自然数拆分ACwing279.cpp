#include<bits/stdc++.h>

using namespace std;

/*1,2,3,...n组合成总和为n得组合总数，其中参与加法的数可以重复

完全背包问题-组合总数 - 正序刷表*/

int getNum(int n){
    vector<int>dp(n + 1,0);
    dp[0] = 1;
    for(int i = 1;i < n ;i++){
        for(int j = i;j <= n; j++){
            dp[j] += dp[j - i]; 
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    int res = getNum(n);
    cout <<res <<endl;
    return 0;
}