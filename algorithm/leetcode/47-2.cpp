/*************************************************************************
	> File Name: 47.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 03:25:18 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 100
#define max_v 10000

int dp[max_v+5];

int main(){
    int V, n,v,w;
    cin>>V>>n;
    for(int i=1;i<=n;i++){
        cin>>v>>w;
        for(int j=V;j>=v;j--){
            dp[j]=max(dp[j],dp[j-v]+w);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
