/*************************************************************************
	> File Name: 49.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 05:06:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 100000
int dp[max_n+5];

int main(){
    int V,n,v,w,s;
    cin>>V>>n;
    for(int i=1;i<=n;i++){
        cin>>v>>w>>s;
        for(int k=0;k<s;k++){
            for(int j=V;j>=v;j--){
                dp[j]=max(dp[j],dp[j-v]+w);
            }
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
