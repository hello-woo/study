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

int v[max_n+5],w[max_n+5];
int dp[2][max_v+5];

int main(){
    int V, n;
    cin>>V>>n;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=V;j++){
            dp[i%2][j]=dp[(i-1)%2][j];
            if(j>=v[i]){
                dp[i%2][j]=max(dp[(i-1)%2][j],dp[(i-1)%2][j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[n%2][V]<<endl;
    return 0;
}
