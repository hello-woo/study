/*************************************************************************
	> File Name: 44.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 12:05:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 1000000
int arr[max_n+5];

int dp[max_n+5];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]>=arr[i]) continue;
            dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
