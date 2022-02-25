/*************************************************************************
	> File Name: backage.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 30 Mar 2021 09:29:26 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int res=0;
vector<int>num;

void dfs(vector<int>&v,int startIndex,int w,int sum){
    if(sum>w) return ;
    if(sum<=w) res++;
    for(int i=startIndex;i<v.size();i++){
        sum+=v[i];
        dfs(v,i+1,w,sum);
        sum-=v[i];
    }
}

int main(){
    int n,w;
    cin>>n>>w;
    int val;
    vector<int>v(n+1,0);
    long sum=0;
    for(int i=0;i<n;i++){
        cin>>val;
        v[i]=val;
        sum+=v[i];
    }
    if(sum<=w) cout<<pow(2,n);
    else {
        dfs(v,0,w,0);
        cout<<res<<endl;
    }
    return 0;
}
