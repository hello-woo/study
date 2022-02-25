/*************************************************************************
	> File Name: 46.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 02:59:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 50000

int dp[max_n+5];

bool is_huiwen(string s,int l,int r){
    while(l<r){
        if(s[l++]-s[r--]) return false;
    }
    return true;
}

int main(){
    string s ;
    cin>>s;
    //dp[i]:表示以第i个字符结尾的切割刀数;
    dp[0]=0;
    for(int i=1;i<=s.size();i++){
        dp[i]=dp[i-1]+1;
        for(int j=0;j<i;j++){
            if(is_huiwen(s,j,i-1)){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    cout<<dp[s.size()]-1<<endl;
    return 0;
}
