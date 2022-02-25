/*************************************************************************
	> File Name: fn.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 27 Mar 2021 04:18:49 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,pair<int,int>>mp;
int n,m;
vector<int>a(n+1,0);
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[i]=temp;
        if(!mp.count(a[i])) mp[a[i]].first=i;
        if(mp.count(a[i])) mp[a[i]].second=i;
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        if(!mp.count(num)) cout<<0<<endl;
        else cout<<mp[num].first+1<<" "<<mp[num].second+1<<endl;
    }
    return 0;
}
