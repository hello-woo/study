/*************************************************************************
	> File Name: fib.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Sat 07 Nov 2020 03:34:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long  num[100000];
long long f(int n){
    if(n==1||n==2) return 1;
    if(num[n]) return num[n];
    return num[n]=f(n-1)+f(n-2);
}
long long f1(int n){
    if(n==1||n==2) return 1;
    return f(n-1)+f(n-2);
}

int main(){
    for(int i=0;i<=100000;i++){
        cout<<i<<":"<<f(i)<<endl;
    }
    return 0;
}
