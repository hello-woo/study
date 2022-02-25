/*************************************************************************
	> File Name: 50.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 05:47:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


#define MAX_N 32
#define MAX_M 1000000
int dp[MAX_N+5][MAX_M+5];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=m;i++) dp[1][i]=i;//一个鸡蛋测m次；
    for(int i=2;i<=n;i++){
        int k=2;
        dp[i][1]=1;
        for(int j=2;j<=m;j++){
            while(k<=j&&dp[i-1][k-1]<dp[i][j-k]) ++k;
            dp[i][j]=max(dp[i-1][k-1],dp[i][j-k])+1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
