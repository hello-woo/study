/*************************************************************************
	> File Name: tencent2.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sun 04 Apr 2021 08:16:48 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
string val;
stack<char>sta;
int main(){
    cin>>n;
    cin>>val;
    for(int i=0;i<val.size();i++){
        if(!sta.empty()&&val[i]-'0'+sta.top()-'0'==10){
            sta.pop();
        }else {
            sta.push(val[i]);
        }
    }
    cout<<sta.size()<<endl;
    return 0;
}
