/*************************************************************************
	> File Name: 1234.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 28 Mar 2021 08:25:46 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

long long  n,m,q;
vector<vector<int>>mmap(100000,vector<int>(100000,0));
int main(){
    cin>>n>>m>>q;
    for(long long  i=0;i<q;i++){
        long long  x,y;
        cin>>x>>y;
        mmap[x-1][y-1]=1;
    }
    vector<vector<long long >>dp(n,vector<long long >(m,0));
    for(long long  i=0;i<n&&mmap[i][0]==0;i++) dp[i][0]=1;
    for(long long  j=0;j<m&&mmap[0][j]==0;j++) dp[0][j]=1;
    for(long long  i=1;i<n;i++){
        for(long long  j=1;j<m;j++){
            if(mmap[i][j]!=1){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}
