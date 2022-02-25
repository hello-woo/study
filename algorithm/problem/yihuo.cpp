/*************************************************************************
	> File Name: yihuo.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 27 Mar 2021 07:52:19 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int len;
vector<int>num;
int taget;
vector<int>dp(len+1,0);
int res=0;
int main(){
    cin>>len;
    num.push_back(0);
    for(int i=0;i<len;i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    //num的长度为n+1，第一位插入0;
    cin>>taget;
    dp[0]=0;
    for(int i=1;i<len+1;i++){
        dp[i]=dp[i-1]^num[i];
        cout<<dp[i]<<endl;
    }
    for(int i=1;i<len+1;i++){
        for(int j=i+1;j<len+1;j++){
            //i到j的异或;
            cout<<(dp[i-1]^dp[j])<<endl;
            if((dp[i-1]^dp[j])<=taget) res++;
        }
    }
    cout<<res+len<<endl;
    return 0;
}
