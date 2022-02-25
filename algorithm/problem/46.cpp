/*************************************************************************
	> File Name: 46.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 07:43:45 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 500000

bool ishuiwen(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int dp[max_n+5];
int main(){
    string s;
    cin>>s;
    dp[0]=0;
    for(int i=1;i<=s.size();i++){
        dp[i]=dp[i-1]+1;
        for(int j=0;j<i;j++){
            if(ishuiwen(s,j,i-1)){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    cout<<dp[s.size()]-1<<endl;
    return 0;
}
