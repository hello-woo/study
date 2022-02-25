/*************************************************************************
	> File Name: hua.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 01 Apr 2021 07:08:14 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
pair<int,int>p;
vector<pair<int,int>>v;
int main(){
    int val,color;
    int res=0;
    for(int i=0;i<27;i++){
        cin>>val>>color;
        v.push_back(make_pair(val,color));
    }
    vector<int>p1;
    vector<int>p2;
    vector<int>p3;
    vector<int>p4;
    for(int i=0;i<27;i++){
        if(v[i].second==1){
            p1.push_back(v[i].first);
        }else if(v[i].second==2){
            p2.push_back(v[i].first);
        }else if(v[i].second==3){
            p3.push_back(v[i].first);
        }else{
            p4.push_back(v[i].first);
        }
    }
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    sort(p3.begin(),p3.end());
    sort(p4.begin(),p4.end());
    int cnt=0;
    for(int i=0;i<p1.size();i++){
        int p=p1[i];

    }

    return 0;
}

