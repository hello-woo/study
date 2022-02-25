/*************************************************************************
> File Name: 50-1.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sat 16 Jan 2021 10:03:58 PM CST
************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100
#define MAX_K 500000
long long  dp[MAX_N+5][MAX_K+5];

int sovle(int n,int m){
    if(n==1) return m;
    for(int i=1;i<=MAX_K;i++) dp[1][i]=i;
    for(int i=2;i<=n;i++){
        for(int k=1;k<=MAX_K;k++){
            dp[i][k]=dp[i-1][k-1]+dp[i][k-1]+1;

        }
    }
    printf("n=%d\n",n);
    for(int i=1;i<=15;i++){
        printf("k=%d,dp=%lld\n",i,dp[n][i]);
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<sovle(n,m)<<endl;
    return 0;

}
