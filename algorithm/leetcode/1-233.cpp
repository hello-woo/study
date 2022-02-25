/*************************************************************************
	> File Name: 1-233.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Thu 01 Apr 2021 11:56:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans[10005];

int main(){
    int n,m,p,h;
    cin>>n>>p>>h>>m;
    for(int i=1;i<=n;i++){
        ans[i]=h;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        int f=0;
        for(int j=a+1;j<b;j++){
            if(ans[a]<=ans[j]||ans[j]>=ans[b]){
                f=1;
                break;
            }
        }
        if(f==1){
            for(int j=a+1;j<b;j++){
                ans[j]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
