/*************************************************************************
	> File Name: 45.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 16 Jan 2021 12:35:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

string s1,s2;
int dp[max_n+5][max_n+5];
int main(){
    int n,m;
    cin>>s1>>s2;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];
    return 0;
}
