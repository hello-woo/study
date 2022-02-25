/*************************************************************************
	> File Name: 227.cpp
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Fri 09 Apr 2021 10:15:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long quick_mul(long long  a,long long  b,long long p){
    long long  ans=0,temp=a;
    while(b){
        if(b&1) ans=(ans+temp)%p;
        temp=temp*2%p;;
        b>>=1;
    }
    return ans;
}
int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<quick_mul(a,b,p)%p<<endl;
    return 0;
}
