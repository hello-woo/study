/*************************************************************************
	> File Name: 383.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 05 Dec 2020 09:12:50 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int x,y,n;

queue<int>qx,qy;
int main(){
    cin>>x>>y>>n;
    for(int i=1;i<=x;i++){
        qx.push(i);
    }
    for(int i=1;i<=y;i++){
        qy.push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<qx.front()<<" "<<qy.front()<<endl;
        qx.push(qx.front());
        qy.push(qy.front());
        qx.pop();
        qy.pop();
    }
    return 0;
}
