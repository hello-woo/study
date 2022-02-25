/*************************************************************************
	> File Name: 198.c
	> Author:zhaozhicai
	> Mail:1871259919@qq.com 
	> Created Time: Mon 12 Oct 2020 05:09:07 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000007
long long int f(long long int n){
    int a[1000000]={0};
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=n;++i){
        a[i]=(a[i-1]%MAX_N+a[i-2]%MAX_N)%MAX_N;
    }
    return a[n];
}
int main(){
   long long  int n;
    scanf("%lld",&n);
    printf("%lld\n",f(n));
    return 0;
}
