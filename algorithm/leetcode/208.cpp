/*************************************************************************
	> File Name: 208.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 02 Apr 2021 12:21:59 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
int m,sore,num[105];
unordered_map<int,int>mp;
int n;
int main(){
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>sore;
        mp[sore]++;
    }
    cin>>n;
    int max_val=INT_MIN;
    for(auto v:mp){
        if(v.first>max_val){
            max_val=v.first;
        }
    }
    for(auto v:mp){
        if(v.first)
    }

    return 0;
}
