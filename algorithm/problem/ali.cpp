/*************************************************************************
	> File Name: ali.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 06 Mar 2021 07:32:58 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[0][0] = 6;
    dp[0][1] = 6;

    for(int i = 1;i<n;i++)
    {
        dp[i][0] = 3*dp[i-1][0]+2*dp[i-1][1];
        dp[i][1] = 2*dp[i-1][0]+2*dp[i-1][1];
    }

    int num = dp[n-1][0]+dp[n-1][1];
    cout<<num<<endl;

    return 0;
}
