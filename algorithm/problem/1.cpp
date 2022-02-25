/*************************************************************************
	> File Name: 1.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Tue 19 Jan 2021 05:32:04 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
   // auto it=upper_bound(v.begin(),v.end(),2);
    auto it=lower_bound(v.begin(),v.end(),2);
    v.insert(it,2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}

