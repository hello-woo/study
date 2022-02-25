/*************************************************************************
	> File Name: 48.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 04:55:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 10000
int dp[max_n+5];
int main(){
    int V,n,v,w;
    cin>>n>>V;
    for(int i=1;i<=n;i++){
        cin>>v>>w;
        for(int j=v;j<=V;j++){
            dp[j]=max(dp[j],dp[j-v]+w);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
