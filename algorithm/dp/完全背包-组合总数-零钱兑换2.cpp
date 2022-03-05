#include<bits/stdc++.h>

using namespace std;

/*1,2,5,10恰好构成100的组合数目*/

/*解题思路：即为求完全背包的组合问题*/

/*
组合不强调元素之间的顺序，排列强调元素之间的顺序

*/


int money[4] = {1,2,5,10};

int main(){
    vector<int>dp(101,0);
    dp[0] = 1;
    for(int i = 0;i< 4;i++){
        for(int j = money[i];j <= 100;j++){
            dp[j] = dp[j] + dp[j-money[i]];
        }
    }
    cout << dp[100] << endl;
}