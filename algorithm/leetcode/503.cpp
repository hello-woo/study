/*************************************************************************
	> File Name: 503.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 09 Apr 2021 10:34:27 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int a[30005],val;
int main(){
    int w,n;
    cin>>w>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        a[i]=val;
    }
    sort(a,a+n);
    int cnt=0;
    int p=0,q=n-1;
    while(p<=q){
        while(p<q&&a[p]+a[q]>w) q--,cnt++;
        cnt+=1;
        p++;
        q--;
    }
    cout<<cnt<<endl;
    return 0;
}
