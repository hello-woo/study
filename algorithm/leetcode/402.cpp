/*************************************************************************
> File Name: 402.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sat 21 Nov 2020 04:47:15 PM CST
************************************************************************/

#include<iostream>
using namespace std;
#include<iostream>
#include<queue>
struct node{
    int now,step;

};

int n,a,b,num[205],check[205];

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>num[i];

    }
    queue<node>que;
    que.push((node){a,0});
    check[a]=1;
    while(!que.empty()){
        node temp=que.front();
        que.pop();
        int up=temp.now+num[temp.now];
        int down=temp.now-num[temp.now];
        if(up==b||down==b){
            cout<<temp.step+1<<endl;
            return 0;

        }
        if(up<=n&&check[up]==0){
            que.push((node){up,temp.step+1});
            check[up]=1;

        }
        if(down>=1&&check[down]==0){
            que.push((node){down,temp.step+1});
            check[down]=1;

        }

    }
    cout<<-1<<endl;
    return 0;

}
