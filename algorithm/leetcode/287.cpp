/*************************************************************************
	> File Name: 287.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 09 Apr 2021 11:36:23 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> >que;

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        que.push(t);
    }
    while(que.size()>1){
        int a=que.top();
        que.pop();
        a+=que.top();
        que.pop();
        ans+=a;
        que.push(a);
    }
    cout<<ans <<endl;
    return 0;
}
