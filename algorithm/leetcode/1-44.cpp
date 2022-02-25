/*************************************************************************
	> File Name: 1-44.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 18 Jan 2021 11:31:56 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

#define max_n 1000000
int arr[max_n+5];
int dp[max_n+5];
int len[max_n+5];

int binary_search(int *len,int n,int val){
    int head=0,tail=n,mid;
    while(head<tail){
        mid=(head+tail)>>1;
        if(len[mid]>=val){
            tail=mid;
        }else{
            head=mid+1;
        }
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    memset(len,0x3f,sizeof(dp));
    len[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=binary_search(len,ans+1,arr[i]);
        len[dp[i]]=arr[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
