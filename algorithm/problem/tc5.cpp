/*************************************************************************
	> File Name: tc5.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 04 Apr 2021 09:24:44 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n,m,w;
int res;
int sovle(vector<int>&fa,int m){
    sort(fa.begin(),fa.end());
    if(fa[fa.size()-1]<m) return -1;
    if(fa[fa.size()-1]%m==0) res=1;

}

int main(){
    int T;
    cin>>T;
    while(T--){
        vector<int>fa;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>w;
            fa.push_back(w);
        }
        sovle(fa,m);
    }
    return 0;
}
