/*************************************************************************
	> File Name: euler14.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 07 Nov 2020 04:05:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long num[1000000];
int f(long long n){
    if(n==1) return 1;
    if(n<1000000&&num[n]) return num[n];
    int t;
    if(n%2==0){
        t = f(n/2)+1;
    }else{
        t = f(3*n+1)+1;
    }
    if (n<1000000){
        num[n]=t;
    }
    return t;
}
int main(){
    int ans=1;
    for(int i=2;i<=1000000;i++){
        if(f(ans)<f(i)){
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
