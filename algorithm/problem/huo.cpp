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
int res=0;
int main(){
    cin>>len;
    for(int i=0;i<len;i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    //num的长度为n+1，第一位插入0;
    cin>>taget;
    for(int i=0;i<len;i++){
        vector<int>dp(len-i,0);
        int j=i;
        dp[j]=num[i];
        for( j=i+1;j<len;j++){
            dp[j]=max(dp[j-1],num[j]);
            if(dp[j]<=taget) res++;
        }
    }
    for(int i=0;i<len;i++){
        if(num[i]<=taget) res++;
    }
    cout<<res<<endl;
    return 0;
}
