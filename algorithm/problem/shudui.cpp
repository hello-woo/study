/*************************************************************************
> File Name: shudui.cpp
> Author:zhaozhicai
> Mail:1871259919@qq.com 
> Created Time: Sun 14 Mar 2021 08:45:57 PM CST
************************************************************************/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    int n,k;
    cin>>n>>k;
    if(n==1) cnt=1;
    for(int i=n;i>=n/2;i--){
        for(int j=2;j<=n/2+1;j++){
            if(i%j>=k){
                cnt++;
                cout<<i<<" "<<j;
            }
            cout<<endl;
        }
    }
    cout<<cnt<<endl;
    cnt=cnt+(n-k+1)*(n-k)/2;
    cout<<cnt<<endl;
    return 0;

}
